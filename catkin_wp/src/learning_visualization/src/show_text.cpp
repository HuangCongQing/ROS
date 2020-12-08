/*
 * @Description: 特定地方显示一行文字 参考：https://lightsail.blog.csdn.net/article/details/80483802
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-08 16:54:26
 * @LastEditTime: 2020-12-08 18:31:40
 * @FilePath: /ROS/catkin_wp/src/learning_visualization/src/show_text.cpp
 */
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include<iostream>
using namespace std;
int main( int argc, char** argv )
{
    ros::init(argc, argv, "showline");
    ros::NodeHandle n;
    ros::Publisher markerPub = n.advertise<visualization_msgs::Marker>("TEXT_VIEW_FACING", 10); // 话题名：TEXT_VIEW_FACING
    visualization_msgs::Marker marker;
    marker.header.frame_id="/odom";
    marker.header.stamp = ros::Time::now();
    marker.ns = "basic_shapes";
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.orientation.w = 1.0;
    marker.id =0;
    marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;  // type类型

    marker.scale.z = 0.2;
    marker.color.b = 0;
    marker.color.g = 0;
    marker.color.r = 1; // 红色
    marker.color.a = 1;

    ros::Rate r(1);
    int k=0;
    while(1)
    {
        geometry_msgs::Pose pose;
        pose.position.x =  (float)(k++)/10;  // 变换位置
        pose.position.y =  0;
        pose.position.z =0;
        marker.text= "blablabla" + to_string(k) ;  // 文字输入  不支持中文==========================================================================
        // ostringstream str;
        // str<<k;   
        // marker.text=str.str();  // 文字输入
        marker.pose=pose;
        markerPub.publish(marker);
        cout<<"k="<<k<<endl;
        r.sleep();
    }
    return 0;
}