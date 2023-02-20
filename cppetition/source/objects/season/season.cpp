#include "season.h"
#include "season_api.h"


Season* this_season;

Season::Season()
{
    period = PRESEASON; 
    season_leagues = get_leagues();
}

T_season_period_enum Season::GetPeriod()
{
    return period;
}

unsigned char Season::GetNumLeagues()
{
    return season_leagues->num_of_leagues;
}

League* Season::GetLeague(unsigned char idx)
{
    return this->season_leagues->leagues[idx];
}


void season_init(void)
{
    /* Init season object */
    this_season = new Season();
}

void season_loop(void)
{
    League* target_league; 

    switch (this_season->GetPeriod())
    {
    case PRESEASON:
        /* 
        * Prepare teams for playing this season:
        *   - Hire new Free Agents if there are 
        */
        for (int i = 0; i < this_season->GetNumLeagues(); i++)
        {
            target_league = this_season->GetLeague(i);
            for (int j = 0; j < target_league->GetNumTeams(); j++)
            {
                target_league->GetTeam(j)->LoopContractOperation();
            }
        }
        break;

    case TRANSFER_SEASON:
        break;

    case FIRST_TRANSFER_PERIOD:
        break;

    case SEASON_PRE_INIT:
        break; 
        
    case SECOND_TRANSFER_PERIOD:
        break; 

    case SEASON_SECOND_ROUND:
        break; 

    case END_OF_SEASON:
        break; 

    default: 
        break; 
    }
}