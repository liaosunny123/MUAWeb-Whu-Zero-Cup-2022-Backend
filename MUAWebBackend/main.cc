#include <drogon/drogon.h>
#include "IntilizeController.h"
int main() {
    //监听HTTP链接地址
    drogon::app().addListener("0.0.0.0",30001);
    //载入CONFIG文件
    drogon::app().loadConfigFile("../config.json");
    //判断MUAWeb是否能载入自身的CONFIG文件，以及完成初始化
    if (!MUAWeb::IntilizeController::Intilize())
        return 0;
    //服务器运行
    drogon::app().run();
    return 0;
}
