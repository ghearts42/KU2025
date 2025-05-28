#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/hjpubuntu22045/korea_c/opencv/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, Scalar(255,255,255));

    int a = 0;
    int b = 0;
    int c = 0;
    

    while (true)
    {        
        img.setTo(white);
        putText(img, "This is Test", Point(20+a, 50), FONT_HERSHEY_SIMPLEX, 1, red);
        putText(img, "This is Test", Point(20+c, 50+b), FONT_HERSHEY_SIMPLEX, 1, blue);
        putText(img, "This is Test", Point(20+a, 50+c), FONT_HERSHEY_SIMPLEX, 1, green);
        line(img, Point(50,50), Point(200,100), Scalar(0,0,255), 3, LINE_AA);
        line(img, Point(70,70), Point(220,120), Scalar(0,0,255), 3, LINE_4);
        line(img, Point(90,90), Point(240,140), Scalar(0,0,255), 3, LINE_8);
    
        arrowedLine(img, Point(110, 110+a), Point(260,100), blue ,3,LINE_8);
        arrowedLine(img, Point(130, 130-c), Point(260,100), red ,3,LINE_8,0,0.05);
    
        drawMarker(img, Point(50+a, 200+b), Scalar(255,0,0), MARKER_CROSS);
        drawMarker(img, Point(50, 200+c), Scalar(255,0,0), MARKER_DIAMOND);
    
        rectangle(img, Rect(50,250,50+a,50+c), cyan, 2, LINE_AA);
        rectangle(img, Rect(50,300,50,50), green, -1, LINE_AA);
    
        circle(img, Point(150,400), 20+a, purple, 3, LINE_AA);
        circle(img, Point(250,300), 30+c, black, 1, LINE_AA);
    
        ellipse(img, Point(234, 30), Size(53,21), 56, 0, 48+a, purple, FILLED, LINE_AA);
    
    
    
        imshow("img", img);
        if (waitKey(33) == 27)
            break;
        a += 1;
        b += 1;
        c += 2;
    }
    

    destroyAllWindows();

    return 0;
}