#include <random>   /* Random CPP */

#include "random.h"         /* */
#include "random_api.h"     /* */



void random_init(void)
{
    /* Init random Seed with time(NULL) */
    srand((unsigned int) time(NULL));
}


unsigned int get_random_between_values(unsigned char min, unsigned char max)
{
    return 0; 
}