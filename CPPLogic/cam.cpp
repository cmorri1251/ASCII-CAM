#include <iostream>
#include <opencv2/opencv.hpp>
#include "cam_logic.h"
#include <string>
#include "/home/bub/crow/scripts/crow_all.h"

using namespace std;

void camera_threads(){
    // webcam initializations
    cv::Mat cam_frame;
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
            cerr << "Error opening camera" << endl;
            return;
        }

        while (true){
            cap >> cam_frame;   
            if (cam_frame.empty()) {
                cerr << "Error capturing frame" << endl;
                cap.release();
                break;

            } else {
                string ascii_art = getCameraLogicString(cam_frame); 
                cout << "\033[H\033[2J" << ascii_art; // change output (033 code esp) 
            }
        }
        cv::destroyAllWindows(); 
        cap.release();
}


int main(int argc, char** argv){
    //crow::mustache::set_base("../FrontandBack/templates");
    crow::SimpleApp app;
    
    CROW_ROUTE(app, "/")([](){
        ifstream file("../FrontandBack/templates/front.html");
        
        // Error protection if your terminal is executing from the wrong directory
        if (!file.is_open()) {
            return crow::response(404, "Error: Could not locate your front.html file via relative paths.");
        }
        
        stringstream buffer;
        buffer << file.rdbuf();
        return crow::response(buffer.str());
    });

    app.port(5000).multithreaded().run();
    return 0;
}