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
	Player* Who_Has_The_Ball(void) { return current_player_with_the_ball; }
	bool Is_Ball_In_Game(void) { return is_ball_in_game; }

	/* Setters */

	/* Other Methods */
	void Init_Ball_Possession(Player* player)
	{
		current_player_with_the_ball = player;
		current_player_with_the_ball->Get_The_Ball();
		is_ball_in_game = true;
	}

	void Change_Player_Possession(Player* player) {
		/* Update assistant */
		old_player_with_the_ball->Lose_The_Ball();
		old_player_with_the_ball = current_player_with_the_ball;
		/* Set new possessor */
		current_player_with_the_ball = player;
		current_player_with_the_ball->Get_The_Ball();
		is_ball_in_game = true;
	}


private:
	Player* current_player_with_the_ball;
	Player* old_player_with_the_ball;
	bool is_ball_in_game;
};

void Ball_Possession_Init(Ball* ball, Player* new_player_with_the_ball);
void Ball_Possession_Changed(Ball* ball, Player* new_player_with_the_ball);

#endif
