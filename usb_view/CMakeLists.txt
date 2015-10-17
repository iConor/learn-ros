cmake_minimum_required(VERSION 2.8.3)
project(usb_view)

find_package(catkin REQUIRED COMPONENTS
  image_view
  usb_cam
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES usb_view
#  CATKIN_DEPENDS image_view usb_cam
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
