#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	string img1 = "ZTK_video_2_Moment2.jpg";
	Mat image = imread(img1);
	imshow("test1",image);
	waitKey(0);
	return 0;
}
