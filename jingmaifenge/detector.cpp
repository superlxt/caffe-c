#include"detector.h"


//Ç°Ž«
//std::vector<Mat> Classifier::Classify(const cv::Mat& img) {
//    std::vector<float> output = Predict(img);
//    Predict(img);
//    //std::vector<Prediction> predictions;
//    //return predictions;
//}

//std::vector<Mat> Classifier::Predict(const cv::Mat& img) {
    Mat Classifier::Predict(const cv::Mat& img) {
    Blob<float>* input_layer = net_->input_blobs()[0];
    input_layer->Reshape(1, num_channels_,
        input_geometry_.height, input_geometry_.width);
    net_->Reshape();
    std::vector<cv::Mat> input_channels;
    WrapInputLayer(&input_channels);
    Preprocess(img, &input_channels);
    net_->Forward();
    Blob<float>* output_layer = net_->output_blobs()[0];
    cv::Mat merged_output_image = cv::Mat(output_layer->height(), output_layer->width(), CV_32FC1, const_cast<float *>(output_layer->cpu_data()));
    cv::Mat merged_output_image1 = cv::Mat(output_layer->height(), output_layer->width(), CV_32FC1, const_cast<float *>(output_layer->cpu_data() + 256 * 256));

    Mat  imggg = Mat::zeros(merged_output_image.cols, merged_output_image.rows, CV_32FC1);
    for (int i = 0; i<merged_output_image.cols; i++)
        for (int j = 0; j < merged_output_image.rows; j++)
        {
            if (merged_output_image.at<float>(j, i) > merged_output_image1.at<float>(j, i))
                imggg.at<float>(j, i) = 0;
            else
                imggg.at<float>(j, i) = 1;
        }
    return imggg;
//    cv::imshow("Display window", imggg);
//    cv::waitKey(0);
    //cv::destroyWindow("Display window");
}

void Classifier::WrapInputLayer(std::vector<cv::Mat>* input_channels) {
    Blob<float>* input_layer = net_->input_blobs()[0];
    int width = input_layer->width();
    int height = input_layer->height();
    float* input_data = input_layer->mutable_cpu_data();
    for (int i = 0; i < input_layer->channels(); ++i) {
        cv::Mat channel(height, width, CV_32FC1, input_data);
        input_channels->push_back(channel);
        input_data += width * height;
    }
}

void Classifier::Preprocess(const cv::Mat& img,
    std::vector<cv::Mat>* input_channels) {
    cv::Mat sample;
    if (img.channels() == 3 && num_channels_ == 1)
        cv::cvtColor(img, sample, cv::COLOR_BGR2GRAY);
    else if (img.channels() == 4 && num_channels_ == 1)
        cv::cvtColor(img, sample, cv::COLOR_BGRA2GRAY);
    else if (img.channels() == 4 && num_channels_ == 3)
        cv::cvtColor(img, sample, cv::COLOR_BGRA2BGR);
    else if (img.channels() == 1 && num_channels_ == 3)
        cv::cvtColor(img, sample, cv::COLOR_GRAY2BGR);
    else
     sample = img;

    cv::Mat sample_resized;
    if (sample.size() != input_geometry_)
        cv::resize(sample, sample_resized, input_geometry_);
    else
        sample_resized = sample;

    cv::Mat sample_float;
    if (num_channels_ == 3)
        sample_resized.convertTo(sample_float, CV_32FC3);
    else
        sample_resized.convertTo(sample_float, CV_32FC1);

    cv::Mat sample_normalized;
    cv::subtract(sample_float, 0, sample_normalized);
    cv::split(sample_normalized, *input_channels);

    CHECK(reinterpret_cast<float*>(input_channels->at(0).data)
        == net_->input_blobs()[0]->cpu_data())
        << "Input channels are not wrapping the input layer of the network.";
}
