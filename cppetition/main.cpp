#include "ball.h"
#include "team.h"
#include "match.h"
#include "aux_functions.h"

#include <Windows.h>	/* Sleep */

#include "error_types.h"


Console_Printer* console_printer;
Match* todays_match;
Team* local_team;
Team* visitor_team;
Ball* match_ball;

int main()
{
	bool finish_execution = false;

	/* Init SEED for srand generation */
	Init_Aux_Functions();

	/* Init Teams that will play */
	local_team = new Team(Get_Random_Team_Name(), 11);		/* Default team without players, only size and naming */
	visitor_team = new Team(Get_Random_Team_Name(), 11);		/* Default team without players, only size and naming */

	/* Init Console for printing the match */
	console_printer = new Console_Printer();

	/* Init the Ball */
	match_ball = new Ball();

	/* Init the Match */
	todays_match = new Match(local_team, visitor_team, (float) 5000.0, (float) 1, console_printer, match_ball);

	/* Time to Sign in new players */
	Team_Sign_New_Players(local_team);
	Team_Sign_New_Players(visitor_team);

	/*	This is just an example for educative purposes! 
		Below printf won't ever work since variable "name" has been defined as PRIVATE, so code won't have access to it directly.
		We have to access using Getter 
	*/
	// printf("%s", local_team.name);

	/* Update Match Header in the console */
	Match_Update_Header(todays_match);
	Sleep(1000);
	Match_Update_Alineation(todays_match);
	Sleep(1000);

	printf(">> Referee is about to start the game!\n");



	/* Infinite Loop */
	while(!finish_execution)
	{
		/* Do loop depending on match time */
		Sleep(todays_match->Get_Match_Velocity());

		/* TODO: Clear terminal */

		/* Update Match Header in the console periodically */
		Match_Update_Header(todays_match);
		Match_Update_Alineation(todays_match);

		switch (todays_match->Get_Match_Stage())
		{
			case GAME_HAS_TO_START_YET:
				if (!Start_Match(todays_match))
				{
					/* Game couldn't start */
					return NO_VALID_PLAYER_FOUND_ERROR;
				}
				break;

			case GAME_IS_ON_GOING:

				/* Check status of the ball */
				if (todays_match->Get_Ball()->Is_Ball_In_Game())
				{
					/* Ball is on the field! Count time and do actions */
					Loop_Match(todays_match);
				}
				else
				{
					/* Ball is not in game, set in game back again */
				}
				break;

			case GAME_TIME_UP:
				Finish_Match(todays_match);

				/* Move to next match stage */
				todays_match->Set_Match_Stage(END_OF_THE_GAME);
				break;

			case END_OF_THE_GAME:
				Report_Results(todays_match);

				/* Wait for 5 seconds */
				Sleep(5000);

				/* End the program */
				finish_execution = true;
				break;

			case NO_VALID_MATCH_STAGE:
			default:
				return NO_VALID_MATCH_STAGE_ERROR;
		}
	}

	/* If here, no issues found */
	return NO_ERROR_FOUND;
}