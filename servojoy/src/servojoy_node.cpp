#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "sensor_msgs/Joy.h"

class PS3Controller
{
private:
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
  std_msgs::Float32 angle;

public:
  PS3Controller() : nh()
  {
    pub = nh.advertise<std_msgs::Float32>("angle", 1);
    sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, &PS3Controller::callback, this);
  }
  void callback(const sensor_msgs::Joy::ConstPtr& joy)
  {
    angle.data = 90 + joy->axes[2] * -90;
    pub.publish(angle);
  }
  void loop()
  {
    ros::Rate rate(10);
    while(ros::ok())
    {
      ros::spinOnce();
      rate.sleep();
    }
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ds3_node");
  PS3Controller ps3;
  ps3.loop();
}
