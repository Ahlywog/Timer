#include "Timer_Manager.h"

void Timer_Manager::AddTimerToMap(std::string Name, Timer newTimer)
{
	Timers.insert(std::pair<std::string, Timer>(Name, newTimer));
}

bool Timer_Manager::CheckTimersForInstance(std::string Name)
{
	bool Success = false;
	for (Timers_It = Timers.begin(); Timers_It != Timers.end(); ++Timers_It)
	{
		if ((*Timers_It).first == Name)
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
	if (CheckTimersForInstance(Name) == false)
	{
		Timer Temp;
		AddTimerToMap(Name, Temp);
		Success = true;
	}
	return Success;
}

bool Timer_Manager::GetPerformanceFrequency(std::string Name)
{
	// get ticks per second
	bool Success = false;
	if (CheckTimersForInstance(Name) == true)
	{
			QueryPerformanceFrequency(&(*Timers_It).second.frequency);
			Success = true;
	}
	return Success;
}

bool Timer_Manager::GetStartTime(std::string Name)
{
	// Set t1 to start time
	bool Success = false;
	if (CheckTimersForInstance(Name) == true)
	{
			QueryPerformanceCounter(&(*Timers_It).second.t1);
			Success = true;
	}
	return Success;
}

bool Timer_Manager::GetStopTime(std::string Name)
{
	// Set t2 to stp time
	bool Success = false;
	if (CheckTimersForInstance(Name) == true)
	{
			QueryPerformanceCounter(&(*Timers_It).second.t2);
			Success = true;
	}
	return Success;
}

bool Timer_Manager::CalculateElapsedTime(std::string Name)
{
	// Elapsed time in Nanoseconds
	bool Success = false;
	if (CheckTimersForInstance(Name) == true)
	{
		(*Timers_It).second.ElapsedTime = ((*Timers_It).second.t2.QuadPart - (*Timers_It).second.t1.QuadPart) * 1000.0 / (*Timers_It).second.frequency.QuadPart;
		Success = true;
	}
	return Success;
}

bool Timer_Manager::GetElapsedTime(std::string Name, double &Time)
{
	bool Success = false;
	if (CheckTimersForInstance(Name) == true)
	{
		Time = (*Timers_It).second.ElapsedTime;
		Success = true;
	}
	return Success;
}