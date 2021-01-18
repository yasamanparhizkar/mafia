#include <iostream>
#include <vector>
#include "Room.hpp"

#define UNKNOWN_ADDR 0

using namespace std;

class God{
public:
	God():current_room(UNKNOWN_ADDR){}
	void add_room(string room_name);
	int get_room_num(){ return rooms.size(); }
	Room* get_room(int index);
	Room* get_current_room(){ return current_room; }
	void set_current_room(Room* target);

private:
	vector<Room*> rooms;
	Room* current_room;
};
