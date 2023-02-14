#include "data_base_api.h"
#include "data_base.h"


void data_base_init(void)
{
    /* Call all the objects so they can init their own data bases by creating 
    the objects accordingly */
    if (!player_load_data_base("./source/os/databases/players_data_base.txt"))
    {
        /* Error, Database not loaded properly */
        exit(-1);
    }

    if (!team_load_data_base("./source/os/databases/teams_data_base.txt"))
    {
        /* Error, Database not loaded properly */
        exit(-1);
    }
}


std::vector<std::string> data_base_parse_line(string line_to_parse)
{
    std::string delimiter = ",";
    std::string result;
    size_t pos = 0; 
    std::vector<std::string> results;

    while ((pos = line_to_parse.find(delimiter)) != std::string::npos)
    {
        result = line_to_parse.substr(0, pos);
        results.push_back(result);
        line_to_parse.erase(0, pos + delimiter.length());
    }

    return results;
}