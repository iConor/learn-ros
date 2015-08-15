#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/JointState.h>

class Laps
{
  private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    tf::TransformBroadcaster bcast;
    geometry_msgs::TransformStamped tform;
    sensor_msgs::JointState js;
    int refresh_rate;
    double one_degree;
    double angle;
    double port;
    double stbd;
    int depth;
    int radius;
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
  tform.header.frame_id = "odom";
  tform.child_frame_id = "base_link";

  pub = nh.advertise<sensor_msgs::JointState>("joint_states", 1);

  refresh_rate = 30;

  one_degree = M_PI / 180.0;
  angle = 0.0;
  port = 0.0;
  stbd = 0.0;

  depth = 0.5;
  radius = 1;
}

void Laps::loop()
{
  ros::Rate rate(refresh_rate);
  while(ros::ok())
  {
    tform.header.stamp = ros::Time::now();

    tform.transform.translation.x = radius * cos(angle);
    tform.transform.translation.y = radius * sin(angle);
    tform.transform.translation.z = depth;

    tform.transform.rotation = tf::createQuaternionMsgFromYaw(angle + M_PI / 2);

    bcast.sendTransform(tform);

    js.header.stamp = ros::Time::now();
    js.name.resize(2);
    js.position.resize(2);
    js.name[0] ="port-base";
    js.position[0] = port;
    js.name[1] ="stbd-base";
    js.position[1] = stbd;

    pub.publish(js);

    angle += one_degree / 4;
    port += one_degree / 4;
    stbd += one_degree / 2;

    rate.sleep();
  }
}
