#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    Mat frame;

    while(true)
    {
        cap >> frame;
        imshow("frame", frame);
        if (waitKey(33) == 27)
        {
            break;
        }
    }

    return 0;
}