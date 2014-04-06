#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

struct Timer
{
	LARGE_INTEGER t1, t2;

	Timer()
	{
		t1.QuadPart = 0;
		t2.QuadPart = 0;
	}
};

class Timer_Manager
{
private:
	std::map<std::string, Timer> Timers;
	std::map<std::string, Timer>::iterator Timers_It;

	static void AddTimerToMap(std::string Name, Timer newTimer);

	static bool CheckTimersForInstance(std::string Name);

	Timer_Manager();

	Timer_Manager(Timer_Manager const&);

	void operator = (Timer_Manager const&);

	LARGE_INTEGER Frequency;

public:
	static Timer_Manager& Instance();

	static bool CreateNewTimer(std::string Name);

	static bool GetStartTime(std::string Name);

	static bool GetStopTime(std::string Name);

	static bool GetElapsedTime(std::string Name, double &Time);
};

#endif