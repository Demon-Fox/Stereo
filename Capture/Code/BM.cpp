//#include <opencv2\core\core.hpp>
//#include <opencv2\highgui\highgui.hpp>
//#include <opencv2\imgproc\imgproc.hpp>
//#include <opencv2\calib3d\calib3d.hpp>
//#include <iostream>
//
//using namespace cv;
//int main(int argc, char** argv) {
//
//	//����ͼ��
//	Mat left = cv::imread("E:/data/190429/result_l/rtest  6.jpg");
//	Mat right = cv::imread("E:/data/190429/result_r/rtest  6.jpg");
//	if (left.empty() || right.empty()) {
//		std::cout << "could not load image...\n";
//		return -1;
//	}
//
//	//ͼ��ת�Ҷ�
//	cv::cvtColor(left, left,COLOR_RGB2GRAY);
//	cv::cvtColor(right, right, COLOR_RGB2GRAY);
//
//	//���ò���
//	int numberOfDisparities = 16, SADWindowSize = 11;
//	int uniquenessRatio = 15, speckleWindowSize = 50, speckleRange = 32;
//	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(0, numberOfDisparities, SADWindowSize);
//	int cn = left.channels();
//	sgbm->setP1(8 * cn * SADWindowSize * SADWindowSize);
//	sgbm->setP2(32 * cn * SADWindowSize * SADWindowSize);
//	sgbm->setPreFilterCap(63);
//	sgbm->setUniquenessRatio(uniquenessRatio);
//	sgbm->setSpeckleWindowSize(speckleWindowSize);
//	sgbm->setSpeckleRange(speckleRange);
//	sgbm->setDisp12MaxDiff(1);
//
//	//���㲢��ʾ�Ӳ�
//	Mat disp;
//	sgbm->compute(left, right, disp);
//	disp.convertTo(disp, CV_8U, 255 / (numberOfDisparities*16.));   //��16λ�������ε��Ӳ����ת��Ϊ8λ�޷������ξ���
//	cv::imshow("disparity", disp);
//	cv::imwrite("E:/data/190429/d/rtest  6.jpg", disp);
//	cv::waitKey();
//
//	return 0;
//}