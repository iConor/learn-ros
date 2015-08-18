#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Joy.h>

class Orientation
{
  private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    tf::TransformBroadcaster bcast;
    geometry_msgs::TransformStamped tform;
    double roll;
    double pitch;
    double yaw;
  public:
    Orientation();
    void callback(const sensor_msgs::Joy::ConstPtr& joy);
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
  sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, &Orientation::callback, this);

  tform.header.frame_id = "odom";
  tform.child_frame_id = "base_link";

  tform.transform.translation.x = 0.0;
  tform.transform.translation.y = 0.0;
  tform.transform.translation.z = 0.0;

  roll = 0.0;
  pitch = 0.0;
  yaw = 0.0;
}

void Orientation::callback(const sensor_msgs::Joy::ConstPtr& joy)
{
  roll = joy->axes[2] * -0.7853975;
  pitch = joy->axes[3] * 0.7853975;
  yaw = joy->axes[0] * 0.7853975;

  tform.header.stamp = ros::Time::now();

  tform.transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(roll, pitch, yaw);

  bcast.sendTransform(tform);
}

void Orientation::loop()
{
  while(ros::ok())
  {
    ros::spin();
  }
}
