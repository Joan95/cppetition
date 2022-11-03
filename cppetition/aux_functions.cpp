#include "aux_functions.h"


void Init_Aux_Functions(void)
{
	/* Init rand SEED for random method */
	srand(time(NULL));
}


int Get_Random_Number(int range)
{
	/* Return a random number based in a given range */
	return rand() % range;
}