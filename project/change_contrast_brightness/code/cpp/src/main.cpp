#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char* argv[])
{
    double alpha = 1.5;
    int beta = 25;
    if (argc >= 3)
    {
        alpha = atof(argv[1]);
        beta = atoi(argv[2]);
        std::cout << alpha << " " << beta;
    }
    std::string imagePath = "./car.jpg";
    cv::Mat src = cv::imread(imagePath);
    if (src.empty())
    {
        std::cout << "Can't load image!" << std::endl;
        return -1;
    }
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());
    int channels = src.channels();    
     //for (int row=0; row<src.rows; ++row)
     //{
     //    for (int col=0; col<src.cols; ++col)
     //    {
     //        for (int c=0; c<channels; ++c)
     //        {
     //            dst.at<cv::Vec3b>(row, col)[c] = 
     //                cv::saturate_cast<uchar>(alpha * src.at<cv::Vec3b>(row, col)[c] + beta);
     //        }
     //    }
     //}
    src.convertTo(dst, -1, alpha, beta);
    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
    return 0;
}