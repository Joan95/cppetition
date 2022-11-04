#ifndef BALL_HEADER
#define BALL_HEADER

#include "player.h"

class Ball
{
public:
	Ball() 
	{
		is_ball_in_game = false;
	}

	/* Getters */
	Player* Who_Has_The_Ball(void) { return player_with_the_ball; }
	bool Is_Ball_In_Game(void) { return is_ball_in_game; }

	/* Setters */
	void Give_The_Ball_To_Player(Player* player) { 
		player_with_the_ball = player; 
		is_ball_in_game = true;
	}


private:
	Player* player_with_the_ball;
	bool is_ball_in_game;
};


#endif
