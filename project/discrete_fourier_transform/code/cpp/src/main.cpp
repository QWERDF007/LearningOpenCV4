#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{
    std::string imagePath = "./car.jpg";
    cv::Mat src = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (src.empty())
    {
        std::cout << "Can't load image." << std::endl;
        return -1;
    }
    
    // 拓展图像至最佳大小，0填充
    cv::Mat padded;
    int m = cv::getOptimalDFTSize(src.rows);
    int n = cv::getOptimalDFTSize(src.cols);
    cv::copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, 
        cv::BORDER_CONSTANT, cv::Scalar::all(0));

    // 构建复平面
    cv::Mat planes[] = { cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F) };
    cv::Mat complexImg;
    cv::merge(planes, 2, complexImg);

    // 离散傅里叶变换
    cv::dft(complexImg, complexImg); // 支持 in-place 计算
    
    // 计算幅值，并转换为log(1 + magnitude), magnitude = sqrt(Re(DFT(I))^2 + Im(DFT(I))^2)
    cv::split(complexImg, planes); // planes[0] = Re(DFT(I)), planes[1] = Im(DFT(I))
    cv::magnitude(planes[0], planes[1], planes[0]);
    cv::Mat magnitudeImg = planes[0];
    magnitudeImg += cv::Scalar::all(1);
    cv::log(magnitudeImg, magnitudeImg);

    magnitudeImg = magnitudeImg(cv::Rect(0, 0, magnitudeImg.cols & -2, magnitudeImg.rows & -2));

    // 重新排列图像的象限，以便原点在图像中心
    int cx = magnitudeImg.cols / 2;
    int cy = magnitudeImg.rows / 2;
    cv::Mat q0(magnitudeImg, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(magnitudeImg, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(magnitudeImg, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(magnitudeImg, cv::Rect(cx, cy, cx, cy));

    cv::Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    cv::normalize(magnitudeImg, magnitudeImg, 0, 1, cv::NORM_MINMAX);
    
    cv::imshow("src", src);
    cv::imshow("magnitude", magnitudeImg);
    cv::waitKey();
    return 0;
}