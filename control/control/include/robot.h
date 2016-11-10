#ifndef ROBOT_H
#define ROBOT_H
#include <memory>
#include <iostream>
#include <thread>

class SLAM;
class Planning;
class RobotState;
class RobotAction;
class Config;
class Robot
{
    public:
        /** Default constructor */
        Robot();
        /** Default destructor */
        virtual ~Robot();

        /** @brief (one liner)
          *
          * (documentation goes here)
          */


        bool Init();
        bool StartSLAM();

        static std::shared_ptr<Robot> getRobot();
        //初始化系统元件
        static std::shared_ptr<Config>  GetConfigInstance();
        static std::shared_ptr<SLAM>  GetSLAMInstance();
        static std::shared_ptr<Planning>  GetPlanningInstance();
        static std::shared_ptr<RobotAction> GetActionInstance();
        static std::shared_ptr<RobotState> GetRobotStateInstance();


    protected:

    private:
        static std::shared_ptr<Robot> robot;
        //系统元件
        static std::shared_ptr<Config> config;//VO路径，相机参数路径，硬件信息等
        static std::shared_ptr<SLAM> slamSystem;// SLAM 算法系统
        static std::shared_ptr<Planning> planningSystem;// Planning 算法系统
        static std::shared_ptr<RobotAction> action;//
        static std::shared_ptr<RobotState> state;

        //SLAM 主线程
        std::shared_ptr<std::thread> mptSLAM;
        //Planning 主线程
        std::shared_ptr<std::thread> mptPlanning;

};

#endif // ROBOT_H
