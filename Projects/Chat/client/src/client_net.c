#include "client_net.h"

#define SERVER_IP "127.0.0.1"
#define MAGIC_NUMBER 8123475
#define SERVER_PORT 5555
#define GROUPS_AMOUNT 20
#define BUFFER_SIZE 500

static void SinSetting(struct sockaddr_in *_sin);
int ClientInitialization(struct sockaddr_in *_sin);
static int ConnectToServer(struct sockaddr_in *_sin, int _socketNum);
static int SendAndReceiveData(int _socketNum, char* _buffer, int _length);

int soket;

//Set fixed IP and port to server
static void SinSetting(struct sockaddr_in *_sin)
{
	memset (_sin, 0, sizeof(*_sin)); //Reset the struct
	
	_sin -> sin_family = AF_INET; // For version 4 - AF_INET.  For version 6 - AF_INET6.
	_sin -> sin_addr.s_addr =  inet_addr(SERVER_IP); // ip in network byte
	_sin -> sin_port = htons(SERVER_PORT); //port in network byte
}

 int ClientInitialization(struct sockaddr_in *_sin)
{
	int optval = 1;

	//Open channel between the application and the networking package of the OS
	soket = socket(AF_INET, SOCK_STREAM, 0);
	if(soket < 0)
	{
		perror("Socket fail!\n");
		return CLIENT_FAIL;
	}

	//Immediate release the port when connection close
	if(setsockopt(soket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("Setsockopt fail!\n");
		return CLIENT_FAIL;
	}
		
	return soket;
}

void RunClientNet(Client* _client, char* _buffer, int _length)
{
	struct sockaddr_in sin;

	if(_client == NULL)
	{
		return;
	}
	
	SinSetting(&sin);
	ConnectToServer(&sin, soket);
	SendAndReceiveData(soket, _buffer, _length);
}

void SendRecive(Client* _client, char* _buffer, int _length)
{
	if(_client == NULL)
	{
		return;
	}

	SendAndReceiveData(soket, _buffer, _length);
}

static int ConnectToServer(struct sockaddr_in *_sin, int _socketNum)
{
	SinSetting(_sin);
		
	if(connect(_socketNum, (struct sockaddr*)_sin, sizeof(*_sin)) < 0)
	{	
		perror("Connect fail!\n");
		return CLIENT_FAIL;	
	}
	
	return CLIENT_SUCCESS;
}

static int SendAndReceiveData(int _socketNum, char* _buffer, int _length)
{
	char* recvBuffer;
	int receiveBytes;
	int sentByte;
	int MessageSize = 0;
		
	sentByte = send(_socketNum, _buffer, _length, 0);
	if(sentByte < 0)
	{
		perror("Send fail!\n");	
		return CLIENT_FAIL;	
	}
	
	receiveBytes = recv(_socketNum, _buffer, BUFFER_SIZE, 0);
	if(receiveBytes == 0)
	{
		printf("Connection closed!\n");
		return CLIENT_FAIL;
	}
	if(receiveBytes < 0)
	{
		perror("Receive fail!\n");
		return CLIENT_FAIL;	
	}

	MessageSize = ReturnMessageSize(_buffer);
	while(receiveBytes < MessageSize)
	{
		receiveBytes += recv(_socketNum, (_buffer + receiveBytes), BUFFER_SIZE, 0);
	}	
	_buffer[receiveBytes] = '\0';

	return CLIENT_SUCCESS;
}
	
