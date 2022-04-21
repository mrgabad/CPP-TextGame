#include "SuperUser.h"
#include <iostream>

SuperUser::SuperUser()
{
	this->setUserType(SUPERUSER);
}

bool SuperUser::getSuperRand() const
{
	return this->SuperRand;
}

void SuperUser::setSuperRand(bool sr)
{
	this->SuperRand = sr;
}

void SuperUser::Random()
{
	RandIndx = rand() % 5; //use % to keep index in range
	SuperRand = true;
}

void SuperUser::SuperDay()
{
	if (getUserType() == SUPERUSER)
	{
		cout << getUserName() << ", have a super day!" << endl;
	}
	else cout << getUserName() << " is not a super user and does not have permissions to perform this action." << endl;
}