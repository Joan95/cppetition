#ifndef MATCH_HEADER
#define MATCH_HEADER

#include <string>	/* For string type usage */
#include "team.h"

/* Functions Declaration */
void Print_Match_Header(std::string local_name, std::string visitor_name);
void Match_Report_Teams_Alignment(Team *local_team, Team *visitor_team);

#endif