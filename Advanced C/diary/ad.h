#ifndef __AD_H__
#define __AD_H__

/*return err messages*/
typedef enum
{
UNDER_FLOW_ERR = -2, 
OVER_FLOW_ERR = -1, 
NULL_ERR =0, 
OK =1,
NO_OVERLAP = 2,
OVERLAP = 3,
NOT_EXIST_ERR = 4,
MEETING_EXISTS = 5,
MEETING_NOT_EXISTS = 6,
INVALID_TIME = 7
}errMessage;
			
/*new name to the meeting structure*/
typedef struct meeting meet;

/*new name to the appointment_diary structure*/
typedef struct appointment_diary ad;

/*Description:
The function creates the diary by allocat memory to the diary structure and for the meetings array.

Input variables:
 _arraySize: Size of memory allocation to the array.
 _arrayIncreaseSize: Size for reallocation of memory to the array (if necessary).

Output variables:
NULL: if _arraySize and _arrayIncreaseSize both equal 0 or if _arrayIncreaseSize is negative or if one of the memory allocations failed.
ad_ptr: Pointer to the diary structure.*/
ad *CreateAd(size_t _arraySize, int _arrayIncreaseSize);

/*Description:
The function creates meeting by allocat memory to the meeting structure and entering the data to its parameters.

Input variables:
 _begin: Start time (between 0 and 23.99).
_end: End time (between 0 and 23.99).
_room: Room number.

Output variables:
NULL: if _begin is bigger then _end or if _end is bigger then 23.99 or if _begin smaller then 0 or If the memory allocation for the meeting failed.
meet_ptr: Pointer to the meeting structure.*/
meet *CreateMeeting (float _begin, float _end, int _room);

/*Description:
The function destroys all meeting structures, the array, and the diary structures.

Input variables:
*_ad: pointer to the diary structures.

Output variables:
NULL_ERR: if *_ad is NULL.*/
errMessage DestroyAd (ad *_ad);

/*Description:
the function insert meeting to the diary, checks that there is no overlap with existing meetings, Re-allocate memory if necessary and sorts all meetings according to begin time.

Input variables:
*_ad: pointer to the diary structures.
*_meet: pointer to the meeting structures that the function will by insert to the diary.

Output variables:
NULL_ERR: if *_ad or *_meet is NULL or if thr memory Re-allocate failed.
OVERLAP: If there is overlap between the hours of the meeting and the meetings that are already in the diary.
OVER_FLOW_ERR: If the place in the diary runs out and _arrayIncreaseSize is 0.
OK: If everything was done successfully.*/
errMessage InsertMeeting (ad *_ad, meet *_meet);

/*Description:
the function removes meeting by begin time and Shifts all the remaining meetings one place to the left / right.

Input variables:
*_ad: pointer to the diary structures.
begin: begin time.

Output variables:
NULL_ERR: if *_ad is NULL.
UNDER_FLOW_ERR: If the diary is empty.
NOT_EXIST_ERR: If there is no meeting in the diary with the begin time as the function received.*/
errMessage RemoveMeeting (ad *_ad, float begin);

/*Description:
The function checks if a meeting exists in the diary by begin time.

Input variables:
*_ad: pointer to the diary structures.
_Begin_time: begin time.

Output variables:
INVALID_TIME: if _Begin_time > 24 or if _Begin_time < 0. 
MEETING_EXISTS: If the meeting exists.
MEETING_NOT_EXISTS: If the meeting not exists.*/
errMessage IsMeetingExists(ad *_ad, float _Begin_time);

/*Description:
The function prints the data for all meetings in the diary.

Input variables:
*_ad: pointer to the diary structures.*/
errMessage PrintAd (ad *_ad);

/*Description:
The function saves the meetings created in the diary to an external file.

Input variables:
*_ad: pointer to the diary structures.
_fileName: The name of the file that will contain the saved meetings.

NULL_ERR: if *_ad is NULL or if the file could not be opened.
NOT_EXIST_ERR: If the diary is empty.
OK: If the meetings were successfully saved in the file.*/
errMessage SaveAd (ad *_ad, char _fileName[]);

/*Description:
The function loads meetings to the diary from an external file.

Input variables:
*_ad: pointer to the diary structures.
_fileName: The name of the file that will by loads.

NULL_ERR: if *_ad is NULL or if the file could not be opened.
OK: If the meetings were successfully loaded frome the file.*/
errMessage LoadAd (ad *_ad, char _fileName[]);




#endif /*#ifndef__AD_H__*/


