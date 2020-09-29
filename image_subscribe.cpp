#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>
#include <image_transport/image_transport.h>

using namespace cv;
using namespace std;
string path="/home/chunran";
string path1=".jpg";
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
    //cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
  //  cv::Mat src = cv_bridge::toCvShare(msg, "bgr8")->image;
    //string name;
    static int a = 1;   
    cv::Mat src = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
    //string(msg->header.stamp);
    cv::imwrite(to_string(a)+".jpg",src);
    a++;
    std::cout<<a<<std::endl;
    if(a==10) exit(0);
    cv::waitKey(3000);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_subscribe");
  ros::NodeHandle nh;
 //cv::namedWindow("view");
 // cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("image_raw", 1, imageCallback);
  ros::spin();
 // cv::destroyWindow("view");
}

