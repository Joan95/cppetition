#include "match.h"


void Print_Match_Header(std::string local_name, std::string visitor_name)
{
	printf("\t----------------------------------------------------------");
	printf("\n\t-- LOCAL TEAM --\t\t\t-- VISITOR TEAM --\n\t-> %s", local_name.c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */
	printf("\t\t\t\t-> %s\n", visitor_name.c_str());	/* c_str() for printing std::string pretty, otherwise rubbish will appear */
	printf("\t----------------------------------------------------------\n\n");
}


void Match_Report_Teams_Alignment(Team *local_team, Team *visitor_team)
{
	Team_Report_Alignment(local_team);
	printf("\t-----------------\n");
	Team_Report_Alignment(visitor_team);
}