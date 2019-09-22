#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    std::string filename = "readme.xml";
    cv::FileStorage fs;
    fs.open(filename, cv::FileStorage::WRITE);
    if (!fs.isOpened()) {
		std::cout << "Can't write " << filename << " !\n";
		return -1;
    }

	cv::Mat one = cv::Mat::ones(cv::Size(3, 3), CV_32FC1);
	// WRITE
	fs << "filename" << "["; // 前面是节点名，sequence 需要用"[]"来标识，之间的会被保存
	fs << filename << "Awesomeness" << "readme.jpg" <<  "]"; 
	fs << "Mapping";
	fs << "{" << "One" << 1; // maps 用 "{}" 来标识
	fs << "Two" << 2 << "}"; 
	fs << "pi" << 3.1415926;
	fs << "int_pi" << 31415926;
	fs << "ones" << one;
	fs.release();

	// READ 
	// 读取需要节点名，读取后可以用 >> 也可以用类型转换
	fs.open(filename, cv::FileStorage::READ);
	if (!fs.isOpened()) {
		std::cout << "Can't read " << filename << " !\n";
		return -1;
	}
	double pi;
	fs["pi"] >> pi;
	std::cout << "pi: " << pi << std::endl;
	cv::FileNode n = fs["filename"];
	if (n.type() != cv::FileNode::SEQ) {
		std::cout << "no sequence" << std::endl;
		return -1;
	}
	cv::FileNodeIterator it = n.begin(); // 迭代器来迭代序列
	for (; it != n.end(); ++it) {
		std::cout << static_cast<std::string>(*it) << std::endl;
	}
	n = fs["Mapping"];
	std::cout << int(n["Two"]) << int(n["One"]) << std::endl;
	cv::Mat res;
	fs["ones"] >> res;
	std::cout << res << std::endl;
	fs.release();
    return 0;
}