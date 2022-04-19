#include <stdio.h>
#include <stdlib.h>
#include "ad.h"

/*******************************TestsFunction*************************************/

meet *GetMeetPointer(ad *_ad, int i);

/**************************CreateAd***************************/

void CreateAdIsTwoZerosGiveNull(void)
{
	ad *ptr;
	ptr = CreateAd(0, 0);
	if(ptr == NULL)
	{
		printf("CreateAd test - Is two zero give NULL          - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("QueueCreate test - Is two zero give NULL        - FAILS! \n");	
	}
DestroyAd (ptr);	
}

void CreateAdIsNegativeSizeGiveNull(void)
{
	ad *ptr;
	ptr = CreateAd(-1, 5);
	if(ptr == NULL)
	{
		printf("CreateAd test - Is negative size give NULL     - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("CreateAd test - Is negative size give NULL     - FAILS! \n");	
	}
DestroyAd (ptr);	
}

void CreateAdIsNegativeIncreaseGiveNull(void)
{
	ad *ptr;
	ptr = CreateAd(5, -1);
	if(ptr == NULL)
	{
		printf("CreateAd test - Is negative increase give NULL - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("CreateAd test - Is negative increase give NULL - FAILS! \n");	
	}
DestroyAd (ptr);	
}

void IsZeroIncreaseGiveNull(void)
{
	ad *ptr;
	ptr = CreateAd(1, 0);
	if(ptr != NULL)
	{
		printf("CreateAd test - Is zero increase give NULL     - PASS! \n");	
	}
	if(ptr == NULL)
	{
		printf("CreateAd test - Is zero increase give NULL     - FAILS! \n");	
	}
DestroyAd (ptr);	
}

void CreateAdIsZeroSizeGiveNull(void)
{
	ad *ptr;
	ptr = CreateAd(0, 1);
	if(ptr != NULL)
	{
		printf("CreateAd test - Is zero size give NULL         - PASS! \n");	
	}
	if(ptr == NULL)
	{
		printf("CreateAd test - Is zero size give NULL         - FAILS! \n");	
	}
DestroyAd (ptr);	
}



void CreateAdCheckParameters(void)
{
	ad *ptr;
	ptr = CreateAd(10, 2);
	if(GetSize(ptr) == 10 && Increase(ptr) == 2 && NumberOfMeetings(ptr) == 0)
	{
		printf("CreateAd test - Check parameters               - PASS! \n");	
	}
	else
	{
		printf("CreateAd test - Check parameters               - FAILS! \n");	
	}

DestroyAd (ptr);	
}

/**************************CreateMeeting***************************/


void CreateMeetingIsBeginBigerThenEndGiveNull(void)
{
	meet *ptr;
	ptr = CreateMeeting(5, 3, 4);
	if(ptr == NULL)
	{
		printf("CreateMeeting test - Is begin biger then end give NULL - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("CreateMeeting test - Is begin biger then end give NULL - FAILS! \n");	
	}
	
}

void CreateMeetingIsBeginNegativeGiveNull(void)
{
	meet *ptr;
	ptr = CreateMeeting(-1, 3, 4);
	if(ptr == NULL)
	{
		printf("CreateMeeting test - Is begin negative give NULL       - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("CreateMeeting test - Is begin negative give NULL       - FAILS! \n");	
	}
	
}

void CreateMeetingIsEndBigerThen24GiveNull(void)
{
	meet *ptr;
	ptr = CreateMeeting(3, 24.01, 4);
	if(ptr == NULL)
	{
		printf("CreateMeeting test - Is end biger then 24 give NULL    - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("CreateMeeting test - Is end biger then 24 give NULL     - FAILS! \n");	
	}
	
}

void CreateMeetingCheckParameters(void)
{
	meet *ptr;
	ptr = CreateMeeting(3.16, 4.18, 5);
	if(GetBegin(ptr) - 3.16 < 0.1 ||GetBegin(ptr) - 3.16 > 0.1 && GetEnd(ptr) - 4.18 > 0.1 || GetEnd(ptr) - 4.18 < 0.1 && GetRoom(ptr)
 == 4)
	{
		printf("CreateMeeting test - Check parameters                  - PASS! \n");	
	}
	else
	{
		printf("CreateMeeting test - Check parameters                  - FAILS! \n");	
	}

}

/**************************InsertMeeting***************************/


void IsAdNullGiveNullErr(void)
{	
	ad *ptr;
	meet *meet;
	meet = CreateMeeting(3.16, 4.18, 5);
	
	if(InsertMeeting (NULL, meet) == NULL_ERR)
	{
		printf("InsertMeeting test - Is ad NULL give NULL err        - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is ad NULL give NULL err       - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsMeetNullGiveNullErr(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 5);
	
	if(InsertMeeting (ptr, NULL) == NULL_ERR)
	{
		printf("InsertMeeting test - Is meet NULL give Null err      - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is meet NULL give Null err     - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}



void IsMeetEnterTheArray(void)
{
	ad *ptr;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(meet == GetMeetPointer(ptr, 0))
	{
		printf("InsertMeeting test - Is meet pointer enter the array - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is meet pointer enter the array - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsRoomEnterTheArray(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(GetMeetRoom(ptr,0) == 5)
	{
		printf("InsertMeeting test - Is room enter the array         - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is room enter the array        - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsBeginEnterTheArray(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(GetMeetBegin(ptr,0) - 3.1 > 0.1 || GetMeetBegin(ptr,0) - 3.16 < 0.1)
	{
		printf("InsertMeeting test - Is begin enter the array        - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is begin enter the array       - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsEndEnterTheAraay(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(GetMeetEnd(ptr,0) - 4.18 > 0.1 || GetMeetEnd(ptr,0) - 4.18 < 0.1)
	{
		printf("InsertMeeting test - Is end enter the araay          - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is end enter the araay         - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsRoom2EnterTheArray(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.15, 4.18, 5);
	InsertMeeting (ptr, meet);
	meet = CreateMeeting(4.7, 5.18, 8);
	InsertMeeting (ptr, meet);
	
	
	if(GetMeetRoom(ptr,1) == 8)
	{
		printf("InsertMeeting test - Is room2 enter the array        - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is room2 enter the array       - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}


void IsOverlapErrWork(void)
{	
	ad *ptr;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(1, 2, 5);
	InsertMeeting (ptr, meet);
	meet2 = CreateMeeting(1.5, 2.5, 10);

	
	
	if(InsertMeeting (ptr, meet2) == OVERLAP)
	{
		printf("InsertMeeting test - Is overlap err work             - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is overlap err work            - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsOverlap2ErrWork(void)
{	
	ad *ptr;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	meet2 = CreateMeeting(2.2, 3.5, 10);
	
	
	
	if(InsertMeeting (ptr, meet2) == OVERLAP)
	{
		printf("InsertMeeting test - Is overlap2 err work            - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is overlap2 err work           - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}


void IsOverFlowErrWork(void)
{	
	ad *ptr;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(1, 0);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	meet2 = CreateMeeting(8, 9.5, 10);

	
	
	if(InsertMeeting (ptr, meet2) == OVER_FLOW_ERR)
	{
		printf("InsertMeeting test - Is overflow err work            - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is overflow err work           - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsRealocWork(void)
{	
	ad *ptr;
	meet *meet3;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(1, 1);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	meet2 = CreateMeeting(8, 9.5, 15);
	InsertMeeting (ptr, meet2);
	meet3 = CreateMeeting(10.3, 15.4, 30);
	InsertMeeting (ptr, meet3);

	if(GetSize(ptr) == 3 && NumberOfMeetings(ptr) == 3 && GetMeetRoom(ptr, 2) == 30)
	{
		printf("InsertMeeting test - Is realoc work                  - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is realoc err work             - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsSortWork(void)
{	
	ad *ptr;
	meet *meet3;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(10, 2);
	meet = CreateMeeting(3.16, 4.18, 3);
	InsertMeeting (ptr, meet);
	meet2 = CreateMeeting(2.2, 3, 2);
	InsertMeeting (ptr, meet2);
	meet3 = CreateMeeting(1.2, 2.1, 1);
	InsertMeeting (ptr, meet3);
	
	
	if(GetMeetRoom(ptr,0) == 1 &&  GetMeetRoom (ptr,1) == 2 && GetMeetRoom (ptr,2) == 3)
	{
		printf("InsertMeeting test - Is sort work                    - PASS! \n");	
	}
	else
	{
		printf("InsertMeeting test - Is sort work                   - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

/*******************************RemoveMeeting*************************************/

void RemoveMeetingIsAdNullGiveNullErr(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(RemoveMeeting (NULL, 3.16) == NULL_ERR)
	{
		printf("RemoveMeeting test - Is ad NULL give NULL err   - PASS! \n");	
	}
	else
	{
		printf("RemoveMeeting test - Is ad NULL give NULL err   - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}


void RemoveMeetingIsUnderflowErrWork(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(3.16, 4.18, 5);

	if(RemoveMeeting (ptr, 3.16) == UNDER_FLOW_ERR)
	{
		printf("RemoveMeeting test - Is underflow err work      - PASS! \n");	
	}
	else
	{
		printf("RemoveMeeting test - Is underflow err work       - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void RemoveMeetingIsDeliteWork(void)
{	
	ad *ptr;
	meet *meett;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(3.16, 4.18, 5);
	meett = meet;
	InsertMeeting (ptr, meet);
	RemoveMeeting (ptr, 3.16);
	if(GetMeetPointer(ptr, 0) != meett)
	{
		printf("RemoveMeeting test - Is delite work             - PASS! \n");	
	}
	else
	{
		printf("RemoveMeeting test - Is err work                 - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void RemoveMeetingIsSortingWork(void)
{	
	ad *ptr;
	meet *meet1;
	meet *meet2;
	meet *meet3;
	meet *meet4;
	ptr = CreateAd(5, 1);
	meet1 = CreateMeeting(1.1 , 2.1, 1);
	meet2 = CreateMeeting(3.16, 4.18, 2);
	meet3 = CreateMeeting(5.16, 6.18, 3);
	meet4 = CreateMeeting(7.16, 8.18, 4);
	InsertMeeting (ptr, meet1);
	InsertMeeting (ptr, meet2);
	InsertMeeting (ptr, meet3);
	InsertMeeting (ptr, meet4);
	
	RemoveMeeting (ptr, 1.1);
	if(GetMeetRoom(ptr, 0) == 2 && GetMeetRoom(ptr, 1) == 3 && GetMeetRoom(ptr, 2) == 4)
	{
		printf("RemoveMeeting test - Is sorting work            - PASS! \n");	
	}
	else
	{
		printf("RemoveMeeting test - Is sorting work              - FAILS! \n");	
	}
		
DestroyAd(ptr);	
}

/*******************************IsMeetingExists*************************************/

void IsMeetingExistsIsAdNullGiveNullErr(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(3.16, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(IsMeetingExists(NULL, 3.16) == NULL_ERR)
	{
		printf("IsMeetingExists test - Is ad NULL give NULL err   - PASS! \n");	
	}
	else
	{
		printf("IsMeetingExists test - Is ad NULL give NULL err   - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsMeetingExistsIsInvalidTimeGiveErr(void)
{	
	ad *ptr;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(25, 4.18, 5);
	InsertMeeting (ptr, meet);
	
	if(IsMeetingExists(ptr, 25) == INVALID_TIME)
	{
		printf("IsMeetingExists test - Is invalid time give err   - PASS! \n");	
	}
	else
	{
		printf("IsMeetingExists test - Is invalid time give err   - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsMeetingExistsWork(void)
{	
	ad *ptr;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(20.444, 22.8, 5);
	meet2 = CreateMeeting(5.3, 10.6, 6);
	InsertMeeting (ptr, meet);
	InsertMeeting (ptr, meet2);
	
	if(IsMeetingExists(ptr, 20.444) == MEETING_EXISTS)
	{
		printf("IsMeetingExists test - Is meeting exists work     - PASS! \n");
	}
	else
	{
		printf("IsMeetingExists test -  Is meeting exists work     - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsMeetingNotExistsWork(void)
{	
	ad *ptr;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(20.444, 22.8, 5);
	meet2 = CreateMeeting(5.3, 10.6, 6);
	InsertMeeting (ptr, meet);
	InsertMeeting (ptr, meet2);
	
	if(IsMeetingExists(ptr, 6.14) == MEETING_NOT_EXISTS)
	{
		printf("IsMeetingExists test - Is meeting not exists work - PASS! \n");	
	}
	else
	{
		printf("IsMeetingExists test -  Is meeting not exists work - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

/*******************************DestroyAd*************************************/

void DestroyAdIsAdNullGiveNullErr(void)
{	
	ad *ptr;
	ptr = CreateAd(5, 1);
	
	if(DestroyAd(NULL) == NULL_ERR)
	{
		printf("DestroyAd test - Is ad NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("DestroyAd test -  Is ad NULL give NULL err - FAILS! \n");	
	}
	
DestroyAd (ptr);	
}

void IsDestroyWork(void)
{	
	ad *ptr;
	meet *meet2;
	meet *meet;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(20.444, 22.8, 5);
	meet2 = CreateMeeting(5.3, 10.6, 6);
	InsertMeeting (ptr, meet);
	InsertMeeting (ptr, meet2);
	DestroyAd(ptr);
	
	if(GetMeetPointer(ptr, 0) != meet && GetMeetPointer(ptr, 1) != meet2 && GetSize(ptr) != 5)
	{
		printf("DestroyAd test - Is destroy work          - PASS! \n");	
	}
	else
	{
		printf("DestroyAd test -  Is destroy work         - FAILS! \n");	
	}

}	

void IsDoubleDestroyWork(void)
{	
	ad *ptr;
	meet *meet4;
	meet *meet3;
	meet *meet2;
	meet *meet;
	int size;
	ptr = CreateAd(5, 1);
	meet = CreateMeeting(20.444, 22.8, 5);
	meet2 = CreateMeeting(5.3, 10.6, 6);
	InsertMeeting (ptr, meet);
	InsertMeeting (ptr, meet2);
	DestroyAd(ptr);
	meet3 = GetMeetPointer(ptr, 0);
	meet4 = GetMeetPointer(ptr, 1);
	size = GetSize(ptr);
	DestroyAd(ptr);
	if(GetMeetPointer(ptr, 0) == meet3 && GetMeetPointer(ptr, 1) == meet4 && GetSize(ptr) == size)
	{
		printf("DestroyAd test - Is double destroy work   - PASS! \n");	
	}
	else
	{
		printf("DestroyAd test -  Is double destroy work   - FAILS! \n");	
	}

}


/*******************************PrintAd*************************************/

void AdPrintIsAdNullGiveNullErr(void)
{	
	ad *ptr;
	ptr = CreateAd(5, 1);

	if(PrintAd(NULL) == NULL_ERR)
	{
		printf("PrintAd test - Is ad NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("PrintAd test - Is ad NULL give NULL err - FAILS! \n");	
	}
DestroyAd (ptr);	
}

void AdPrintIsNotExistErrWork(void)
{	
	ad *ptr;
	ptr = CreateAd(5, 1);

	if(PrintAd(ptr) == NOT_EXIST_ERR)
	{
		printf("PrintAd test - Is not exist err work    - PASS! \n");	
	}
	else
	{
		printf("PrintAd test - Is not exist err work     - FAILS! \n");	
	}
DestroyAd (ptr);	
}

/*******************************Main*************************************/

int main()
{
printf("\n");
printf("------------CreateAd test-------------\n");
CreateAdIsTwoZerosGiveNull();
CreateAdIsNegativeSizeGiveNull();
CreateAdIsNegativeIncreaseGiveNull();
IsZeroIncreaseGiveNull();
CreateAdIsZeroSizeGiveNull();
CreateAdCheckParameters();

printf("\n");
printf("------------CreateMeeting test-------------\n");
CreateMeetingIsBeginBigerThenEndGiveNull();
CreateMeetingIsBeginNegativeGiveNull();
CreateMeetingIsEndBigerThen24GiveNull();
CreateMeetingCheckParameters();

printf("\n");
printf("------------InsertMeeting test-------------\n");
IsAdNullGiveNullErr();
IsMeetNullGiveNullErr();
IsMeetEnterTheArray();
IsRoomEnterTheArray();
IsBeginEnterTheArray();
IsEndEnterTheAraay();
IsRoom2EnterTheArray();
IsOverlapErrWork();
IsOverlap2ErrWork();
IsOverFlowErrWork();
IsRealocWork();
IsSortWork();

printf("\n");
printf("------------RemoveMeeting test-------------\n");
RemoveMeetingIsAdNullGiveNullErr();
RemoveMeetingIsUnderflowErrWork();
RemoveMeetingIsDeliteWork();
RemoveMeetingIsSortingWork();

printf("\n");
printf("------------IsMeetingExists test-------------\n");
IsMeetingExistsIsAdNullGiveNullErr();
IsMeetingExistsIsInvalidTimeGiveErr();
IsMeetingExistsWork();
IsMeetingNotExistsWork();

printf("\n");
printf("------------DestroyAd test-------------\n");
DestroyAdIsAdNullGiveNullErr();
IsDestroyWork();
IsDoubleDestroyWork();

printf("\n");
printf("------------PrintAd test-------------\n");
AdPrintIsAdNullGiveNullErr();
AdPrintIsNotExistErrWork();

}


