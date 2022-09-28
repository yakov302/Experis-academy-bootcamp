#include "user.h"

User* CreateNewUser (FirstAndSecond* _namePsw)
{
	User* newUser = (User*) malloc (sizeof(User));
	if (newUser == NULL)
	{return NULL;}

	newUser->m_groups = ListCreate();
	if (newUser->m_groups == NULL)
	{
		free(newUser);
		return NULL;
	}

	strcpy (newUser->m_username,_namePsw->m_first);
	strcpy (newUser->m_password, _namePsw->m_second);
	newUser->m_active = NO_ACTIVE;
	return newUser;
}

static void destroyGrupName(void* _name)
{
	free(_name);
}

void DestroyUser (User* _user)
{
	if (_user == NULL || _user->m_magicNumber != MAGIC_NUMBER)
	{return;}

	_user->m_magicNumber = 0;
	ListDestroy(&(_user->m_groups), destroyGrupName);
	free (_user);
}

void GetUserPassword (User* _user, char _password[])
{
	if (_user == NULL)
	{return;}

	strcpy (_password, _user -> m_password);
}

int GetUserStatus (User* _user)
{
	return _user->m_active;
}

void SetUserStatus (User* _user, int _status)
{
	_user->m_active = _status;
}

int AddGroupForUser (User* _user, char* _groupName)
{
	char* groupName;
	ListItr begin, end;
	void* pValue;

 	begin = ListItrBegin(_user->m_groups);
	end = ListItrEnd(_user->m_groups);

	while (begin != end)
	{
		pValue = ListItrGet(begin);
		if (strcmp ((char*) pValue, _groupName) != 0)
		{
			begin = ListItrNext(begin);
		}
		else
		{
			return ALREADY_IN_THE_GROUP;
		}
	}
	groupName = malloc (sizeof(char)*SIZE);
	if (groupName == NULL)
	{return USER_STRUCT_MALLOC_FAIL;}

	strcpy (groupName, _groupName);
	ListPushTail(_user->m_groups, groupName);
	return USER_STRUCT_SUCCESS;
}
	
int RemoveGroupFromUser (User* _user, char* _groupName)
{
	ListItr begin, end;
	void* pValue;

 	begin = ListItrBegin(_user->m_groups);
	end = ListItrEnd(_user->m_groups);

	while (begin != end)
	{
		pValue = ListItrGet(begin);
		if (strcmp ((char*) pValue, _groupName) != 0)
		{
			begin = ListItrNext(begin);
		}
		else
		{
			ListItrRemove(begin);
			return USER_STRUCT_SUCCESS;
		}
	}
	return USER_STRUCT_NOT_FOUND_IN_HASH;
}

int UserNotActive (User* _user)
{
	ListItr itr, end;

	itr = ListItrBegin(_user ->m_groups);
	end  = ListItrEnd(_user ->m_groups);

	while (itr != end)
	{	
		ListItrRemove(itr);
		itr = ListItrNext(itr);
	}

	_user->m_active = NO_ACTIVE;
	return USER_STRUCT_SUCCESS;
}	
