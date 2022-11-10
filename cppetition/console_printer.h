#ifndef CONSOLE_PRINTER_HEADER
#define CONSOLE_PRINTER_HEADER

#include <string>		/* For string type usage */
#include <Windows.h>	/* For Console manipulation */


#define SINGLE_COORDINATE_NO_INIT_VALUE		0

typedef struct
{
	bool locked_position;
	COORD init_coordinates;
	COORD offset;
	std::string info_to_write;
} T_console_zone;

class Console_Printer
{
	public:
		Console_Printer() {
			hStdout = GetStdHandle(STD_OUTPUT_HANDLE);		/* Init standard console Handle for console manipulation */
			/* Header Zone */
			match_header_zone.locked_position = false;
			match_header_zone.init_coordinates = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_header_zone.offset = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_header_zone.info_to_write = "";
			/* Alineation Zone */
			match_alineation_zone.locked_position = false;
			match_alineation_zone.init_coordinates = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_alineation_zone.offset = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_alineation_zone.info_to_write = "";
			/* Event Zone */
			match_event_zone.locked_position = false;
			match_event_zone.init_coordinates = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_event_zone.offset = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
			match_event_zone.info_to_write = "";
			/* Current terminal position */
			current_terminal_position = { SINGLE_COORDINATE_NO_INIT_VALUE, SINGLE_COORDINATE_NO_INIT_VALUE };
		}

		/* Getters */
		HANDLE Get_STD_OUT(void) { return hStdout; }
		T_console_zone* Get_Match_Header_Struct(void) { return &match_header_zone; }
		T_console_zone* Get_Match_Alineation_Struct(void) { return &match_alineation_zone; }
		T_console_zone* Get_Match_Event_Struct(void) { return &match_event_zone; }
		COORD Get_Current_Terminal_Position(void) { return current_terminal_position; }

		/* Setters */
		void Update_Current_Terminal_Position(COORD current_position) { current_terminal_position = current_position; }

	private:
		HANDLE hStdout;
		T_console_zone match_header_zone;
		T_console_zone match_alineation_zone;
		T_console_zone match_event_zone;
		COORD current_terminal_position;
};

/* Functions Declaration */

#endif 