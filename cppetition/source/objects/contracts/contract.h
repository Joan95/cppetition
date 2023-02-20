#ifndef CONTRACT_H
#define CONTRACT_H

#include "..\players\player.h"
#include "..\teams\team.h"

typedef enum
{
    NO_OFFER_RECEIVED = 0, 
    TEAM_OFFERED_A_DEAL,
    PLAYER_WAITING_FOR_RE_DEAL,
    PLAYER_OFFER_ACCEPTED,
    PLAYER_OFFER_DENIED
} T_contract_stage_enum;

typedef enum
{
    FREE_AGENT = 0,
    IN_A_TEAM,
    TO_BE_TRANSFERRED,
    TO_BE_FIRED
} T_contract_status_enum;


class Contract
{
    public:
        Contract();
        void SetPlayer(Player* player);
        Player* GetPlayer();
        void SetTeam(Team* team);
        Team* GetTeam();

    private:

    protected:
        Player* player_contract;
        Team* hired_by;
        T_contract_stage_enum contract_stage;
        T_contract_status_enum contract_status;
        long long base_salary;
        long long salary_increment_per_year;
        /* time_t hiring_date;
        time_t expiring_date; */
};


#endif