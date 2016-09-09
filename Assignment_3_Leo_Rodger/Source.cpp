#include <opencv2\xfeatures2d.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

//using namespace std;
using namespace cv;

char *img_1_address = "image_1.jpg";
char *img_2_address = "image_2.jpg";

/// Create Windows
int main(int argc, char** argv)
{
	Mat img_1, img_2;
	img_1 = imread(img_1_address, IMREAD_GRAYSCALE); //IMREAD_GRAYSCALE CV_LOAD_IMAGE_COLOR
	img_2 = imread(img_2_address, IMREAD_GRAYSCALE); //IMREAD_GRAYSCALE CV_LOAD_IMAGE_COLOR
													 
	cv::Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();
	//cv::Ptr<Feature2D> f2d = xfeatures2d::SURF::create();
	//cv::Ptr<Feature2D> f2d = ORB::create();
	// you get the picture, i hope..

	//-- Step 1: Detect the keypoints:
	std::vector<KeyPoint> keypoints_1, keypoints_2;
	f2d->detect(img_1, keypoints_1);
	f2d->detect(img_2, keypoints_2);

	//-- Step 2: Calculate descriptors (feature vectors)    
	Mat descriptors_1, descriptors_2;
	f2d->compute(img_1, keypoints_1, descriptors_1);
	f2d->compute(img_2, keypoints_2, descriptors_2);

	//-- Step 3: Matching descriptor vectors using BFMatcher :
	BFMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match(descriptors_1, descriptors_2, matches);

	// drawing the results
	namedWindow("matches", 1);
	Mat img_matches;
	drawMatches(img_1, keypoints_1, img_2, keypoints_2, matches, img_matches);
	imshow("matches", img_matches);

	waitKey(0);
}