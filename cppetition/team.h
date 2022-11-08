#ifndef TEAM_HEADER
#define TEAM_HEADER

#include <string>	/* For string type usage */
#include <vector>	/* For vector usage */

#include "player.h"	
#include "aux_functions.h"

class Team
{
	public:
		/* Public methods and attributes */
		Team()	/* DEFAULT CONSTRUCTOR */
		{
			name = "";
			size = 0;
			num_of_players = 0;
			list_of_players = NULL;
		};

		Team(std::string new_name, int new_size)	/* Class Constructor with parameters */
		{
			list_of_players = new Player[new_size];	/* This will call the DEFAULT Constructor at player.h */
			name = new_name;
			size = new_size;
			num_of_players = 0;
		}

		/* Setters */
		void Set_New_Team_Size(int new_size) { size = new_size; }	/* Setter for private attribute */

		/* Getters */
		std::string Get_Team_Name(void) { return name; }	/* Getter for private attribute */
		int Get_Team_Size(void) { return size; }			/* Getter for private attribute */
		int Get_Team_Num_Of_Players(void) { return num_of_players; }	/* Getter for private attribute */
		Player* Get_Team_Players(void) { return list_of_players; }		/* Getter for private attribute */
		
		int Get_Player_Based_On_Position(Player** tmp_list_of_players, player_position position)
		{
			int list_indx = 0;

			if (num_of_players > 0)
			{
				for (int i = 0; i < num_of_players; i++)
				{
					if (list_of_players[i].Get_Player_Position() == position)
					{
						/* Save player using pointer, so its stats will be visible */
						tmp_list_of_players[list_indx] = &list_of_players[i];
						list_indx++;
					}
				}
			}
			return list_indx;
		}

		/* Other methods */
		void Inscribe_New_Player_In_The_Team(Player* new_player)
		{
			list_of_players[num_of_players] = *new_player;
			num_of_players++;
		}

	private:
		/* Private methods and attributes */
		std::string name;
		int size;
		int num_of_players;
		Player* list_of_players;
};


/* Functions Declaration */
std::string Get_Random_Team_Name(void);
void Team_Sign_New_Players(Team* team);
void Team_Report_Alignment(Team* team);

#endif