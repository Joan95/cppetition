#ifndef CONSOLE_PRINTER_HEADER
#define CONSOLE_PRINTER_HEADER

#include <string>		/* For string type usage */
#include <Windows.h>	/* For Console manipulation */

#include "team.h"

#define SINGLE_COORDINATE_NO_INIT_VALUE		0

typedef struct
{
	bool locked_position;
	COORD coordinates;
} coordinate_struct;

class Console_Printer
{
	public:
		Console_Printer() {
			hStdout = GetStdHandle(STD_OUTPUT_HANDLE);		/* Init standard console Handle for console manipulation */
			match_header_coord.locked_position = false;
			match_header_coord.coordinates = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			current_terminal_position = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
		}

		/* Getters */
		HANDLE Get_STD_OUT(void) { return hStdout; }
		coordinate_struct Get_Match_Header_Struct(void) { return match_header_coord; }
		COORD Get_Current_Terminal_Position(void) { return current_terminal_position; }

		/* Setters */
		void Update_Match_Header_Coordinates(COORD match_coord) { match_header_coord.coordinates = match_coord; match_header_coord.locked_position = true; }
		void Update_Current_Terminal_Position(COORD current_position) { current_terminal_position = current_position; }

	private:
		HANDLE hStdout;
		coordinate_struct match_header_coord;
		COORD current_terminal_position;
};

/* Functions Declaration */
void Print_Updated_Match_Header_Information(Console_Printer* console, std::string local_name, std::string visitor_name);
void Print_Teams_Alineation(Console_Printer* console, Team* local_team, Team* visitor_team);

#endif 