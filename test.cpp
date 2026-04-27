#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){

    string gscale = "@#S%?*+;:,. ";
    Mat img = imread("test.jpg", IMREAD_GRAYSCALE);
    resize(img, img, Size(100, 50));

    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            int brightness = img.at<uchar>(y, x);
            int index = brightness * (gscale.size() - 1) / 255;
            cout << gscale[index];
        }
        cout << "\n";
    }

    //waitKey(0);
    return 0;

}
