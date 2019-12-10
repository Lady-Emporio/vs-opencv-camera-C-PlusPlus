// opencv.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Windows.h>
using namespace cv;
using namespace std;
int main()
{
	std::cout << "Begin" << std::endl;
	VideoCapture cap;
	if (!cap.open(0)) {
		MessageBox(NULL, L"Not open camera. Maybe not found.", L"Camera error. Not open.", MB_OK);
		return 0;
	}
	int counter = 0;
	for (;;)
	{
		Mat frame;
		//cap >> frame;
		if (!cap.isOpened())  // if not success, exit program
		{
			MessageBox(NULL, L"Camera is closed. Camera not is opened.", L"Camera error.", MB_OK);
			return 1;
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
		//imshow("this is you, smile! :)", frame);
		//if (waitKey(10) == 27) {
		//	std::cout << "Break. Press ESC" << std::endl;
		//	break; // stop capturing by pressing ESC 
		//}
		counter++;
		try {
			bool result_save = imwrite("W:/imgs/img" + to_string(counter) + ".jpg", frame);
			if (!result_save) {
				MessageBox(NULL, L"Cannot save image.", L"Image save error.", MB_OK);
				return 1;
			}
		}
		catch (runtime_error& ex) {
			MessageBox(NULL, L"Exception converting image to PNG format. Something wrong with frame in save time.", L"Its runtime_error.", MB_OK);
			return 1;
		}

		if (counter >= 100) {
			counter = 0;
		}
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
	
std::cout << "End" << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
