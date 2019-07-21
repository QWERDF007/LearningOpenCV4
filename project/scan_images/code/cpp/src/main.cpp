#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

Mat& ScanImageAndReduce(Mat& I, const uchar* const table);
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table);
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table);

int main(int argc, char *argv[])
{
    std::string imagePath = "./scene.jpg";
    Mat image = imread(imagePath, IMREAD_COLOR);
    if (image.empty())
    {
        std::cout << "Can not load image: " << imagePath << std::endl;
        return -1;
    }
    namedWindow("src", WINDOW_NORMAL);
    namedWindow("dst", WINDOW_NORMAL);
    Mat dstImage = image.clone();
    // 创建查找表
    int divideValue = 10;
    uchar table[256];
    for (int i = 0; i < 256; ++i)
        table[i] = (uchar)(i / divideValue * divideValue);
    // LUT 参数2
    Mat lookUpTable(1, 256, CV_8U);
    uchar *p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = table[i];
    
    std::cout << "Image height: " << image.rows << " width: " << image.cols << std::endl;
    clock_t start, end;

    start = clock();
    ScanImageAndReduce(dstImage, table);
    end = clock();
    std::cout << "ScanImageAndReduce time: " << end - start << "ms\n";
    start = clock();
    ScanImageAndReduceIterator(dstImage, table);
    end = clock();
    std::cout << "ScanImageAndReduceIterator time: " << end - start << "ms\n";
    start = clock();
    ScanImageAndReduceRandomAccess(dstImage, table);
    end = clock();
    std::cout << "ScanImageAndReduceRandomAccess time: " << end - start << "ms\n";
    start = clock();
    LUT(image.clone(), lookUpTable, dstImage);
    end = clock();
    std::cout << "LUT time: " << end - start << "ms\n";

    imshow("src", image);
    imshow("dst", dstImage);
    waitKey(); 
    return 0;
}

Mat& ScanImageAndReduce(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U); // 断言是否8bit uchar
    const int channels = I.channels();
    int rows = I.rows;
    int cols = I.cols * channels;

    if (I.isContinuous()) 
    {
        cols *= rows; // 连续存储则将列数设为row*col，行数row设为1
        rows = 1;
    }

    // 遍历图像，修改
    uchar *p;
    for (int i = 0; i < rows; ++i)
    {
        p = I.ptr<uchar>(i);
        for (int j = 0; j < cols; ++j)
            p[j] = table[p[j]]; // lookup table
    }
    return I;
}

Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    
    switch (channels)
    {
    case 1:
    {
        MatIterator_<uchar> it, end;
        for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
            *it = table[*it];
        break;
    }
    case 3:
    {
        MatIterator_<Vec3b> it, end;
        for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
        {
            (*it)[0] = table[(*it)[0]];
            (*it)[1] = table[(*it)[1]];
            (*it)[2] = table[(*it)[2]];
        }
    }
        
    default:
        break;
    }

    return I;
}

Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U);

    const int channels = I.channels();
    switch (channels)
    {
    case 1:
    {
        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j)
                I.at<uchar>(i, j) = table[I.at<uchar>(i, j)];
        break;
    }
    case 3:
    {
        Mat_<Vec3b> _I = I;
        for (int i = 0; i < I.rows; ++i)
        {
            for (int j = 0; j < I.cols; ++j)
            {
                _I(i, j)[0] = table[_I(i, j)[0]];
                _I(i, j)[1] = table[_I(i, j)[1]];
                _I(i, j)[2] = table[_I(i, j)[2]];
            }
        }
        I = _I;
        break;
    }
    default:
        break;
    }
}
