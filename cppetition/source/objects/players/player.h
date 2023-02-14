#include "..\..\os\databases\data_base_api.h"
// #include "..\teams\team.h"


typedef enum
{
    GOALKEEPER  = 0, 
    DEFENDER,
    MIDFIELDER,
    STRIKER,
} T_player_position_enum;

typedef struct
{
    unsigned char average; 
    unsigned char regularity;
    unsigned char mental_strength; 
    unsigned char attack; 
    unsigned char defense; 
    unsigned char passing; 
    unsigned char shooting; 
    unsigned char velocity; 
    unsigned char physic;
    unsigned char saving; 
    unsigned char dribbling;
} T_player_attributes_struct;


class Player
{
    public: 
        Player();
        Player(std::string _name, unsigned char _age, T_player_attributes_struct _attributes);

    private:

    protected: 
        std::string name;
        unsigned char age;
        T_player_position_enum position;
        T_player_attributes_struct attributes; 
        // Team * current_team;
        bool injured; 
        bool being_covered;
        bool has_the_ball; 
};


/* Inhered classes */
/* GK */
class Goalkeeper : public Player
{
    public:
        Goalkeeper(std::string _name, unsigned char _age, T_player_attributes_struct _attributes) : Player(_name, _age, _attributes)
        {
            position = GOALKEEPER;
        }

    private:

    protected:

};

/* DF */
class Defender : public Player
{
    public:
        Defender(std::string _name, unsigned char _age, T_player_attributes_struct _attributes) : Player(_name, _age, _attributes)
        {
            position = DEFENDER;
        }

    private:

    protected:

};

/* MF */
class Midfielder : public Player
{
    public:
        Midfielder(std::string _name, unsigned char _age, T_player_attributes_struct _attributes) : Player(_name, _age, _attributes)
        {
            position = MIDFIELDER;
        }

    private:

    protected:

};

/* FW */
class Striker : public Player
{
    public:
        Striker(std::string _name, unsigned char _age, T_player_attributes_struct _attributes) : Player(_name, _age, _attributes)
        {
            position = STRIKER;
        }

    private:

    protected:

};


void player_register_new_player(Player* new_player);