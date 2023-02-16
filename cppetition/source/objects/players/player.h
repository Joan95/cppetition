#ifndef PLAYER_H
#define PLAYER_H

#include "..\..\lib\types.h"
#include "..\..\lib\soccer_types.h"

typedef enum
{
    FREE_AGENT = 0,
    IN_A_TEAM,
    TO_BE_TRANSFERRED,
    TO_BE_FIRED
} T_player_contract_enum;

typedef struct
{
    T_player_contract_enum current_job_status;
    long long expected_salary;
} T_player_contract_status;

typedef struct
{
    bool being_covered;
    bool has_the_ball;
} T_player_on_game_attributes;

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


/*
* 
*/
class Player
{
    public: 
        Player();
        Player(std::string _name, unsigned char _age, T_player_attributes_struct _attributes);

    private:

    protected: 
        std::string name;
        unsigned char age;
        T_soccer_position_enum position;
        T_player_attributes_struct player_attributes; 
        bool injured; 
        T_player_on_game_attributes game_attributes;
        T_player_contract_status contract_attributes;
};


/* Inhered classes */
/* GK */
/*
* 
*/
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
/*
* 
*/
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
/*
* 
*/
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
/*
* 
*/
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

/*
* 
*/
void player_register_new_player(Player* new_player);


#endif 