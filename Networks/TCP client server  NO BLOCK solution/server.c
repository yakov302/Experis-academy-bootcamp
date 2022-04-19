#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include "list.h"
#include "gen.list.h"
#define SERVER_PORT 5555
#define SERVER_IP "10.0.2.15"
#define BUFFER_SIZE 500
#define FAIL 0
#define SUCCESS 1
#define CLIENT_QUEUE_SIZE 1000
#define TRUE 1
#define FCNTL_FAILL -1
#define  NO_BLOCK -1


static socklen_t SinSetting(struct sockaddr_in *_sin)
{
	memset (_sin, 0, sizeof(*_sin));
	
	_sin -> sin_family = AF_INET;
	_sin -> sin_addr.s_addr =  inet_addr(SERVER_IP);
	_sin -> sin_port = htons(SERVER_PORT);
	
return sizeof(*_sin);
}

static int ServerInitialization(struct sockaddr_in *_sin)
{
int listenSocketNum;
socklen_t sinLen;
int optval = 1;
int flags;

	/**********************OpenListenSocket***********************/

	listenSocketNum = socket(AF_INET, SOCK_STREAM, 0);
	if(listenSocketNum < 0)
	{
		perror("\nSocket fail!");
		return FAIL;
	}
	
	/******************SetNoBlockForListenSocket*****************/
				
	if((flags = fcntl(listenSocketNum, F_GETFL)) == FCNTL_FAILL)
	{
		perror("\nFcntl initialization fail!");
		return FAIL;
	}
	
	if(fcntl(listenSocketNum, F_SETFL, flags|O_NONBLOCK) == FCNTL_FAILL)
	{
		perror("\nFcntl initialization fail!");
		return FAIL;
	}
	
	/******************FreesListenSocketImmediately*****************/
		
	if(setsockopt(listenSocketNum, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("\nSetsockopt fail!");
		return FAIL;
	}
	
	/******************SetFixIpAndPortForServer*****************/
	
	sinLen = SinSetting(_sin);
			
	if(bind(listenSocketNum, (struct sockaddr*)_sin, sinLen) < 0)
	{
		perror("\nBind fail!");	
		return FAIL;
	}
	
	/****************SetListenSocketOnlyForListen****************/
		
	if(listen(listenSocketNum, CLIENT_QUEUE_SIZE) < 0)
	{
		perror("\nListen fail!");	
		return FAIL;
	}

return listenSocketNum;
}

static int AcceptNewClient(struct sockaddr_in *_clientSin, int _listenSocketNum, List* _list)
{
socklen_t clientSinLen;
int clientSocketNum;
int* listData;
int flags;

		clientSinLen = sizeof(*_clientSin);
		clientSocketNum = accept(_listenSocketNum, (struct sockaddr*) _clientSin, &clientSinLen);
		if(clientSocketNum < 0)
		{
			if(errno != EAGAIN && errno != EWOULDBLOCK)
			{
				perror("\nAccept fail!");
				return FAIL;			
			}		
		}
		else
		{
			/***************SetNoBlockForClientSocketNum***************/	
				
			if((flags = fcntl(clientSocketNum, F_GETFL)) == FCNTL_FAILL)
			{
				perror("\nFcntl accept fail!");
				return FAIL;
			}
	
			if(fcntl(clientSocketNum, F_SETFL, flags|O_NONBLOCK) == FCNTL_FAILL)
			{
				perror("\nFcntl accept fail!");
				return FAIL;
			}
			
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
			return clientSocketNum;
		}		

return NO_BLOCK;				
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
			if(errno != EAGAIN && errno != EWOULDBLOCK)
			{
				perror("\nReceive fail!");
				return FAIL;
			}
			return NO_BLOCK;	
		}

		buffer[receiveBytes] = '\0';
		
		printf("%s\n", buffer);

		sentByte = send(_clientSocketNum, message, strlen(message), 0);
		if(sentByte < 0)
		{
			perror("\nSend fail!");
			return FAIL;		
		}
		
return SUCCESS;
}

static void TakeCareClients(List* _list)
{
int* clientSocketNum;
ListItr nodeEnd;
ListItr node;

	node = ListItrBegin(_list);
	nodeEnd = ListItrEnd(_list);
		
	while(node != nodeEnd) 
	{
		clientSocketNum = ListItrGet(node);
		
		if(SendAndReceiveData(*clientSocketNum,  _list) == FAIL)
		{
			node = ListItrNext(node);
			close(*clientSocketNum);
			free(ListItrGet(ListItrPrev(node)));	
			ListItrRemove( ListItrPrev(node));
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
List* list;

	
	if((list = ListCreate()) == NULL)
	{
		printf("List create fail!\n");
		return;
	}

	if((listenSocketNum = ServerInitialization(&sin)) == FAIL)
	{
		ListDestroy(&list, ItemDestroy);
		return;
	}

	while(TRUE)
	{
		if(AcceptNewClient(&clientSin, listenSocketNum, list) == FAIL)
		{
			ListDestroy(&list, ItemDestroy);
			return;
		}

		TakeCareClients(list);
	}
		
}
