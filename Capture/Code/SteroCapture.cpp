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
//	videocapture capture(1); //��˫Ŀ
//
//	if (!capture.isopened()) { //�ж��ܹ�������ͷ
//		cout << "can not open the camera" << endl;
//		cin.get();
//		exit(1);
//	}
//
//	capture.set(cap_prop_fourcc, 'gpjm');  //mjpg��ʽ  60fps
//	capture.set(cap_prop_frame_width, 2560);
//	capture.set(cap_prop_frame_height, 960);   //�ֱ��� 2560*960
//
//	rect left_rect(0, 0, 1279, 960);   //����һ��rect������cv�е��࣬�ĸ���������x,y,width,height  
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
//		capture >> frame; //����ͼ��
//		image_left = mat(frame, left_rect).clone();
//		image_right = mat(frame, right_rect).clone();
//
//		if (frame.empty()) { //�ж�ͼ���Ƿ�����
//			cout << "can not load the frame" << endl;
//		}
//		else {
//			namedwindow("left", 0);
//			resizewindow("left", 640, 480);
//			imshow("left", image_left);
//			namedwindow("right", 0);
//			resizewindow("right", 640, 480);
//			imshow("right", image_right);
//			char c = waitkey(17); //��ʱ17����
//			if (c == 27) //��esc���˳�
//				break;
//			if (c == 'q')
//			{
//				sprintf(savename_l, "e://data//l//lte%3d.jpg", picturenumber);//����ͼƬ����ţ�����
//				sprintf(savename_r, "e://data//r//rte%3d.jpg", picturenumber++);//����ͼƬ����ţ�����
//				imwrite(savename_l, image_left);//����ͼƬ
//				imwrite(savename_r, image_right);//����ͼƬ
//				cout<<"save completed ."<<endl;
//			}
//		}
//	}
//}