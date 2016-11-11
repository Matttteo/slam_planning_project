#ifndef TEACHER_H
#define TEACHER_H

#include <mutex>


class Teacher
{
public:
	Teacher();
	~Teacher();
	bool Init();

	void Run();
	//Thread synch

	bool Stop();
	void RequestStop();
	bool HasRequestStart();
	bool HasRequestStop();
	bool IsStoped();
	bool RequestStart();
	bool OnTeaching();
	void Start();
	void RequestRecord();
	void StartTeaching();
	//void SetFinish();
	bool IsFinished();

protected:

	bool mbStopped;
	bool mbStoppedRequest;
	bool mbNotStop;
	std::mutex mMutexStop;

	bool mbStarted;
	bool mbStartRequest;
	std::mutex mMutexStart;

	bool mbOnTeaching;
	std::mutex mMutexOnTeaching;

	bool mbHasKnowledge;
	std::mutex mMutexHasKnowledge;
};

#endif //TEACHER_H