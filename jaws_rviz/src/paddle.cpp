#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

class Laps
{
  private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    sensor_msgs::JointState js;
    int refresh_rate;
    double one_degree;
    double port;
    double stbd;
  public:
    Laps();
    void loop();
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  Laps laps;
  laps.loop();
}

Laps::Laps() : nh()
{
  pub = nh.advertise<sensor_msgs::JointState>("joint_states", 1);

  refresh_rate = 30;

  one_degree = M_PI / 180.0;
  port = 0.0;
  stbd = 0.0;
}

void Laps::loop()
{
  ros::Rate rate(refresh_rate);
  while(ros::ok())
  {

    js.header.stamp = ros::Time::now();
    js.name.resize(2);
    js.position.resize(2);
    js.name[0] ="port-base";
    js.position[0] = port;
    js.name[1] ="stbd-base";
    js.position[1] = stbd;

    pub.publish(js);

    port += one_degree / 4;
    stbd += one_degree / 2;

    rate.sleep();
  }
}
