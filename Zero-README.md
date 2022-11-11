# 项目介绍  

- 本次项目分为前端和后端，前端为mua-web-frontend文件夹下内容，后端内容为MUAWebBackend文件夹下内容
- 本次项目方向为“游戏官网”方向，对象为“我的世界”游戏官网MUA WEB
- 介绍：MUA为我的世界全国高校联盟，本作品为为MUA组织进行官网开发

## 后端介绍

### 技术实现

后端框架采用Drogon框架，其中实现了包括用户系统，文章管理系统，学校管理系统等API实现。采用C++语言编写。

### 目录介绍

- app:为具体的细节实现类
- controllers:为控制器类，负责对于HTTP请求的解析
- jsonmodels:为json数据模型类，负责对json请求进行抽象和解析
- models:为模型和函数原型(C++)类

### 技术细节

客户端发起GET/POST请求给服务器，服务器由Controllers对应解析相应的请求，并由JsonResponseService(抽象)负责解析Json数据，并在具体的业务逻辑中将请求分别转发给对应的UserService、PassageService等，由业务逻辑层调用DAO层对数据进行集中处理。同时，对于AUTH，有TokenListener和TokenDIctionary负责对Token类进行管理。

对于DAO层，后端预留了ORM接口，本程序暂时仅为MYSQL实现，且对MYSQL的注入进行了安全模块的编写，对密码传输采用BCryto等安全处理。

后端具有一定的架构性，对JSONERROR采用模板方法的设计思想等，具有可扩展性。

后端具有一定的维护友好性，在程序关键的节点有不同级别的日志输出和定位到源码行数的日志系统。

后端具有HTTPS支持性。

## 前端

前端采用React编写，具有良好的架构性，且为响应式布局。对相关组件进行提取细化，组织结构合理。

src目录下:

- pages：页面
- data：数据
- components：基本组件
- assets：资源

### 库

- vite-plugin-server: Vite 的 SVG React 组件化导入
- vitejs/plugin-react: Vite的React模板库
- typescript: 类型化体验
- nuka-carousel: 轮播图功能控件（所有样式全部重新编写）
- react-responsive: react 响应式库
- ahooks: 常用react hooks库
- axios-hooks: axios 的 react hooks封装
- lottie-react: Lottie的React组件封装
- styled-components: 样式React组件封装

## 搭建

参见子文件夹README说明细节