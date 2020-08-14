#!/usr/bin/env python
# -*- coding: utf-8 -*-

########################################################################
####          Copyright 2020 GuYueHome (www.guyuehome.com).          ###
########################################################################

# 该例程设置/读取海龟例程中的参数

import sys
import rospy
from std_srvs.srv import Empty

def parameter_config():
	# ROS节点初始化
    rospy.init_node('parameter_config', anonymous=True)

	# 读取背景颜色参数
    red   = rospy.get_param('/background_r')
    green = rospy.get_param('/background_g')
    blue  = rospy.get_param('/background_b')

    rospy.loginfo("Get Backgroud Color[%d, %d, %d]", red, green, blue)

	# 设置背景颜色参数
    rospy.set_param("/background_r", 255);
    rospy.set_param("/background_g", 255);
    rospy.set_param("/background_b", 255);

    rospy.loginfo("Set Backgroud Color[255, 255, 255]");

	# 读取背景颜色参数
    red   = rospy.get_param('/background_r')
    green = rospy.get_param('/background_g')
    blue  = rospy.get_param('/background_b')

    rospy.loginfo("Get Backgroud Color[%d, %d, %d]", red, green, blue)

	# 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
    rospy.wait_for_service('/clear')
    try:
        clear_background = rospy.ServiceProxy('/clear', Empty)

		# 请求服务调用，输入请求数据
        response = clear_background()
        return response
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":
    parameter_config()
