#include <fstream>      /* For file reading purposes */
#include <vector>       /* For vector usage */

#include "team_api.h"
#include "team.h"
#include "..\..\os\databases\data_base_api.h"
#include "..\leagues\league_api.h"


Team** list_of_teams;
unsigned int num_of_teams;


Team::Team(std::string _name)
{
    name = _name; 
    Player** list_of_players = new Player * [MAX_PLAYERS_ALLOWED];
    ready_to_play = false;
}


void team_register_new_team(Team* new_team)
{
    if (list_of_teams == nullptr)
    {
        /* List of teams has not been initialized */
        list_of_teams = new Team * [1];
        num_of_teams = 0;
        list_of_teams[num_of_teams++] = new_team;
    }
    else
    {
        /* List of teams has been previously initialized, just resize it */
        Team** new_list_of_teams = new Team * [num_of_teams + 1];
        std::copy(list_of_teams, list_of_teams + num_of_teams, new_list_of_teams);
        delete[] list_of_teams;
        list_of_teams = new_list_of_teams;
        list_of_teams[num_of_teams++] = new_team;
    }
}

bool team_load_data_base(std::string path_to_data_base)
{
    Team* newTeam;
    std::string dbTeamLine;
    std::vector<std::string> team_attributes;

    /* Read and create players accordingly */
    ifstream TeamDB(path_to_data_base);

    if (TeamDB)
    {
        while (getline(TeamDB, dbTeamLine))
        {
            team_attributes = data_base_parse_line(dbTeamLine);
            newTeam = new Team(team_attributes[0]);
            team_register_new_team(newTeam);
            league_register_team_to_league(team_attributes[1], newTeam);
        }

        TeamDB.close();
        return 1;
    }
    else
    {
        /* File not found error */
        return 0;
    }
}

