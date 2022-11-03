#include "ball.h"



bool Set_Ball_In_Game(Ball* ball, Team* team_to_retrieve_the_ball)
{
	Player* players_list = new Player[team_to_retrieve_the_ball->Get_Team_Num_Of_Players() - 1];
	Player* choosen_player;
	int base_position = (int) WINGER;
	int num_of_occurrences = 0;

	while (num_of_occurrences == 0)
	{
		num_of_occurrences = team_to_retrieve_the_ball->Get_Player_Based_On_Position(players_list, (player_position) base_position);
		base_position--;
	}

	/* Check that players_list is not empty */
	if (num_of_occurrences != 0)
	{
		/* Select a random player from the list */
		choosen_player = &players_list[Get_Random_Number(1000) % num_of_occurrences];

		/* Give the ball to the choosen player */
		choosen_player->Give_The_Ball();

		/* Assign the Player to the Ball */
		ball->Give_The_Ball_To_Player(choosen_player);
	}

	return 1;
}