#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "neutrophils.png", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img);
    images.emplace_back(Mat());
    images.emplace_back(Mat());
    threshold(img, img, 128, 255, THRESH_BINARY);
    adaptiveThreshold(img, images[2],255,ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,15,5);
    Mat dst1, dst2;


    int i = 1;

    for (auto img : images)
    {
        imshow("img" + to_string(i), img);
        ++i;
    }

    waitKey();
    destroyAllWindows();
    return 0;
}