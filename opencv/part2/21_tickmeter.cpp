#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/hjpubuntu22045/korea_c/opencv/part2/color.hpp>
#include <opencv2/freetype.hpp>
#include <chrono>
#include <thread>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    namedWindow("img");
    auto i = getTickCount();
    int keycode;
    TickMeter tm;
    TickMeter tm2;
    int fps = 100;
    while (true)
    {
        tm.start();
        tm2.start();
        keycode = waitKey(3);
        cout << "keycode : " << keycode << endl;
        cout << "i : " << i << endl;
        tm.stop();
        if (tm.getFPS() > fps)
        {
            auto sleep_duration = static_cast<int>(1000 * (tm.getFPS()- fps) / tm.getFPS()/ fps);
            this_thread::sleep_for(chrono::milliseconds(sleep_duration));
        }
        tm2.stop();

        cout << "fps1 : " << tm.getFPS() << endl;
        cout << "fps2 : " << tm2.getFPS() << endl;

        imshow("img", img);
        if (keycode == 27)
            break;
        i = getTickCount();
    }
    

    destroyAllWindows();

    return 0;
}