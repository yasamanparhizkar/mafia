#include "God.hpp"

void God::add_room(string room_name)
{
	rooms.push_back( new( Room ) );
	current_room = rooms[rooms.size()-1];
	current_room->set_name(room_name);
}
Room* God::get_room(int index)
{ return rooms[index]; }
void God::set_current_room(Room* target)
{ current_room = target; }
