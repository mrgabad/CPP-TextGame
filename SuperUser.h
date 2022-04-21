#include "User.h"
#include <iostream>

#ifndef SUPERUSER_H
#define SUPERUSER_H

class SuperUser : public User
{
public:
	SuperUser();
	//accessor and mutator functions for bool
	bool getSuperRand() const;
	void setSuperRand(bool sr);
	void SuperDay();

	void Random();
	int RandIndx = 0;

private:
	bool SuperRand;
};

#endif //SUPERUSER_H