cmake_minimum_required(VERSION 2.8.3)
project(learn_turtlesim)

find_package(catkin REQUIRED COMPONENTS
  joy
  roscpp
  turtlesim
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES turtlejoy
#  CATKIN_DEPENDS joy roscpp turtlesim
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(steering src/steering.cpp)

target_link_libraries(steering
  ${catkin_LIBRARIES}
)
