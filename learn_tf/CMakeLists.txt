cmake_minimum_required(VERSION 2.8.3)
project(learn_tf)

find_package(catkin REQUIRED COMPONENTS
  jaws_description
  learn_rviz
  roscpp
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_tf
#  CATKIN_DEPENDS jaws_description jaws_rviz roscpp roslaunch tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(jaws_joint_pub src/jaws_joint_pub.cpp)
add_executable(jaws_joint_laps src/jaws_joint_laps.cpp)
add_executable(jaws_laps_tf src/jaws_laps_tf.cpp)

target_link_libraries(jaws_joint_pub
  ${catkin_LIBRARIES}
)
target_link_libraries(jaws_joint_laps
  ${catkin_LIBRARIES}
)
target_link_libraries(jaws_laps_tf
  ${catkin_LIBRARIES}
)
