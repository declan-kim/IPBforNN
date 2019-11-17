#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

HOGDescriptor hog;

#define PI 3.141592

int main() {
	string path = "ZTK_video_2_Moment2.jpg";
	Mat image = imread(path);
	Mat gx, gy, edge;	
	Mat mag, angle;

	cvtColor(image, edge, COLOR_BGR2GRAY);
	GaussianBlur(edge, edge, Size(3, 3), 1.5);
	Canny(edge, edge, 100, 300, 3);

	image.convertTo(image, CV_32F, 1 / 255.0);
	Sobel(image, gx, CV_32F, 1, 0, 1);
	Sobel(image, gy, CV_32F, 0, 1, 1);
	
	cartToPolar(gx, gy, mag, angle, 1);

	imshow("test1",image);
	imshow("test2", gx);
	imshow("test3", gy);
	imshow("test4", mag);
	imshow("test5", angle);
	imshow("test6", edge);

	waitKey(0);
	return 0;
}
