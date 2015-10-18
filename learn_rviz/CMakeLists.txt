cmake_minimum_required(VERSION 2.8.3)
project(learn_rviz)

find_package(catkin REQUIRED COMPONENTS
  roslaunch
  rviz
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_rviz
#  CATKIN_DEPENDS roscpp sensor_msgs tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
