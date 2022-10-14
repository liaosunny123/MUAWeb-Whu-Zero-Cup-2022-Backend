//
// Created by epicmo on 22-10-14.
//

#ifndef MAIN_CC_DATACONTROLLER_H
#define MAIN_CC_DATACONTROLLER_H
#include <iostream>
#include "User.h"
#include "Passage.h"
#include "School.h"
namespace MUAWeb{
    class DataController{
    public:
        //User:
        static std::string getPassword(std::string);
        static User getUser(std::string);
        static void addUser(User);
        static void removeUser(User);
        static void editPassword(User,std::string);
        //Passage:
        static void addPassage(Model::Passage);
        static void removePassage(Model::Passage);
        static Model::Passage getPassage(int);
        static void getPassageNumber(Model::Category);
        static Model::Passage* getFullPassage(Model::Category,int);
        //School:
        static void addSchool(Model::School);
        static void removeSchool(Model::School);
        static Model::School getSchool(int);
        static void getSchoolNumber();
        static Model::School* getFullSchool(Model::School,int);
    };
}
#endif //MAIN_CC_DATACONTROLLER_H
