#include <ctime>    /* For date management */

#include "contract.h"
#include "contract_api.h"

static Contract** list_of_contracts;
static unsigned int num_of_contracts;


Contract::Contract()
{
    player_contract = nullptr;
    hired_by = nullptr;
    contract_status = FREE_AGENT;
    base_salary = 0; 
    salary_increment_per_year = 0; 
}

void Contract::SetPlayer(Player* player)
{
    player_contract = player;
}

Player* Contract::GetPlayer()
{
    return player_contract;
}

void Contract::SetTeam(Team* team)
{
    if (team != nullptr)
    {
        hired_by = team;
        contract_status = IN_A_TEAM;
    }
    else
    {
        exit(-1);
    }
}

Team* Contract::GetTeam()
{
    return hired_by; 
}


void contract_generate_new_contract(Player* newPlayer)
{
    Contract* new_contract = new Contract();
    new_contract->SetPlayer(newPlayer);

    if (list_of_contracts == nullptr)
    {
        /* List of players has not been initialized */
        list_of_contracts = new Contract * [1];
        num_of_contracts = 0;
        list_of_contracts[num_of_contracts++] = new_contract;
    }
    else
    {
        /* List of players has been previously initialized, just resize it */
        Contract** new_list_of_contracts = new Contract * [num_of_contracts + 1];
        std::copy(list_of_contracts, list_of_contracts + num_of_contracts, new_list_of_contracts);
        delete[] list_of_contracts;
        list_of_contracts = new_list_of_contracts;
        list_of_contracts[num_of_contracts++] = new_contract;
    }
    
}