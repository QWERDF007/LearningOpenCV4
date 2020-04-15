#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char *argv[])
{
	int w = 400, h = 400, r=20, a = 100, b = 25;
    cv::Mat atomImage(h, w, CV_8UC3, cv::Scalar::all(0));
    cv::Mat rectImage(h, w, CV_8UC3, cv::Scalar::all(0));
	cv::Point center(w / 2, h / 2);
    // 画一个原子，中心用红圆，外围用蓝椭圆
	cv::circle(atomImage, center, r, cv::Scalar(0,0,255), cv::FILLED);
	cv::ellipse(atomImage, center, cv::Size(a, b), 0, 0, 360, cv::Scalar(255, 0, 0));
	cv::ellipse(atomImage, center, cv::Size(a, b), 45, 0, 360, cv::Scalar(255, 0, 0));
	cv::ellipse(atomImage, center, cv::Size(a, b), -45, 0, 360, cv::Scalar(255, 0, 0));
	cv::ellipse(atomImage, center, cv::Size(a, b), 90, 0, 360, cv::Scalar(255, 0, 0));
    // 画一个梯形和矩形
	const int numPts = 4;
	cv::Point pts[numPts] = {cv::Point(100, 100), cv::Point(50, 300), cv::Point(350, 300), cv::Point(300, 100)};
	const cv::Point *ppt[1] = { pts };
	cv::fillPoly(rectImage, ppt, &numPts, 1, cv::Scalar::all(255));
	cv::rectangle(rectImage, cv::Rect(170, 50, 50, 50), cv::Scalar(0, 255, 0), 4);
	cv::imshow("atom", atomImage);
	cv::imshow("rect", rectImage);
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}