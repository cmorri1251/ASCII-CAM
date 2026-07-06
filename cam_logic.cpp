#include <string>
#include "cam_logic.h"

std::string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
std::string output;
cv::Mat processed_frame;

std::string getCameraLogicString(const cv::Mat& cam_input){ // camera input switched to constant
    cv::cvtColor(cam_input, processed_frame, cv::COLOR_BGR2GRAY); 
    cv::resize(processed_frame, processed_frame, cv::Size(80, 40));
    output.clear();
    output.reserve(processed_frame.rows * (processed_frame.cols + 1));

    for (int y = 0; y < processed_frame.rows; y++) {
        for (int x = 0; x < processed_frame.cols; x++) {
            int brightness = processed_frame.at<uchar>(y, x);
            int index = brightness * (gscale.size() - 1) / 255;
            output += gscale[index];
            //std::cout << output;
        }
        output += "\n";
    }
//output.flush();
return output;
}