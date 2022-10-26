#pragma once
#include "jsonmodels/SchoolModels.h"
#include <drogon/HttpController.h>

using namespace drogon;
using namespace MUAWeb;
class School : public drogon::HttpController<School>
{
  public:
    METHOD_LIST_BEGIN
        METHOD_ADD(School::GetSchoolList, "/getSchoolList", Get);
        METHOD_ADD(School::GetSchoolContent, "/getSchoolContent/{pid}", Get);
        METHOD_ADD(School::CreateSchool, "/createSchool", Post);
        METHOD_ADD(School::RemoveSchool, "/removeSchool", Post);
    METHOD_LIST_END
    void GetSchoolList(JsonModels::School::GetSchoolList &&pGetSchoolList , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void GetSchoolContent(JsonModels::School::GetSchoolContent &&pGetSchoolContent , std::function<void (const HttpResponsePtr &)> &&callback,std::string pid) const;
    void CreateSchool(JsonModels::School::CreateSchool &&pCreateSchool , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void RemoveSchool(JsonModels::School::RemoveSchool &&pRemoveSchool , std::function<void (const HttpResponsePtr &)> &&callback) const;

};
