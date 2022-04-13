#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#define ACCEPT_CLIENT 1
#define BUFFER_SIZE 1500

int numOfClient;

int NewClient(int _clientId)
{
numOfClient++;
return ACCEPT_CLIENT;

}

void GetMessage(Server* _server, int _clientId, void* _message, int _messageSize)
{
char message[BUFFER_SIZE];


		printf("%s", (char*)_message);

		sprintf(message, "Hi client socket no. %d\n", _clientId);
		
SendMessageToClien(_server, _clientId,  message,  strlen(message));
}

void RemoveClient(int _clientId)
{
numOfClient--;
}


void FailErr(Server* _server, ServerErr _failErr, char* _perror)
{
	printf("%d : %s\n", _failErr, _perror);
	
	if(_failErr<=8)
	{
		PauseServer(_server);
		DestroyServer(_server);	
	}
	


}

CreateInputs* CreateInputsStruct(AcceptClient _newClient, ReceiveMessage _getMessage, CloseClient _removeClient, Fail _failErr)
{
CreateInputs* inputs;

	if(_getMessage == NULL || _failErr == NULL)
	{
		return NULL;
	}
	
	if((inputs = (CreateInputs*) malloc(sizeof(CreateInputs))) == NULL)
	{
		return NULL;
	}
	
	inputs -> m_acceptClient = _newClient;
	inputs -> m_receiveMessage = _getMessage;
	inputs -> m_closeClient = _removeClient;
	inputs -> m_fail = _failErr;
	inputs -> m_clientQueueSize = 1000;
	inputs -> m_maxSokets = 1000;
	inputs -> m_context = NULL;
	inputs ->  m_maxMessageZize = 1500;

return inputs;
}



int main()
{
CreateInputs* inputs;
Server* server;
inputs = CreateInputsStruct(NewClient, GetMessage, RemoveClient, FailErr);

server = CreateServer(inputs);

RunServer(server);



free(inputs);
}
