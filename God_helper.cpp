#include <iostream>
#include <vector>
#include <string>
#include "myCommand.hpp"

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

using namespace std;

int main()
{
	God god;
	Command* command = new( Create_room );

	while(true)
	{
		try
		{
			command->extract( cin );
			Command* temp = command->breed();
			delete command;
			command = temp;
			command->execute(god);
		}
		catch(Exception e)
		{
			cout<<e.get_type()<<endl;

			if( e.get_type() == "End of file reached." )
				break;
		}

	}



	return 0;
}
