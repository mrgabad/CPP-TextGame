#include <iostream>
#include <vector>
using namespace std;

#ifndef ROOM_H
#define ROOM_H

//room class (interface)
class Room
{
public:
	// return the name of the room
	string getName() const {
		return this->Name;
	};

	//set the name of the room
	void setName(string nm) {
		this->Name = nm;
	};

	// return the description of the room
	string getDesc() const {
		return this->Desc;
	};

	//set the description of the room
	void setDesc(string ds) {
		this->Desc = ds;
	};

	//set the index of the room to the north
	void setIndexRoomToNorth(int indx);
	//get the index of the room to the north
	int getIndexRoomToNorth() const;

	//set the index of the room to the south
	void setIndexRoomToSouth(int indx);
	//get the index of the room to the south
	int getIndexRoomToSouth() const;

	//set the index of the room to the east
	void setIndexRoomToEast(int indx);
	//get the index of the room to the east
	int getIndexRoomToEast() const;

	//set the index of the room to the west
	void setIndexRoomToWest(int indx);
	//get the index of the room to the west
	int getIndexRoomToWest() const;

	//overload <<
	friend ostream& operator<<(ostream& outputStream, const Room& room);

private:
	string Name; //name of room
	string Desc; //description of room
	int IndexOfRoomToNorth; //index of room to north
	int IndexOfRoomToSouth; //index of room to south
	int IndexOfRoomToEast;  //index of room to east
	int IndexOfRoomToWest;  //index of room to west
};

#endif