#ifndef CONTRACT_H
#define CONTRACT_H

#include "..\players\player.h"


class Contract
{
    public:
        Contract();
        Contract(Player* player, long long _base_salary, long long _salary_increment);

    private:

    protected:
        Player* hired_player;
        long long base_salary;
        long long salary_increment_per_year;
        /* time_t hiring_date;
        time_t expiring_date; */
};


#endif