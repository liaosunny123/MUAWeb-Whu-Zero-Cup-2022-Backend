//
// Created by epicmo on 22-10-14.
//
#include <mysql/mysql.h>
#include <trantor/utils/Logger.h>
#include "DataController.h"
#include "MySQLParameter.h"
#include "TokenDictionary.h"
namespace MUAWeb{
    std::string DataController::getPassword(std::string username){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("SELECT passwd FROM `user` WHERE username = '@username';");
        mySqlParameter->addParameter("@username",username);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
        row = mysql_fetch_row(mysql_store_result(&mysql));
        if (row != nullptr){
            mysql_close(&mysql);
            return row[0];
        }else{
            mysql_close(&mysql);
            return "";
        }
    }
    User DataController::getUser(std::string username){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("SELECT * FROM `user` WHERE username = '@username';");
        mySqlParameter->addParameter("@username",username);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
        row = mysql_fetch_row(mysql_store_result(&mysql));
        if (row != nullptr){
            User *user = new User(row[0],row[1]);
            mysql_close(&mysql);
            return *user;
        } else{
            mysql_close(&mysql);
            return *(new User());
        }
    }
    void DataController::addUser(User user){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("INSERT INTO `user` VALUES('@username','@password');");
        mySqlParameter->addParameter("@username",user.getUsername());
        mySqlParameter->addParameter("@password",user.getPassword());
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
    }
    void DataController::removeUser(User user){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("DELETE FROM `user` where username = '@username';");
        mySqlParameter->addParameter("@username",user.getUsername());
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
    }
    void DataController::editPassword(User user ,std::string newpassword){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("UPDATE `user` SET passwd='@newpassword' where username='@username';");
        mySqlParameter->addParameter("@username",user.getUsername());
        mySqlParameter->addParameter("@newpassword",newpassword);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
    }
    //Passage:
    void DataController::addPassage(Model::Passage passage){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("INSERT INTO '@category' VALUES(NULL,'@title','@content','@editor','@time'");
        mySqlParameter->addParameter("@title",passage.title);
        mySqlParameter->addParameter("@content",passage.content);
        mySqlParameter->addParameter("@editor",passage.author);
        mySqlParameter->addParameter("@time",passage.datetime);
        mySqlParameter->addParameter("@category",(std::string) (const char *) passage.category);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
    }
    void DataController::removePassage(Model::Passage passage){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("DELETE FROM `@category` where pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(passage.pid));
        mySqlParameter->addParameter("@category",(std::string) (const char *) passage.category);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
    }
    Model::Passage DataController::getPassage(Model::Category category,int index){
        MYSQL mysql; //mysql连接
        MySQLParameter *mySqlParameter = new MySQLParameter("SELECT passwd FROM `@category` WHERE pid = '@pid';");
        mySqlParameter->addParameter("@pid", reinterpret_cast<const char *>(index));
        mySqlParameter->addParameter("@category",(std::string) (const char *) category);
        std::string sql = mySqlParameter->getSQL();
        delete mySqlParameter;
        MYSQL_ROW row = NULL;
        if(mysql_query(&mysql,sql.c_str())){
            mysql_close(&mysql);
            LOG_WARN << "Cannot fetch Mysql Data! SQL:" << sql;
            throw ;
        }
        row = mysql_fetch_row(mysql_store_result(&mysql));
        if (row != nullptr){
            Model::Passage *passage = new Model::Passage((int)(size_t)row[0],category,row[1],row[2],row[3],row[4]);
            mysql_close(&mysql);
            return *passage;
        }else{
            mysql_close(&mysql);
            return *(new Model::Passage());
        }
    }
    void DataController::getPassageNumber(Model::Category){

    }
    Model::Passage* DataController::getFullPassageList(Model::Category){

    }
    //School:
    void DataController::addSchool(Model::School){

    }
    void DataController::removeSchool(Model::School){

    }
    Model::School DataController::getSchool(int){

    }
    void DataController::getSchoolNumber(){

    }
    Model::School* DataController::getFullSchoolList(Model::School){

    }
}