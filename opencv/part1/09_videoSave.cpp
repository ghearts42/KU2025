#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hjpubuntu22045/korea_c/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");

    if(!cap.isOpened())
    {
        cerr << "No video" << endl;
        // cerr << "No device" << endl;
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

    VideoWriter outputVideo(folderPath + "inverse_vtest.avi", fourcc, fps, Size(w,h));
    if(!outputVideo.isOpened())
    {
        cerr << "Failed to make file" << endl;
    }

    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    // auto fps = cap.get(CAP_PROP_FPS);
    // cout << "fps : " << cvRound(fps) << endl;

    Mat frame;
    while(true)
    {
        cap >> frame;
        frame = ~frame;
        if(frame.empty())
        {
            break;
        }
        outputVideo << frame;
        imshow("frame", frame);
        if (waitKey(1000 / fps) == 27)
        {
            break;
        }
    }

    cap.release();
    outputVideo.release();
    destroyAllWindows();

    return 0;
}