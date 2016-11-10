#include "Configuration.h"

Configuration::Configuration()
{
    //ctor
}

Configuration::~Configuration()
{
    //dtor
}
static std::shared_ptr<Configuration> Configuration::GetConfigInstance(){
    if(config == nullptr){
        config = std::make_shared<Configuration>(Configuration());
    }
    return config;
}
