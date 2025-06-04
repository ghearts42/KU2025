#include <iostream>
#include <opencv2/ml.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;
using namespace cv::ml;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    vector <float> x_data = {1.0, 2.0, 3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    vector <float> y_data;

    //ADD Noise
    RNG rng(12345);
    for (auto &x : x_data)
    {
        float noise = rng.gaussian(0.5);
        y_data.push_back(2.f * x + 1.f);
    }
    
    Mat samples(x_data.size(), 1, CV_32F);
    Mat response(y_data.size(), 1, CV_32F);

    for (size_t i = 0; i < x_data.size(); ++i)
    {
        samples.at<float>(i, 0) = x_data[i];
        response.at<float>(i, 0) = y_data[i];
    }
    Ptr<TrainData> tData = TrainData::create(samples, ROW_SAMPLE, response);

    Mat X = Mat(samples.rows, 2, CV_32F);
    for (int i = 0; i < samples.rows; ++i)
    {
        X.at<float>(i, 0) = samples.at<float>(i,0);
        X.at<float>(i, 1) = 1.0f;
    }
    
    Mat XtX = X.t() * X;
    Mat XtX_inv;
    invert(XtX, XtX_inv, DECOMP_SVD);
    Mat weights = XtX_inv * X.t() * response;
    
    cout << "기울기" << weights.at<float>(0,0) << endl;
    cout << "절편" << weights.at<float>(1,0) << endl;

    float test_x = 15.0f;
    float predicted_y = weights.at<float>(0.0) * test_x + weights.at<float>(1.0);
    cout << "결과" << predicted_y << endl;

    return 0;
}