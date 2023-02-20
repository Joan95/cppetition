#ifndef LEAGUE_API_H
#define LEAGUE_API_H

#include "..\teams\team.h"
#include "league.h"

#define LEAGUE_VERSION      1

typedef struct
{
    League** leagues;
    unsigned char num_of_leagues;
} T_leagues_struct;

/*
* 
*/
void league_register_team_to_league(std::string league_name, Team * team);


/*
* 
*/
T_leagues_struct * get_leagues(void);


#endif