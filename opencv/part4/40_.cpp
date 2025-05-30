//카메라 켜기 frame 확보
//양방향 필터 처리
//inrange -> 색종이 인식하게
//morph 함수 -> 이진화 Mat 정리
//labeling
//화면에 rectagle 표시
//putText, ft2로 "color-paper"
//사각형, 폰트는 색종이를 따라댜녀야 함.

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/freetype.hpp> // ft2 텍스트 사용
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0); // 카메라 열기
    if (!cap.isOpened()) {
        cout << "카메라를 열 수 없습니다." << endl;
        return -1;
    }

    Ptr<freetype::FreeType2> ft2 = freetype::createFreeType2();
    ft2->loadFontData("/home/hjpubuntu22045/korea_c/opencv/data/NanumPenScript-Regular.ttf", 0);

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        // 1. Bilateral Filter로 노이즈 제거 + 경계 보존
        Mat filtered;
        bilateralFilter(frame, filtered, 9, 75, 75);

        // 2. HSV 변환
        Mat hsv;
        cvtColor(filtered, hsv, COLOR_BGR2HSV);

        // // 3. 색종이 인식 (예: 빨간색 영역)
        // Scalar lower_red1(191, 175, 193), upper_red1(211, 195, 255);
        // Scalar lower_red2(189, 174, 195), upper_red2(209, 194, 255);
        // Mat mask1, mask2, mask;
        // inRange(hsv, lower_red1, upper_red1, mask1);
        // inRange(hsv, lower_red2, upper_red2, mask2);
        // bitwise_or(mask1, mask2, mask); // 두 마스크 결합

        // 3. 색종이 인식 (RGB 231 197 204 대략 HSV로 변환한 값 기반)
        Scalar lower_paper(150, 20, 180); // Hue-6, Sat-15, Val-50
        Scalar upper_paper(177, 60, 255); // Hue+6, Sat+25, Val+24

        Mat mask;
        inRange(hsv, lower_paper, upper_paper, mask);

        // 4. Morphology - 잡음 제거 및 외곽 정리
        Mat morph;
        Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(mask, morph, MORPH_OPEN, kernel);
        morphologyEx(morph, morph, MORPH_CLOSE, kernel);

        // 5. Contours 검출 (라벨링 대체 가능)
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(morph, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for (size_t i = 0; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area < 1000) continue; // 너무 작은 건 무시

            Rect bound = boundingRect(contours[i]);
            rectangle(frame, bound, Scalar(0, 255, 0), 2);

            // 색종이 중심 좌표 계산
            Point center(bound.x + bound.width / 2, bound.y + bound.height / 2);

            // 텍스트 표시 ("color-paper") - 사각형을 따라다님
            ft2->putText(frame, "color-paper", Point(bound.x, bound.y - 10), 30,
                         Scalar(255, 255, 255), -1, LINE_AA, true);
        }

        imshow("Detected Color Paper", frame);

        if (waitKey(10) == 27) break; // ESC 누르면 종료
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
