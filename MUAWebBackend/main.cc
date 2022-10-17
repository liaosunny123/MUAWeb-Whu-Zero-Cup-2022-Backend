#include <drogon/drogon.h>
#include "IntilizeController.h"
int main() {
    //监听HTTP链接地址
    LOG_INFO << "MUAWeb is running on targeted url:port";
    drogon::app().addListener("0.0.0.0",30001);
    //载入CONFIG文件
    LOG_INFO << "MUAWeb loaded ../config.json";
    drogon::app().loadConfigFile("../config.json");
    //判断MUAWeb是否能载入自身的CONFIG文件，以及完成初始化
    LOG_INFO << "MUAWeb has intilized.";
    if (!MUAWeb::IntilizeController::Intilize())
        return 1;
    //服务器运行
    LOG_INFO << "MUAWeb is running.";
    drogon::app().run();
    //清空缓存池子
    LOG_INFO << "MUAWeb is trying to clear all the User Token in the pour.";
    MUAWeb::IntilizeController::EndRun();
    return 0;
}
