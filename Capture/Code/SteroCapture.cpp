//#include <opencv2\opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//
//int main()
//{
//	char savename_l[128];
//	char savename_r[128];
//	int picturenumber = 1;
//	videocapture capture(1); //打开双目
//
//	if (!capture.isopened()) { //判断能够打开摄像头
//		cout << "can not open the camera" << endl;
//		cin.get();
//		exit(1);
//	}
//
//	capture.set(cap_prop_fourcc, 'gpjm');  //mjpg格式  60fps
//	capture.set(cap_prop_frame_width, 2560);
//	capture.set(cap_prop_frame_height, 960);   //分辨率 2560*960
//
//	rect left_rect(0, 0, 1279, 960);   //创建一个rect框，属于cv中的类，四个参数代表x,y,width,height  
//	rect right_rect(1280, 0, 1279, 960);
//
//	mat image_left, image_right;
//	string left_road;
//	string right_road;
//
//
//
//
//	while (1) {
//		mat frame;
//		capture >> frame; //载入图像
//		image_left = mat(frame, left_rect).clone();
//		image_right = mat(frame, right_rect).clone();
//
//		if (frame.empty()) { //判断图像是否载入
//			cout << "can not load the frame" << endl;
//		}
//		else {
//			namedwindow("left", 0);
//			resizewindow("left", 640, 480);
//			imshow("left", image_left);
//			namedwindow("right", 0);
//			resizewindow("right", 640, 480);
//			imshow("right", image_right);
//			char c = waitkey(17); //延时17毫秒
//			if (c == 27) //按esc键退出
//				break;
//			if (c == 'q')
//			{
//				sprintf(savename_l, "e://data//l//lte%3d.jpg", picturenumber);//设置图片的序号，名称
//				sprintf(savename_r, "e://data//r//rte%3d.jpg", picturenumber++);//设置图片的序号，名称
//				imwrite(savename_l, image_left);//保存图片
//				imwrite(savename_r, image_right);//保存图片
//				cout<<"save completed ."<<endl;
//			}
//		}
//	}
//}