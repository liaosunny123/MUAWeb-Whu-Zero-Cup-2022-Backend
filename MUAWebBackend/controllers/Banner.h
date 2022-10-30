#pragma once

#include <drogon/HttpController.h>
#include "jsonmodels/BannerModels.h"
using namespace drogon;
using namespace MUAWeb;
class Banner : public drogon::HttpController<Banner>
{
  public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Banner::CreateBanner, "/createBanner", Post);
        METHOD_ADD(Banner::GetBanner, "/getBanner/{position}", Get);
        METHOD_ADD(Banner::RemoveBanner, "/removeBanner", Post);
    METHOD_LIST_END
    void CreateBanner(JsonModels::Banner::CreateBanner &&pCreateBanner , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void RemoveBanner(JsonModels::Banner::RemoveBanner &&pRemoveBanner , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void GetBanner(JsonModels::Banner::GetBanner &&pGetBanner , std::function<void (const HttpResponsePtr &)> &&callback,std::string position) const;
};
