#include <iostream>

#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{
    std::string imagePath1 = "./japan.jpg";
    std::string imagePath2 = "./beach.jpg";
    cv::Mat src1 = cv::imread(imagePath1);
    cv::Mat src2 = cv::imread(imagePath2);
    
    if (src1.empty() || src2.empty())
    {
        std::cout << "Can't load images!" << std::endl;
        return -1;
    }
    
    cv::Mat dst;
    double alpha = 0.5;
    double beta = 1 - alpha;
    cv::addWeighted(src1, alpha, src2, beta, 0.0, dst);
    
    cv::imshow("dst", dst);
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}