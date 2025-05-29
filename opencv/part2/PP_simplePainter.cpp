#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/hjpubuntu22045/korea_c/opencv/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

void on_mouse(int event, int x, int y, int flags, void *data);

int main()
{
    Mat img(400, 600, CV_8UC3, Scalar(255,255,255));
    namedWindow("img");

    setMouseCallback("img", on_mouse, (void *)&img);
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        // cout << "keycode: " << keycode << endl;
        // cout << "i: " << i << endl;
        // cout << "fps: " << getTickFrequency() / (getTickCount() - i) << endl;
        i = getTickCount();
        imshow("img", img);
        keycode = waitKey(33);
        if (keycode == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void *data)
{
    static Point ptOld;
    static bool pushed;
    static bool erased;
    int pos1, pos2, pos3;
    int b = 0;
    int g = 0;
    int r = 0;
    cv::Scalar paintColor = cv::Scalar(b,g,r);
    Mat *img = (Mat *)data;
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        ptOld = Point(x, y);
        pushed = true;
        break;
    case EVENT_LBUTTONUP:
        pushed = false;
        break;
    case EVENT_RBUTTONDOWN:
        ptOld = Point(x, y);
        erased = true;
        break;
    case EVENT_RBUTTONUP:
        erased = false;
        break;
    case EVENT_MOUSEMOVE:
        if (pushed)
        {
            line(*img, ptOld, Point(x, y), black, 2);
            ptOld = Point(x, y);
        }
        if (erased)
        {
            line(*img, ptOld, Point(x, y), white, 4);
            ptOld = Point(x, y);
        }
        break;
    default:
        // cout << "마우스 이벤트!!" << endl;
        break;
    }
}