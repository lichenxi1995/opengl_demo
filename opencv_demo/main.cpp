/*
 * main.cpp
 *
 *  Created on: 2017��8��10��
 *      Author: lcx19
 */
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main(){
	namedWindow("[demo]",WINDOW_AUTOSIZE);

	VideoCapture vc(0);

	Mat frame,edge,edgex,edgey;

	bool stop = false;

	while(!stop){
		vc>>frame;

		GaussianBlur(frame,edge,Size(3,3),2,2);

		Sobel(edge,edgex,CV_16S,1,0,-1);
		Sobel(edge,edgey,CV_16S,0,1,-1);
		convertScaleAbs(edgex,edgex);      //��CV_16SתΪCV_8U
		convertScaleAbs(edgey,edgey);
		addWeighted(edgex, 0.5, edgey, 0.5, 0,edge);     //����ͼ���

		imshow("[demo]",edge);

		if(((char)waitKey(1))=='q'){
			stop = true;
		}
	}
	return 0;
}



