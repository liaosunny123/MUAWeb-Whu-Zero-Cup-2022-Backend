# MUAWebBackend  
The WebBackend for MUA.  
The program which is going to be handed in competition is developed by WHU Student.  
# Dir Tree  
- models: DataModels and head file of fuction.  
- app: Application of Backend.  
- controllers: Controller of Backend.  
# How to run it  
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
# Environment of the production  
You should confirm that you have MYSQL (Version above 8.0) to let the server connect to your Database.  
You can edit your database information in MUA.Json which supports basic format.  
