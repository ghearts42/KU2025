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
    VideoCapture cap(0);
    // Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    // vector<Mat> images;

    Mat img, edge;

    int low_v, high_v;
    namedWindow("imgl");

    createTrackbar("lowedge", "imgl", &low_v, 255);
    createTrackbar("highedge", "imgl", &high_v, 255);
    
    // images.push_back(edge);
    
    // vector img show 코드
    while (true)
    {
        cap >> img;
        Canny(img, edge, low_v, high_v);
        imshow("imgi",edge);
        waitKey(33);
    }

    destroyAllWindows();
    return 0;
}