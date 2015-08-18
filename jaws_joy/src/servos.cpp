#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/Joy.h>

class Servos
{
  private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher pub;
    sensor_msgs::JointState js;
  public:
    Servos();
    void callback(const sensor_msgs::Joy::ConstPtr& joy);
    void loop();
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  Servos servos;
  servos.loop();
}

Servos::Servos() : nh()
{
  sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, &Servos::callback, this);
  pub = nh.advertise<sensor_msgs::JointState>("joint_states", 1);
}

void Servos::callback(const sensor_msgs::Joy::ConstPtr& joy)
{
  js.header.stamp = ros::Time::now();
  js.name.resize(2);
  js.position.resize(2);
  js.name[0] ="port-base";
  js.position[0] = joy->axes[2] * 0.7853975;
  js.name[1] ="stbd-base";
  js.position[1] = joy->axes[2] * 0.7853975;

  pub.publish(js);
}

void Servos::loop()
{
  while(ros::ok())
  {
    ros::spin();
  }
}
