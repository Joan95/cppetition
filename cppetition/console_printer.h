#ifndef CONSOLE_PRINTER_HEADER
#define CONSOLE_PRINTER_HEADER

#include <string>		/* For string type usage */
#include <Windows.h>	/* For Console manipulation */


#define SINGLE_COORDINATE_NO_INIT_VALUE		0

typedef struct
{
	bool locked_position;
	COORD coordinates;
} T_coordinate_struct;

class Console_Printer
{
	public:
		Console_Printer() {
			hStdout = GetStdHandle(STD_OUTPUT_HANDLE);		/* Init standard console Handle for console manipulation */
			match_header_coord.locked_position = false;
			match_header_coord.coordinates = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_alineation_coord.locked_position = false;
			match_alineation_coord.coordinates = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			current_terminal_position = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
		}

		/* Getters */
		HANDLE Get_STD_OUT(void) { return hStdout; }
		T_coordinate_struct Get_Match_Header_Struct(void) { return match_header_coord; }
		T_coordinate_struct Get_Match_Alineation_Struct(void) { return match_alineation_coord; }
		COORD Get_Current_Terminal_Position(void) { return current_terminal_position; }

		/* Setters */
		void Update_Match_Header_Coordinates(COORD match_coord) { match_header_coord.coordinates = match_coord; match_header_coord.locked_position = true; }
		void Update_Match_Alienation_Coordinates(COORD match_coord) { match_alineation_coord.coordinates = match_coord; match_alineation_coord.locked_position = true; }
		void Update_Current_Terminal_Position(COORD current_position) { current_terminal_position = current_position; }

	private:
		HANDLE hStdout;
		T_coordinate_struct match_header_coord;
		T_coordinate_struct match_alineation_coord;
		COORD current_terminal_position;
};

/* Functions Declaration */

#endif 