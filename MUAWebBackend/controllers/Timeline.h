#pragma once

#include <drogon/HttpController.h>
#include "jsonmodels/TimelineModels.h"
using namespace drogon;
using namespace MUAWeb;
class Timeline : public drogon::HttpController<Timeline>
{
  public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Timeline::CreateTimeline, "/createTimeline", Post);
        METHOD_ADD(Timeline::GetTimeline, "/getTimeline", Get);
        METHOD_ADD(Timeline::RemoveTimeline, "/removeTimeline", Post);
    METHOD_LIST_END
    void CreateTimeline(JsonModels::Timeline::CreateTimeline &&pCreateTimeline , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void RemoveTimeline(JsonModels::Timeline::RemoveTimeline &&pRemoveTimeline , std::function<void (const HttpResponsePtr &)> &&callback) const;
    void GetTimeline(JsonModels::Timeline::GetTimeline &&pGetTimeline , std::function<void (const HttpResponsePtr &)> &&callback) const;

};
