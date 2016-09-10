/*****************************************************************************/ //max 80 charaters long
#include <opencv2\xfeatures2d.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
using namespace cv;

char *img_1_address = "image_1.jpg";

/// Create Windows
int main(int argc, char** argv)
{
	//SIFT section
	Mat img_1;
	img_1 = imread(img_1_address, IMREAD_GRAYSCALE); //IMREAD_GRAYSCALE CV_LOAD_IMAGE_COLOR
													 
	cv::Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();

	//start time
	double t = (double)getTickCount();
	//-- Step 1: Detect the keypoints:
	std::vector<KeyPoint> keypoints_SIFT;
	f2d->detect(img_1, keypoints_SIFT);

	drawKeypoints(img_1, keypoints_SIFT, img_1);

	//get time taken
	t = ((double)getTickCount() - t) / getTickFrequency();

		
	cout << "SURF Feature Detection time taken: " << t << endl;
	cout << ("keypoint number:") << keypoints_SIFT.size() << endl;
	// drawing the results

	namedWindow("SIFT Feature Detection", 1);
	imshow("SIFT Feature Detection", img_1);
///*
	//orb section
	//Mat img_1;
	img_1 = imread(img_1_address, IMREAD_GRAYSCALE); //IMREAD_GRAYSCALE CV_LOAD_IMAGE_COLOR
														 
	cv::Ptr<Feature2D> Of2d = ORB::create();

	//start time
	t = (double)getTickCount();

	//-- Step 1: Detect the keypoints:
	std::vector<KeyPoint> keypoints_orb;
	Of2d->detect(img_1, keypoints_orb);

	drawKeypoints(img_1, keypoints_orb, img_1);
	//get time taken
	t = ((double)getTickCount() - t) / getTickFrequency();
	

	cout << "ORB Feature Detection time taken: " << t << endl;

	cout << ("keypoint number:") << keypoints_orb.size()<< endl;

	// drawing the results
	namedWindow("ORB Feature Detection", 1);
	imshow("ORB Feature Detection", img_1);//*/
	

	waitKey(0);
}