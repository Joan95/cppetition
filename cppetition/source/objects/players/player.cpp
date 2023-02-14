#include <fstream>      /* For file reading purposes */

#include "player_api.h"
#include "player.h"

Player** list_of_players;
unsigned int num_of_players;

/*
*/
Player::Player(std::string _name, unsigned char _age, T_player_attributes_struct _attributes)
{
    name = _name;  
    age = _age; 
    attributes = _attributes;

    injured = false; 
    being_covered = false;
    has_the_ball = false; 
}

/*
*/
void player_register_new_player(Player* new_player)
{
    if (list_of_players == nullptr)
    {
        /* List of players has not been initialized */
        list_of_players = new Player * [1];
        num_of_players = 0; 
        list_of_players[num_of_players++] = new_player;
    }
    else
    {
        /* List of players has been previously initialized, just resize it */
        Player** new_list_of_players = new Player * [num_of_players + 1];
        std::copy(list_of_players, list_of_players + num_of_players, new_list_of_players);
        delete[] list_of_players;
        list_of_players = new_list_of_players;
        list_of_players[num_of_players++] = new_player;
    }
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
         
            switch ((T_player_position_enum) stoi(player_attributes[2]))
            {
                case GOALKEEPER:
                    newPlayer = new Goalkeeper(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    player_register_new_player(newPlayer);
                    break; 

                case DEFENDER:
                    newPlayer = new Defender(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    player_register_new_player(newPlayer);
                    break; 

                case MIDFIELDER:
                    newPlayer = new Midfielder(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    player_register_new_player(newPlayer);
                    break; 

                case STRIKER:
                    newPlayer = new Striker(player_attributes[0], stoi(player_attributes[1]), newPlayerAttributes);
                    player_register_new_player(newPlayer);
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
