#include "myCommand.hpp"

int stoi(string src)
{
	int number;
	stringstream ss;
	ss<<src;
	ss>>number;
}

Command::Command()
{}
Command::Command(Command& _src)
{
	name = _src.get_name();

	for(int i=0; i<_src.get_fields_num(); i++)
		fields.push_back( _src.get_field(i) );

	for(int i=0; i<_src.get_options_num(); i++)
		options.push_back( _src.get_option(i) );

	for(int i=0; i<_src.get_flags_num(); i++)
		flags.push_back( _src.get_flag(i) );
}
void Command::import(Command& _src)
{
	name = _src.get_name();

	for(int i=0; i<_src.get_fields_num(); i++)
		fields.push_back( _src.get_field(i) );

	for(int i=0; i<_src.get_options_num(); i++)
		options.push_back( _src.get_option(i) );

	for(int i=0; i<_src.get_flags_num(); i++)
		flags.push_back( _src.get_flag(i) );
}
void Command::extract(istream& _stream)
{
	if( _stream.eof() )
		throw Exception( "End of file reached." );

	clear();

	string _line;
	getline(_stream, _line);

	stringstream _linestream;
	_linestream.str(_line);

	_linestream >> name;
	if( name == "" )
		throw Exception("Empty Command.");

	while( !_linestream.eof() )
	{
		string _command;
		_linestream >> _command;

		if( _command == "" )
			continue;
		else if( _command[0] != '-' )
			fields.push_back( _command );
		else
		{
			_command = _command.substr( 1, _command.size()-1);
			if( _command == "" )
				throw Exception("expected an option after \'-\' .");
			options.push_back( _command );

			if( _linestream.eof() )
			 	throw Exception( "Option entered with no flags." );

			_linestream >> _command;
			if( _command == "" )
				throw Exception( "Option entered with no flags." );
			else if( _command[0] != '-' )
				flags.push_back( _command );
			else
				throw Exception( "Option entered with no flags." );
		}
	}
}
void Command::clear()
{
	name.erase();
	fields.clear();
	options.clear();
	flags.clear();
}
Command* Command::breed()
{
	if(name == "Create_room")
	{
		Command* c = new( Create_room );
		c->import((*this));
		return c;
	}
	else if(name == "Switch_room")
	{
		Command* c = new( Switch_room );
		c->import((*this));
		return c;
	}
	else if(name == "Join")
	{
		Command* c = new( Join );
		c->import((*this));
		return c;
	}
	else if(name == "Vote")
	{
		Command* c = new( Vote );
		c->import((*this));
		return c;
	}
	else if(name == "End_vote")
	{
		Command* c = new( End_vote );
		c->import((*this));
		return c;
	}
	else if(name == "Detect")
	{
		Command* c = new( Detect );
		c->import((*this));
		return c;
	}
	else if(name == "Heal")
	{
		Command* c = new( Heal );
		c->import((*this));
		return c;
	}
	else if(name == "Silent")
	{
		Command* c = new( Silent );
		c->import((*this));
		return c;
	}
	else if(name == "Get_room_state")
	{
		Command* c = new( Get_room_state );
		c->import((*this));
		return c;
	}
	else
		throw Exception("Invalid command.");
}
void Command::print()
{
	cout<<"   **Command**   "<<endl;
	cout<<"name: "<<name<<endl;

	for( int i=0; i<fields.size(); i++ )
		cout<<"field "<<i<<" : "<<fields[i]<<endl;
	for( int i=0; i<options.size(); i++ )
		cout<<"option "<<i<<" : "<<options[i]<<"   flag: "<<flags[i]<<endl;
}
string Command::get_name()
{ return name; }
string Command::get_field(int index)
{ return fields[index]; }
string Command::get_option(int index)
{ return options[index]; }
string Command::get_flag(int index)
{ return flags[index]; }
int Command::get_fields_num()
{ return fields.size(); }
int Command::get_options_num()
{ return options.size(); }
int Command::get_flags_num()
{ return flags.size(); }
Room* Command::search(God& god)
{
	string room_name = fields[fields.size()-1];

	for(int i=0; i<god.get_room_num(); i++)
		if( god.get_room(i)->get_name() == room_name )
			return god.get_room(i);
	return UNKNOWN_ADDR;
}


void Create_room::execute(God& god)
{
	if(fields.size() < 1)
		throw Exception("Invalid room name");
	if(options.size() < 1)
		throw Exception("Roles not enetered.");

	check_room_name(god);
	god.add_room( fields[fields.size()-1] );

	trim();
	Room* current = god.get_current_room();
	for(int i=0; i<options.size(); i++)
		current->add_player(options[i], stoi(flags[i]) );

}
void Create_room::trim()
{
	for(int i=0; i<options.size(); i++)
		for(int j=i+1; j<options.size(); j++)
			if( options[i] == options[j] )
			{
				flags[i]=flags[j];
				options.erase( options.begin()+j );
				flags.erase( flags.begin()+j );
				j--;
			}
}
void Create_room::check_room_name(God& god)
{
	Room* r = search(god);
	if(r != UNKNOWN_ADDR)
		throw Exception("Invalid room name");
}


void Switch_room::execute(God& god)
{
	if(fields.size() < 1)
		throw Exception("Invalid room name");

	Room* next_room = search(god);
	if( next_room == UNKNOWN_ADDR )
		throw Exception("Invalid room name");
	god.set_current_room(next_room);
}


void Join::execute(God& god)
{

}


void Vote::execute(God& god)
{

}


void End_vote::execute(God& god)
{

}


void Detect::execute(God& god)
{

}


void Heal::execute(God& god)
{

}


void Silent::execute(God& god)
{

}


void Get_room_state::execute(God& god)
{

}
