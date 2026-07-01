#include <iostream>
#include <opencv2/opencv.hpp>
#include "cam_logic.cpp"

using namespace std;

int main(int argc, char** argv){
    // webcam initializations
    cv::Mat cam_frame;
    cv::VideoCaptture cap(0);

    if (!cap.isOpened()) {
        cerr << "Error opening camera" << endl;
        return -1;
    }

    while (true){
        cap >> cam_frame;   
        if (cam_frame.empty()) {
            cerr << "Error capturing frame" << endl;
            cap.release()
            break;

        } else {
            string ascii_art = getCameraLogicString(cam_frame); // cam_frame output isn't string!!!!!!!!!!
            cout << ascii_art << endl;
        }
    }

    destroyAllWindows() 
    cap.release() #resource cleaning
    return 0;

}
