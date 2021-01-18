#include "Player.hpp"

void Player::hang()
{
	if(life < 1)
		throw Exception("User already died");
	life = 0;
}
void Player::kill()
{
	if(life < 1)
		throw Exception("User already died");
	life--;
}
void Player::heal()
{ life++; }
string Player::type()
{ return "Player"; }
string Player::get_name()
{ return name; }
bool Player::is_silent()
{ return silent; }
void Player::set_name(string _name)
{ name = _name; }
void Player::set_silent(bool value)
{ silent = value; }
