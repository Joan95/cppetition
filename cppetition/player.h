#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>	/* For string type usage */
#include <vector>	/* For vector usage */

#include "aux_functions.h"

typedef enum
{
	NO_VALID_POSITION = 0,		/* Value for default constructor 0 */
	GOALKEEPER,					/* Value 1 */
	DEFENDER,					/* Value 2 */
	MIDFIELDER,					/* Value 3 */
	STRIKER,					/* Value 4 */
	WINGER						/* Value 5 */
} player_position;


/* Class definition */
class Player
{
	public:
		/* Public methods and attributes */
		Player()	/* DEFAULT CONSTRUCTOR */
		{
			name = "";
			number = 0;
			position = NO_VALID_POSITION;
			injuried = false;			/* Default value */
			has_the_ball = false;		/* Default value */
			has_yellow_card = false;	/* Default value */
		}

		Player(std::string new_name, int new_number, player_position new_position, void(*main_action)(void), void(*secondary_action)(void)) { /* Class Constructor with parameters */
			name = new_name;
			number = new_number;
			position = new_position;
			injuried = false;			/* Default value */
			has_the_ball = false;		/* Default value */
			has_yellow_card = false;	/* Default value */
			attack_action = main_action;
			defensive_action = secondary_action;
		}

		/* Getters */
		std::string Get_Player_Name(void) { return name; }	/* Getter for private attribute */
		int Get_Player_Number(void) { return number; }		/* Getter for private attribute */
		player_position Get_Player_Position(void) { return position; }	/* Getter for private attribute */
		bool Has_The_Ball(void) { return has_the_ball; }

		/* Setters */
		void Lose_The_Ball(void) { has_the_ball = false; }
		void Get_The_Ball(void) { has_the_ball = true; }

		/* Other methods */
		void Do_Action(void)
		{
			attack_action();
		}

	private:
		/* Private methods and attributes */
		std::string name; 
		int number;
		player_position position;
		bool injuried; 
		bool has_the_ball;
		bool has_yellow_card;
		void (*attack_action)(void);
		void (*defensive_action)(void);
};


/* Functions Declaration */
std::string Get_Random_Player_Name(void);
int Get_Random_Player_Number(void);
player_position Get_Random_Player_Position_Enum(void);
std::string Get_Position_From_Enum(player_position player_position);

void Goalkeeper_Save(void);
void Break_A_Leg(void);
void Winger_Center(void);
void Striker_Shoot(void);
void Pass_The_Ball(void);

#endif