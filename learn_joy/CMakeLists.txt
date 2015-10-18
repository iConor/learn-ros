cmake_minimum_required(VERSION 2.8.3)
project(learn_joy)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  jaws_description
  joy
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

add_executable(jaws_joy_pub_joint src/jaws_joy_pub_joint.cpp)
add_executable(jaws_tf_orientation src/jaws_tf_orientation.cpp)
add_executable(jaws_tf_translation src/jaws_tf_translation.cpp)

target_link_libraries(jaws_joy_pub_joint
  ${catkin_LIBRARIES}
)
target_link_libraries(jaws_tf_orientation
  ${catkin_LIBRARIES}
)
target_link_libraries(jaws_tf_translation
  ${catkin_LIBRARIES}
)
