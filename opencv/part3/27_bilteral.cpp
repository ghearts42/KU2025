// ls /dev/vi*
// v4l2-ctl --list-devices
// v4l2-ctl -d /dev/video0 --list-formats-ext
// sudo usermod -aG video $USER

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";
int main()
{
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img.clone());
    Mat noise(img.size(), CV_32SC1);
    randn(noise, 0, 15);
    add(img, noise, img, Mat(), CV_8U);
    images.push_back(img);
    images.emplace_back(Mat());
    images.emplace_back(Mat());
    GaussianBlur(img, images[2], Size(), 5);
    bilateralFilter(img, images[3], -1, 10, 5);

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