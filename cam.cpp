#include <iostream>
#include <opencv2/opencv.hpp>
#include "cam_logic.cpp"

using namespace std;

int main(int argc, char** argv){

    string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    cv::Mat cam_frame;

    // webcam handle 
    cv::VideoCaptture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error opening video stream" << endl;
        return -1;
    }


    while (true){
        cap >> cam_frame;   
        if (cam_frame.empty()) {
            cerr << "Error capturing frame" << endl;
            break;

        } else {
            string ascii_art = getCameraLogicString();
            cout << ascii_art << endl;
        }
    }
    return 0;

}
