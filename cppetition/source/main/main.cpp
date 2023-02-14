#include "..\os\random\random_api.h"
#include "..\os\timer\timer_api.h"
#include "..\objects\displayer\displayer_api.h"
#include "..\os\databases\data_base_api.h"
#include "..\objects\season\season_api.h"


void init(void)
{
    /* Init Random Seed */
    random_init();

    /* Init Timers */
    timer_init();

    /* Init displayer */
    displayer_init();

    /* Init Data Bases */
    data_base_init();

    /* Init Season */
    season_init();
}

int main(void)
{
    /* Init phase */
    init(); 

    /* Play seasons */

    return 0; 
}