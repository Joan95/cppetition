#include "console_printer.h"


void Print_Updated_Match_Header_Information(Console_Printer* console, std::string local_name, std::string visitor_name)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	COORD old_coordinates;
	bool restore_old_coordinate = true;

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
			printf("\t|-- LOCAL TEAM --\t-> %s", local_name.c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */
			printf("\n");
			printf("\t|-- VISITOR TEAM --\t-> %s", visitor_name.c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */
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

void Print_Teams_Alineation(Console_Printer* console, Team* local_team, Team* visitor_team)
{
	Team_Report_Alignment(local_team);
	printf("\t-----------------\n");
	Team_Report_Alignment(visitor_team);
	printf("\t-----------------\n");
}