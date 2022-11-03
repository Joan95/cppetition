#ifndef AUX_FUNCTIONS_HEADER
#define AUX_FUNCTIONS_HEADER

#include <stdio.h>	/* printf, NULL */
#include <stdlib.h>	/* srand, rand */
#include <time.h>	/* time */
#include <string>	/* For string type usage */
#include <vector>	/* For vector usage */


/* Functions Declaration */
void Init_Aux_Functions(void);
int Get_Random_Number(int range);
std::string Get_Random_String_From_Vector(std::vector<std::string> list);

#endif