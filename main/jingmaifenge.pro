QT += core
QT -= gui

TARGET = jingmaifenge
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    detector.cpp



#INCLUDEPATH +=/home/nvidia/Install-OpenCV/Ubuntu/OpenCV/opencv-3.4.2/include \
#               /home/nvidia/Install-OpenCV/Ubuntu/OpenCV/opencv-3.4.2/include/opencv \
#               /home/nvidia/Install-OpenCV/Ubuntu/OpenCV/opencv-3.4.2/include/opencv2

#LIBS += /home/nvidia/Install-OpenCV/Ubuntu/OpenCV/opencv-3.4.2/build/lib/libopencv_*.so \
INCLUDEPATH += /usr/include \
                /usr/include/opencv \
                /usr/include/opencv2

LIBS += /usr/lib/x86_64-linux-gnu/libopencv_core.so   \
        /usr/lib/x86_64-linux-gnu/libopencv_highgui.so \
        /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so
       # /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so \
  #      /usr/lib/x86_64-linux-gnu/libopencv_videoio.so




INCLUDEPATH += /home/b515/caffe-enet/include/
LIBS += -L/home/b515/caffe-enet/build/lib -lcaffe
#LIBS += /home/nvidia/caffe-enet/build/lib/_caffe.so \
#        /home/nvidia/caffe-enet/build/lib/libcaffe.so.1.0.0-rc3


LIBS+= -L/usr/lib/x86_64-linux-gnu  -lglog -lgflags -lprotobuf -lleveldb -lsnappy -llmdb -lboost_system  -lm -lboost_thread -lstdc++  -lprotobuf  -lcblas -latlas
LIBS+= -L/usr/lib/x86_64-linux-gnu/libhdf5_hl_cpp.so \
         /usr/lib/x86_64-linux-gnu/libhdf5_cpp.so




INCLUDEPATH +=/usr/include/python2.7/
INCLUDEPATH +=/usr/include/
INCLUDEPATH +=/usr/local/include/
LIBS += -lboost_python -lpython2.7 -lboost_system


LIBS += -pthread
QMAKE_CXXFLAGS += -std=c++11 -g

## CUDA settings <-- may change depending on your system
#CUDA_SDK = "/usr/local/cuda-8.0"   # Path to cuda SDK install
#CUDA_DIR = "/usr/local/cuda-8.0"            # Path to cuda toolkit install

## DO NOT EDIT BEYOND THIS UNLESS YOU KNOW WHAT YOU ARE DOING....

#SYSTEM_NAME = unix         # Depending on your system either 'Win32', 'x64', or 'Win64'
#SYSTEM_TYPE = 64           # '32' or '64', depending on your system
#CUDA_ARCH = compute_61     # Type of CUDA architecture, for example 'compute_10', 'compute_11', 'sm_10'
#NVCC_OPTIONS = --use_fast_math


## include paths
#INCLUDEPATH += $$CUDA_DIR/include

## library directories
#QMAKE_LIBDIR += $$CUDA_DIR/lib64/

#CUDA_OBJECTS_DIR = ./

## CUDA settings <-- may change depending on your system



## Add the necessary libraries
#CUDA_LIBS = -lcuda -lcudart

## The following makes sure all path names (which often include spaces) are put between quotation marks
#CUDA_INC = $$join(INCLUDEPATH,'" -I"','-I"','"')
##LIBS += $$join(CUDA_LIBS,'.so ', '', '.so')
#LIBS += $$CUDA_LIBS

## Configuration of the Cuda compiler
#CONFIG(debug, debug|release) {
#    # Debug mode
#    cuda_d.input = CUDA_SOURCES
#    cuda_d.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
#    cuda_d.commands = $$CUDA_DIR/bin/nvcc -D_DEBUG $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda_d.dependency_type = TYPE_C
#    QMAKE_EXTRA_COMPILERS += cuda_d
#}
#else {
#    # Release mode
#    cuda.input = CUDA_SOURCES
#    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
#    cuda.commands = $$CUDA_DIR/bin/nvcc $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda.dependency_type = TYPE_C
#    QMAKE_EXTRA_COMPILERS += cuda
#}

HEADERS += \
    detector.h

CUDA_SDK = "/usr/local/cuda"   # Path to cuda SDK install
CUDA_DIR = "/usr/local/cuda"            # Path to cuda toolkit install

# DO NOT EDIT BEYOND THIS UNLESS YOU KNOW WHAT YOU ARE DOING....

SYSTEM_NAME = ubuntu         # Depending on your system either 'Win32', 'x64', or 'Win64'
SYSTEM_TYPE = 64           # '32' or '64', depending on your system
CUDA_ARCH = sm_50           # Type of CUDA architecture, for example 'compute_10', 'compute_11', 'sm_10'
NVCC_OPTIONS = --use_fast_math


# include paths
INCLUDEPATH += $$CUDA_DIR/include \
            /usr/local/cuda/samples/common/inc

# library directories
QMAKE_LIBDIR += $$CUDA_DIR/lib64/

CUDA_OBJECTS_DIR = ./


# Add the necessary libraries
CUDA_LIBS = -lcuda \
 -lcudart \
/usr/local/cuda-9.0/lib64/libcufft.so \
#/usr/local/cuda-8.0/targets/aarch64-linux/lib/libcudart.so \


# The following makes sure all path names (which often include spaces) are put between quotation marks
CUDA_INC = $$join(INCLUDEPATH,'" -I"','-I"','"')
#LIBS += $$join(CUDA_LIBS,'.so ', '', '.so')
LIBS += $$CUDA_LIBS

# Configuration of the Cuda compiler
CONFIG(debug, debug|release) {
    # Debug mode
    cuda_d.input = CUDA_SOURCES
    cuda_d.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
    cuda_d.commands = $$CUDA_DIR/bin/nvcc -D_DEBUG $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
    cuda_d.dependency_type = TYPE_C
    QMAKE_EXTRA_COMPILERS += cuda_d
}
else {
    # Release mode
    cuda.input = CUDA_SOURCES
    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
    cuda.commands = $$CUDA_DIR/bin/nvcc $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
    cuda.dependency_type = TYPE_C
    QMAKE_EXTRA_COMPILERS += cuda
}


