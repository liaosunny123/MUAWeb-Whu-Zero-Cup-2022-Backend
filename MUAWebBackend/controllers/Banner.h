#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class Banner : public drogon::HttpController<Banner>
{
  public:
    METHOD_LIST_BEGIN

    METHOD_LIST_END
    
};
