//
// Created by epicmo on 22-10-30.
//

#ifndef MAIN_CC_BANNERMODELS_H
#define MAIN_CC_BANNERMODELS_H
#include <iostream>
#include <drogon/HttpRequest.h>

namespace MUAWeb::JsonModels::Banner{
    struct CreateBanner{
        std::string username;
        std::string token;
        std::string img;
        std::string position;
    };
    struct RemoveBanner{
        std::string username;
        std::string token;
        int pid;
        std::string position;
    };
    struct GetBanner{

    };
}
namespace drogon{
    template <>
    inline MUAWeb::JsonModels::Banner::CreateBanner fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::Banner::CreateBanner banner;
        if (json){
            banner.username = (*json)["username"].asString();
            banner.token = (*json)["token"].asString();
            banner.img = (*json)["img"].asString();
            banner.position = (*json)["position"].asString();
        }
        return banner;
    }
    template <>
    inline MUAWeb::JsonModels::Banner::RemoveBanner fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::Banner::RemoveBanner banner;
        if (json){
            banner.username = (*json)["username"].asString();
            banner.token = (*json)["token"].asString();
            banner.pid = (*json)["pid"].asInt();
            banner.position = (*json)["position"].asString();
        }
        return banner;
    }
    template <>
    inline MUAWeb::JsonModels::Banner::GetBanner fromRequest(const HttpRequest &req){
        MUAWeb::JsonModels::Banner::GetBanner banner;
        return banner;
    }
}
#endif //MAIN_CC_BANNERMODELS_H
