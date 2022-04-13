#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SERVER_PORT 5555
#define SERVER_IP "10.0.2.15"


int main()
{
struct sockaddr_in6 sin6;
struct sockaddr_in sin;
socklen_t sinLen;
int receiveBytes;
char buffer[100];
int socketNum;
int sentByte;
int i;
char sendMessages [5][20] = {"\nTake Page 1\n", "\nTake Page 2\n", "\nTake Page 3\n", "\nTake Page 4\n", "\nTake Page 5\n"};

	/****************IPv4********************/
	
	printf("IPv4:\n");
	
	memset (&sin, 0, sizeof(sin));
	
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr =  inet_addr(SERVER_IP);
	sin.sin_port = htons(SERVER_PORT);
	
	sinLen = sizeof(sin);
	
	socketNum = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketNum < 0)
	{
		perror("\nSocket fail!");
		return;
	}
			
	if(bind(socketNum, (struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
		perror("\nBind fail!");	
		return;
	}
		
	for(i = 0; i < 5; i++)
	{
		receiveBytes = recvfrom(socketNum, buffer, sizeof(buffer),0 , (struct sockaddr*) &sin, &sinLen);
		if(receiveBytes < 0)
		{
			perror("\nReceive fail!");
			return;	
		}
		sleep(1);
		printf("%s", buffer);


		sentByte = sendto(socketNum, sendMessages[i], strlen(sendMessages[i]), 0 , (struct sockaddr*) &sin, sizeof(sin));
		if(sentByte < 0)
		{
			perror("\nSend fail!");	
			return;	
		}
	}
		
	close(socketNum);
	
	/****************IPv6********************/
	
	printf("\nIPv6:\n");
		
	memset (&sin6, 0, sizeof(sin6));
	
	sin6.sin6_family = AF_INET6;
	sin6.sin6_addr =  in6addr_loopback;
	sin6.sin6_port = htons(SERVER_PORT);
		
	sinLen = sizeof(sin6);
	
	socketNum = socket(AF_INET6, SOCK_DGRAM, 0);
	if(socketNum < 0)
	{
		perror("\nSocket fail!");
		return;
	}
			
	if(bind(socketNum, (struct sockaddr*) &sin6, sizeof(sin6)) < 0)
	{
		perror("\nBind fail!");	
		return;
	}
		
	for(i = 0; i < 5; i++)
	{
		receiveBytes = recvfrom(socketNum, buffer, sizeof(buffer),0 , (struct sockaddr*) &sin6, &sinLen);
		if(receiveBytes < 0)
		{
			perror("\nReceive fail!");
			return;	
		}
		sleep(1);
		printf("%s", buffer);


		sentByte = sendto(socketNum, sendMessages[i], strlen(sendMessages[i]), 0 , (struct sockaddr*) &sin6, sizeof(sin6));
		if(sentByte < 0)
		{
			perror("\nSend fail!");	
			return;	
		}
	}
		
	close(socketNum);
}
