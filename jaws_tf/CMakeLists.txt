cmake_minimum_required(VERSION 2.8.3)
project(jaws_tf)

find_package(catkin REQUIRED COMPONENTS
  jaws_description
  jaws_rviz
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

add_executable(laps_tf src/laps_tf.cpp)
add_executable(joint_pub src/joint_pub.cpp)
add_executable(laps_both src/laps_both.cpp)

 target_link_libraries(laps_tf
   ${catkin_LIBRARIES}
 )
 target_link_libraries(joint_pub
   ${catkin_LIBRARIES}
 )
 target_link_libraries(laps_both
   ${catkin_LIBRARIES}
 )
