#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Joy.h>

class Translation
{
  private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    tf::TransformBroadcaster bcast;
    geometry_msgs::TransformStamped tform;
  public:
    Translation();
    void callback(const sensor_msgs::Joy::ConstPtr& joy);
    void loop();
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  Translation translation;
  translation.loop();
}

Translation::Translation() : nh()
{
  sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, &Translation::callback, this);

  tform.header.frame_id = "odom";
  tform.child_frame_id = "base_link";

  tform.transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
}

void Translation::callback(const sensor_msgs::Joy::ConstPtr& joy)
{
  tform.header.stamp = ros::Time::now();

  tform.transform.translation.x = joy->axes[3] / 16.0;
  tform.transform.translation.y = joy->axes[2] / 16.0;
  tform.transform.translation.z = joy->axes[1] / 16.0;

  bcast.sendTransform(tform);
}

void Translation::loop()
{
  while(ros::ok())
  {
    ros::spin();
  }
}
