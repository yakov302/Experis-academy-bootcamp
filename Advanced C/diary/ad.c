#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ad.h"
#define MAGIC_NUMBER 8123475

errMessage OverlapCheck(ad *_ad, meet *_meet);
void ShiftMeet(ad *_ad, int i);
void SortArray (ad *_ad);

/********************appointment diary struct********************/

struct appointment_diary
{
	meet **array_ptr;
	int array_size;
	int array_increase_size;
	int number_of_meetings;
	int magic_number;
};

/************************meeting struct************************/

struct meeting
{
	float begin;
	float end;
	int room;	
};

/*******************************CreateAd*************************************/

ad *CreateAd(size_t _arraySize, int _arrayIncreaseSize)
{
	ad *ad_ptr;
	
	if ((_arraySize == 0 && _arrayIncreaseSize == 0) || _arrayIncreaseSize < 0)
	{
		return NULL;
	}
		
	
	if((ad_ptr = ((ad*)malloc(sizeof(ad)))) == NULL)
	{
		return NULL;
	}
	
	if (( ad_ptr -> array_ptr = ((meet**) malloc(_arraySize * sizeof(meet*)))) == NULL)
	{
		free(ad_ptr);
		return NULL;
	}
	
	ad_ptr -> array_size = _arraySize;
	ad_ptr -> array_increase_size = _arrayIncreaseSize;
	ad_ptr -> number_of_meetings = 0;
	ad_ptr -> magic_number = MAGIC_NUMBER;
	
	return ad_ptr;
}


/*******************************DestroyAd*************************************/

errMessage DestroyAd (ad *_ad)
{
int i;

	if(_ad == NULL || _ad -> magic_number != MAGIC_NUMBER)
	{
		return NULL_ERR;
	}
	
	 _ad -> magic_number = 0;
	 
	for(i = 0; i < _ad -> number_of_meetings; i++)
	{
		free(_ad -> array_ptr[i]);
	}
	
	free (_ad -> array_ptr);
	free(_ad);
return OK;
}


/*******************************CreateMeeting*************************************/

meet *CreateMeeting (float _begin, float _end, int _room)
{
	meet *meet_ptr;
	
	if (_begin >= _end || _begin < 0 || _end > 24)
	{
		return NULL;
	}
	
	if((meet_ptr = ((meet*)malloc(sizeof(meet)))) == NULL)
	{
		return NULL;
	}
	
	meet_ptr -> begin = _begin;
	meet_ptr -> end = _end;
	meet_ptr -> room = _room;
	
	return meet_ptr;
}

/*******************************InsertMeeting*************************************/
 
errMessage InsertMeeting (ad *_ad, meet *_meet)
{
meet **temp;

	if(_ad == NULL || _meet == NULL)
	{
		free(_meet);
		return NULL_ERR;
	}
	
	if(OverlapCheck(_ad, _meet) == OVERLAP)
	{
		free(_meet);
		return OVERLAP;
	}

	if((_ad -> number_of_meetings) >= (_ad -> array_size))
	{
		if(_ad -> array_increase_size == 0)
		{
			free(_meet);
			return OVER_FLOW_ERR;
		}
		
		temp = (meet**)realloc(_ad -> array_ptr, (_ad -> array_size + _ad -> array_increase_size) * sizeof(meet*));
		if(temp == NULL)
		{
			free(_meet);
			return NULL_ERR;
		}
				
		_ad -> array_ptr = temp;
		_ad -> array_size = _ad -> array_size + _ad -> array_increase_size;	
	}
	
		/*for (index = _ad -> number_of_meetings -1; index >  0 ; index--)
		{
			if (_ad -> number_of_meetings == 0)
			{
				_ad -> array_ptr [_ad -> number_of_meetings] = _meet;
				_ad -> number_of_meetings++;
			}
			if(_meet -> begin > _ad -> array_ptr [_ad -> number_of_meetings - 1] -> begin)
			{
			
			}
		}*/
			
	_ad -> array_ptr [_ad -> number_of_meetings] = _meet;
	_ad -> number_of_meetings++;
	
	SortArray (_ad);
	return OK;		
}


void SortArray (ad *_ad)
{
int index;
meet *hold;

	for (index = _ad -> number_of_meetings -1; index >  0 ; index--)
        {
               if((_ad -> array_ptr [index] -> begin) < (_ad -> array_ptr [index - 1] -> begin))
                {
                    hold = (_ad -> array_ptr [index]);
                   (_ad -> array_ptr [index]) = (_ad -> array_ptr [index - 1] );
                   (_ad -> array_ptr [index - 1] ) = hold;
                }
        }
}

errMessage OverlapCheck(ad *_ad, meet *_meet)
{
int i;

	for (i = 0; i < _ad -> number_of_meetings; i++)
	{
		if(
			(_meet -> begin) >= ((_ad -> array_ptr [i]) -> begin) && (_meet -> begin) <= ((_ad -> array_ptr [i]) -> end)
			|| 
			(_ad -> array_ptr [i] -> begin) >= (_meet -> begin) && (_ad -> array_ptr [i] -> begin) <= (_meet -> end)
			)
		{
			return OVERLAP;
		}
	}
	
return NO_OVERLAP;
}

/*******************************RemoveMeeting*************************************/

errMessage RemoveMeeting (ad *_ad, float begin)
{
int i;

	if(_ad == NULL)
	{
		return NULL_ERR;
	}
	
	if(_ad -> number_of_meetings == 0)
	{
		return UNDER_FLOW_ERR;
	}
	
		for (i = 0; i < _ad -> number_of_meetings; i++)
		{
			if (begin == _ad -> array_ptr[i] -> begin)
			{
				free(_ad -> array_ptr[i]);
           			ShiftMeet(_ad, i);
           			_ad -> number_of_meetings--;
				return OK;
			}
		}
return NOT_EXIST_ERR;
}


void ShiftMeet(ad *_ad, int i)
{
meet *hold;
	for(i; i <  _ad -> number_of_meetings; i++)
	{
            (_ad -> array_ptr [i]) = (_ad -> array_ptr [i + 1] );
  	}

}

/*******************************IsMeetingExists*************************************/

errMessage IsMeetingExists(ad *_ad, float _Begin_time)
{
int i;

	if(_ad == NULL)
	{
		return NULL_ERR;
	}
	if(_Begin_time < 0 || _Begin_time > 24)
	{
		return INVALID_TIME;
	}
	
		for (i = 0; i < _ad -> number_of_meetings; i++)
		{
			if(_Begin_time == _ad -> array_ptr [i] -> begin)
			{
				return MEETING_EXISTS;
			}
		}
return MEETING_NOT_EXISTS;
}

/*******************************PrintAd*************************************/

errMessage PrintAd (ad *_ad)
{
int i;
		if(_ad == NULL)
		{
		return NULL_ERR;
		}
		if(_ad -> number_of_meetings == 0)
		{
			return NOT_EXIST_ERR;
		}
		
		printf("\n");
		printf("Dear user, these are your meetings for today\n");
		printf("\n");
		
		for (i = 0; i < _ad -> number_of_meetings; i++)
		{	
			printf("Meeting number %d \n", i+1);
			printf("Begin time: %0.2f \n", _ad -> array_ptr [i] -> begin);
			printf("End time: %0.2f \n", _ad -> array_ptr [i] -> end);
			printf("Room number: %d \n",  _ad -> array_ptr [i] -> room);
			printf("\n");
		}
		
}

/*******************************SaveAd*************************************/

errMessage SaveAd (ad *_ad, char _fileName[])
{
FILE* ptr; 
int i;

	if(_ad == NULL)
	{
		return NULL_ERR;
	}
	
	if(_ad -> number_of_meetings == 0)
	{
		return NOT_EXIST_ERR;
	}	

	if((ptr = fopen(_fileName, "a")) == NULL)
	{
		return NULL_ERR;
	}
		

	fprintf(ptr, "%d\n", _ad -> number_of_meetings);	
		
	for (i = 0; i < _ad -> number_of_meetings; i++)
	{	
		fprintf(ptr, "%.2f\n%.2f\n%d\n", _ad -> array_ptr[i] -> begin, _ad -> array_ptr[i] -> end, _ad -> array_ptr[i] -> room);		
	}
	
	fclose(ptr);
return OK;
}

/*******************************LoadAd*************************************/

errMessage LoadAd (ad *_ad, char _fileName[])
{
FILE* ptr;
int i; 
int number_of_meetings;
float begin;
float end;
int room;
meet* meet;

	if(_ad == NULL)
	{
		return NULL_ERR;
	}

	if((ptr = fopen(_fileName, "r")) == NULL)
	{
		return NULL_ERR;
	}
		
	for(i = 0; i < _ad -> number_of_meetings; i++)
	{
		free(_ad -> array_ptr[i]);
	}
	_ad -> number_of_meetings = 0;
	
	
	fscanf(ptr, "%d\n", &number_of_meetings);	
		
	for (i = 0; i < number_of_meetings; i++)
	{
			
		fscanf(ptr,"%f\n%f\n%d\n", &begin, &end, &room);
		meet = CreateMeeting (begin, end, room);
		InsertMeeting(_ad, meet);		
	}
	
	fclose(ptr);
	
return OK;
}


/*******************************TestsFunction*************************************/
	
int GetSize(ad *_ad)
{
	return _ad -> array_size;
}
int Increase(ad *_ad)
{
	return _ad -> array_increase_size;
}
int NumberOfMeetings(ad *_ad)
{
	return _ad -> number_of_meetings;
}
	
int GetBegin(meet *_meet)
{
	return  _meet -> begin;
}
int GetEnd(meet *_meet)
{
	return  _meet -> end;
}
int GetRoom(meet *_meet)
{
	return _meet -> room;
}

meet *GetMeetPointer(ad *_ad, int i)
{
	return _ad -> array_ptr [i];
}

int GetMeetRoom(ad *_ad, int i)
{
	return _ad -> array_ptr [i] -> room;
}

float GetMeetBegin(ad *_ad, int i)
{
	return _ad -> array_ptr [i] -> begin;
}

float GetMeetEnd(ad *_ad, int i)
{
	return _ad -> array_ptr [i] -> end;
}










