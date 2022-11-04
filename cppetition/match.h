#ifndef MATCH_HEADER
#define MATCH_HEADER


#include "team.h"
#include "console_printer.h"

typedef enum
{
	NO_VALID_MATCH_STAGE,
	GAME_HAS_TO_START_YET,
	END_OF_THE_GAME,
} match_stage;

class Match
{
	public:
		/* Public methods and attributes */
		Match()		/* DEFAULT CONSTRUCTOR */
		{
			stage_of_the_match = NO_VALID_MATCH_STAGE;
			local_goals = 0;
			visitor_goals = 0;
			match_time = 0;
		};

		Match(Team* new_local_team, Team* new_visitor_team, int time_of_match, Console_Printer* console)	/* Class Constructor with parameters */
		{
			stage_of_the_match = GAME_HAS_TO_START_YET;
			local_team = new_local_team;
			visitor_team = new_visitor_team;
			local_goals = 0;
			visitor_goals = 0;
			match_time = time_of_match;
			printer = console;
		}

		/* Getters */
		Console_Printer* Get_Console_For_Printing(void) { return printer; }

		/* Special Methods */
		void Match_Update_Header(void) {}

	private:
		match_stage stage_of_the_match;
		Team* local_team;
		Team* visitor_team;
		int local_goals;
		int visitor_goals;
		int match_time;
		Console_Printer* printer;
};

/* Functions Declaration */

#endif