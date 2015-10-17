cmake_minimum_required(VERSION 2.8.3)
project(jaws_description)

find_package(catkin REQUIRED COMPONENTS
  urdf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_description
#  CATKIN_DEPENDS urdf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
