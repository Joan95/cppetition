#include "team.h"


void Team_Sign_New_Players(Team *team)
{
	int i = 0;
	int team_size = team->Get_Team_Size();
	Player *player; /* Create null pointer to object Player for later init */

	if (team_size > 0)
	{
		/* Special case for Goalkeeper */
		player = new Player(Get_Random_Player_Name(), 1, GOALKEEPER);

		/* Sign new player in into the TEAM! */
		team->Inscribe_New_Player_In_The_Team(player);
		i++;

		for (; i < team_size; i++)
		{
			/* Average Player */
			player = new Player(Get_Random_Player_Name(), Get_Random_Player_Number(), MIDFIELDER); 

			/* Sign new player in into the TEAM! */
			team->Inscribe_New_Player_In_The_Team(player);
		}
	}
	else
	{
		/* TODO: Error, size of team is 0! */
	}
}

void Team_Report_Alignment(Team *team)
{
	int team_size = team->Get_Team_Num_Of_Players();
	Player * tmp_list_of_players;

	if (team_size > 0)
	{
		printf(">> %s\n", team->Get_Team_Name().c_str());

		tmp_list_of_players = team->Get_Team_Players();

		for (int i = 0; i < team_size; i++)
		{
			printf("\t[%i]\t[%s]\n", tmp_list_of_players[i].Get_Player_Number(), tmp_list_of_players[i].Get_Player_Name().c_str());
		}
	}
	else
	{
		/* TODO: Error, size of team is 0! */
	}
}