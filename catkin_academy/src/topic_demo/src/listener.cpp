/*
 * @Description: 话题接收者   https://sychaichangkun.gitbooks.io/ros-tutorial-icourse163/content/chapter6/6.3.html
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-11-02 17:14:38
 * @LastEditTime: 2020-11-02 17:48:53
 * @FilePath: /ROS/catkin_academy/src/topic_demo/src/listener.cpp
 */
#include<ros/ros.h>
#include<topic_demo/gps.h>
#include <std_msgs/Float32.h>

void gpsCallback(const topic_demo::gps::ConstPtr &msg){
    std_msgs::Float32 distance;  //计算离原点(0,0)的距离   官方自带的std_msgs
    distance.data = sqrt(pow(msg->x, 2) + pow(msg->y, 2));
    // ROS_INFO("Listener: Distance to origin = %f, state : %f", distance.data, msg->state.c_str()); // 输出
}

int main(int argc, char  **argv){
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("gps_info", 1, gpsCallback);  //设置回调函数gpsCallback
    ros::spin();//ros::spin()用于调用所有可触发的回调函数，将进入循环，不会返回，类似于在循环里反复调用spinOnce() 
  //而ros::spinOnce()只会去触发一次
    return 0;
}