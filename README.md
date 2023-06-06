<!--
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2019-04-16 15:26:41
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-12-29 15:06:55
-->
# ROS
机器人操作系统@[双愚](https://github.com/HuangCongQing/ROS)

* 运行环境：Ubuntu18.04 微软云服务器（AzureUser@aitraining）
`/home/AzureUser/hcq/ROS`

* ROS & SLAM个人笔记：https://www.yuque.com/huangzhongqing/ld627o
* 创建工作空间与功能包详解：https://www.yuque.com/huangzhongqing/ld627o/zr0eix
* **ROS2(python): https://github.com/HuangCongQing/ros2_python**
* 【202210】个人制作的ros环境镜像(with rviz 界面): https://hub.docker.com/repository/docker/2015212821/ros
* 相关链接
   * PCL库：https://github.com/HuangCongQing/pcl-learning

创建一个知识星球 **【自动驾驶感知(PCL/ROS+DL)】** 专注于自动驾驶感知领域，包括传统方法(PCL点云库,ROS)和深度学习（目标检测+语义分割）方法。同时涉及Apollo，Autoware(基于ros2)，BEV感知，三维重建，SLAM(视觉+激光雷达) ，模型压缩（蒸馏+剪枝+量化等），自动驾驶模拟仿真，自动驾驶数据集标注&数据闭环等自动驾驶全栈技术，欢迎扫码二维码加入，一起登顶自动驾驶的高峰！
![image](https://github.com/HuangCongQing/HuangCongQing/assets/20675770/304e0c4d-89d2-4cee-a2a9-3c690611c9d9)


## 编译和运行
```
// 1 设置工作空间
cd catkin_wp/src
catkin_init_workspace

// 编译（需要回到工作空间catkin_wp）
cd ..
catkin_make  // 产生build和devel文件夹（类似cmake）
catkin_make install // 就会有install文件夹

//设置环境变量（个人是zsh）
source devel/setup.zsh  // 不同shell，不同哦.bash  .zsh

通过设置gedit ~/.zshrc，不用每次都source
gedit ~/.zshrc   或者  gedit ~/.bashrc
source ~/.zshrc  或者 source ~/.bashrc
```



```shell
//2 创建功能包(src文件夹下)
//创建包 catkin_create_pkg 包名 依赖1 依赖2 
cd src
catkin_create_pkg test_pkg std_msgs roscpp rospy

// 编译功能包(回到目录catkin_ws)
catkin_make
// 设置环境变量(能让系统找到我们的工作空间和功能包) 此命令只在当前终端生效
source devel/setup.bash

通过设置gedit ~/.zshrc，不用每次都source
gedit ~/.zshrc
source ~/.zshrc

// 运行
roscore //启动ROS master
rosrun turtlesim(功能包名) turtlesim_node(节点名) //rosrun启动节点，该节点归属于功能包，这个节点就是小海龟仿真器
rosrun turtlesim turtle_teleop_key
```

## ROS介绍

>作者：Morgan  其博士生导师：吴恩达!

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
> PDF路径: **[slides-ros_21_tutorials](slides-ros_21_tutorials)**
>视频：https://www.bilibili.com/video/BV1zt411G7Vn

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



#### 2 中科院软件所-机器人操作系统入门（ROS入门教程)(**推荐先看，讲的更细致**) 【推荐入门先看】
官方代码: https://github.com/DroidAITech/ROS-Academy-for-Beginners
个人fork代码：https://github.com/HuangCongQing/ROS-Academy-for-Beginners
>本地学习 代码路径: **[catkin_academy/src](catkin_academy/src)**
>视频：https://www.bilibili.com/video/BV1mJ411R7Ni


#### 3 机器人操作系统ROS理论与实践【9讲】

> 代码路径: **[catkin_ROS9/src](catkin_ROS9/src)**
> PDF路径: **[机器人操作系统ROS理论与实践](机器人操作系统ROS理论与实践)**

* [1：认识ROS](机器人操作系统ROS理论与实践/1：认识ROS)
* [2：ROS基础](机器人操作系统ROS理论与实践/2：ROS基础)
* [3：机器人系统设计](机器人操作系统ROS理论与实践/3：机器人系统设计)
* [4：机器人仿真](机器人操作系统ROS理论与实践/4：机器人仿真)
* [5：机器人感知](机器人操作系统ROS理论与实践/5：机器人感知)
* [6：机器人SLAM与自主导航](机器人操作系统ROS理论与实践/6：机器人SLAM与自主导航)
* [7：ROS理论与实践Moveit](机器人操作系统ROS理论与实践/7：ROS理论与实践Moveit)
* [8：ROS机器人综合应用](机器人操作系统ROS理论与实践/8：ROS机器人综合应用)
* [9：ROS2.0](机器人操作系统ROS理论与实践/9：ROS2.0)


Tips： **注意不同ROS，切换到不同分支**
* kinetic版本切换到kinetic分支
* melodic版本切换到melodic分支


#### 4 可视化（Visualization）

code:
* [catkin_wp/src/learning_visualization](catkin_wp/src/learning_visualization)


```shell

rosrun learning_visualization 1basic_shapes
rosrun learning_visualization 2points_and_lines
rosrun learning_visualization 3path


```


## ROS组织结构

一个workspace下面可以有多个package，但是workspace有自己组织package的方式。每一个package都是workspace当中的代码包，应该存放在src下面。那么，组织结构如下所示：

```
---workspace
|   |---src
|      |---package_1
|         |---CMakeLists.txt
|         |---src
|             |---xxx.cpp
       |---package_2
...
|
|      |---package_n
```
## Reference
### 书籍：《ROS机器人开发实践_胡春旭》
* 《ROS机器人开发实践》源码：https://github.com/huchunxu/ros_exploring

### 视频和代码
* 1 古月 · ROS入门21讲
* 2 中科院软件所-机器人操作系统入门（ROS入门教程
* 3 机器人操作系统ROS理论与实践【9讲】

#### 1 古月 · ROS入门21讲
视频：https://www.bilibili.com/video/BV1zt411G7Vn

课件：https://github.com/huchunxu/ros_21_tutorials/tree/master/docs/slides

源码：https://github.com/huchunxu/ros_21_tutorials

* [个人代码](https://github.com/HuangCongQing/ROS/tree/master/catkin_wp/src)



#### 2 中科院软件所-机器人操作系统入门（ROS入门教程）

* 视频：https://www.bilibili.com/video/BV1mJ411R7Ni


#### 3 机器人操作系统ROS理论与实践【9讲】


---


微信公众号：**【双愚】**（huang_chongqing） 聊科研技术,谈人生思考,欢迎关注~

![image](https://user-images.githubusercontent.com/20675770/169835565-08fc9a49-573e-478a-84fc-d9b7c5fa27ff.png)

**往期推荐：**
1. [本文不提供职业建议，却能助你一生](https://mp.weixin.qq.com/s/rBR62qoAEeT56gGYTA0law)
2. [聊聊我们大学生面试](https://mp.weixin.qq.com/s?__biz=MzI4OTY1MjA3Mg==&mid=2247484016&idx=1&sn=08bc46266e00572e46f3e5d9ffb7c612&chksm=ec2aae77db5d276150cde1cb1dc6a53e03eba024adfbd1b22a048a7320c2b6872fb9dfef32aa&scene=178&cur_album_id=2253272068899471368#rd)
3. [清华大学刘知远：好的研究方法从哪来](https://mp.weixin.qq.com/s?__biz=MzI4OTY1MjA3Mg==&mid=2247486340&idx=1&sn=6c5f69bb37d91a343b1a1e7f6929ddae&chksm=ec2aa783db5d2e95ba4c472471267721cafafbe10c298a6d5fae9fed295f455a72f783872249&scene=178&cur_album_id=1855544495514140673#rd)


