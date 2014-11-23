#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "boost/asio.hpp"

class SerialPort
{
private:
  ros::NodeHandle nh;
  ros::Subscriber sub;
  std_msgs::Float32 angle;
  boost::asio::io_service i_o;
  boost::asio::serial_port s_p;

public:
  SerialPort() : nh(), i_o(), s_p(i_o, "/dev/ttyACM0")
  {
    sub = nh.subscribe<std_msgs::Float32>("angle", 1, &SerialPort::callback, this);
  }
  void callback(const std_msgs::Float32::ConstPtr& angle)
  {
    unsigned char d = (char)angle->data;
    s_p.write_some(boost::asio::buffer(&d, 1));
  }
  void loop()
  {
    ros::spin();
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "serial_node");
  SerialPort sp;
  sp.loop();
}
