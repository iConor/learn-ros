#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/Joy.h"

ros::Publisher publisher;
geometry_msgs::Twist twist;

void turtlejoyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  twist.linear.x = (double) joy->axes[1];
  twist.angular.z = (double) joy->axes[2];
  publisher.publish(twist);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlejoy_node");
  ros::NodeHandle node_handle;
  publisher = node_handle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  ros::Subscriber subscriber = node_handle.subscribe<sensor_msgs::Joy>("joy", 1, turtlejoyCallback);
  ros::spin();
}
