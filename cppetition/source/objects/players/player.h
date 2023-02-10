#include <fstream>      /* For file reading purposes */
#include <string>       /* For string data type usage */

using namespace std; 


class Player
{
    public: 
        Player(string name, unsigned char number, unsigned char age);

    private:
        string name;
        unsigned char age; 
        bool injured; 
        bool being_covered;

    protected: 

};


/* Inhered classes */
/* GK */
class Goalkeeper : public Player
{

};

/* DF */
class Defender : public Player
{

};

/* MF */
class Midfielder : public Player
{

};

/* FW */
class Forward : public Player
{

};