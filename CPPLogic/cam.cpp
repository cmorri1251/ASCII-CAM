#include <iostream>
#include <opencv2/opencv.hpp>
#include "cam_logic.h"
#include <mutex>
#include <unordered_set>
#include <string>
#include "/home/bub/crow/scripts/crow_all.h"

using namespace std;

static std::mutex conn_mutex;
static std::unordered_set<crow::websocket::connection*> clients;

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
            }
            string ascii_art = getCameraLogicString(cam_frame); 
            //cout << "\033[H\033[2J" << ascii_art; // change output (033 code esp) 
            
            std::lock_guard<std::mutex> lock(conn_mutex);
            for (auto* client : clients){
                client->send_text(ascii_art);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(33));  // 30fps limited
        }
        cv::destroyAllWindows(); 
        cap.release();
}


int main(int argc, char** argv){
    //crow::mustache::set_base("../FrontandBack/templates");
    crow::SimpleApp app;
    
    CROW_ROUTE(app, "/")([](){
        ifstream file("../FrontandBack/templates/front.html");
        if (!file.is_open()) {
            return crow::response(404, "Could not locate  front.html");
        }
        
        stringstream buffer;
        buffer << file.rdbuf();
        return crow::response(buffer.str());
    });

    CROW_WEBSOCKET_ROUTE(app, "/ws")
        .onopen([](crow::websocket::connection& conn){
            std::lock_guard<std::mutex> lock(conn_mutex);
            clients.insert(&conn);
        })
        .onclose([](crow::websocket::connection& conn, const std::string& reason, uint16_t code){
            std::lock_guard<std::mutex> lock(conn_mutex);
            clients.erase(&conn);
})
        .onmessage([](crow::websocket::connection& conn, const std::string& data, bool is_binary){
        });


    std::thread cam(camera_threads);
    cam.detach();
    app.port(5000).multithreaded().run();

    return 0;
}