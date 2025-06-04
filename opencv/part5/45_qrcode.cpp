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

    QRCodeDetector qrDetector;
    vector<Point> points;
    String info;
    Mat img;

    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        info = qrDetector.detect(img, points);
        if(!info.empty())
            polylines(img, points, true, Scalar(0,0,255), 2);
            putText(img, info, Point(10,30),FONT_HERSHEY_DUPLEX, 1, Scalar(0,0,0));
            imshow("img", img);
        if (waitKey(100) == 27)
            break;        
    }


    destroyAllWindows();
    return 0;
}