#ifndef TEAM_H
#define TEAM_H

#include "..\..\lib\types.h"
#include "..\..\lib\soccer_types.h"

#define MAX_PLAYERS_ALLOWED     21
#define MIN_PLAYERS_ALLOWED     11


typedef struct
{
    T_soccer_position_enum position_to_hire;
    long long position_budget;
} T_team_needs;

/*
* 
*/
class Team
{
    public:
        Team(std::string _name);
        void DetectNeeds(void);
        void LoopContractOperation(void);

    private:
        std::string name; 
        unsigned char num_of_contracts;
        unsigned char num_of_offers_made;
        long long int budget; 
        bool ready_to_play;
        T_team_needs* list_of_needs;


    protected: 

};


#endif