#include <iostream>

#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{
    std::string imagePath = "./car.jpg";
    cv::Mat image = cv::imread(imagePath); // 默认读取RGB
    if (image.empty())
    {
        std::cout << "Could not open image: " << imagePath << std::endl;
        return -1;
    }
    cv::namedWindow("Display window", cv::WINDOW_NORMAL);
    cv::imshow("Display window", image);
    cv::waitKey(); // 等待任意键退出显示
    return 0;
}