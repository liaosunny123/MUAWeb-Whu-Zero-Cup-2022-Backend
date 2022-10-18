#include <drogon/drogon.h>
#include "IntilizeController.h"
#include "TokenListener.h"
#include <thread>
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
    //创建Token钩子
    std::thread TokenListener(MUAWeb::TokenListener::startListenerProcess);
    TokenListener.detach();
    //服务器运行
    LOG_INFO << "MUAWeb is running.";
    drogon::app().run();
    //清空Token钩子
    //MUAWeb::TokenListener::endListenerProcess();
    //清空缓存池子
    LOG_INFO << "MUAWeb is trying to clear all the User Token in the pour.";
    MUAWeb::IntilizeController::EndRun();
    return 0;
}
