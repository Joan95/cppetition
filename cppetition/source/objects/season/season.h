#ifndef SEASON_H
#define SEASON_H

#include "..\leagues\league_api.h"

typedef enum
{
    PRESEASON       = 0,
    TRANSFER_SEASON,
    FIRST_TRANSFER_PERIOD,
    SEASON_PRE_INIT,
    SECOND_TRANSFER_PERIOD,
    SEASON_SECOND_ROUND,
    END_OF_SEASON
} T_season_period_enum;


/*
* 
*/
class Season
{
    public:
        Season();
        T_season_period_enum GetPeriod();
        unsigned char GetNumLeagues();
        League* GetLeague(unsigned char idx);

    private:
        T_season_period_enum period;
        T_leagues_struct * season_leagues;

    protected:
};

#endif 