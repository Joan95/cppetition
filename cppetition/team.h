#ifndef TEAM_HEADER
#define TEAM_HEADER

#include <string>	/* For string type usage */
#include "player.h"	
#include "aux_functions.h"

class Team
{
	public:
		/* Public methods and attributes */
		Team() {};	/* DEFAULT CONSTRUCTOR */
		Team(std::string new_name, int new_size)	/* Class Constructor with parameters */
		{
			name = new_name;
			size = new_size;
			num_of_players = 0;
			list_of_players = new Player[new_size];	/* This will call the DEFAULT Constructor at player.h */
		}

		/* Setters */
		void Set_New_Team_Size(int new_size) { size = new_size; }	/* Setter for private attribute */

		/* Getters */
		std::string Get_Team_Name(void) { return name; }	/* Getter for private attribute */
		int Get_Team_Size(void) { return size; }			/* Getter for private attribute */
		int Get_Team_Num_Of_Players(void) { return num_of_players; }	/* Getter for private attribute */
		Player * Get_Team_Players(void) { return list_of_players; }		/* Getter for private attribute */

		/* Special methods */
		void Inscribe_New_Player_In_The_Team(Player *new_player)
		{
			list_of_players[num_of_players] = *new_player;
			num_of_players++;
		}

	private:
		/* Private methods and attributes */
		std::string name;
		int size;
		int num_of_players;
		Player * list_of_players;
};


/* Functions Declaration */
void Team_Sign_New_Players(Team *team);
void Team_Report_Alignment(Team *team);

#endif