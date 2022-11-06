//
// Created by epicmo on 22-10-14.
//
#include <mysql/mysql.h>
#include <trantor/utils/Logger.h>
#include "Utility.h"
#include <utility>
#include "DataController.h"
#include "MySQLParameter.h"
#include "TokenDictionary.h"
#include "IntilizeController.h"
namespace MUAWeb {
    bool DataController::connectSQL(MYSQL &mysql) {
        mysql_init(&mysql);
        return mysql_real_connect(&mysql,
                                  IntilizeController::DBUrl.c_str(),
                                  IntilizeController::DBUser.c_str(),
                                  IntilizeController::DBPassword.c_str(),
                                  IntilizeController::DBTable.c_str(),
                                  IntilizeController::DBPort,
                                  nullptr,
                                  0);
    }

    std::string DataController::getPassword(std::string username) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("SELECT passwd FROM `user` WHERE username = '@username';");
        mySqlParameter->addParameter("@username", std::move(username));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        MYSQL_RES *result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        if (row != nullptr) {
            mysql_free_result(result);
            mysql_close(&mysql);
            return row[0];
        } else {
            mysql_free_result(result);
            mysql_close(&mysql);
            return Utility::generateUnsignedUUID();
        }
    }

    User DataController::getUser(std::string username) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("SELECT * FROM `user` WHERE username = '@username';");
        mySqlParameter->addParameter("@username", std::move(username));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        auto result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        if (row != nullptr) {
            User *user = new User(row[0], row[1]);
            mysql_free_result(result);
            mysql_close(&mysql);
            return *user;
        } else {
            mysql_free_result(result);
            mysql_close(&mysql);
            return *(new User());
        }
    }

    void DataController::addUser(User user) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("INSERT INTO `user` VALUES('@username','@password');");
        mySqlParameter->addParameter("@username", user.getUsername());
        mySqlParameter->addParameter("@password", user.getPassword());
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    void DataController::removeUser(User user) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("DELETE FROM `user` where username = '@username';");
        mySqlParameter->addParameter("@username", user.getUsername());
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    void DataController::editPassword(User user, std::string newpassword) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter(
                "UPDATE `user` SET passwd='@newpassword' where username='@username';");
        mySqlParameter->addParameter("@username", user.getUsername());
        mySqlParameter->addParameter("@newpassword", std::move(newpassword));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    //Passage:
    void DataController::addPassage(const Model::Passage &passage) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter(
                "INSERT INTO '@category' VALUES(NULL,'@title','@content','@editor','@time'");
        mySqlParameter->addParameter("@title", passage.title);
        mySqlParameter->addParameter("@content", passage.content);
        mySqlParameter->addParameter("@editor", passage.author);
        mySqlParameter->addParameter("@time", passage.datetime);
        mySqlParameter->addParameter("@category", Model::CategoryToString(passage.category));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    void DataController::removePassage(const Model::Passage &passage) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("DELETE FROM `@category` where pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(passage.pid));
        mySqlParameter->addParameter("@category", Model::CategoryToString(passage.category));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    Model::Passage DataController::getPassage(Model::Category category, int index) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("SELECT passwd FROM `@category` WHERE pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(index));
        mySqlParameter->addParameter("@category", Model::CategoryToString(category));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        auto result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        if (row != nullptr) {
            auto *passage = new Model::Passage(std::stoi(row[0]), category, row[1], row[2], row[3], row[4]);
            mysql_free_result(result);
            mysql_close(&mysql);
            return *passage;
        } else {
            mysql_free_result(result);
            mysql_close(&mysql);
            return *(new Model::Passage());
        }
    }

    int DataController::getPassageNumber(Model::Category category) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid FROM @category;");
        mySqlParameter->addParameter("@category",Model::CategoryToString(category));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        unsigned long long number = mysql_num_rows(result);
        row = mysql_fetch_row(result);
        mysql_free_result(result);
        mysql_close(&mysql);
        return number;
    }

    Model::Passage *DataController::getFullPassageList(Model::Category category, int &length) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid,title,editor,time FROM @category;");
        mySqlParameter->addParameter("@category", Model::CategoryToString(category));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        length = mysql_num_rows(result);
        row = mysql_fetch_row(result);
        auto *passages = new Model::Passage[length];
        for (int i = 0; i < length; ++i) {
            passages[i].pid = std::stoi(row[0]);
            passages[i].title = row[1];
            passages[i].author = row[2];
            passages[i].datetime = row[3];
            passages[i].category = category;
            if(!(i == length - 1))
                row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        mysql_close(&mysql);
        return passages;
    }

    //School:
    void DataController::addSchool(const Model::School &school) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter(
                "INSERT INTO 'schooldescription' VALUES(NULL,'@title','@content','@url','@editor','@time'");
        mySqlParameter->addParameter("@title", school.title);
        mySqlParameter->addParameter("@content", school.content);
        mySqlParameter->addParameter("@editor", school.author);
        mySqlParameter->addParameter("@time", school.datetime);
        mySqlParameter->addParameter("@url", school.url);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    void DataController::removeSchool(const Model::School &school) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("DELETE FROM `schooldescription` where pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(school.pid));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }

    Model::School DataController::getSchool(int index) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("SELECT passwd FROM `schooldescription` WHERE pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(index));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        auto result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        if (row != nullptr) {
            auto *school = new Model::School(std::stoi(row[0]), row[3], row[1], row[2], row[4], row[5]);
            mysql_free_result(result);
            mysql_close(&mysql);
            return *school;
        } else {
            mysql_free_result(result);
            mysql_close(&mysql);
            return *(new Model::School());
        }
    }

    int DataController::getSchoolNumber() {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid FROM 'schooldescription';");
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;

        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        unsigned long long number = mysql_num_rows(result);
        mysql_free_result(result);
        mysql_close(&mysql);
        return number;
    }
    Model::School *DataController::getFullSchoolList(int &length) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid,title,editor,time,url FROM 'schooldescription';");
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        length = mysql_num_rows(result);
        row = mysql_fetch_row(result);
        auto *schools = new Model::School[length];
        for (int i = 0; i < length; ++i) {
            schools[i].pid = std::stoi(row[0]);
            schools[i].title = row[1];
            schools[i].author = row[2];
            schools[i].datetime = row[3];
            schools[i].url = row[4];
            if(!(i == length - 1))
                row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        mysql_close(&mysql);
        return schools;
    }

    Model::Passage* DataController::search(std::string content,int & length){
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid,title,editor,time,'projectdescription'\n"
                                                  "    AS `category` FROM projectdescription where title LIKE '%@content%' or content like '%@content%' UNION SELECT pid,title,editor,time,'rebuilddescription'\n"
                                                  "    AS `percentage` FROM rebuilddescription where title LIKE '%@content%' or content like '%@content%' UNION SELECT pid,title,editor,time,'activitydescription' \n"
                                                  "    AS `percentage` FROM activitydescription where title LIKE '%@content%' or content like '%@content%' UNION SELECT pid,title,editor,time,'othersdescription'\n"
                                                  "    AS `percentage` FROM othersdescription where title LIKE '%@content%' or content like '%@content%';");
        mySqlParameter->addParameter("@content",std::move(content));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        length = mysql_num_rows(result);
        row = mysql_fetch_row(result);
        auto *passages = new Model::Passage[length];
        for (int i = 0; i < length; ++i) {
            passages[i].pid = std::stoi(row[0]);
            passages[i].title = row[1];
            passages[i].author = row[2];
            passages[i].datetime = row[3];
            passages[i].category = Model::StringToCategory(row[4]);
            if(!(i == length - 1))
                row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        mysql_close(&mysql);
        return passages;
    }

    void DataController::createBanner(std::string position,std::string img){
        MYSQL mysql;
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError";
        }
        auto *mySqlParameter = new MySQLParameter("INSERT INTO banner VALUES(NULL,'@img','@position'");
        mySqlParameter->addParameter("@img",std::move(img));
        mySqlParameter->addParameter("@position",std::move(position));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }
    void DataController::removeBanner(int pid){
        MYSQL mysql;
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("DELETE FROM banner where pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(pid));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }
    Model::Banner* DataController::getBanner(std::string position,int& length){
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT * FROM banner WHERE position='@position';");
        mySqlParameter->addParameter("@position", std::move(position));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        length = mysql_num_rows(result);
        row = mysql_fetch_row(result);
        auto *banner = new Model::Banner[length];
        for (int i = 0; i < length; ++i) {
            banner[i].pid = std::stoi(row[0]);
            banner[i].img = row[1];
            banner[i].position = row[2];
            if(!(i == length - 1))
                row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        mysql_close(&mysql);
        return banner;
    }
    //Timeline:
    void DataController::createTimeline(std::string name,std::string description,std::string time){
        MYSQL mysql;
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError";
        }
        auto *mySqlParameter = new MySQLParameter("INSERT INTO timeline VALUES(NULL,'@name','@description','@time'");
        mySqlParameter->addParameter("@img",std::move(name));
        mySqlParameter->addParameter("@position",std::move(description));
        mySqlParameter->addParameter("@time",std::move(time));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }
    void DataController::removeTimeline(int pid){
        MYSQL mysql;
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        auto *mySqlParameter = new MySQLParameter("DELETE FROM timeline where pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(pid));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }else{
            mysql_close(&mysql);
        }
    }
    Model::Timeline* DataController::getTimeline(int& length){
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT * FROM timeline;");
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = nullptr;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        length = mysql_num_rows(result);
        row = mysql_fetch_row(result);
        auto *timeline = new Model::Timeline[length];
        for (int i = 0; i < length; ++i) {
            timeline[i].pid = std::stoi(row[0]);
            timeline[i].name = row[1];
            timeline[i].description = row[2];
            timeline[i].time = row[3];
            if(!(i == length - 1))
                row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        mysql_close(&mysql);
        return timeline;
    }

    int DataController::getBannerNumber(std::string position) {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid FROM banner where position='@position';");
        mySqlParameter->addParameter("@position",std::move(position));
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        unsigned long long number = mysql_num_rows(result);
        mysql_free_result(result);
        mysql_close(&mysql);
        return number;
    }

    int DataController::getTimelineNumber() {
        MYSQL mysql; //mysql连接
        if (!DataController::connectSQL(mysql)){
            LOG_FATAL << "Cannot Carry command for error sql connect!";
            throw "MysqlError.";
        }
        MYSQL_RES *result = nullptr;
        auto *mySqlParameter = new MySQLParameter("SELECT pid FROM timeline;");
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        if (mysql_query(&mysql, sql.c_str())) {
            mysql_free_result(result);
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw;
        }
        result = mysql_store_result(&mysql);
        unsigned long long number = mysql_num_rows(result);
        mysql_free_result(result);
        mysql_close(&mysql);
        return number;
    }
}
