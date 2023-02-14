#ifndef LEAGUE_H
#define LEAGUE_H

#include "..\..\lib\types.h"
#include "..\teams\team.h"


class League
{
    public: 
        League();
        League(std::string _name);
        void addTeam(Team* team);
        std::string GetLeagueName(void);

    private: 
        std::string name;
        Team** list_of_teams;
        unsigned char num_of_teams;

    protected: 

};

#endif