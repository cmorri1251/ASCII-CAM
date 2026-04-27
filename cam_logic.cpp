#include <string>

std::string getCameraLogicString(){
     cv::cvtColor(camframe, camframe, cv::IMREAD_GRAYSCALE);
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
        output << std::flush;

    return output;
}