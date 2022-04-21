#include <iostream>
#include <vector>
#include "Room.h"
#include "User.h"
#include <fstream>

// students - you need to put program header here
/*Name: Marc Abad
* Date: 10/17/2020
* Section: 14
* Assignment: Module 7: Text-based game Program - Part 6
* DueDate: 10/18/2020
* About this project: The purpose of this project is to create a text-based game program where more than one player
*	moves from room to room. This time utilizing .
* Assumptions: The User will provide a name. The player can move through rooms with N,S,E,W, check who's in the room with O,
* and quit with Q.
* The rooms are in the map below:
*
*							Cave (Index 1)
* White House (Index 2)		Times Square (Index 0)		Eiffel Tower (Index 3)
*							Forest (Index 4)
*
* All work below was performed by Marc Abad with some code provided by Dr. Works*/
using namespace std;

//number of rooms
const int NUM_ROOMS = 5;

int User::indexUserTurn = 0;

////////////////////////////////////////////////////
// sets up rooms
void initRooms(Room rooms[]);
// sets up User
void initUser(User& u);
// sets up/loads data file
void initData(vector <User> &Users);
// changes data file
void setData(User u);

//User selects an action
void promptUserAction(const User* u, const Room rooms[], string& strCh);
//implement Users Action
void implementUserAction(User* u, const Room rooms[], const vector <User> Users, const string strCh);

int main() {
	Room rooms[NUM_ROOMS];
	User user1;	//  definition of user1 as an instance of User class
	User user2; //  second instance of User class
	Room* rm = rooms;

	//initialize User and rooms
	initRooms(rm);

	//vector of users
	vector <User> Users;
	Users.push_back(user1);
	Users.push_back(user2);

	string strData;
	cout << "Do you want to load stored user data (Y/N)?" << endl;
	cin >> strData;
	if ((strData == "Y") || (strData == "y"))
	{
		initData(Users);
	}
	else initUser(user1);

	//welcome
	cout << "Welcome to my game!" << endl;	// 5) changed to simple welcome message

	string UserAction;
	int indexNextUser = 0;
	do
	{
		//display whose turn
		cout << "*************" << endl;
		cout << Users.at(indexNextUser) << "'s turn" << endl;

		promptUserAction(&Users.at(indexNextUser), rooms, UserAction);
		implementUserAction(&Users.at(indexNextUser), rooms, Users, UserAction);

		if ((UserAction == "Q") || (UserAction == "q"))
		{
			Users.erase(Users.begin() + indexNextUser);
		}
		if (Users.size() > 0)
		{
			indexNextUser = User::getNextIndexUser(Users.size());
		}
	} while (Users.size() > 0); //continue until all users decide to quit
	return 0;
}

// sets up rooms
void initRooms(Room rooms[])
{
	//init Cave (Index 1 - northmost position)
	(rooms + 1)->setName("Cave");
	(rooms + 1)->setDesc("Description: Spooky & Scary!");
	(rooms + 1)->setIndexRoomToNorth(-99);
	(rooms + 1)->setIndexRoomToSouth(0);
	(rooms + 1)->setIndexRoomToEast(-99);
	(rooms + 1)->setIndexRoomToWest(-99);
	//init Forest (Index 4 - southmost position)
	(rooms + 4)->setName("Forest");
	(rooms + 4)->setDesc("Description: Wow! Trees!");
	(rooms + 4)->setIndexRoomToNorth(0);
	(rooms + 4)->setIndexRoomToSouth(-99);
	(rooms + 4)->setIndexRoomToEast(-99);
	(rooms + 4)->setIndexRoomToWest(-99);
	//init Eiffel Tower (Index 3 - eastmost position)
	(rooms + 3)->setName("Eiffel Tower");
	(rooms + 3)->setDesc("Description: Pointy and also French!");
	(rooms + 3)->setIndexRoomToNorth(-99);
	(rooms + 3)->setIndexRoomToSouth(-99);
	(rooms + 3)->setIndexRoomToEast(-99);
	(rooms + 3)->setIndexRoomToWest(0);
	//init White House (Index 2 - westmost position)
	(rooms + 2)->setName("White House");
	(rooms + 2)->setDesc("Description: Wow! Very Presidential!");
	(rooms + 2)->setIndexRoomToNorth(-99);
	(rooms + 2)->setIndexRoomToSouth(-99);
	(rooms + 2)->setIndexRoomToEast(0);
	(rooms + 2)->setIndexRoomToWest(-99);
	//init Times Square (Index 0 - middle position)
	rooms->setName("Times Square");
	rooms->setDesc("Description: New York! New York!");
	rooms->setIndexRoomToNorth(1);
	rooms->setIndexRoomToSouth(4);
	rooms->setIndexRoomToEast(3);
	rooms->setIndexRoomToWest(2);
}

// sets up user
void initUser(User& u)
{
	//prompt User for name
	string tempname;
	cout << "What is your name?" << endl;
	cin >> tempname;
	u = User(tempname, 0);
}

// sets up data file
void initData(vector <User> &Users)
{
	ifstream inputFile("data.txt");
	string name;
	int indx;

	if (inputFile.fail())
	{
		cout << "Error opening data.txt" << endl;
		exit(1);
	}

	for (unsigned int i = 0; i < Users.size() && inputFile >> name >> indx; i++)
	{
		Users[i].setUserName(name);
		Users[i].setIndexOfCurrentRoom(indx);
	}
	inputFile.close();
}

void setData(User u)
{
	fstream outputFile("data.txt", ios::out | ios::app);
	if (outputFile.fail())
	{
		cout << "Error opening data.txt" << endl;
		exit(1);
	}

	outputFile << u.getUserName() << " " << u.getIndexOfCurrentRoom() << endl;
	outputFile << flush;
	outputFile.close();
}

//User Action
void promptUserAction(const User* u, const Room rooms[], string& strCh)
{
	//where the user is
	int current = u->getIndexOfCurrentRoom();

	// tell user where they are
	cout << (*u) << " you are currently in " << rooms[current];

	//prompt user for choice
	cout << "What would you like to do?" << endl;
	cin >> strCh;
}
//implement Users Action
void implementUserAction(User* u, const Room rooms[], const vector <User> Users, const string strCh) //changed parameter for User comparison
{
	int current = u->getIndexOfCurrentRoom();
	if ((strCh == "N") || (strCh == "n"))
	{
		//User has selected to move north

		// is it possible to move north from the room the User
		//is currently in
		int indxRoomNorth = rooms[current].getIndexRoomToNorth();
		if (indxRoomNorth != -99)
		{
			u->setIndexOfCurrentRoom(indxRoomNorth);
			cout << u->getUserName() << ", you are now in " << rooms[indxRoomNorth].getName() << endl; //changed getName to u
		}
		else {
			cout << u->getUserName() << ", you can not move north from " << rooms[current].getName() << endl;
		}
	}
	else if ((strCh == "S") || (strCh == "s"))
	{
		//User has selected to move south

		// is it possible to move south from the room the User
		//is currently in
		int indxRoomSouth = rooms[current].getIndexRoomToSouth();
		if (indxRoomSouth != -99)
		{
			u->setIndexOfCurrentRoom(indxRoomSouth);
			cout << u->getUserName() << ", you are now in " << rooms[indxRoomSouth].getName() << endl;

		}
		else {
			cout << u->getUserName() << ", you can not move south from " << rooms[current].getName() << endl;
		}
	}
	else if ((strCh == "E") || (strCh == "e"))	//added identical east and west options
	{
		//User has selected to move east

		// is it possible to move east from the room the User
		//is currently in
		int indxRoomEast = rooms[current].getIndexRoomToEast();
		if (indxRoomEast != -99)
		{
			u->setIndexOfCurrentRoom(indxRoomEast);
			cout << u->getUserName() << ", you are now in " << rooms[indxRoomEast].getName() << endl;

		}
		else {
			cout << u->getUserName() << ", you can not move east from " << rooms[current].getName() << endl;
		}
	}
	else if ((strCh == "W") || (strCh == "w"))
	{
		//User has selected to move west

		// is it possible to move west from the room the User
		//is currently in
		int indxRoomWest = rooms[current].getIndexRoomToWest();
		if (indxRoomWest != -99)
		{
			u->setIndexOfCurrentRoom(indxRoomWest);
			cout << u->getUserName() << ", you are now in " << rooms[indxRoomWest].getName() << endl;

		}
		else {
			cout << u->getUserName() << ", you can not move west from " << rooms[current].getName() << endl;
		}
	}
	else if ((strCh == "O") || (strCh == "o"))
	{
		//User wants to know who else is in the room
		cout << "The following users are also in the room... " << endl;
		for (User usr : Users)
		{
			if (usr == (*u))
			{
				cout << usr.getUserName() << endl;
			}
		}
	}
	else if ((strCh == "Q") || (strCh == "q"))
	{
		//User has selected to quit
		cout << "Thank you for playing..." << endl;
		string strQ;
		cout << "Do you want to save this user's data? y/n" << endl;
		cin >> strQ;
		if ((strQ == "Y") || (strQ == "y"))
		{
			setData(*u);
		}
		else if ((strQ == "N") || (strQ == "n"))
		{
			remove("data.txt");
		}
	}
	else
	{
		//User has selected an invalid option
		cout << strCh << " is not a valid option." << endl;
	}
}

bool User::operator ==(const User& otherUser)
{
	return (indexCurrentRoom == otherUser.indexCurrentRoom);
}

//overload <<
ostream& operator <<(ostream& outputStream, const User& u)
{
	outputStream << u.Username;
	return outputStream;
}

//overload <<
ostream& operator <<(ostream& outputStream, const Room& room)
{
	outputStream << room.Name << endl;
	outputStream << room.Desc << endl;
	return outputStream;
}