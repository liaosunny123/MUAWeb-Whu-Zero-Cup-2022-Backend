//
// Created by epicmo on 22-10-14.
//

#ifndef MAIN_CC_DATACONTROLLER_H
#define MAIN_CC_DATACONTROLLER_H
#include <iostream>
#include "mysql/mysql.h"
#include "User.h"
#include "Passage.h"
#include "School.h"
#include "Banner.h"
#include "Timeline.h"

namespace MUAWeb{
    class DataController{
    public:
        //SQL:
        static bool connectSQL(MYSQL &);
        //User:
        static std::string getPassword(std::string);
        static User getUser(std::string);
        static void addUser(User);
        static void removeUser(User);
        static void editPassword(User,std::string);
        //Passage:
        static void addPassage(const Model::Passage&);
        static void removePassage(const Model::Passage&);
        static Model::Passage getPassage(Model::Category,int);
        static int getPassageNumber(Model::Category);
        static Model::Passage* getFullPassageList(Model::Category category, int &);
        //School:
        static void addSchool(const Model::School&);
        static void removeSchool(const Model::School&);
        static Model::School getSchool(int);
        static int getSchoolNumber();
        static Model::School* getFullSchoolList(int &);
        //Search:
        static Model::Passage* search(std::string,int &);
        //Banner:
        static void createBanner(std::string position,std::string img);
        static void removeBanner(int pid);
        static int getBannerNumber(std::string position);
        static Model::Banner* getBanner(std::string position,int& length);
        //Timeline:
        static void createTimeline(std::string name,std::string description,std::string time);
        static void removeTimeline(int pid);
        static int getTimelineNumber();
        static Model::Timeline* getTimeline(int& length);

    };
}
#endif //MAIN_CC_DATACONTROLLER_H
