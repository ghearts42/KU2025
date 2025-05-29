#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    namedWindow("img");
    Mat img2 = img + 100;
    Mat img3 = 2.f * img;
    Mat img4 = img + (img -128) * 1.f;

    double min, max;
    minMaxLoc(img, &min, &max);

    Mat img5 = (img - min) *255 / (max - min);

    Mat img6;
    equalizeHist(img, img6);

    imshow("img", img);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
    imshow("img6", img6);
            
    waitKey();
    destroyAllWindows();

    return 0;
}