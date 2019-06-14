#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    //  读取图像
    std::string imagePath = "./car.jpg";
    Mat src = imread(imagePath); // 默认读取BGR
    Mat gray = imread(imagePath, IMREAD_GRAYSCALE); // 读取灰度图
    // 判断图像是否为空，也可以用.data属性来判断是否空指针
    if (src.empty() || gray.empty())
    {
        std::cout << "Can't open image" << std::endl;
        return -1;
    }
    
    // 访问像素亮度
    int x = 10, y =10; // 图像原点在左上角
    Scalar grayIntensity = gray.at<uchar>(x,y); 
    // Scalar grayIntensity = gray.at<uchar>(Point(x,y));
    
    Vec3b srcIntensity = src.at<Vec3b>(x, y);
    uchar blue = srcIntensity[0]; // uchar blue = intensity.val[0];
    uchar green = srcIntensity[1];
    uchar red = srcIntensity[2];
    
    // 访问 floating-point 图像
    // vec3f intensity = img.at<vec3f>(y, x);
    // float blue = intensity.val[0];
    // float green = intensity.val[1];
    // float red = intensity.val[2];
    
    // 修改图像
    gray.at<uchar>(x,y) = 255; // 修改像素值
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV); // 转换颜色空间 RGB -> HSV
    Mat f32Image;
    src.convertTo(f32Image, CV_32F); // 转换格式 CV_8UC1 -> CV_32FC1
    
    // ROI
    Mat roi = src(Rect(10, 10, 20, 20));
    
    // 复制数据
    Mat srcCopy = src.clone(); // src.copyTo(srcCopy);
    
    // 将图像写入文件
    imwrite("gray.jpg", gray);
    
    // 可视化图像
    namedWindow("src", WINDOW_AUTOSIZE); // 创建窗口并指定窗口标志
    namedWindow("hsv", WINDOW_NORMAL);
    imshow("src", src);
    imshow("gray", gray);
    imshow("hsv", hsv);
    char key = waitKey(0); // 返回按键的ascii值
    destroyAllWindows(); // 简单程序可不用，程序退出时会自动销毁
    return 0;
}
