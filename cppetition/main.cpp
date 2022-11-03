#include "ball.h"
#include "team.h"
#include "match.h"
#include "aux_functions.h"

#include <Windows.h>	/* Sleep */

Team* local_team;
Team* visitor_team;
Ball* my_ball;

int main()
{
	/* Init SEED for srand generation */
	Init_Aux_Functions();

	// local_team = new Team();
	local_team = new Team(Get_Random_Team_Name(), 5);		/* Default team without players, only size and naming */
	visitor_team = new Team(Get_Random_Team_Name(), 5);		/* Default team without players, only size and naming */

	/* Init the Ball */
	my_ball = new Ball();

	/* Time to Sign in new players */
	Team_Sign_New_Players(local_team);
	Team_Sign_New_Players(visitor_team);

	/*	This is just an example for educative purposes! 
		Below printf won't ever work since variable "name" has been defined as PRIVATE, so code won't have access to it directly.
		We have to access using Getter 
	*/
	// printf("%s", local_team.name);

	/* Access using Getter */
	Print_Match_Header(local_team->Get_Team_Name(), visitor_team->Get_Team_Name());

	Match_Report_Teams_Alignment(local_team, visitor_team);

	printf(">> Referee is about to start the game!\n");

	/* Infinite Loop */
	while(true)
	{
		/* Do loop each second */
		Sleep(1000);

		/* Check whether the ball is in game or not */
		if (!my_ball->Is_Ball_In_Game())
		{
			/* Check stage of the game in order to decide who has the receive the ball */
			if (Set_Ball_In_Game(my_ball, local_team))
			{
				printf("STARTS THE GAME!\n");
				printf("%s has the ball!\n", my_ball->Who_Has_The_Ball()->Get_Player_Name().c_str());
			}
		}
		else
		{
			/* Ball is in game, perform players action */
			my_ball->Who_Has_The_Ball()->Do_Action();
		}

	}
}