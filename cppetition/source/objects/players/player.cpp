#include "player.h"


Player::Player(string name, unsigned char number, unsigned char age)
{
    name = name;  
    age = age; 
    injured = false; 
    being_covered = false; 
}




bool load_players_data_base(void)
{
    return 0; 
}