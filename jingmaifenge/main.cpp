//#include "stdafx.h"
#include <caffe/caffe.hpp>
#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/objdetect/objdetect.hpp"
//#include <opencv2/imgproc/imgproc.hpp>
//#include <highgui.h>
#include <algorithm>
#include <iomanip>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
//#include <tchar.h>
//#include <afx.h>
#include <detector.h>
#include <iostream>
//#include <time.h>


using namespace std;
using namespace cv;

Classifier::Classifier(const string& model_file,
    const string& trained_file) {
#ifdef CPU_ONLY
    Caffe::set_mode(Caffe::CPU);
#else
    Caffe::set_mode(Caffe::GPU);
#endif

    /* Load the network. */
    net_.reset(new Net<float>(model_file, TEST));
    net_->CopyTrainedLayersFrom(trained_file);

    CHECK_EQ(net_->num_inputs(), 1) << "Network should have exactly one input.";
    CHECK_EQ(net_->num_outputs(), 1) << "Network should have exactly one output.";

    Blob<float>* input_layer = net_->input_blobs()[0];
    num_channels_ = input_layer->channels();
    CHECK(num_channels_ == 3 || num_channels_ == 1)
        << "Input layer should have 1 or 3 channels.";
    input_geometry_ = cv::Size(input_layer->width(), input_layer->height());

    Blob<float>* output_layer = net_->output_blobs()[0];
}



//int main(int argc, char** argv)
int main()
{
    //clock_t start_time1, end_time1, start_time2, end_time2, start_time3, end_time3;
    //::google::InitGoogleLogging(argv[0]);
    //start_time3 = clock();
//    string model_file = "/home/nvidia/gjz/1123/xueguan128-4/bn_conv_merged_model.prototxt";
//    string weights_file = "/home/nvidia/gjz/1123/xueguan128-4/bn_conv_merged_weights.caffemodel";
//    string model_file = "/home/nvidia/caffe-enet/xueguanxin/bn_conv_merged_model.prototxt";
//    string weights_file = "/home/nvidia/caffe-enet/xueguanxin/bn_conv_merged_weights.caffemodel";
    string model_file = "/home/b515/1221/xueguanxin/bn_conv_merged_model.prototxt";
    string weights_file = "/home/b515/1221/xueguanxin/bn_conv_merged_weights.caffemodel";

    //start_time1 = clock();
    Classifier classifier(model_file, weights_file);
    //end_time1 = clock();
    //double seconds1 = (double)(end_time1 - start_time1) / CLOCKS_PER_SEC;
    //std::cout << "init time=" << seconds1 << "s" << std::endl;
   for(int k=1;k<13;k++)
   {
    Mat img_1 = imread("/media/b515/新加卷/lxt/Enet-caffe/dataset/xueguanxin/train/1.png",-1);
    std::vector<cv::Mat> aaa;
    aaa.push_back(img_1);
    aaa.push_back(img_1);
    aaa.push_back(img_1);
    cv::Mat img;
    cv::merge(aaa, img);
    Mat result;
    double start_time = clock();
    result=classifier.Predict(img);
    double end_time = clock();
   double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
   std::cout << "classify time=" << seconds << "s" << std::endl;
//    imshow("result",result);
    result.convertTo(result,CV_8U,255);
    imwrite("/media/b515/新加卷/lxt/Enet-caffe/dataset/result_qtq/"+to_string(k)+".png",result);
}

    waitKey(0);
    return 0;
}


//    CFileFind finder;
//    string strFileName;
//    bool bResult = FALSE;
//    bool bWorking = finder.FindFile(_T("/home/nvidia/caffe-enet/test/*.png"));
//    while (bWorking)
//    {
/*        bWorking = finder.FindNextFile();
        if (!finder.IsDirectory())
        {
            string absolutePath = finder.GetFilePath();
            char *p = absolutePath.GetBuffer();
            int iSize;
            char* name;
            iSize = WideCharToMultiByte(CP_ACP, 0, p, -1, NULL, 0, NULL, NULL);
            name = (char*)malloc((iSize + 1));
            WideCharToMultiByte(CP_ACP, 0, p, -1, name, iSize, NULL, NULL);
            std::cout << "---------- Prediction for "
                << name << " ----------" << std::endl;
            start_time2 = clock()*/;

           // CHECK(!img.empty()) << "Unable to decode image " << name;
            //std::vector<Prediction> predictions = classifier.Classify(img);

//        }
