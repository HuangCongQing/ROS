# ROS
机器人操作系统

* 运行环境：Ubuntu18.04 微软云服务器（AzureUser@aitraining）


* ROS & SLAM个人笔记：https://www.yuque.com/huangzhongqing/ld627o



## ROS介绍

作者：Morgan  博士生导师：吴恩达
ROS2：一开始只是学术界，后面成为机器人领域的普遍标准，很多设计上的局限性和问题暴露出来，所以需要改良到工业界。
别人已经早好轮子，集成起来，提高软件复用率。
有的组织擅长建模，OR导航 OR物理识别，ROS就可以把这些组织都连接起来，帮助他们建立一种相互合作的的高效的方式，在已有成果做更多东西。

1. 节点 节点管理器（婚介所）
2. 话题&服务

两种通信机制：话题和服务
* 话题：发布订阅模型 异步通信机制（单向），话题数据：消息
* 服务：客户端 服务端模型 同步通信机制

![](https://cdn.nlark.com/yuque/0/2020/png/232596/1583747169660-fe70ab3f-7927-45f2-8d8a-651c0d365c41.png)




## Reference
书籍：《ROS机器人开发实践_胡春旭》
### 古月 · ROS入门21讲
课件：https://github.com/huchunxu/ros_21_tutorials/tree/master/docs/slides
源码：https://github.com/huchunxu/ros_21_tutorials

### 机器人操作系统ROS理论与实践【9讲】

