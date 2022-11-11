//
// Created by epicmo on 22-10-30.
//

#ifndef MAIN_CC_TIMELINEMODELS_H
#define MAIN_CC_TIMELINEMODELS_H
#include <iostream>
#include <drogon/HttpRequest.h>

namespace MUAWeb::JsonModels::Timeline{
    struct CreateTimeline{
        std::string username;
        std::string token;
        std::string name;
        std::string description;
        std::string time;
    };
    struct RemoveTimeline{
        std::string username;
        std::string token;
        int pid{};
    };
    struct GetTimeline{

    };
}
namespace drogon{
}
namespace drogon{
    template <>
    inline MUAWeb::JsonModels::Timeline::CreateTimeline fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::Timeline::CreateTimeline timeline;
        if (json){
            timeline.username = (*json)["username"].asString();
            timeline.token = (*json)["token"].asString();
            timeline.name = (*json)["name"].asString();
            timeline.description = (*json)["description"].asString();
            timeline.time = (*json)["time"].asString();
        }
        return timeline;
    }
    template <>
    inline MUAWeb::JsonModels::Timeline::RemoveTimeline fromRequest(const HttpRequest &req){
        const auto& json = req.getJsonObject();
        MUAWeb::JsonModels::Timeline::RemoveTimeline timeline;
        if (json){
            timeline.username = (*json)["username"].asString();
            timeline.token = (*json)["token"].asString();
            timeline.pid = (*json)["pid"].asInt();
        }
        return timeline;
    }
    template <>
    inline MUAWeb::JsonModels::Timeline::GetTimeline fromRequest(const HttpRequest &req){
        MUAWeb::JsonModels::Timeline::GetTimeline timeline;
        return timeline;
    }
}
#endif //MAIN_CC_TIMELINEMODELS_H
