#ifndef MATCH_H
#define MATCH_H

#include "..\teams\team.h"
#include "..\faults\fault.h"


typedef struct
{
    Team* local_team;
    Team* visitor_team;
    unsigned char local_num_goals; 
    unsigned char visitor_num_goals;
    Fault* faults_list; 
} T_match_attributes;


/*
* 
*/
class Match
{
    public:
        Match();

    private:

    protected: 

};


/*
* 
*/
void match_schedule_random_match();


#endif 