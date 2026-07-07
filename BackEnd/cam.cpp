#include <iostream>
#include <opencv2/opencv.hpp>
#include "cam_logic.h"
#include <string>

using namespace std;

int main(int argc, char** argv){
    // webcam initializations
    cv::Mat cam_frame;
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "Error opening camera" << endl;
        return -1;
    }

    while (true){
        cap >> cam_frame;   
        if (cam_frame.empty()) {
            cerr << "Error capturing frame" << endl;
            cap.release();
            break;

        } else {
            string ascii_art = getCameraLogicString(cam_frame); 
            cout << "\033[H\033[2J" << ascii_art; // change to frame end spacer instead of the 033 code 
        }
    }
    cv::destroyAllWindows(); 
    cap.release();
    return 0;
}