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
    Mat src = imread(folderPath + "coins.png", IMREAD_GRAYSCALE);

    if(src.empty())
    {
        cerr << "image load failed" << endl;
        return -1;
    }

    Mat blurred;
    blur(src, blurred, Size(3,3));

    vector<Vec3f> circles;
    HoughCircles(blurred, circles, HOUGH_GRADIENT, 1,50,150,30);

    Mat dst;
    cvtColor(src,dst,COLOR_GRAY2BGR);

    for (Vec3f c : circles)
    {
        Point center(cvRound(c[0]), cvRound(c[1]));
        int radius = cvRound(c[2]);
        circle(dst, center, radius, Scalar(0,0,255), 2, LINE_AA);
    }

    imshow("src", src);
    imshow("dst", dst);

    destroyAllWindows();
    return 0;
}