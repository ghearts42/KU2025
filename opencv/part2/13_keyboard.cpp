#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/hjpubuntu22045/korea_c/opencv/part2/color.hpp>
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    namedWindow("img");
    imshow("img", img);
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        keycode = waitKey(10);
        cout << "keycode : " << keycode << endl;
        cout << "i : " << i << endl;
        cout << "fps : " << getTickFrequency() / (getTickCount() - i) << endl;

        if (keycode == 'v' || keycode == 'V')
        {
            img = ~img;
        }
        if (keycode == 'a' || keycode == 'A')
        {
            img = img + 10;
        }
        if (keycode == 'd' || keycode == 'D')
        {
            img = img - 10;
        }
        if (keycode == 65364)
        {
            cout << "key up arrow!" << endl;
        }
        if (keycode == 65362)
        {
            cout << "key down arrow!" << endl;
        }
        imshow("img", img);
        if (keycode == 27)
            break;
        i = getTickCount();
    }
    

    destroyAllWindows();

    return 0;
}