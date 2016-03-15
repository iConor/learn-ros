cmake_minimum_required(VERSION 2.8.3)
project(learn_opencv)

find_package(
  OpenCV REQUIRED
)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  roscpp
  sensor_msgs
  std_msgs
  image_transport
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES learn_opencv
#  CATKIN_DEPENDS cv_bridge roscpp
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(learn_opencv_node src/learn_opencv_node.cpp)

target_link_libraries(learn_opencv_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)
