#include "Timer_Manager.h"

Timer_Manager::Timer_Manager()
{
	QueryPerformanceFrequency(&Instance().Frequency);
}

Timer_Manager& Timer_Manager::Instance()
{
	static Timer_Manager Time;
	return Time;
}

void Timer_Manager::AddTimerToMap(std::string Name, Timer newTimer)
{
	Instance().Timers.insert(std::pair<std::string, Timer>(Name, newTimer));
}

bool Timer_Manager::CheckTimersForInstance(std::string Name)
{
	bool Success = false;
	for (Instance().Timers_It = Instance().Timers.begin(); Instance().Timers_It != Instance().Timers.end(); ++Instance().Timers_It)
	{
		if ((*Instance().Timers_It).first == Name)
		{
			Success = true;
			break;
		}
	}
	return Success;
}

bool Timer_Manager::CreateNewTimer(std::string Name)
{
	bool Success = false;
	if (Instance().CheckTimersForInstance(Name) == false)
	{
		Timer Temp;
		Instance().AddTimerToMap(Name, Temp);
		Success = true;
	}
	return Success;
}

bool Timer_Manager::GetStartTime(std::string Name)
{
	// Set t1 to start time
	bool Success = false;
	if (Instance().CheckTimersForInstance(Name) == true)
	{
		QueryPerformanceCounter(&(*Instance().Timers_It).second.t1);
		Success = true;
	}
	return Success;
}

bool Timer_Manager::GetStopTime(std::string Name)
{
	// Set t2 to stp time
	bool Success = false;
	if (Instance().CheckTimersForInstance(Name) == true)
	{
		QueryPerformanceCounter(&(*Instance().Timers_It).second.t2);
		Success = true;
	}
	return Success;
}

bool Timer_Manager::GetElapsedTime(std::string Name, double &Time)
{
	bool Success = false;
	if (Instance().CheckTimersForInstance(Name) == true)
	{
		Time = ((*Instance().Timers_It).second.t2.QuadPart - (*Instance().Timers_It).second.t1.QuadPart) * 1000.0 / Instance().Frequency.QuadPart;
		Success = true;
	}
	return Success;
}