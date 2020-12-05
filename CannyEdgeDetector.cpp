#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <iostream>
#include "CannyEdgeDetector.h"
using namespace cv;
#define max_lowThreshold 100
#define ratio 3
#define kernel_size 3
const char* window_name = "Edge Map";
int lowThreshold = 0;
Mat src, src_gray;
Mat dst, detected_edges;
static void CannyThreshold(int, void*)
{
    blur(src_gray, detected_edges, cv::Size(3, 3));
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    dst = cv::Scalar::all(0);
    src.copyTo(dst, detected_edges);

}
int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | fruits.jpg | input image}");
    src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR); // Load an image
    if (src.empty())
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }
    dst.create(src.size(), src.type());
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}
