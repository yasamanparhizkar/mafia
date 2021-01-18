#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

#define UNKNOWN_ADDR 0

using namespace std;

class Room{
public:
	Room();
	void set_name(string _name){ name = _name; }
	void add_player(string role, int number);
	//add_name()
	//assign_roles()
	//add_vote()
	//print_killed()
	//is_mafia()
	//heal()
	//silence()
	//get_state()
	string get_name(){ return name; }

private:
	enum scene_type {player_join, role_assignment, day_vote, mafia_vote, detection, healthcare, silention};
	class Table{
	public:
		Table(){}
		//add_vote()
		//clac()
		//clear()
	private:
		class Vote;
		vector<Vote> votes;
	};

	string name;
	vector<Player*> players;
	int calender;
	bool light;
	Player* target;
	Table table;
	scene_type scene;
	vector<string> names;

};

class Room::Table::Vote{
public:
	Vote(string voter_name, string votee_name):voter(voter_name), votee(votee_name){}
	string voter;
	string votee;
};
