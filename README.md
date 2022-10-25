# MUAWebBackend  
The WebBackend for MUA.  
The program which is going to be handed in competition is developed by 2022 new WHU Student.  
# Dir Tree  
- models: DataModels and head file of fuction.  
- app: Application of Backend.  
- controllers: Controllers of Backend.  
- test: Test for backend server. 
# Prepare environment  
```bash
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
make && sudo make install
```  
Beyond that, please confirm that you have following libs:libs:g++,gcc,cmake,libjsoncpp-dev,uuid-dev,openssl,libssl-dev,zlib1g-dev and boost.  
# How to run it  
After you make it , you can use ".\MUAWeb" to run it.
# Environment of the production  
You should edit database.json in your production dir.  
The format of json is:  
```json
{
    "DBUrl": "127.0.0.1",
    "DBPort": 3306,
    "DBUser": "user",
    "DBPassword": "passwd",
    "DBTable": "MUAweb",
    "DBType": "MYSQL",
}
```
Besides that, you should import SQL from dir "SQL".  
Please note that this project can only support MYSQL (Version above 8.0) in current version.  
If MUAweb cannot connect SQLServer according to your config, the program will be stoped.  
# Welcome PR  
You can PR to this project, but you should make sure your project based on original code style.  
