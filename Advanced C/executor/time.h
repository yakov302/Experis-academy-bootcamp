#ifndef __TIME_H__
#define __TIME_H__
#define _POSIX_C_SOURCE 199309L
#include <sys/types.h>
#include <time.h> 

/*RenameToStructTimespec*/

typedef struct timespec timespec;


/*Description:
Returns the current time.

Input:
_clockId - Clock type:
	* CLOCK_REALTIME,
	* CLOCK_REALTIME_COARSE,
	* CLOCK_MONOTONIC.
	
Output:
time - the current time.*/
timespec getTime(clockid_t _clockId);


/*Description:
Calculates the next run time of the task.

Input:
 _periodTime - Time between the task runs (in milliseconds - number of seconds divided by a thousand)
_clockId - Clock type:
	* CLOCK_REALTIME,
	* CLOCK_REALTIME_COARSE,
	* CLOCK_MONOTONIC.
	
Output:
time - the next run time of the task.*/
timespec CalculateNextTime(size_t _periodTime, clockid_t _clockId);


/*Description:
Causes the task to sleep the period time.

Input:
_nextRunTime - the next run time of the task.
_clockId - Clock type:
	* CLOCK_REALTIME,
	* CLOCK_REALTIME_COARSE,
	* CLOCK_MONOTONIC.*/
void sleepTime(timespec _nextRunTime, clockid_t _clockId);

/*Description:
Calculates the difference between two different times.

Input:
_time1 - time 1.
_time2 - time 2.
	
Output:
time - the difference between two times (in nanoseconds - the number of seconds divided by a billion)*/
long TimesDifference(timespec _time1, timespec _time2);

















#endif /*#ifndef__TIME_H__*/
