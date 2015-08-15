#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

class Laps
{
  private:
    ros::NodeHandle nh;
    tf::TransformBroadcaster bcast;
    geometry_msgs::TransformStamped tform;
    int refresh_rate;
    double one_degree;
    double angle;
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

  refresh_rate = 30;

  one_degree = M_PI / 180.0;
  angle = 0.0;

  depth = -1;
  radius = 5;
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

    angle += one_degree / 4;

    rate.sleep();
  }
}
