
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <pcl/visualization/cloud_viewer.h>
using namespace std;
// 定义点云类型
typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloud;

// 相机内参
const double camera_factor = 10000;
const double camera_cx = 365;
const double camera_cy = 265;
const double camera_fx = 500;
const double camera_fy = 500;


int main(int argc, char** argv)
{

	cv::Mat rgb, depth;

	rgb = cv::imread("E:/data/sunrgb/0000101.jpg");
	cout << "read rgb" << endl;

	depth = cv::imread("E:/data/sunrgb/0000101.png");
	cout << "read depth" << endl;

	PointCloud::Ptr cloud(new PointCloud);

	for (int m = 0; m < depth.rows; m+=2)
		for (int n = 0; n < depth.cols; n+= 2)
		{

			unsigned long d = depth.ptr<unsigned long>(m)[n];

			if (d < 20000)
				continue;
			PointT p;


			p.z = (double(d) / camera_factor);
			p.x = ((n - camera_cx) * p.z / camera_fx) ;
			p.y = ((m - camera_cy) * p.z / camera_fy) ;
			
			//p.b = rgb.ptr<uchar>(m)[3*n];
			//p.g = rgb.ptr<uchar>(m)[3 * n + 1];
			//p.r = rgb.ptr<uchar>(m)[3 * n + 2];

			p.b = rgb.ptr<uchar>(303)[303];
			p.g = rgb.ptr<uchar>(33)[33];
			p.r = rgb.ptr<uchar>(303)[303];

			cloud->points.push_back(p);
			//cout << cloud->points.size() << endl;
		}

	cloud->height = 1;
	cloud->width = cloud->points.size();
	cout << "point cloud size = " << cloud->points.size() << endl;
	cloud->is_dense = false;
	try {

		//pcl::io::savePCDFile("E:/data/rotate_20190620/pcd/ltest 38.pcd", *cloud);
	}
	catch (pcl::IOException &e) {
		cout << e.what() << endl;
	}
	//显示点云图
	pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
	viewer.showCloud(cloud);
	while (!viewer.wasStopped())
	{
	}
	//pcl::io::savePCDFileASCII("E:/data/sunrgb/img_0070.pcd", *cloud);
	// 清除数据并退出
	cloud->points.clear();
	cout << "Point cloud saved." << endl;
	return 0;

}