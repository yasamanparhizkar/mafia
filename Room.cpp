#include "Room.hpp"

Room::Room():calender(1),light(true),target(UNKNOWN_ADDR),scene(player_join)
{}

void Room::add_player(string role, int number)
{
	for(int i=0; i<number; i++)
	{
		if(role == "Joker")
			players.push_back( new( Joker ) );
		else if(role == "Mafia")
			players.push_back( new( Mafia ) );
		else if(role == "Villager")
			players.push_back( new( Villager ) );
		else if(role == "GodFather")
			players.push_back( new( GodFather ) );
		else if(role == "Silencer")
			players.push_back( new( Silencer ) );
		else if(role == "Detective")
			players.push_back( new( Detective ) );
		else if(role == "Doctor")
			players.push_back( new( Doctor ) );
		else if(role == "RouinTan")
			players.push_back( new( RouinTan ) );
		else
			throw Exception("Invalid role.");
	}
}
