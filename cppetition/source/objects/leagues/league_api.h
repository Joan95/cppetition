#ifndef LEAGUE_API_H
#define LEAGUE_API_H

#include "..\teams\team.h"
#include "league.h"

#define LEAGUE_VERSION      1

/*
* 
*/
void league_register_team_to_league(std::string league_name, Team * team);


#endif