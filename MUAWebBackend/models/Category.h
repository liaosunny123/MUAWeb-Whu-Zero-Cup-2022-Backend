//
// Created by epicmo on 22-10-14.
//

#ifndef MUAWEBBACKEND_CATEGORY_H
#define MUAWEBBACKEND_CATEGORY_H
namespace MUAWeb::Model{
    enum Category{
        SchoolDescription,
        ProjectDescription,
        RebuildDescription,
        ActivityDescription,
        OthersDescription,
    };
    enum DatabaseType{
        Oracle,
        Mysql,
        SQLite,
    };
}
#endif //MUAWEBBACKEND_CATEGORY_H
