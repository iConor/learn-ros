cmake_minimum_required(VERSION 2.8.3)
project(learn_arduino)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES joy_servo
#  CATKIN_DEPENDS roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(angle src/angle.cpp)
add_executable(serial src/serial.cpp)

target_link_libraries(angle
  ${catkin_LIBRARIES}
)
target_link_libraries(serial
  ${catkin_LIBRARIES}
)
