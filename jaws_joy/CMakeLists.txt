cmake_minimum_required(VERSION 2.8.3)
project(jaws_joy)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_joy
#  CATKIN_DEPENDS roscpp sensor_msgs tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(joint_pub_joy src/joint_pub_joy.cpp)
add_executable(tf_orientation src/tf_orientation.cpp)
add_executable(tf_translation src/tf_translation.cpp)

target_link_libraries(joint_pub_joy
  ${catkin_LIBRARIES}
)
target_link_libraries(tf_orientation
  ${catkin_LIBRARIES}
)
target_link_libraries(tf_translation
  ${catkin_LIBRARIES}
)
