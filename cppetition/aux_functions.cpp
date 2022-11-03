#include "aux_functions.h"


void Init_Aux_Functions(void)
{
	/* Init rand SEED for random method */
	srand((unsigned int)time(NULL));
}


int Get_Random_Number(int range)
{
	/* Return a random number based in a given range */
	return rand() % range;
}


std::string Get_Random_String_From_Vector(std::vector<std::string> list)
{
	return list[Get_Random_Number(list.size())].c_str();
}