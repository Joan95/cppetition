#include "match.h"


void Loop_Match(Match* match)
{
	/* Count time */
	match->Do_Match_Cycle();

	/* Player do action */
	printf("%s has the ball!\n", match->Get_Ball()->Who_Has_The_Ball()->Get_Player_Name().c_str());
}


int Start_Match(Match* match)
{
	Player* players_list = new Player[match->Get_Match_Local_Team()->Get_Team_Num_Of_Players() - 1];
	Player* choosen_player;
	int base_position = (int)WINGER;
	int num_of_occurrences = 0;

	/*	Iterate over PLAYER_POSITION enum for assigning the ball with preference: 
		- 1st WINGER, 2nd STRIKER, 3rd MIDFIELDER, 4th DEFENDER and last one GOALKEEPER */
	while (num_of_occurrences == 0)
	{
		/* Keep iterating if no matches found for this PLAYER POSITION */
		num_of_occurrences = match->Get_Match_Local_Team()->Get_Player_Based_On_Position(players_list, (player_position)base_position);

		/* Take the very next one */
		base_position--;
	}

	/* While is over. Check that players_list is not empty */
	if (num_of_occurrences != 0)
	{
		/* Select a random player from the list */
		choosen_player = &players_list[Get_Random_Number(1000) % num_of_occurrences];

		/* Init Ball Possession */
		Ball_Possession_Init(match->Get_Ball(), choosen_player);

		/* Set Match Stage on GOING state */
		match->Set_Match_Stage(GAME_IS_ON_GOING);

		return 1;
	}
	else
	{
		/* Match can not start, no valid player has been found */
		return 0;
	}
}

void Match_Update_Header(Match* match)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	COORD old_coordinates;
	bool restore_old_coordinate = true;
	Console_Printer* console = match->Get_Match_Console();

	/* Check if we have already stored value for header coordenates, otherwise update it */
	if (!console->Get_Match_Header_Struct().locked_position)
	{
		/* Coordinate still not set, take current console position and store it */
		if (GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi))
		{
			console->Update_Match_Header_Coordinates(cbsi.dwCursorPosition);
		}
	}

	/* Check we are having valid coordinates for writing */
	if (console->Get_Match_Header_Struct().locked_position)
	{
		/* Get current cursor position for restoring it */
		if (GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi))
		{
			old_coordinates = cbsi.dwCursorPosition;

			/* Check if terminal has been written before or not */
			if ((console->Get_Current_Terminal_Position().X == old_coordinates.X) && (console->Get_Current_Terminal_Position().Y == old_coordinates.Y))
			{
				/*	Means no-one has written in to the terminal yet,
					old_coordinate won't need to be restored
				*/
				restore_old_coordinate = false;
			}

			/* Set cursor in Header Zone */
			SetConsoleCursorPosition(console->Get_STD_OUT(), console->Get_Match_Header_Struct().coordinates);

			/* Print in Header zone */
			printf("\t --------------------------------------------------\n");

			if (match->Get_Match_Stage() == GAME_IS_ON_GOING)
			{
				printf("\t|\t\t\t\tMinute: %f / %f\n", match->Get_Match_Current_Time(), match->Get_Match_Max_Time());
			}
			else
			{
				printf("\t|\tVelocity: %f\n", match->Get_Match_Velocity());
			}
			printf("\t|-- LOCAL TEAM --\t-> %s", match->Get_Match_Local_Team()->Get_Team_Name().c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */
			printf("\n");
			printf("\t|-- VISITOR TEAM --\t-> %s", match->Get_Match_Visitor_Team()->Get_Team_Name().c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */
			printf("\n");
			printf("\t --------------------------------------------------\n\n");

			/* Restore the old position if needed */
			if (restore_old_coordinate)
			{
				SetConsoleCursorPosition(console->Get_STD_OUT(), old_coordinates);
			}

			/* Update current position */
			GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi);
			console->Update_Current_Terminal_Position(cbsi.dwCursorPosition);
		}
		else
		{
			/* TODO: Error couldn't get the Console Info ... */
		}
	}
}

void Match_Update_Alineation(Match* match)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	COORD old_coordinates;
	bool restore_old_coordinate = true;
	Console_Printer* console = match->Get_Match_Console();
	Player* alineation;

	/* Check if we have already stored value for alineation coordenates, otherwise update it */
	if (!console->Get_Match_Alineation_Struct().locked_position)
	{
		/* Coordinate still not set, take current console position and store it */
		if (GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi))
		{
			console->Update_Match_Alienation_Coordinates(cbsi.dwCursorPosition);
		}
	}

	/* Check we are having valid coordinates for writing */
	if (console->Get_Match_Alineation_Struct().locked_position)
	{
		/* Get current cursor position for restoring it */
		if (GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi))
		{
			old_coordinates = cbsi.dwCursorPosition;

			/* Check if terminal has been written before or not */
			if ((console->Get_Current_Terminal_Position().X == old_coordinates.X) && (console->Get_Current_Terminal_Position().Y == old_coordinates.Y))
			{
				/*	Means no-one has written in to the terminal yet,
					old_coordinate won't need to be restored
				*/
				restore_old_coordinate = false;
			}

			/* Set cursor in Alineation Zone */
			SetConsoleCursorPosition(console->Get_STD_OUT(), console->Get_Match_Alineation_Struct().coordinates);

			/* Print local team name */
			printf(">> %s\n", match->Get_Match_Local_Team()->Get_Team_Name().c_str());

			/* Get local alineation */
			alineation = match->Get_Match_Local_Team()->Get_Team_Players();
			for (int i = 0; i < match->Get_Match_Local_Team()->Get_Team_Num_Of_Players(); i++)
			{
				/* Only if Game is ongoing */
				if(match->Get_Match_Stage() == GAME_IS_ON_GOING)
				{
					if (alineation[i].Has_The_Ball())
					{
						printf("(*)\t#%i\t[%s]\t%s\n", alineation[i].Get_Player_Number(), Get_Position_From_Enum(alineation[i].Get_Player_Position()).c_str(), alineation[i].Get_Player_Name().c_str());
					}
					else
					{
						printf("( )\t#%i\t[%s]\t%s\n", alineation[i].Get_Player_Number(), Get_Position_From_Enum(alineation[i].Get_Player_Position()).c_str(), alineation[i].Get_Player_Name().c_str());
					}
				}
				else
				{
					printf("   \t#%i\t[%s]\t%s\n", alineation[i].Get_Player_Number(), Get_Position_From_Enum(alineation[i].Get_Player_Position()).c_str(), alineation[i].Get_Player_Name().c_str());
				}
			}

			/* Print visitor team name */
			printf("\n>> %s\n", match->Get_Match_Visitor_Team()->Get_Team_Name().c_str());

			/* Get visitor alineation */
			alineation = match->Get_Match_Visitor_Team()->Get_Team_Players();
			for (int i = 0; i < match->Get_Match_Visitor_Team()->Get_Team_Num_Of_Players(); i++)
			{
				/* Only if Game is ongoing */
				if (match->Get_Match_Stage() == GAME_IS_ON_GOING)
				{

					printf("( )\t#%i\t[%s]\t%s\n", alineation[i].Get_Player_Number(), Get_Position_From_Enum(alineation[i].Get_Player_Position()).c_str(), alineation[i].Get_Player_Name().c_str());
				}
				else
				{
					printf("   \t#%i\t[%s]\t%s\n", alineation[i].Get_Player_Number(), Get_Position_From_Enum(alineation[i].Get_Player_Position()).c_str(), alineation[i].Get_Player_Name().c_str());
				}
			}

			printf("\n");

			/* Restore the old position if needed */
			if (restore_old_coordinate)
			{
				SetConsoleCursorPosition(console->Get_STD_OUT(), old_coordinates);
			}

			/* Update current position */
			GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi);
			console->Update_Current_Terminal_Position(cbsi.dwCursorPosition);
		}
		else
		{
			/* TODO: Error couldn't get the Console Info ... */
		}
	}
	else
	{
		/* TODO: Error couldn't get the Console Info ... */
	}
}


void Finish_Match(Match* match)
{
	printf("Match is over!\n");

	/* Check for results */
	if (match->Get_Match_Local_Goals() > match->Get_Match_Visitor_Goals())
	{
		printf("%s WINS THE MATCH!\n", match->Get_Match_Local_Team()->Get_Team_Name().c_str());
	}
	else if (match->Get_Match_Local_Goals() < match->Get_Match_Visitor_Goals())
	{
		printf("%s WINS THE MATCH!\n", match->Get_Match_Visitor_Team()->Get_Team_Name().c_str());
	}
	else
	{
		printf("It has been a DRAW!\n");
	}
}


void Report_Results(Match* match)
{

}