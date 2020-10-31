<!--
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2019-04-16 15:26:41
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-31 12:23:39
-->
# ROS
机器人操作系统@[双愚](https://github.com/HuangCongQing/ROS)

* 运行环境：Ubuntu18.04 微软云服务器（AzureUser@aitraining）
`/home/AzureUser/hcq/ROS`

* ROS & SLAM个人笔记：https://www.yuque.com/huangzhongqing/ld627o

## 编译和运行
```
// 1 设置工作空间
cd catkin_wp/src
catkin_init_workspace

// 编译（需要回到工作空间catkin_wp）
cd ..
catkin_make  // 产生build和devel文件夹
catkin_make install // 就会有install文件夹

//设置环境变量
source devel/setup.bash  // 不同shell，不同哦.sh  .zsh
```



```shell
//2 创建功能包(src文件夹下)
//创建包 catkin_create_pkg 包名 依赖1 依赖2 
cd src
catkin_create_pkg test_pkg std_msgs roscpp rospy

// 编译功能包(回到目录catkin_ws)
catkin_make
// 设置环境变量(能让系统找到我们的工作空间和功能包)
source devel/setup.bash


// 运行
roscore //启动ROS master
rosrun turtlesim(功能包名) turtlesim_node(节点名) //rosrun启动节点，该节点归属于功能包，这个节点就是小海龟仿真器
rosrun turtlesim turtle_teleop_key
```

## ROS介绍

>作者：Morgan  其博士生导师：吴恩达
>别人已经造好轮子，集成起来，提高软件复用率。
(有的组织擅长建模，OR导航 OR物理识别，ROS就可以把这些组织都连接起来，帮助他们建立一种相互合作的的高效的方式，在已有成果做更多东西。)

> ROS2：一开始只是学术界，后面成为机器人领域的普遍标准，很多设计上的局限性和问题暴露出来，所以需要改良到工业界。


1. 节点 节点管理器（婚介所）
2. 话题&服务

两种通信机制：话题和服务
* 话题：
    * 发布订阅模型 
    * 异步通信机制（单向）
    * 话题数据：**消息**
* 服务：
    * 客户端服务端模型 
    * 同步通信机制(双向)

![](https://cdn.nlark.com/yuque/0/2020/png/232596/1583747169660-fe70ab3f-7927-45f2-8d8a-651c0d365c41.png)

#### 1 古月 · ROS入门21讲
> 代码路径: **[catkin_wp/src](catkin_wp/src)**

* [09.创建工作空间与功能包](catkin_wp/src/test_pkg)
* [10-11 发布者订阅者的编程实现](catkin_wp/src/learning_topic)
* [12.话题消息的定义与使用](catkin_wp/src/learning_topic)
* [13.客户端Client的编程实现](catkin_wp/src/learning_service)
* [14.服务端Server的编程实现](catkin_wp/src/learning_service)
* [15.服务数据的定义与使用](catkin_wp/src/learning_service)
* [16.参数的使用与编程方法](catkin_wp/src/learning_parameter)
* [17.ROS中的坐标系管理系统 tf](catkin_wp/src/learning_tf)
* [18.tf坐标系广播与监听的编程实现](catkin_wp/src/learning_tf)
* [19.launch启动文件的使用方法](catkin_wp/src/learning_launch)


## Reference
### 书籍：《ROS机器人开发实践_胡春旭》
* 《ROS机器人开发实践》源码：https://github.com/huchunxu/ros_exploring

### 视频和代码
* 1 古月 · ROS入门21讲
* 2 机器人操作系统ROS理论与实践【9讲】

#### 1 古月 · ROS入门21讲
课件：https://github.com/huchunxu/ros_21_tutorials/tree/master/docs/slides
源码：https://github.com/huchunxu/ros_21_tutorials
* [个人代码](https://github.com/HuangCongQing/ROS/tree/master/catkin_wp/src)

#### 2 机器人操作系统ROS理论与实践【9讲】

