#include "opencv2/aruco.hpp"
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
    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);
    VideoCapture cap(0);

    vector<int> markerIds;
    vector<Vec3d> rvecs, tvecs;
    vector<vector<Point2f>> markerConers;
    Mat cameraMatrix = (Mat_<double>(3,3) << 1000, 0, 640, 0, 1000, 360, 0,0,1);
    Mat distCoeffs = (Mat_<double>(5,1) << 0, 0, 0, 0, 0);
    
    Mat img;

    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        aruco::detectMarkers(img, dictionary, markerConers, markerIds);
        aruco::drawDetectedMarkers(img, markerConers, markerIds);
        aruco::estimatePoseSingleMarkers(markerConers, 0.05, cameraMatrix, distCoeffs, rvecs, tvecs);

        
        for (int i = 0; i < markerIds.size(); ++i)
        {
            cout << rvecs[0] << rvecs[1] << rvecs[2] << endl;
            cout << tvecs[0] << tvecs[1] << tvecs[2] << endl;
            cv::drawFrameAxes(img, cameraMatrix, distCoeffs, rvecs, tvecs, 0.1);
        }

        imshow("img", img);
        if (waitKey(100) == 27)
            break;        
    }


    destroyAllWindows();
    return 0;
}