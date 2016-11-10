#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H


class RobotState
{
    enum CONTROL_STATE{
        STOP = -1;
        HUMAN_CONTROL = 0;
        AUTO_CONTROL = 1;
        RANDOM_WALK = 2;
    }
    public:
        /** Default constructor */
        RobotState();
        /** Default destructor */
        virtual ~RobotState();

    protected:

    private:
};

#endif // ROBOTSTATE_H
