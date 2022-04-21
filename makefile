#makefile Text Based Game
CC= g++ -std=c++11
Game: TextBasedGamePart7.o Room.o User.o SuperUser.o UserList.o
	$(CC) TextBasedGamePart7.o Room.o User.o SuperUser.o UserList.o -o Game
	
TextBasedGamePart7.o: TextBasedGamePart7.cpp
	$(CC) -c TextBasedGamePart7.cpp

Room.o: Room.h Room.cpp
	$(CC) -c Room.h
	$(CC) -c Room.cpp
	
User.o: User.h User.cpp
	$(CC) -c User.h
	$(CC) -c User.cpp

SuperUser.o: SuperUser.h SuperUser.cpp
	$(CC) -c SuperUser.h
	$(CC) -c SuperUser.cpp

UserList.o: UserList.h UserList.cpp
	$(CC) -c UserList.h
	$(CC) -c UserList.cpp
	
clean:
	rm -rf *o Game

