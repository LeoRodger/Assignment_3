/***************************************************************************** max 80 charaters long
Date:        11 September 2016
Author:      Leo Rodger
File Name:   assignment3.cpp, assignment3.h
Description: This is a program for Assingment 3: comparison of feacture 
detection, for 282.772 Industrial System Design and Integration. 
*****************************************************************************/

#include "assignment3.h"

using namespace std;
using namespace cv;

const char *img_1_address = "image_1.jpg";

/// Create Windows
int main(int argc, char** argv)
{
	//SIFT feature detection
	Mat img_1 = imread(img_1_address, IMREAD_GRAYSCALE);
													 
	cv::Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();

	//start time
	double sift_t = (double)getTickCount();
	//-- Step 1: Detect the keypoints:
	std::vector<KeyPoint> keypoints_SIFT;
	f2d->detect(img_1, keypoints_SIFT);

	drawKeypoints(img_1, keypoints_SIFT, img_1);

	// Get time taken
	sift_t = ((double)getTickCount() - sift_t) / getTickFrequency();
			
	cout << "SURF Feature Detection time taken: " << sift_t << endl;
	cout << ("keypoint number:") << keypoints_SIFT.size() << endl;

	//  Image position of results
	Point text_position1, text_position2;
	text_position1.x = 20;
	text_position1.y = 25;
	text_position2.x = 20;
	text_position2.y = 50;

	putText(img_1,                //InputOutputArray
       to_string(sift_t),       //convert time to string
		   text_position1,          //Point org
		   CV_FONT_HERSHEY_SIMPLEX, //fontFace
		   1,                       //fontScale
		   Scalar(255, 0, 0),       //color 
		   2,                       //thickness
		   5);                      //lineType

	putText(img_1,                           //InputOutputArray
		   to_string(keypoints_SIFT.size()), //convert time to string
		   text_position2,                   //Point org
		   CV_FONT_HERSHEY_SIMPLEX,          //fontFace
		   1,                                //fontScale
		   Scalar(255, 0, 0),                //color 
		   2,                                //thickness
		   5);                               //lineType

	namedWindow("SIFT Feature Detection", 1); //create window
	imshow("SIFT Feature Detection", img_1);  //outputArray to window

	// ORB feature detection
  img_1 = imread(img_1_address, IMREAD_GRAYSCALE); //Reload clean image
														 
  cv::Ptr<Feature2D> Of2d = ORB::create();

	//  start time
	double ORB_t = (double)getTickCount();

	// Detect the keypoints:
	std::vector<KeyPoint> keypoints_orb;
	Of2d->detect(img_1, keypoints_orb);

	drawKeypoints(img_1, keypoints_orb, img_1);

	// Get time taken
	ORB_t = ((double)getTickCount() - ORB_t) / getTickFrequency();
	
	cout << "ORB Feature Detection time taken: " << ORB_t << endl;
	cout << ("keypoint number:") << keypoints_orb.size()<< endl;

	// drawing the results
	putText(img_1, to_string(ORB_t), text_position1, CV_FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2, 5);
	putText(img_1, to_string(keypoints_orb.size()), text_position2, CV_FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2, 5);

	
	namedWindow("ORB Feature Detection", 1);
	imshow("ORB Feature Detection", img_1);
	

	waitKey(0);
}