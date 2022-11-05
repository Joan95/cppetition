#ifndef MATCH_HEADER
#define MATCH_HEADER

#include "console_printer.h"
#include "team.h"
#include "ball.h"
#include "error_types.h"

#define BASE_TIME_UNIT	1000	/* 1 second in milliseconds */

typedef enum
{
	NO_VALID_MATCH_STAGE,
	GAME_HAS_TO_START_YET,
	GAME_IS_ON_GOING,
	GAME_TIME_UP,
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
			max_match_time = 0;
			current_match_time = 0;
		};

		Match(Team* new_local_team, Team* new_visitor_team, float time_of_match, float match_velocity, Console_Printer* new_console, Ball* match_ball)	/* Class Constructor with parameters */
		{
			stage_of_the_match = GAME_HAS_TO_START_YET;
			local_team = new_local_team;
			visitor_team = new_visitor_team;
			local_goals = 0;
			visitor_goals = 0;
			max_match_time = time_of_match;
			current_match_time = 0;
			velocity = BASE_TIME_UNIT * match_velocity;
			console = new_console;
			ball = match_ball;
		}

		/* Getters */
		match_stage Get_Match_Stage(void) { return stage_of_the_match; }
		Team* Get_Match_Local_Team(void) { return local_team; }
		Team* Get_Match_Visitor_Team(void) { return visitor_team; }
		unsigned int Get_Match_Local_Goals(void) { return local_goals; }
		unsigned int Get_Match_Visitor_Goals(void) { return visitor_goals; }
		float Get_Match_Max_Time(void) { return max_match_time; }
		float Get_Match_Current_Time(void) { return current_match_time; }
		float Get_Match_Velocity(void) { return velocity; }
		Console_Printer* Get_Match_Console(void) { return console; }
		Ball* Get_Ball(void) { return ball; }
		
		/* Setters */
		void Set_Match_Stage(match_stage new_match_stage) { stage_of_the_match = new_match_stage; }

		/* Special Methods */
		void Match_Start_Match(void) { stage_of_the_match = GAME_IS_ON_GOING; }
		void Match_Finish_Match(void) { stage_of_the_match = END_OF_THE_GAME; }

		void Do_Match_Cycle(void) 
		{
			if (current_match_time >= max_match_time)
			{
				/* Time Up! */
				stage_of_the_match = GAME_TIME_UP;
			}
			else
			{
				current_match_time += velocity;
			}
		}

	private:
		match_stage stage_of_the_match;
		Team* local_team;
		Team* visitor_team;
		unsigned int local_goals;
		unsigned int visitor_goals;
		float max_match_time;
		float current_match_time;
		float velocity;
		Console_Printer* console;
		Ball* ball;
};

/* Functions Declaration */
void Loop_Match(Match* match);
int Start_Match(Match* match);
void Finish_Match(Match* match);
void Report_Results(Match* match);
void Match_Update_Header(Match* match);
void Match_Update_Alineation(Match* match);

#endif