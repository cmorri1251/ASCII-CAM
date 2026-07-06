#include <string>

string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
string output;
std::string getCameraLogicString(const cv::Mat& cam_input){ // camera input switched to constant
     cv::cvtColor(camframe, camframe, cv::IMREAD_GRAYSCALE); 
            cv::resize(cam_frame, cam_frame, cv::Size(250, 250));
            output.reserve(cam_frame.rows * (cam_frame.cols + 1));

            for (int y = 0; y < cam_frame.rows; y++) {
                for (int x = 0; x < cam_frame.cols; x++) {
                    int brightness = cam_frame.at<uchar>(y, x);
                    int index = brightness * (gscale.size() - 1) / 255;
                    output += gscale[index];
                }
                output += "\n";
            }
        output << std::flush;
    return output;
}