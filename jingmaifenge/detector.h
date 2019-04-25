#ifndef CAFFEDETECTOR_H
#define CAFFEDETECTOR_H
#include <caffe/caffe.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iomanip>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace caffe;  // NOLINT(build/namespaces)
using namespace cv;
using namespace std;
typedef std::pair<string, float> Prediction;

class Classifier {
public:
    Classifier(const string& model_file,
        const string& weights_file);
    //std::vector<Prediction> Classify(const cv::Mat& img);
//    std::vector<Mat> Predict(const cv::Mat& img);
    Mat Predict(const cv::Mat& img);


private:
    void WrapInputLayer(std::vector<cv::Mat>* input_channels);
    void Preprocess(const cv::Mat& img,
        std::vector<cv::Mat>* input_channels);

private:
    std::shared_ptr<Net<float> > net_;
    cv::Size input_geometry_;
    int num_channels_;
};
#endif // CAFFEDETECTOR_H
