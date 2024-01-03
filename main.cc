

#include <drogon/drogon.h>

int main() 
{
    ////Set HTTP listener address and port
    //drogon::app().addListener("0.0.0.0",80);
    //Load config file

#ifdef NDEBUG
    drogon::app().loadConfigFile("./config.json");
#else
    drogon::app().loadConfigFile("../../../config.json");
#endif
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}


//请求地址:127.0.0.1:8080/check_ctrl/check_time