#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include "imu_3dm_gx4/FilterOutput.h"

class Orientation
{
  private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    tf::TransformBroadcaster bcast;
    geometry_msgs::TransformStamped tform;
  public:
    Orientation();
    void callback(const imu_3dm_gx4::FilterOutput::ConstPtr& filter);
    void loop();
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  Orientation orientation;
  orientation.loop();
}

Orientation::Orientation() : nh()
{
  sub = nh.subscribe<imu_3dm_gx4::FilterOutput>("/imu/filter", 1, &Orientation::callback, this);

  tform.header.frame_id = "odom";
  tform.child_frame_id = "base_link";

  tform.transform.translation.x = 0.0;
  tform.transform.translation.y = 0.0;
  tform.transform.translation.z = 0.0;
}

void Orientation::callback(const imu_3dm_gx4::FilterOutput::ConstPtr& filter)
{
  tform.header.stamp = ros::Time::now();

  tform.transform.rotation.x = filter->orientation.x;
  tform.transform.rotation.y = -filter->orientation.y;
  tform.transform.rotation.z = -filter->orientation.z;
  tform.transform.rotation.w = filter->orientation.w;

  bcast.sendTransform(tform);
}

void Orientation::loop()
{
  while(ros::ok())
  {
    ros::spin();
  }
}
