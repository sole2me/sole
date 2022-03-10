# sole
sole是一个轻量级的工作流和业务流程管理（BPM）平台，基于[TARS](https://github.com/TarsCloud/Tars)框架，面向业务人员、开发人员和系统管理员。 它的核心是基于C++开发的一个超快速和稳定可靠BPMN2过程引擎。它是开源的，在麻省理工学院的许可下发布。sole可以在任何基于tars框架的应用程序、服务器、集群或云中运行。它与Tars框架完美结合的，轻量的，基于简单的概念。

## 支持平台

> * Linux

## 支持语言

> * C、C++、Java、PYthon、NodeJS、PHP

## 快速上手

详见[sole安装文档](docs/install.md)

## 文档

sole接口使用方法请参考文档[sole接口指南](docs/proxy_api_guide.md)，更多文档请查看[docs目录](docs/README.md)

## 目录说明

* ```src```：存储相关的后台服务代码。

目录 |功能
------------------|----------------
src/Utils         |各服务共用的通用代码
src/TarsComm      |内部Tars协议
src/Parser        |sole语法解析器
src/Grammar       |sole语法分析器
src/Engine        |sole运行时引擎
src/DataServer    |数据中心服务
src/FlowServer    |数据流服务
src/WorkServer    |控制流服务
src/EventServer   |事件服务

* ```docs```：文档。

## 参与贡献

如果你有任何想法，别犹豫，立即提 Issues 或 Pull Requests，欢迎所有人参与到sole的开源建设中。<br>详见：[CONTRIBUTING.md](./CONTRIBUTING.md)

