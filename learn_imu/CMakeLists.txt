cmake_minimum_required(VERSION 2.8.3)
project(learn_imu)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  imu_3dm_gx4
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES jaws_imu
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(quaternion src/quaternion.cpp)

target_link_libraries(quaternion
  ${catkin_LIBRARIES}
)
