#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void sharpen(Mat &src, Mat &dst);

int main(int argc, char *argv[])
{
    std::string imagePath = "./car.jpg";
    Mat src, dst0, dst1;
    src = imread(imagePath, IMREAD_COLOR);
    if (src.empty())
    {
        std::cout << "Can't open image: " << imagePath;
        return -1;
    }

    double t = getTickCount();
    sharpen(src, dst0);
    t = double(getTickCount() - t) / getTickFrequency();
    std::cout << "sharpen time elapsed: " << t << "s" << std::endl;
    Mat kernel = (Mat_<char>(3,3) << 0, -1, 0,
                                     -1, 5, -1,
                                     0, -1, 0);
    t = getTickCount();
    filter2D(src, dst1, src.depth(), kernel);
    t = double(getTickCount() - t) / getTickFrequency();
    std::cout << "filter2D time elapsed: " << t << "s" << std::endl;
    imshow("src", src);
    imshow("Sharpen", dst0);
    imshow("filter2D", dst1);
    waitKey();
    return 0;
}

void sharpen(Mat &src, Mat &dst)
{
    CV_Assert(src.depth() == CV_8U);
    
    const int channels = src.channels();
    dst.create(src.size(), src.type());
    for (int i = 1; i < src.rows - 1; ++i)
    {
        const uchar* previous = src.ptr<uchar>(i - 1);
        const uchar* current  = src.ptr<uchar>(i    );
        const uchar* next     = src.ptr<uchar>(i + 1);
        uchar* output = dst.ptr<uchar>(i);
        
        for (int j = channels; j < channels * (src.cols - 1); ++j)
        {
            *output++ = saturate_cast<uchar>(5*current[j] - current[j-channels]
                                           - current[j+channels] - previous[j] - next[j]);
        }
    }
    dst.row(0).setTo(Scalar(0));
    dst.row(dst.rows-1).setTo(Scalar(0));
    dst.col(0).setTo(Scalar(0));
    dst.col(dst.cols-1).setTo(Scalar(0));
}
