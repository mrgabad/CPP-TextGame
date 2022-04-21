#include "Room.h"
//implementation file for Room Class
//set the index of the room to the north
void Room::setIndexRoomToNorth(int indx)
{
	this->IndexOfRoomToNorth = indx;
};

//get the index of the room to the north
int Room::getIndexRoomToNorth() const
{
	return this->IndexOfRoomToNorth;
};

//set the index of the room to the south
void Room::setIndexRoomToSouth(int indx)
{
	this->IndexOfRoomToSouth = indx;
};

//get the index of the room to the south
int Room::getIndexRoomToSouth() const
{
	return this->IndexOfRoomToSouth;
};

//set the index of the room to the east
void Room::setIndexRoomToEast(int indx) //2a Mutator Function
{
	this->IndexOfRoomToEast = indx;
};

//get the index of the room to the east
int Room::getIndexRoomToEast() const//2a Accessor Function
{
	return this->IndexOfRoomToEast;
};

//set the index of the room to the west
void Room::setIndexRoomToWest(int indx) //2b Mutator Function
{
	this->IndexOfRoomToWest = indx;
};

//get the index of the room to the west
int Room::getIndexRoomToWest() const //2b Accessor Function
{
	return this->IndexOfRoomToWest;
};

/*
//overload <<
ostream& operator <<(ostream& outputStream, const Room& room)
{
	outputStream << room.Name << endl;
	outputStream << room.Desc << endl;
	return outputStream;
}*/