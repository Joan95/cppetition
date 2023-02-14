#ifndef FAULT_H
#define FAULT_H

#include "..\players\player.h"  /* For Player object usage */

class Fault
{
    public:
        Fault(Player* Fault_motivator, Player* Fault_receiver);

    private:

    protected: 
        Player* Fault_motivator;
        Player* Fault_receiver; 

};


#endif