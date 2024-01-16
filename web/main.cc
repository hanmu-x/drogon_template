

#include <drogon/drogon.h>
#include <filesystem>

#include "tp_config.h"

int main() 
{
    ////Set HTTP listener address and port
    //drogon::app().addListener("0.0.0.0",80);
    //Load config file

    std::string web_cfg_name = "web_config.json";
    std::string core_cfg_name = "core_config.json";
#ifndef NDEBUG
    std::filesystem::path web_config(DEFAULT_CONFIG_DIR);
    std::filesystem::path core_config(DEFAULT_CONFIG_DIR);
#else
    std::filesystem::path web_config("./config");
    std::filesystem::path core_config("./config");
#endif
    web_config.append(web_cfg_name);
    core_config.append(core_cfg_name);

    Config::instance().load(core_config.string());

    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().loadConfigFile(web_config.string());
    drogon::app().run();
    return 0;
}

