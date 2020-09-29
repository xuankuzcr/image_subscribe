cmake_minimum_required(VERSION 2.8.3)
project(image_subscribe)
add_compile_options(-std=c++11)
 
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
)
 
find_package(OpenCV 3.2.0 REQUIRED)
 
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES my_image_transport
  CATKIN_DEPENDS cv_bridge image_transport
#  DEPENDS system_lib
)
 
 
 
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)
 
 
 
#build my_publisher and my_subscriber
add_executable(image_subscribe image_subscribe.cpp)
target_link_libraries(image_subscribe ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
 

