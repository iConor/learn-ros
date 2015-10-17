cmake_minimum_required(VERSION 2.8.3)
project(jaws_visualization)

find_package(catkin REQUIRED COMPONENTS
  imu_3dm_gx4
  joy
  roscpp
  rviz
  sensor_msgs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_visualization
#  CATKIN_DEPENDS imu_3dm_gx4 joy roscpp rviz sensor_msgs tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
