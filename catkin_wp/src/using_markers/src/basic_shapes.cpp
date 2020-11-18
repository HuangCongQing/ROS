/*
 * @Description: 基本形状 参考：  https://www.cnblogs.com/wxt11/p/6561283.html
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-11-18 16:48:13
 * @LastEditTime: 2020-11-18 17:01:22
 * @FilePath: /ROS/catkin_wp/src/using_markers/src/basic_shapes.cpp
 */
#include "ros/ros.h"
#include "visualization_msgs/Marker.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);   // 话题

    uint32_t shape = visualization_msgs::Marker::CUBE;

    while(ros::ok())
    {
        visualization_msgs::Marker marker;
        marker.header.frame_id = "/my_frame";   // frame_id   和rviz对应起来
        marker.header.stamp = ros::Time::now();
        marker.ns = "basic_shapes";
        marker.id = 0;
        marker.type = shape;
        marker.action = visualization_msgs::Marker::ADD;

        marker.pose.position.x = 0;
        marker.pose.position.y = 0;
        marker.pose.position.z = 0;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;

        marker.scale.x = 1.0;
        marker.scale.y = 1.0;
        marker.scale.z = 1.0;

        marker.color.r = 0.0f;
        marker.color.g = 1.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;

        marker.lifetime = ros::Duration();

        while(marker_pub.getNumSubscribers() < 1)
        {
            if(!ros::ok())
            {
                return 0;
            }
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }
        marker_pub.publish(marker);  // 发布消息  marker  消息msg

        switch(shape)
        {
            case visualization_msgs::Marker::CUBE:      // 立方体
                shape = visualization_msgs::Marker::SPHERE;      // 球
                break;
            case visualization_msgs::Marker::SPHERE:     // 球
                shape = visualization_msgs::Marker::ARROW;
                break;
            case visualization_msgs::Marker::ARROW:     // 箭头
                shape = visualization_msgs::Marker::CYLINDER;
                break;
            case visualization_msgs::Marker::CYLINDER:     // 圆柱
                shape = visualization_msgs::Marker::CUBE;
                break;

        }
        r.sleep();
    }

}