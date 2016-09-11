/*****************************************************************************
Date:        11 September 2016
Author:      Leo Rodger
File Name:   assignment3.cpp, assignment3.h
Description: This is a program for Assignment 3: comparison of feature 
detection, for 282.772 Industrial System Design and Integration. 
*****************************************************************************/

#include "assignment3.h"

const char *KImage_1_Address = "image_1.jpg";

int main(int argc, char** argv)
{
	//SIFT feature detection
	cv::Mat image_1 = imread(KImage_1_Address, cv::IMREAD_GRAYSCALE);

	//Initiate SIFT												 
	cv::Ptr<cv::Feature2D> f2d = cv::xfeatures2d::SIFT::create();

	//start time
	double sift_time = (double)cv::getTickCount();

	//Create vector and Detect the keypoints
	std::vector<cv::KeyPoint> keypoints_SIFT;
	f2d->detect(image_1, keypoints_SIFT);

	//Draw Key points
	drawKeypoints(image_1, keypoints_SIFT, image_1);

	// Get time taken
	sift_time = ((double)cv::getTickCount() - sift_time) / cv::getTickFrequency();

	//Output time and number of key points to console		
	std::cout << "SURF Feature Detection time taken: " << sift_time << std::endl;
	std::cout << ("keypoint number:") << keypoints_SIFT.size() << std::endl;

	//  Image position of results
	cv::Point text_position_time, text_position_keypoints;
	text_position_time.x = 20;
	text_position_time.y = 25;
	text_position_keypoints.x = 20;
	text_position_keypoints.y = 50;

	putText(image_1,                //InputOutputArray
		   std::to_string(sift_time),  //convert time to string
		   text_position_time,          //Point org
		   CV_FONT_HERSHEY_SIMPLEX, //fontFace
		   1,                       //fontScale
		   cv::Scalar(255, 0, 0),   //color 
		   2,                       //thickness
		   5);                      //lineType

	putText(image_1,                              //InputOutputArray
		   std::to_string(keypoints_SIFT.size()), //convert time to string
		   text_position_keypoints,                        //Point org
		   CV_FONT_HERSHEY_SIMPLEX,               //fontFace
		   1,                                     //fontScale
		   cv::Scalar(255, 0, 0),                 //color 
		   2,                                     //thickness
		   5);                                    //lineType

	cv::namedWindow("SIFT Feature Detection", 1); //create window
	imshow("SIFT Feature Detection", image_1);  //outputArray to window
	imwrite("result_sift.jpg", image_1); //store the result_sift image

	// ORB feature detection
	image_1 = imread(KImage_1_Address, cv::IMREAD_GRAYSCALE); //Reload clean image

	//Initiate ORB													 
  cv::Ptr<cv::Feature2D> Of2d = cv::ORB::create();

	//  start time
	double ORB_t = (double)cv::getTickCount();

	//Create vector and Detect the keypoints
	std::vector<cv::KeyPoint> keypoints_orb;
	Of2d->detect(image_1, keypoints_orb);

	//Draw Key points
	drawKeypoints(image_1, keypoints_orb, image_1);

	// Get time taken
	ORB_t = ((double)cv::getTickCount() - ORB_t) / cv::getTickFrequency();

	//Output time and number of key points to console
	std::cout << "ORB Feature Detection time taken: " << ORB_t << std::endl;
	std::cout << ("keypoint number:") << keypoints_orb.size()<< std::endl;

	// drawing the results
	putText(image_1,             //InputOutputArray
		std::to_string(ORB_t),   //convert time to string
		text_position_time,          //Point org
		CV_FONT_HERSHEY_SIMPLEX, //fontFace
		1,                       //fontScale
		cv::Scalar(255, 0, 0),   //color 
		2,                       //thickness
		5);                      //lineType

	putText(image_1,                          //InputOutputArray
		std::to_string(keypoints_orb.size()), //convert time to string
		text_position_keypoints,                       //Point org
		CV_FONT_HERSHEY_SIMPLEX,              //fontFace
		1,                                    //fontScale
		cv::Scalar(255, 0, 0),                //color 
		2,                                    //thickness
		5);                                   //lineType

	cv::namedWindow("ORB Feature Detection", 1); //create window
	imshow("ORB Feature Detection", image_1);  //outputArray to window
	imwrite("result_orb.jpg", image_1); //store the result_orb image

	cv::waitKey(0); //wait for window to be closed
}