#include "match.h"


void Loop_Match(Match* match)
{
	/* Count time */
	match->Do_Match_Cycle();

	/* Player do action */
	/* */

	/* Update Terminal information */
	Match_Update_Terminal_Feedback(match);
}


int Start_Match(Match* match)
{
	Player** players_list = new Player* [match->Get_Match_Local_Team()->Get_Team_Num_Of_Players()];
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
		choosen_player = players_list[Get_Random_Number(1000) % num_of_occurrences];

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

void Match_Update_Terminal_Feedback(Match* match)
{
	/* Update HEADER */
	match->Get_Match_Console()->Get_Match_Header_Struct()->info_to_write = Match_Update_Header(match);
	Update_Zone(match, match->Get_Match_Console()->Get_Match_Header_Struct());

	/* Update ALINEATION */
	match->Get_Match_Console()->Get_Match_Alineation_Struct()->info_to_write = Match_Update_Alineation(match);
	Update_Zone(match, match->Get_Match_Console()->Get_Match_Alineation_Struct());

	/* Update EVENTS */
	match->Get_Match_Console()->Get_Match_Event_Struct()->info_to_write = Match_Update_Event(match);
	Update_Zone(match, match->Get_Match_Console()->Get_Match_Event_Struct());

}


void Update_Zone(Match* match, T_console_zone* zone_to_update)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	COORD old_coordinates;
	bool restore_old_coordinate = true;
	Console_Printer* console = match->Get_Match_Console();
	std::string text_to_be_printed = "";

	/* Check if we have already stored value for alineation coordenates, otherwise update it */
	if (!zone_to_update->locked_position)
	{
		/* Coordinate still not set, take current console position and store it */
		if (GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi))
		{
			zone_to_update->init_coordinates = cbsi.dwCursorPosition;
			zone_to_update->locked_position = true;
		}
	}

	/* Check we are having valid coordinates for writing */
	if (zone_to_update->locked_position)
	{
		/* Check if clean header can be run */
		if (zone_to_update->offset.Y != SINGLE_COORDINATE_NO_INIT_VALUE)
		{
			/* Set cursor in Header Zone */
			SetConsoleCursorPosition(console->Get_STD_OUT(), zone_to_update->init_coordinates);

			for (int i = 0U; i < zone_to_update->offset.Y; i++)
			{
				text_to_be_printed = text_to_be_printed + "                                                                                 ";
				text_to_be_printed = text_to_be_printed + "\n";
			}

			/* Clean Header */
			printf(text_to_be_printed.c_str());
		}

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
			SetConsoleCursorPosition(console->Get_STD_OUT(), zone_to_update->init_coordinates);

			/* Print text */
			printf("%s", zone_to_update->info_to_write.c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */

			/* Restore the old position if needed */
			if (restore_old_coordinate)
			{
				SetConsoleCursorPosition(console->Get_STD_OUT(), old_coordinates);
			}
			else
			{
				/* Get status after printing */
				GetConsoleScreenBufferInfo(console->Get_STD_OUT(), &cbsi);

				/* It was first time to get updated, calculate the amount of space it takes */
				zone_to_update->offset = { cbsi.dwCursorPosition.X - old_coordinates.X, cbsi.dwCursorPosition.Y - old_coordinates.Y };
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

/* Update Header Console Zone */
std::string Match_Update_Header(Match* match)
{
	std::string info_to_update;

	/* Construct Header zone */
	info_to_update = "";
	info_to_update = info_to_update + "\t --------------------------------------------------\n";

	if ((match->Get_Match_Stage() == NO_VALID_MATCH_STAGE) || (match->Get_Match_Stage() == GAME_HAS_TO_START_YET))
	{
		info_to_update = info_to_update + "\t|\tVelocity: ";
		info_to_update = info_to_update + std::to_string(match->Get_Match_Velocity());
	}

	/* Info that will be only available once the game is being played */
	if (match->Get_Match_Stage() == GAME_IS_ON_GOING)
	{
		info_to_update = info_to_update + "\t|\tMinute:";
		info_to_update = info_to_update + std::to_string(match->Get_Match_Current_Time());
		info_to_update = info_to_update + " / " + std::to_string(match->Get_Match_Max_Time());
	}

	info_to_update = info_to_update + "\n";
	info_to_update = info_to_update + "\t|-- LOCAL TEAM --\t-> ";
	info_to_update = info_to_update + match->Get_Match_Local_Team()->Get_Team_Name();
	info_to_update = info_to_update + "\n";
	info_to_update = info_to_update + "\t|-- VISITOR TEAM --\t-> ";
	info_to_update = info_to_update + match->Get_Match_Visitor_Team()->Get_Team_Name();
	info_to_update = info_to_update + "\n";
	info_to_update = info_to_update + "\t --------------------------------------------------\n\n";

	return info_to_update;
}

/* Update Alineation Console Zone */
std::string Match_Update_Alineation(Match* match)
{
	Player* alineation;
	std::string info_to_update = "";

	/* Local team name */
	info_to_update = info_to_update + ">> ";
	info_to_update = info_to_update + match->Get_Match_Local_Team()->Get_Team_Name();
	info_to_update = info_to_update + "\n";

	/* Get local alineation */
	alineation = match->Get_Match_Local_Team()->Get_Team_Players();
	for (int i = 0; i < match->Get_Match_Local_Team()->Get_Team_Num_Of_Players(); i++)
	{
		/* Only if Game is ongoing */
		if(match->Get_Match_Stage() == GAME_IS_ON_GOING)
		{
			if (alineation[i].Has_The_Ball())
			{
				info_to_update = info_to_update + "(*)\t";
			}
			else
			{
				info_to_update = info_to_update + "( )\t";
			}
		}
		else
		{
			info_to_update = info_to_update + "   \t";
		}
		info_to_update = info_to_update + "#" + std::to_string(alineation[i].Get_Player_Number()) + "\t[";
		info_to_update = info_to_update + Get_Position_From_Enum(alineation[i].Get_Player_Position()) + "]\t";
		info_to_update = info_to_update + alineation[i].Get_Player_Name();
		info_to_update = info_to_update + "\n";
	}

	info_to_update = info_to_update + "\n";

	/* Print visitor team name */
	info_to_update = info_to_update + ">> ";
	info_to_update = info_to_update + match->Get_Match_Visitor_Team()->Get_Team_Name();
	info_to_update = info_to_update + "\n";

	/* Get visitor alineation */
	alineation = match->Get_Match_Visitor_Team()->Get_Team_Players();
	for (int i = 0; i < match->Get_Match_Visitor_Team()->Get_Team_Num_Of_Players(); i++)
	{
		/* Only if Game is ongoing */
		if (match->Get_Match_Stage() == GAME_IS_ON_GOING)
		{
			if (alineation[i].Has_The_Ball())
			{
				info_to_update = info_to_update + "(*)\t";
			}
			else
			{
				info_to_update = info_to_update + "( )\t";
			}
		}
		else
		{
			info_to_update = info_to_update + "   \t";
		}
		info_to_update = info_to_update + "#" + std::to_string(alineation[i].Get_Player_Number()) + "\t[";
		info_to_update = info_to_update + Get_Position_From_Enum(alineation[i].Get_Player_Position()) + "]\t";
		info_to_update = info_to_update + alineation[i].Get_Player_Name();
		info_to_update = info_to_update + "\n";
	}

	info_to_update = info_to_update + "\n";
	return info_to_update;
}

/* Update Events Console Zone */
std::string Match_Update_Event(Match* match)
{
	std::string info_to_update = "";

	/* Construct Event zone */
	info_to_update = info_to_update + "------------------------------------\n";
	info_to_update = info_to_update + ">> Events:\n";
	info_to_update = info_to_update + "\t";
	if (match->Get_Match_Stage() == GAME_IS_ON_GOING)
	{
		info_to_update = info_to_update + match->Get_Ball()->Who_Has_The_Ball()->Get_Player_Name() + " has the ball!\n";
	}

	return info_to_update;
}

/* Once Match finishes */
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

/* Results */
void Report_Results(Match* match)
{

}