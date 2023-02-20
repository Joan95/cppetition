#include "league.h"
#include "league_api.h"

static League** list_of_leagues;
static unsigned char num_of_leagues;

League::League()
{
    num_of_teams = 0;
    list_of_teams = nullptr;
}

League::League(std::string _name)
{
    name = _name;
    num_of_teams = 0;
}

void League::AddTeam(Team* team)
{
    if (list_of_teams == nullptr)
    {
        /* List of teams has not been initialized */
        list_of_teams = new Team * [1];
        list_of_teams[num_of_teams++] = team;
    }
    else
    {
        /* List of teams has been previously initialized, just resize it */
        Team** new_list_of_teams = new Team * [num_of_teams + 1];
        std::copy(list_of_teams, list_of_teams + num_of_teams, new_list_of_teams);
        delete[] list_of_teams;
        list_of_teams = new_list_of_teams;
        list_of_teams[num_of_teams++] = team;
    }

}

std::string League::GetLeagueName(void)
{
    return name;
}

unsigned char League::GetNumTeams(void)
{
    return this->num_of_teams;
}

Team* League::GetTeam(unsigned char idx)
{
    return this->list_of_teams[idx];
}

void league_register_team_to_league(std::string league_name, Team * team)
{
    unsigned char i = 0; 
    League* newLeague; 
    bool leagueFound = false; 

    /* Check if there is some league */
    if (list_of_leagues == nullptr)
    {
        newLeague = new League(league_name);
        num_of_leagues = 0; 
        list_of_leagues = new League * [1];
        list_of_leagues[num_of_leagues++] = newLeague;

        newLeague->AddTeam(team);
    }
    else
    {
        /* There is some league */
        /* Check whether league is present or not */
        while((!leagueFound) && (i < num_of_leagues))
        {
            if (list_of_leagues[i]->GetLeagueName() == league_name)
            {
                /* League is there, just add team into league */
                leagueFound = true;
                list_of_leagues[i]->AddTeam(team);
            }
            i++;
        }

        /* Check if league could be found */
        if (!leagueFound)
        {
            /* League was not found, add and resize league list */
            newLeague = new League(league_name);

            League** new_list_of_leagues = new League * [num_of_leagues + 1];
            std::copy(list_of_leagues, list_of_leagues + num_of_leagues, new_list_of_leagues);
            delete[] list_of_leagues;
            list_of_leagues = new_list_of_leagues;
            list_of_leagues[num_of_leagues++] = newLeague;

            /* Add team to this league */
            newLeague->AddTeam(team);
        }
    }
}

T_leagues_struct * get_leagues(void)
{
    T_leagues_struct * leagues = new T_leagues_struct;
    leagues->leagues = list_of_leagues;
    leagues->num_of_leagues = num_of_leagues;
    return leagues;
}