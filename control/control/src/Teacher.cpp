/*
* @Author: Matttteo
* @Date:   2016-11-11 10:55:29
* @Last Modified by:   Matttteo
* @Last Modified time: 2016-11-11 15:15:27
*/

#include "Teacher.h"

void Teacher::Run(){
	while(1){
		if(HasRequestStart()() && IsStopped()){
			Start();
			continue;
		}
		if(HasRequestStop() && OnTeaching()){
			Stop();
			continue;
		}
		if(OnTeaching()){
			RequestRecord();
			continue;
		}
	}
}
void Teacher::RequestRecord(){
	//TODO...
}

bool Teacher::IsFinished(){
	unique_lock<mutex> lock(mMutexStop);
	unique_lock<mutex> lock(mMutexHasKnowledge);
	return(mbStopped && mbHasKnowledge);
}

bool Teacher::HasRequestStop(){
	unique_lock<mutex> lock(mMutexStop);
	return mbStoppedRequest;
}

bool Teacher::HasRequestStart(){
	unique_lock<mutex> lock(mMutexStart);
	return mbStartRequest;
}

bool Teacher::IsStopped(){
	unique_lock<mutex> lock(mMutexStop);
	return mbStopped;
}

bool Teacher::OnTeaching(){
	unique_lock<mutex> lock(mMutexOnTeaching);
	return mbOnTeaching;
}

void Teacher::Start(){
	unique_lock<mutex> lock(mMutexStop);
	mbStopped = false;
	unique_lock<mutex> lock<mMutexStart>
	mbStart = true;
	StartTeaching();
}

void Teacher::StartTeaching(){
	unique_lock<mutex> lock(mMutexOnTeaching);
	mbOnTeaching = true;
}
