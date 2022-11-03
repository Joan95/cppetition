#ifndef MATCH_HEADER
#define MATCH_HEADER

#include <string>	/* For string type usage */

#include "team.h"

typedef enum
{
	START_OF_THE_GAME,
	END_OF_THE_GAME,
} match_stage;

class Match
{
	public:
		/* Public methods and attributes */
		Match()		/* DEFAULT CONSTRUCTOR */
		{
			stage_of_the_match = START_OF_THE_GAME;
		};

		Match(Team *local_team, Team *visitant_team)	/* Class Constructor with parameters */
		{

		}

	private:
		match_stage stage_of_the_match;
};

/* Functions Declaration */
void Print_Match_Header(std::string local_name, std::string visitor_name);
void Match_Report_Teams_Alignment(Team *local_team, Team *visitor_team);

#endif