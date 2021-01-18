#include <iostream>
#include <string>
#include <vector>

#define DEF_LIFE 1
#define ROUIN_LIFE 2

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

class Player{
public:
	Player():life(DEF_LIFE),silent(false){}
	void hang();
	void kill();
	void heal();
	virtual string type();
	string get_name();
	bool is_silent();
	void set_name(string _name);
	void set_silent(bool value);
protected:
	string name;
	int life;
	bool silent;
};

class Joker:public Player{
public:
	Joker():Player(){}
	virtual string type(){ return "Joker"; }
};

class Mafia:public Player{
public:
	Mafia():Player(){}
	virtual string type(){ return "Mafia"; }
};

class Villager:public Player{
public:
	Villager():Player(){}
	virtual string type(){ return "Villager"; }
};

class GodFather:public Mafia{
public:
	GodFather():Mafia(){}
	virtual string type(){ return "GodFather"; }
};

class Silencer:public Mafia{
public:
	Silencer():Mafia(){}
	virtual string type(){ return "Silencer"; }
};

class Detective:public Villager{
public:
	Detective():Villager(){}
	virtual string type(){ return "Detective"; }
};

class Doctor:public Villager{
public:
	Doctor():Villager(){}
	virtual string type(){ return "Doctor"; }
};

class RouinTan:public Villager{
public:
	RouinTan():Villager(){ life = ROUIN_LIFE; }
	virtual string type(){ return "RouinTan"; }
};
