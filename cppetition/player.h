#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>	/* For string type usage */
#include <vector>	/* For vector usage */

typedef enum
{
	NO_VALID_POSITION = 0,		/* Value for default constructor */
	GOALKEEPER, 
	DEFENDER, 
	MIDFIELDER,
	STRIKER,
	WINGER
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
			injuried = false;		/* Default value */
			has_the_ball = false;	/* Default value */
		}

		Player(std::string new_name, int new_number, player_position new_position) { /* Class Constructor with parameters */
			name = new_name; 
			number = new_number;
			position = new_position;
			injuried = false;		/* Default value */
			has_the_ball = false;	/* Default value */
		}

		/* Getters */
		std::string Get_Player_Name(void) { return name; }	/* Getter for private attribute */
		int Get_Player_Number(void) { return number; }		/* Getter for private attribute */

	private:
		/* Private methods and attributes */
		std::string name; 
		int number;
		player_position position;
		bool injuried; 
		bool has_the_ball;
};


/* Functions Declaration */
std::string Get_Random_Player_Name(void);
int Get_Random_Player_Number(void);

#endif