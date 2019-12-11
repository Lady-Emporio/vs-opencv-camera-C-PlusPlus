// opencv1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
/*
NOT know where Vfw32.Lib and comctl32.lib and what is it. But with in not working.

Vfw32.Lib
comctl32.lib
IlmImf.lib
libjasper.lib
libjpeg.lib
libpng.lib
libtiff.lib
opencv_calib3d2413.lib
opencv_contrib2413.lib
opencv_core2413.lib
opencv_features2d2413.lib
opencv_flann2413.lib
opencv_gpu2413.lib
opencv_highgui2413.lib
opencv_imgproc2413.lib
opencv_legacy2413.lib
opencv_ml2413.lib
opencv_nonfree2413.lib
opencv_objdetect2413.lib
opencv_ocl2413.lib
opencv_photo2413.lib
opencv_stitching2413.lib
opencv_superres2413.lib
opencv_ts2413.lib
opencv_video2413.lib
opencv_videostab2413.lib
zlib.lib
*/
using namespace cv;

void www() {
	VideoCapture cap;
	if (!cap.open(0)) {
		MessageBox(NULL, L"Not open camera. Maybe not found.", L"Camera error. Not open.", MB_OK);
		return;
	}
	int counter = 0;
	for (;;)
	{
		Mat frame;
		//cap >> frame;
		if (!cap.isOpened())  // if not success, exit program
		{
			MessageBox(NULL, L"Camera is closed. Camera not is opened.", L"Camera error.", MB_OK);
			return;
		}
		bool bSuccess = cap.read(frame); // read a new frame from video
		if (!bSuccess) //if not success, break loop
		{
			MessageBox(NULL, L"Cannot read a frame from video file. Maybe camera not connecter to computer.", L"Camera error.", MB_OK);
			break;
		}
		if (frame.empty()) {
			MessageBox(NULL, L"Frame is empty.", L"Frame error.", MB_OK);
			break;
		}
		imshow("this is you, smile! :)", frame);
		if (waitKey(10) == 27) {
			std::cout << "Break. Press ESC" << std::endl;
			break; // stop capturing by pressing ESC 
		}
		counter++;
		try {
			std::string path = "C:/imgs/img" + std::to_string(counter) + ".jpg";
			bool result_save = imwrite(path, frame);
			if (!result_save) {
				MessageBox(NULL, L"Cannot save image in ""C:/imgs/img/imgN.jpg"".", L"Image save error.", MB_OK);
				return;
			}
		}
		catch (std::runtime_error & ex) {
			MessageBox(NULL, L"Exception converting image to PNG format. Something wrong with frame in save time.", L"Its runtime_error.", MB_OK);
			return;
		}

		if (counter >= 100) {
			counter = 0;
		}
	}
	std::cout << "Hello World!\n";
}

int main()
{
	std::cout << "Begin" << std::endl;
	www();
}

//Mat image;
//image = imread("C:/Users/al/Pictures/Uplay/Far Cry52019-11-23-20-25-9.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

//if (!image.data)                              // Check for invalid input
//{
//	cout << "Could not open or find the image" << std::endl;
//	return -1;
//}
//imwrite("./Gray_Image.jpg", image);
//namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display.
//imshow("Display window", image);                   // Show our image inside it.

//waitKey(0);