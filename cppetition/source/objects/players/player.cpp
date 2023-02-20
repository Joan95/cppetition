#include <fstream>      /* For file reading purposes */
#include <vector>       /* For vector usage */

#include "..\..\os\databases\data_base_api.h"   /* For data_base_parse_line usage */
#include "..\contracts\contract_api.h"

#include "player_api.h" /* API Header */
#include "player.h"     /* Header */

#define BASE_INITIAL_SALARY_EXPECTATION     -10


/*
*/
Player::Player()
{
    name = "";
    age = 0;
    position = NO_VALID_POSITION;
    injured = false;
    game_attributes.being_covered = false;
    game_attributes.has_the_ball = false;
}

/*
*/
Player::Player(std::string _name, unsigned char _age, T_player_attributes_struct _attributes)
{
    name = _name;  
    age = _age; 
    player_attributes = _attributes;
    injured = false;
    game_attributes.being_covered = false;
    game_attributes.has_the_ball = false;
}

/*
*/
bool player_load_data_base(std::string path_to_data_base)
{
    Player * newPlayer;
    std::string dbPlayerLine;
    T_player_attributes_struct newPlayerAttributes; 
    std::vector<std::string> player_attributes; 

    /* Read and create players accordingly */
    ifstream PlayerDB(path_to_data_base);

    if (PlayerDB)
    {
        while (getline(PlayerDB, dbPlayerLine))
        {
            player_attributes = data_base_parse_line(dbPlayerLine);
            newPlayerAttributes.average = stoi(player_attributes[3]);
            newPlayerAttributes.regularity = stoi(player_attributes[4]);
            newPlayerAttributes.mental_strength = stoi(player_attributes[5]);
            newPlayerAttributes.attack = stoi(player_attributes[6]);
            newPlayerAttributes.defense = stoi(player_attributes[7]);
            newPlayerAttributes.passing = stoi(player_attributes[8]);
            newPlayerAttributes.shooting = stoi(player_attributes[9]);
            newPlayerAttributes.velocity = stoi(player_attributes[10]);
            newPlayerAttributes.physic = stoi(player_attributes[11]);
            newPlayerAttributes.saving = stoi(player_attributes[12]);
            newPlayerAttributes.dribbling = stoi(player_attributes[13]);
         
            switch ((T_soccer_position_enum) stoi(player_attributes[2]))
            {
                case GOALKEEPER:
                    newPlayer = new Goalkeeper(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    contract_generate_new_contract(newPlayer);
                    break; 

                case DEFENDER:
                    newPlayer = new Defender(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    contract_generate_new_contract(newPlayer);
                    break; 

                case MIDFIELDER:
                    newPlayer = new Midfielder(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    contract_generate_new_contract(newPlayer);
                    break; 

                case STRIKER:
                    newPlayer = new Striker(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    contract_generate_new_contract(newPlayer);
                    break; 

                default:
                    break;
            }
        }

        PlayerDB.close();
        return 1;
    }
    else
    {
        /* File not found error */
        return 0;
    }
}
