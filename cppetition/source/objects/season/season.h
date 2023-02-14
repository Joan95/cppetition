#ifndef SEASON_H
#define SEASON_H


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

    private:
        T_season_period_enum period;

    protected:
};

#endif 