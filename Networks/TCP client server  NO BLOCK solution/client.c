#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#define SERVER_PORT 5555
#define SERVER_IP "10.0.2.15"
#define BUFFER_SIZE 500
#define FAIL 0
#define SUCCESS 1
#define CLIENTS_NUMBER 1000
#define DISCONNECTED 0
#define TRUE 1


static void SinSetting(struct sockaddr_in *_sin)
{
	memset (_sin, 0, sizeof(*_sin));
	
	_sin -> sin_family = AF_INET;
	_sin -> sin_addr.s_addr =  inet_addr(SERVER_IP);
	_sin -> sin_port = htons(SERVER_PORT);
}

static int ClientInitialization(struct sockaddr_in *_sin)
{
int socketNum;
socklen_t sinLen;
int optval = 1;
int flags;

	socketNum = socket(AF_INET, SOCK_STREAM, 0);
	if(socketNum < 0)
	{
		perror("\nSocket fail!");
		return FAIL;
	}
		
	if(setsockopt(socketNum, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("\nSetsockopt fail!");
		return FAIL;
	}
		
return socketNum;
}

static int ConnectToServer(struct sockaddr_in *_sin, int _socketNum)
{
	SinSetting(_sin);
	
	if(connect(_socketNum, (struct sockaddr*)_sin, sizeof(*_sin)) < 0)
	{	
		perror("\nConnect fail!");
		return FAIL;	
	}
	
return SUCCESS;
}

static int SendAndReceiveData(int _socketNum)
{
char message[BUFFER_SIZE];
char buffer[BUFFER_SIZE];
int receiveBytes;
int sentByte;

		sprintf(message, "Hi server, my socket is: %d", _socketNum);
		
		sentByte = send(_socketNum, message, strlen(message), 0);
		if(sentByte < 0)
		{
			perror("\nSend fail!");	
			return FAIL;	
		}

		receiveBytes = recv(_socketNum, buffer, sizeof(buffer),0);
		if(receiveBytes == 0)
		{
			printf("Connection closed!");
			return FAIL;
		}
		if(receiveBytes < 0)
		{
			perror("\nReceive fail!");
			return FAIL;	
		}
		
		buffer[receiveBytes] = '\0';
		
		/*usleep(100000);*/
		printf("%s", buffer);

return SUCCESS;
}

static void CloseAllClient(int clientStock[])
{
int i;
	for(i = 0; i < CLIENTS_NUMBER; i++)
	{
		close(clientStock[i]);
		clientStock[i] = DISCONNECTED;	
	}

	printf("\nAll client closed!\n");
}

int main()
{
static int clientStock[CLIENTS_NUMBER] = {DISCONNECTED};
struct sockaddr_in sin;
int socketNum;
int index = 0;
int random;

	while(TRUE)
	{
		random = rand()%100;
		
		if(clientStock[index] ==  DISCONNECTED)
		{
			if(random < 30)
			{
				if((socketNum = ClientInitialization(&sin)) != FAIL)
				{
					if(ConnectToServer(&sin, socketNum) != FAIL)
					{
						clientStock[index] = socketNum;						
					}
					else
					{
						break;				
					}	
				}				
			}		
		}
		
		if(clientStock[index] !=  DISCONNECTED)
		{
			if(random > 95)
			{
				printf("client socket no. %d disconnects!\n", clientStock[index]);
				close(clientStock[index]);
				clientStock[index] = DISCONNECTED;
			}
			if(random < 30)
			{
			
				if(SendAndReceiveData(clientStock[index]) == FAIL)
				{
					printf("\nclient socket no. %d failed and disconnected!\n", clientStock[index]);
					close(clientStock[index]);
					clientStock[index] = DISCONNECTED;
				}
			}
			
		}
		
		
		index = (index + 1)%CLIENTS_NUMBER;
	}
	
		
CloseAllClient(clientStock);
}
