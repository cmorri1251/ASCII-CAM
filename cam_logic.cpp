#include <string>
#include "cam_logic.h"
#include <algorithm>

std::string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
std::string output;
cv::Mat processed_frame;
double minVal, maxVal;

std::string getCameraLogicString(const cv::Mat& cam_input){ // camera input switched to constant
    cv::cvtColor(cam_input, processed_frame, cv::COLOR_BGR2GRAY); 
    cv:: minMaxLoc(processed_frame, &minVal, &maxVal);
    if (minVal == maxVal){
        processed_frame+cv::Scalar(128);
    } else{
        processed_frame.convertTo(processed_frame, CV_8U, 255.0 / (maxVal - minVal));
    }


    cv::resize(processed_frame, processed_frame, cv::Size(80, 40));
    output.clear();
    output.reserve(processed_frame.rows * (processed_frame.cols + 1));

    for (int y = 0; y < processed_frame.rows; y++) {
        for (int x = 0; x < processed_frame.cols; x++) {
            int brightness = processed_frame.at<uchar>(y, x);
            brightness == std::max(0, std::min(255,brightness));
            int index = brightness * (gscale.size() - 1) / 255;
            output += gscale[index];
        }
        output += "\n";
    }
//output.flush();
return output;
}