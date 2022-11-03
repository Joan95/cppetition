#include "team.h"
#include "match.h"
#include "aux_functions.h"

#include <Windows.h>	/* Sleep */



int main()
{
	/* Init SEED for srand generation */
	Init_Aux_Functions();

	Team local_team(Get_Random_Team_Name(), 5);			/* Default team without players, only size and naming */
	Team visitor_team(Get_Random_Team_Name(), 5);		/* Default team without players, only size and naming */

	/* Time to Sign in new players */
	Team_Sign_New_Players(&local_team);
	Team_Sign_New_Players(&visitor_team);

	/*	This is just an example for educative purposes! 
		Below printf won't ever work since variable "name" has been defined as PRIVATE, so code won't have access to it directly.
		We have to access using Getter 
	*/
	// printf("%s", local_team.name);

	/* Access using Getter */
	Print_Match_Header(local_team.Get_Team_Name(), visitor_team.Get_Team_Name());

	Match_Report_Teams_Alignment(&local_team, &visitor_team);

	/* Infinite Loop */
	while(true)
	{
		Sleep(1000);

	}
}