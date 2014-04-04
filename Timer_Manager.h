#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

struct Timer
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double ElapsedTime;

	Timer()
	{
		frequency.QuadPart = 0;
		t1.QuadPart = 0;
		t2.QuadPart = 0;
		ElapsedTime = 0;
	}
};

class Timer_Manager
{
private:
	std::map<std::string, Timer> Timers;
	std::map<std::string, Timer>::iterator Timers_It;

	void AddTimerToMap(std::string Name, Timer newTimer);

	bool CheckTimersForInstance(std::string Name);

public:
	bool CreateNewTimer(std::string Name);

	bool GetPerformanceFrequency(std::string Name);

	bool GetStartTime(std::string Name);

	bool GetStopTime(std::string Name);

	bool CalculateElapsedTime(std::string Name);

	bool GetElapsedTime(std::string Name, double &Time);
};

#endif