#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include <fstream>

std::ofstream file;
char character;

void callback(const sensor_msgs::Joy::ConstPtr& joy)
{
  character = (unsigned char)(90 + joy->axes[2] * -90);
  file.write(&character, 1);
  file.flush();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "servotest_node");
  ros::NodeHandle node_handle;
  ros::Subscriber subscriber = node_handle.subscribe<sensor_msgs::Joy>("joy", 1, callback);
  file.open("/dev/ttyACM0");
  ros::Rate rate(10);
  while(ros::ok())
  {
    ros::spinOnce();
    rate.sleep();
  }
  file.close();
}
