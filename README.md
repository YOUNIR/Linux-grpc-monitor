# Linux-grpc-monitor

- 技术栈：Linux，c++，c++常用特性，docker，grpc，protobuf，cmake  

- 项目描述：该项目通过 docker 在多台服务器上部署环境，利用 protobuf 和 grpc 传输服务器性能状况，并采用工厂方法进行实时的分析监控。

- 主要工作：

	1、通过 Dockerfile 指定相关依赖，简化项目在多台服务器上的环境部署。

​       2、采用工厂方法，定义 Monitor 抽象类接口，实现 CPU 使用率、系统负载、软中断等监控，便于后续扩展更多监控项；使用 stress 工具进行模拟压测，分析服务器的 CPU 和中断情况。

​       3、利用 gRPC 框架构建 server 和 client 进行远程连接，server 部署在需要监控的服务器上，client 提供库供 Monitor 模块调用，确保模块间独立，低耦合。

​       4、使用 protobuf 序列化协议，构建出整个项目的数据结构。