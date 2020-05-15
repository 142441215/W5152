#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int equalizeMain()
{
	cv::Mat srcMat = imread("C://project//etest.jpg", 0);
	cv::Mat dstMat;

	if (srcMat.empty()) {
		cout << "fail to read pic!" << endl;
		return -1;
	}

	if (srcMat.type() == CV_8UC1) {
		equalizeHist(srcMat, dstMat);
	}
	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
		Mat out[3];
		split(srcMat, channel);
		for (int i = 0; i < 3; i++) {
			equalizeHist(channel[i], out[i]);
		}

		merge(out, 3, dstMat);

	}


	float srcHist[256];
	float dstHist[256];
	cv::Mat srcHistMat;
	cv::Mat dstHistMat;
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);

	destroyAllWindows();

	return 0;

}
int main()
{
	double start = static_cast<double>(cvGetTickCount());
	equalizeMain();
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	cout << "processing time:" << time / 1000 << "ms" << endl;
	system("pause");
	return 0;
}
