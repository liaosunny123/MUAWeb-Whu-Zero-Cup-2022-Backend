//
// Created by epicmo on 22-10-26.
//
#include "Search.h"
#include "DataController.h"
void Search::co(JsonModels::Search::Search &&pSearch, std::function<void(const HttpResponsePtr &)> &&callback,
               std::string q) const {
    int length;
    Model::Passage* Passage = DataController::search(q,length);
    Json::Value json;
    for(int i = 0;i < length;i++){
        Json::Value jsons;
        jsons["index"] = Passage[i].pid;
        jsons["name"] = Passage[i].author;
        jsons["author"] = Passage[i].author;
        jsons["time"] = Passage[i].datetime;
        jsons["category"] = Passage[i].category;
        json["Passage"][i] = jsons;
    }
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}