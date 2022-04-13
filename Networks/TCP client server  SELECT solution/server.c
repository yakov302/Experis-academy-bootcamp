#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/select.h>
#include "list.h"
#include "gen.list.h"
#define SERVER_PORT 5555
#define SERVER_IP "10.0.2.15"
#define BUFFER_SIZE 500
#define FAIL 0
#define SUCCESS 1
#define CLIENT_QUEUE_SIZE 1000
#define TRUE 1
#define MAX_FD 1024
#define MAX_SOKET 1000

int clientsCountr = 1;

static socklen_t SinSetting(struct sockaddr_in *_sin)
{
	memset (_sin, 0, sizeof(*_sin));
	
	_sin -> sin_family = AF_INET;
	_sin -> sin_addr.s_addr =  inet_addr(SERVER_IP);
	_sin -> sin_port = htons(SERVER_PORT);
	
return sizeof(*_sin);
}

static int ServerInitialization(struct sockaddr_in *_sin, fd_set* _socketsList)
{
int listenSocketNum;
socklen_t sinLen;
int optval = 1;
int flags;

	/**********************OpenListenSocket***********************/

	listenSocketNum = socket(AF_INET, SOCK_STREAM, 0);
	if(listenSocketNum < 0)
	{
		perror("Socket fail!\n");
		return FAIL;
	}
	
	/****************EnterTo fd_set forNoBlocking*****************/
	
	FD_SET(listenSocketNum, _socketsList);	
	
	/******************FreesListenSocketImmediately*****************/
		
	if(setsockopt(listenSocketNum, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("Setsockopt fail!\n");
		return FAIL;
	}
	
	/******************SetFixIpAndPortForServer*****************/
	
	sinLen = SinSetting(_sin);
			
	if(bind(listenSocketNum, (struct sockaddr*)_sin, sinLen) < 0)
	{
		perror("Bind fail!\n");	
		return FAIL;
	}
	
	/****************SetListenSocketOnlyForListen****************/
		
	if(listen(listenSocketNum, CLIENT_QUEUE_SIZE) < 0)
	{
		perror("Listen fail!\n");	
		return FAIL;
	}

return listenSocketNum;
}

static int AcceptNewClient(struct sockaddr_in *_clientSin, int _listenSocketNum, List* _list, fd_set* _socketsList)
{
socklen_t clientSinLen;
int clientSocketNum;
int* listData;
int flags;

		clientSinLen = sizeof(*_clientSin);
		clientSocketNum = accept(_listenSocketNum, (struct sockaddr*) _clientSin, &clientSinLen);
		if(clientSocketNum < 0)
		{
			perror("Accept fail!\n");
			return FAIL;				
		}
		else if (clientsCountr < MAX_SOKET)
		{	
			
			/***********EnterTo fd_set forNoBlocking************/
			
			FD_SET(clientSocketNum, _socketsList);	
			
			/***************EnterSocketNumToList***************/	

			if((listData = (int*) malloc(sizeof(int))) == NULL)
			{
				printf("Data malloc fail!\n");
				return FAIL;
			}
			*listData = clientSocketNum;
			if(ListPushHead(_list, listData) != LIST_SUCCESS)
			{
				printf("List push head fail!\n");
				return FAIL;		
			}
			
			clientsCountr++;
						
			return clientSocketNum;
		}
		
	printf("Server full!\n");
	close(clientSocketNum);	
	return SUCCESS;					
}


static int SendAndReceiveData(int _clientSocketNum, List* _list)
{
char message[BUFFER_SIZE];
char buffer[BUFFER_SIZE];
int receiveBytes;
int sentByte;

		sprintf(message, "Hi client, my socket is: %d\n", _clientSocketNum);

		receiveBytes = recv(_clientSocketNum, buffer, sizeof(buffer),0);
		if(receiveBytes == 0)
		{
			printf("Connection closed!\n");
			return FAIL;
		}
		if(receiveBytes < 0)
		{
			perror("Receive fail!\n");
			return FAIL;
		}

		buffer[receiveBytes] = '\0';
		
		printf("%s\n", buffer);

		sentByte = send(_clientSocketNum, message, strlen(message), 0);
		if(sentByte < 0)
		{
			perror("Send fail!\n");
			return FAIL;		
		}
		
return SUCCESS;
}

static void TakeCareClients(List* _list, fd_set* _socketsList, fd_set* _activeSockets, int* _activity)
{
int* clientSocketNum;
ListItr nodeEnd;
ListItr node;

	node = ListItrBegin(_list);
	nodeEnd = ListItrEnd(_list);
		
	while((node != nodeEnd) && (*_activity > 0)) 
	{
		clientSocketNum = ListItrGet(node);
		
		if(FD_ISSET(*clientSocketNum, _activeSockets))
		{
			if(SendAndReceiveData(*clientSocketNum,  _list) == FAIL)
			{
				FD_CLR(*clientSocketNum, _socketsList);
				node = ListItrNext(node);
				close(*clientSocketNum);
				free(ListItrGet(ListItrPrev(node)));	
				ListItrRemove( ListItrPrev(node));
				clientsCountr--;
			}
			else
			{		
				node = ListItrNext(node);
			}
			*_activity--;
		}
		else
		{		
			node = ListItrNext(node);
		}	 
	} 
}

void ItemDestroy(void* _item)
{
	free(_item);
}


int main()
{
struct sockaddr_in clientSin;
struct sockaddr_in sin;
int listenSocketNum;
fd_set activeSockets;
fd_set socketsList;
static int activity;
List* list;
	
	FD_ZERO(&activeSockets);
	FD_ZERO(&socketsList);
	
	if((list = ListCreate()) == NULL)
	{
		printf("List create fail!\n");
		return;
	}

	if((listenSocketNum = ServerInitialization(&sin, &socketsList)) == FAIL)
	{
		ListDestroy(&list, ItemDestroy);
		return;
	}
	

	while(TRUE)
	{	
		activeSockets = socketsList;	
		activity = select(MAX_FD, &activeSockets, NULL, NULL, NULL);
		if((activity < 0) && (errno != EINTR))
		{
			perror("Select fail!\n");
			return;			
		}
		
		if(FD_ISSET(listenSocketNum, &activeSockets))
		{
			if(AcceptNewClient(&clientSin, listenSocketNum, list, &socketsList) == FAIL)
			{
				ListDestroy(&list, ItemDestroy);
				return;
			}
			activity--;
		}

		TakeCareClients(list, &socketsList, &activeSockets, &activity);
	}
		
}
