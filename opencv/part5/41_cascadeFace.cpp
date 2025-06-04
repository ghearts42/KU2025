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
    Mat img = imread(folderPath + "kids.png", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img);
    images.emplace_back(Mat());

    CascadeClassifier classifier(folderPath + "haarcascade_frontalface_default.xml");

    vector<Rect> faces;
    classifier.detectMultiScale(img, faces);
    // classifier.detect(img, faces);

    for(auto &rect : faces)
    {
        rectangle(img, rect, Scalar(0,0,255), 2);
    }

    // vector img show 코드
    imshow("img", img);

    waitKey();
    destroyAllWindows();
    return 0;
}