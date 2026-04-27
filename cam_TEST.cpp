#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv){

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <video_file>" << endl;
        return -1;
    }

    string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    cv::Mat cam_frame;

    cv::VideoCapture cap(argv[1]);
    if (!cap.isOpened()) {
        cerr << "Error opening video file" << endl;
        return -1;
    }

    while (true) {
        cap >> cam_frame;
        if (cam_frame.empty()) break;

        cv::cvtColor(cam_frame, cam_frame, cv::COLOR_BGR2GRAY);
        cv::resize(cam_frame, cam_frame, cv::Size(100, 50));

        string output;
        output.reserve(cam_frame.rows * (cam_frame.cols + 1)); 

        for (int y = 0; y < cam_frame.rows; y++) {
            for (int x = 0; x < cam_frame.cols; x++) {
                int brightness = cam_frame.at<uchar>(y, x);
                int index = brightness * (gscale.size() - 1) / 255;
                output += gscale[index];
            }
            output += "\n";

        }
        cout << output << flush;

    }


    return 0;

}
