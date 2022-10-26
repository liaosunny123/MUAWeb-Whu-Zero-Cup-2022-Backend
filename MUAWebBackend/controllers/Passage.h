#pragma once
#include "jsonmodels/PassageModels.h"
#include <drogon/HttpController.h>

using namespace drogon;
using namespace MUAWeb;
class Passage : public drogon::HttpController<Passage>
{
    public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Passage::GetPassageList, "/getPassageList/{category}", Get);
        METHOD_ADD(Passage::GetPassageContent, "/getPassageContent/{category}/{pid}", Get);
        METHOD_ADD(Passage::CreatePassage, "/createPassage", Post);
        METHOD_ADD(Passage::RemovePassage, "/removePassage", Post);
    METHOD_LIST_END
    void GetPassageList(JsonModels::Passage::GetPassageList &&pGetPassageList , std::function<void (const HttpResponsePtr &)> &&callback,std::string category) const;
    void GetPassageContent(JsonModels::Passage::GetPassageContent &&pGetPassageContent , std::function<void (const HttpResponsePtr &)> &&callback,std::string category,std::string pid) const;
    void CreatePassage(JsonModels::Passage::CreatePassage &&pCreatePassage , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void RemovePassage(JsonModels::Passage::RemovePassage &&pRemovePassage , std::function<void (const HttpResponsePtr &)> &&callback) const;
};
