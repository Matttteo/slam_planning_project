#ifndef ROBOTACTION_H
#define ROBOTACTION_H


class RobotAction
{
    public:
        enum ACTION_TIME{
            STOP = -1;
            MOVE_ONE_TIME = 0;
            MOVE_SEVERL_TIME = 1;
            PERSIST = 2;
        }
        RobotAction();
        virtual ~RobotAction();

    protected:

    private:
};

#endif // ROBOTACTION_H
