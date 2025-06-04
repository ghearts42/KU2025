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
    VideoCapture cap(folderPath + "vtest.avi");

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    vector<Rect> people;
    Mat img;
    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        hog.detectMultiScale(img, people);
        for (auto &rect : people)
        {
            rectangle(img, rect, Scalar(0,0,255));
        }
        imshow("img", img);
        if (waitKey(100) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}