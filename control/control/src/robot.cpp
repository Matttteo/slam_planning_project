#include "robot.h"

Robot::Robot()
{
    //ctor
}

Robot::~Robot()
{
    //dtor
}


bool Robot::Init(){
    slamSystem = GetSLAMInstance();
    planningSystem = GetPlanningInstance();
    action = GetActionInstance();
    state = GetRobotStateInstance();
    teacher = GetTeacherInstance();
}

bool Robot::StartSLAM(){
    if(!slamSystem->Init()){
        std::cout << "SLAM system not initial success ..." << std::endl;
        return false;
    }
    mptSLAM = std::make_shared<thread>(*(new thread(&SLAM::Run(), slamSystem.get())));
    return true;
}

bool Robot::StartPlanning(){
    if(!planningSystem->Init()){
        std::cout << "Planning system not initial success ..." << std::endl;
        return false;
    }
    if(!teacher->IsFinished()){
        std::cout << "Planning system not teached ... " << std::endl;
        return false;
    }
    mptPlanning = std::make_shared<thread>(*(new thread(&Planning::Run(), planningSystem.get())));
    return true;
}

void Robot::StartTeaching(){
    teacher->RequestStart();
}

static std::shared_ptr<Robot> Robot::getRobot(){
    if(robot == nullptr){
        robot = std::make_shared<Robot>(Robot());
    }
    return robot;
}



static std::shared_ptr<SLAM> Robot::GetSLAMInstance(){
    if(slamSystem == nullptr){
        slamSystem = std::make_shared<SLAM>(SLAM())
    }
    return slamSystem;
}

static std::shared_ptr<Planning> Robot::GetPlanningInstance(){
    if(planningSystem == nullptr){
        planningSystem = std::make_shared<Planning>(Planning())
    }
    return planningSystem;
}

static std::shared_ptr<Action> Robot::GetActionInstance(){
    if(action == nullptr){
        action = std::make_shared<Action>(Action())
    }
    return action;
}
static std::shared_ptr<RobotState> Robot::GetRobotStateInstance(){
    if(state == nullptr){
        state = std::make_shared<RobotState>(RobotState())
    }
    return state;
}

static std::shared_ptr<Teacher> Robot::GetTeacherInstance(){
    if(teacher == nullptr){
        teacher == std::make_shared<Teacher>(Teacher());
    }
    return teacher;
}