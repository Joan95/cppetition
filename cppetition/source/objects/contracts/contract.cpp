#include <ctime>    /* For date management */

#include "contract.h"
#include "contract_api.h"

Contract::Contract()
{
    base_salary = 0; 
    salary_increment_per_year = 0; 
}

Contract::Contract(Player* player, long long _base_salary, long long _salary_increment)
{
    hired_player = player;
    base_salary = _base_salary;
    salary_increment_per_year = _salary_increment;
}