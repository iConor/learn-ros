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
    int refresh_rate;
    double port;
    double stbd;
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

  refresh_rate = 30;

  port = 0.0;
  stbd = 0.0;
}

void Servos::callback(const sensor_msgs::Joy::ConstPtr& joy)
{
  port = joy->axes[2] * 0.7853975;
  stbd = joy->axes[2] * 0.7853975;
}

void Servos::loop()
{
  ros::Rate rate(refresh_rate);
  while(ros::ok())
  {
    ros::spinOnce();

    js.header.stamp = ros::Time::now();
    js.name.resize(2);
    js.position.resize(2);
    js.name[0] ="port-base";
    js.position[0] = port;
    js.name[1] ="stbd-base";
    js.position[1] = stbd;

    pub.publish(js);

    rate.sleep();
  }
}
