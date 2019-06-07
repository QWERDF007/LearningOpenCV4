#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    std::string imagePath = "./car.jpg";
    cv::Mat image;
    image = cv::imread( imagePath, cv::IMREAD_COLOR );
    if(!image.data ) // image empty
    {
        std::cout << "Could not load image!" << std::endl;
        return -1;
    }
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY );
    cv::imwrite("result.jpg", grayImage);
    return 0;
}