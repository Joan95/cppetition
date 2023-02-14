#ifndef TEAM_H
#define TEAM_H

#include "..\..\lib\types.h"
#include "..\players\player.h"

#define MAX_PLAYERS_ALLOWED     11
#define MIN_PLAYERS_ALLOWED     7

class Team
{
    public: 
        Team();
        Team(std::string _name);

    private:
        std::string name; 
        unsigned char num_of_players;
        Player* list_of_players;
        long long int budget; 

    protected: 

};

void team_register_new_team(Team* new_team);


#endif