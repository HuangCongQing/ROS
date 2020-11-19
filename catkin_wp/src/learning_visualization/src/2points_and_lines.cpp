/*
 * @Description: 
 * http://wiki.ros.org/rviz/Tutorials/Markers%3A%20Points%20and%20Lines
 * 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-11-18 17:28:55
 * @LastEditTime: 2020-11-19 14:36:53
 * @FilePath: /ROS/catkin_wp/src/learning_visualization/src/2points_and_lines.cpp
 */
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include <cmath>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

  ros::Rate r(30);

  float f = 0.0;
  while (ros::ok())
  {

    visualization_msgs::Marker points, line_strip, line_list;  // 定义了3个消息
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "/my_frame";  // 三个msg的frameid一致
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_strip.ns = line_list.ns = "points_and_lines";
    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;  // orientation  方向


    // id不同
    points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;

    // 三个markers分配了三个不同的ID。使用points_and_lines命名空间可确保它们不会与其他r broadcasters广播公司发生冲突。

    points.type = visualization_msgs::Marker::POINTS;  // 点
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;   // 线
    line_list.type = visualization_msgs::Marker::LINE_LIST;  // 线段



    // POINTS markers 分别使用x和y比例表示宽度/高度
    points.scale.x = 0.2;
    points.scale.y = 0.2;

    // LINE_STRIP/LINE_LIST markers 将比例尺的x分量用于线宽
    line_strip.scale.x = 0.1;
    line_list.scale.x = 0.1;



    // Points are green   设置绿色
    points.color.g = 1.0f;
    points.color.a = 1.0;

    // Line strip线条 is blue  蓝色
    line_strip.color.b = 1.0;
    line_strip.color.a = 1.0;

    // Line list is red   红色
    line_list.color.r = 1.0;
    line_list.color.a = 1.0;



    // Create the vertices(顶点)  for the points and lines  //创建点和线的顶点
    for (uint32_t i = 0; i < 100; ++i)
    {
      float y = 5 * sin(f + i / 100.0f * 2 * M_PI);  // f += 0.04;   // f改变
      float z = 5 * cos(f + i / 100.0f * 2 * M_PI);

      geometry_msgs::Point p;    //  点坐标public visualization_msgs::Marker's points and lines which contains an array of geometry_msgs/Point
      p.x = (int32_t)i - 50;  //x (-50, 50)
      p.y = y;
      p.z = z;

      points.points.push_back(p);  // 
      line_strip.points.push_back(p);

      // The line list needs two points for each line  每条线需要两个点
      line_list.points.push_back(p);
      p.z += 1.0;
      line_list.points.push_back(p);
    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);
    marker_pub.publish(line_list);

    r.sleep();

    f += 0.04;   // f改变
  }
}