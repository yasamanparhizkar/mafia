#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <sstream>
#include "God.hpp"

using namespace std;

#ifndef _EXCEPTION_
#define _EXCEPTION_
class Exception{
public:
	Exception( string type ): type(type){}
	string get_type(){ return type; }

private:
	string type;
};
#endif

#define UNKNOWN_ADDR 0

class Command{
public:
	Command();
	Command(Command& _src);
	virtual ~Command(){}
	void import(Command& _src);
	void extract(istream& _stream);
	void clear();
	Command* breed();
	void print();
	string get_name();
	string get_field(int index);
	string get_option(int index);
	string get_flag(int index);
	int get_fields_num();
	int get_options_num();
	int get_flags_num();
	virtual void execute(God& god) = 0;
	Room* search(God& god);

protected:
	string name;
	vector<string> fields;
	vector<string> options;
	vector<string> flags;
};

class Create_room:public Command{
public:
	Create_room():Command(){}
	virtual void execute(God& god);
	void trim();
	void check_room_name(God& god);
};

class Switch_room:public Command{
public:
	Switch_room():Command(){}
	virtual void execute(God& god);
};

class Join:public Command{
public:
	Join():Command(){}
	virtual void execute(God& god);
};

class Vote:public Command{
public:
	Vote():Command(){}
	virtual void execute(God& god);
};

class End_vote:public Command{
public:
	End_vote():Command(){}
	virtual void execute(God& god);
};

class Detect:public Command{
public:
	Detect():Command(){}
	virtual void execute(God& god);
};

class Heal:public Command{
public:
	Heal():Command(){}
	virtual void execute(God& god);
};

class Silent:public Command{
public:
	Silent():Command(){}
	virtual void execute(God& god);
};

class Get_room_state:public Command{
public:
	Get_room_state():Command(){}
	virtual void execute(God& god);
};
