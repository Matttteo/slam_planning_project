#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <memory>

class Configuration
{
    public:
        /** Default constructor */
        Configuration();
        /** Default destructor */
        virtual ~Configuration();
        static std::shared_ptr<Configuration> GetConfigInstance();
        static std::shared_ptr<Configuration> config;

    protected:

    private:
};

#endif // CONFIGURATION_H
