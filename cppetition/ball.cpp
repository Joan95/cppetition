#include "ball.h"


void Ball_Possession_Init(Ball* ball, Player* new_player_with_the_ball)
{
	ball->Init_Ball_Possession(new_player_with_the_ball);
}

void Ball_Possession_Changed(Ball* ball, Player* new_player_with_the_ball)
{
	/* Set Ball in game */
	ball->Change_Player_Possession(new_player_with_the_ball);
}