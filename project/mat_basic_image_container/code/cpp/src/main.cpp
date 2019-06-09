#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	
	Mat A; // 仅创建头指针
	A = imread("./car.jpg", IMREAD_COLOR); // 读取图像
	Mat B(A); // 拷贝构造
	Mat C = A; // ABC指向同一份数据，头指针不同，任意一个上的操作将修改全部
	// 构造函数 Mat(nrows, ncols, type[, fillValue])
	Mat M0(7, 7, CV_32FC2, Scalar(1, 3)); // 创建7x7复数矩阵
	// 创建一个 100x100 的单通道 8bit 矩阵，并以 255 填充
	Mat M1(100, 100, CV_8UC1, Scalar(255)); 
	Mat M2(Size(100, 100), CV_8UC3);
	// 拷贝一份数据，修改DE不会修改A
	Mat D = A.clone();  // A.copyTo(D);
	
	// ROI
	Mat E(A, Rect(0, 0, 10, 10));
	Mat F = A(Range::all(), Range(1, 3));

	// Output
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255)); // 随机填充0-255至R
	cout << "R (default format):\n" << R << endl << endl;
	cout << "R (python):\n" << format(R, Formatter::FMT_PYTHON) << endl << endl;
	cout << "R (numpy):\n" << format(R, Formatter::FMT_NUMPY) << endl << endl;
	cout << "R (csv):\n" << format(R, Formatter::FMT_CSV) << endl << endl;
	cout << "R (c):\n" << format(R, Formatter::FMT_C) << endl << endl;
    return 0;
}