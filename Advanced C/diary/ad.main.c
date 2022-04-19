#include <stdio.h>
#include <stdlib.h>
#include "ad.h"
meet *manag(ad *ad);
meet *Meeting (ad *ad);

ad *Ad(void)
{
ad *ptr;
int choice;
int size;
int increase;

	printf("\n");
	printf("Dear user, would you like to create a daily appointment diary ? \n 1 - for Yes.\n 2 - for No.\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 2:
			printf("\n");
			printf("Ok! Come back whenever you need.\n");
			
			break;
			
		case 1:
			printf("\n");
			printf("Enter the number of meetings you want the diary contain:\n");
			scanf("%d", &size);
			printf("\n");
			printf("In case the place in the diary runs out, by how much would you like to increase it ?\n");
			scanf("%d", &increase);
			ptr = CreateAd(size, increase);
			if(ptr == NULL)
			{
				printf("\n");
				printf("Oops! Something went wrong. Try again.\n");
				Ad();
				break;
			}
			printf("\n");
			printf("Greate! Your diary has been created.\n");
			Meeting(ptr);
			break;
			
		default:
			printf("\n");
			printf("Invalid choice! try again.\n ");
			Ad();
			break;
	}	
}



meet *Meeting (ad *ad)
{
int choice;
float begin;
float end;
int room;
meet *meet;
errMessage Insert;
char fileName[50];

		printf("\n");
		printf("Please select the choice you want: \n 1 - for create a new meeting.\n 2 - for Load meetings from seved file.\n 3 - for Destroy the daily appointment diary.\n ");
		
		scanf("%d", &choice);
		switch(choice)
		{
	
			case 1:
				printf("\n");
				printf("Enter begin time (between 0 and 23.99):\n");
				scanf("%f", &begin);
				printf("Enter end time (between 0 and 23.99):\n");
				scanf("%f", &end);
				printf("Enter room number:\n");
				scanf("%d", &room);
				meet = CreateMeeting(begin, end, room);
				if(meet == NULL)
				{
					printf("\n");
					printf("Invalid times, try again.\n");
					Meeting(ad);
					break;
				}
				Insert = InsertMeeting(ad, meet);
				if(Insert == OVERLAP)
				{
					printf("\n");
					printf("Oops! Looks like you already have meeting at these hours. try again.\n");
					Meeting(ad);
					break;		
				}
				if(Insert == OVER_FLOW_ERR)
				{
					printf("\n");
					printf("Oops! The place in diary is run out. Since you set 0 increase, you cannot add another meeting.\n");
					Meeting(ad);
					break;	
				}
				printf("\n");
				printf("Greate! Your meeting has been created and entered in the diary.\n");
				manag(ad);
				break;
				
			case 3:
				DestroyAd(ad);
				printf("\n");
				printf("Ok! Your daily appointment diary has been destroyed. Come back whenever you need.\n");
				break;
				
			case 2:
				printf("\n");
				printf("Enter the file name you want to load.\n");
				scanf("%s", fileName);
				LoadAd (ad,fileName);
				printf("\n");
				printf("Greate! Your meetings are loaded to the diary.\n");
				printf("\n");
				manag(ad);
				break;
				
			default:
				printf("\n");
				printf("Invalid choice! try again.\n ");
				Meeting(ad);
				break;
		}
}

meet *manag(ad *ad)
{
int choice;
float begin;
float end;
int room;
meet *meet;
errMessage Insert;
errMessage Remove;
errMessage IsExists;
char fileName[50];
int approval;

		printf("\n");
		printf("Please select the choice you want: \n 1 - for Create another meeting.\n 2 - for Delete meeting.\n 3 - for Check if meeting exists.\n 4 - for Print all the meeting in the diary.\n 5 - for Destroy the daily appointment diary.\n 6 - for Save the diary to file.\n 7 - for Load meetings from seved file.\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
		
			case 1:
				printf("\n");
				printf("Enter begin time (between 0 and 23.99):\n");
				scanf("%f", &begin);
				printf("Enter end time (between 0 and 23.99):\n");
				scanf("%f", &end);
				printf("Enter room number:\n");
				scanf("%d", &room);
				meet = CreateMeeting(begin, end, room);
				if(meet == NULL)
				{
					printf("\n");
					printf("Invalid times, try again.\n");
					manag(ad);
					break;
				}
				Insert = InsertMeeting(ad, meet);
				if(Insert == OVERLAP)
				{
					printf("\n");
					printf("Oops! Looks like you already have meeting at these hours. try again.\n");
					manag(ad);
					break;		
				}
				if(Insert == OVER_FLOW_ERR)
				{
					printf("\n");
					printf("Oops! The place in diary is run out. Since you set 0 increase, you cannot add another meeting.\n");
					manag(ad);
					break;		
				}
				printf("\n");
				printf("Greate! Your meeting has been created and entered in the diary.\n");
				manag(ad);
				break;
				
			case 2:
				printf("\n");
				printf("Enter the begine time of the meeting you want to delete.\n");
				scanf("%f", &begin);
				Remove = RemoveMeeting(ad, begin);
				if(Remove == UNDER_FLOW_ERR)
				{
				   	printf("\n");
					printf("Oops! The diary is empty there is nothing to delete.\n");
					printf("\n");
					manag(ad);
					break;
				}
				if(Remove == NOT_EXIST_ERR)
				{
					printf("\n");
					printf("Oops! There is no meeting that begine at the time you entered. try again");
					printf("\n");
					manag(ad);
					break;
				}
				if(Remove == OK)
				{
				    	printf("\n");
					printf("The meeting has been deleted!");
					printf("\n");
					manag(ad);
					break;
				}

			case 3:	
				printf("\n");
				printf("Enter the begine time of the meeting you want to find.\n");
				scanf("%f", &begin);
				IsExists = IsMeetingExists(ad, begin);
				if(IsExists == MEETING_EXISTS)
				{
					printf("\n");
					printf("You have meeting starting this time!\n");
					manag(ad);
					break;
				}
				if(IsExists == MEETING_NOT_EXISTS)
				{
					printf("\n");
					printf("You dont have meeting starting this time!\n");
					manag(ad);
					break;
				}
				if(IsExists == INVALID_TIME)
				{
					printf("\n");
					printf("Invalid times, try again.\n");
					manag(ad);
					break;
				}
				
			case 4:
				PrintAd(ad);
				manag(ad);
				break;
				
			case 5:
				DestroyAd(ad);
				printf("\n");
				printf("Ok! Your daily appointment diary has been destroyed. Come back whenever you need.\n");
				break;
				
			case 6:
				printf("\n");
				printf("Enter a file name:\n");
				scanf("%s", fileName);
				SaveAd (ad, fileName);
				printf("\n");								
				printf("Greate! Your diary has been saved.\n");
				manag(ad);
				break;
				
			case 7:
				printf("\n");
				printf("Note!\nAll the meetings currently in the diary will be deleted!\nPlease enter:\n1 - For approval.\n2 - For cancel.\n");
				scanf("%d", &approval);
				if(approval == 1)
				{
				printf("Enter the file name you want to load.\n");
				scanf("%s", fileName);
				LoadAd (ad,fileName);
				printf("\n");
				printf("Greate! Your meetings are loaded to the diary.\n");
				printf("\n");
				manag(ad);
				break;
				}
				else
				{
				printf("\n");
				printf("Ok! the file uploads have been canceled.");
				printf("\n");
				manag(ad);
				break;
				}
				break;
				
			default:
				printf("\n");
				printf("Invalid choice! try again.\n ");
				manag(ad);
				break;

		}
}


int main()
{
Ad();
}

















