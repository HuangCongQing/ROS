/*
 * @Description: 基本形状 参考：
 * 官网：http://wiki.ros.org/action/fullsearch/rviz/Tutorials/Markers%3A%20Basic%20Shapes?action=fullsearch&context=180&value=linkto%3A%22rviz%2FTutorials%2FMarkers%3A+Basic+Shapes%22
 * 中文博客：  https://www.cnblogs.com/wxt11/p/6561283.html
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-11-18 16:48:13
 * @LastEditTime: 2020-11-19 14:54:10
 * @FilePath: /ROS/catkin_wp/src/learning_visualization/src/1basic_shapes.cpp
 */
#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include <math.h>

int main(int argc,char** argv)
{
    ros::init(argc,argv,"basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);   // 话题

    //将我们的初始形状类型设置为立方体cube
    uint32_t shape = visualization_msgs::Marker::CUBE;

    while(ros::ok())
    {
        visualization_msgs::Marker marker;
        //设置frame ID and timestamp。有关这些信息，请参见TF教程。
        marker.header.frame_id = "/my_frame";   // frame_id   和rviz对应起来
        marker.header.stamp = ros::Time::now();
        //设置此标记的namespace和id。这用于创建唯一的id
        //任何使用相同namespace和id发送的标记都将覆盖旧标记
        marker.ns = "basic_shapes";
        marker.id = 0;  // 每次获取到机器人的位姿后，就在对应点发布一个标志，然后将lifetime设为0，也就是无限久地保存～～
        // 但是需要注意一点，让ns或者id变量每次都不一样，否则ns和id一直一样的话，后面的操作会覆盖前面的操作，也就一直只能看到最新的了。建议每次让id+=1。
        //设置the marker type。最初是CUBE，并且在那个和SPHERE，ARROW和CYLINDER之间循环
        marker.type = shape;
        // //设置marker action。选项包括ADD，DELETE和new
        marker.action = visualization_msgs::Marker::ADD;
        // 设置the pose of the marker。这是相对于标头中指定的frame/time的完整6DOF pose 
        marker.pose.position.x = 0;
        marker.pose.position.y = 0;
        marker.pose.position.z = 0;
        marker.pose.orientation.x = M_PI;   // π  3.1415   Roll：两侧摆动
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;
        //设置标记的比例尺scale -1x1x1,此处表示1m
        marker.scale.x = 1.0;
        marker.scale.y = 1.0;
        marker.scale.z = 1.0;
        // 设置颜色-确保将alpha设置为非零值！
        marker.color.r = 0.0f;
        marker.color.g = 1.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;

        marker.lifetime = ros::Duration();

        // Publish the marker
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

        //   在不同形状之间循环 Cycle between different shapes
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