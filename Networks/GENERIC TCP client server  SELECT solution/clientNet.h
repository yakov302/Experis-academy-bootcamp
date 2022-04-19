#ifndef __CLIENT_NET_H__
#define __CLIENT_NET_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/select.h>
#include <unistd.h>

/************************ClientResultEnum*************************/

typedef enum ClientResult
{
CLIENT_SUCCESS,
CLIENT_FAIL,
CLIENT_NULL,
CLIENT_ALLOCATION_FAIL
} ClientResult;

/************************ClientResultEnum*************************/

typedef struct Client Client;
typedef struct GroupAndId GroupAndId;

/*Description:
Creates new socket for communication with server.

Input:
_sin - struct which the socket will enter.

Output:
soket - new socket for communication with server.*/
int ClientInitialization(struct sockaddr_in *_sin);

/*Description:
Connects to the server and sends/receives message from him.

Input:
_client - Pointer to the client struct.
_buffer - buffer with a message to send and the message that received will also enter it.
_length - The length of the message.*/
void RunClientNet(Client* _client, char* _buffer, int _length);

/*Description:
sends/receives message from server.

Input:
_client - Pointer to the client struct.
_buffer - buffer with a message to send and the message that received will also enter it.
_length - The length of the message.*/
void SendRecive(Client* _client, char* _buffer, int _length);



#endif 
