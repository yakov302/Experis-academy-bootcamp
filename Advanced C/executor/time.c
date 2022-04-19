#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h> 
#include "time.h"
#include "task.h"
#define BILLION 1000000000
#define THOUSAND 1000
#define MILLION 1000000

/**********************getTime***********************/

timespec getTime(clockid_t _clockId)
{
timespec time;

	clock_gettime(_clockId ,&time);

return time;
}

/**********************CalculateNextTime***********************/

timespec CalculateNextTime(size_t _periodTime, clockid_t _clockId)
{
timespec time;
long period;
	
	time = getTime( _clockId);
	period = _periodTime * MILLION;
	time.tv_nsec = (time.tv_nsec + period)%BILLION;
	time.tv_sec = time.tv_sec + (time.tv_nsec + period)/BILLION;
	
return time;
}

/**********************sleepTime***********************/

void sleepTime(timespec _nextRunTime, clockid_t _clockId)
{
timespec time;
long sleepTime;

	time = getTime(_clockId);
	if(TimesDifference(_nextRunTime, time) <= 0) 
	{
		return;
	}

	sleepTime = TimesDifference(_nextRunTime, time)/THOUSAND;
	usleep(sleepTime);
		
return;
}

/**********************TimesDifference***********************/

long TimesDifference(timespec _time1, timespec _time2)
{
long secDif;
long nanoDif;
	
	if(_time1.tv_nsec - _time2.tv_nsec < 0)
	{
		nanoDif = _time1.tv_nsec + BILLION -  _time2.tv_nsec;
		secDif = _time1.tv_sec - 1 - _time2.tv_sec;
	}
	else
	{
		nanoDif = _time1.tv_nsec  -  _time2.tv_nsec;
		secDif = _time1.tv_sec  - _time2.tv_sec;	
	}
	
return secDif*BILLION + nanoDif;	
}


