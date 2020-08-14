/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-08-14 12:26:13
 * @LastEditors: HCQ
 * @LastEditTime: 2020-08-14 15:38:52
 */
/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程将请求/spawn服务，服务数据类型turtlesim::Spawn
 */

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "turtle_spawn"); // 节点名 turtle_spawn

	// 创建节点句柄
	ros::NodeHandle node;

	// 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
	ros::service::waitForService("/spawn"); // 阻塞循环等待，直到查询到/spawn服务
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

	// 初始化turtlesim::Spawn的请求数据
	turtlesim::Spawn srv; // 定义srv
	srv.request.x = 2.0;
	srv.request.y = 2.0;
	srv.request.name = "turtle2";

	// 请求服务调用  log日志
	ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]",
			 srv.request.x, srv.request.y, srv.request.name.c_str());

	add_turtle.call(srv); // 阻塞，知道结果发出

	// 显示服务调用结果
	ROS_INFO("Spwan turtle successfully [name:%s]", srv.response.name.c_str());

	return 0;
};
