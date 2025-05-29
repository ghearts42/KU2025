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
    Mat img = imread(folderPath + "lenna.bmp");
    vector<Mat> images;
    images.push_back(img.clone());
    for (int i = 0; i < 3; ++i)
        images.emplace_back(Mat());

    Mat M = Mat_<double>({2,3},{1,0,150,0,1,100});
    warpAffine(img, images[1], M, img.size() + Size(150, 100));

    // 전단 변환
    double mx = 0.3, my = 0.2;
    M = Mat_<double>({2, 3}, {1, mx, 0, my, 1, 0});
    warpAffine(img, images[2], M, Size());

    Point2f srcPts[3], dstPts[3];
    srcPts[0] = Point2f(0,0);
    srcPts[1] = Point2f(1,0);
    srcPts[2] = Point2f(1,1);
    dstPts[0] = Point2f(0,0);
    dstPts[1] = Point2f(1,0);
    dstPts[2] = Point2f(2,1);
    dstPts[3] = Point2f(1.5,1.3);

    M = getAffineTransform(srcPts, dstPts);
    warpAffine(img, images[3], M, img.size()+Size(200,200));

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