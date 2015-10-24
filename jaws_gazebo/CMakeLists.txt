cmake_minimum_required(VERSION 2.8.3)
project(jaws_gazebo)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roslaunch
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_gazebo
#  CATKIN_DEPENDS gazebo_ros roslaunch
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
