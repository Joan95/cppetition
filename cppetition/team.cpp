#include "team.h"

/* https://wooterapparel.com/football-team-name-generator */
std::vector<std::string> team_names_list = {
	"Raging Samaritans",
	"Savage Defenders",
	"Groundbreaking Fuel",
	"Strong Legends",
	"Grandiose Oilers",
	"Hot Warhawks",
	"Shrewd Pilots",
	"Murder Hornets",
	"Solid Rainbows",
	"Rare Lunatics",
	"Foolish Pandas",
	"Spinning Locomotives",
	"Giddy Colts",
	"Ambitious Sentinels",
	"Forged Cardinals",
	"Delta Crocodiles",
	"Chemical Snakes",
	"Verdant Lions",
	"Invincible Huskies",
	"Taboo Redwoods",
	"Skilled Bruins",
	"Spirit Cougars",
	"Dangerous Aardvarks",
	"Crazy Warriors",
	"Cruel Wheels",
	"Crazy Sentinels",
	"Onerous Wings",
	"Reminiscent Rebels",
	"Fire Renegades",
	"Fretful Tamales",
	"Lucky Ambassadors",
	"Frozen Chargers",
	"Skilled Wolfpack",
	"Cohesive Blazers",
	"Fire Bullets",
	"Concrete Vikings",
	"Encouraging Sabres",
	"Spotted Packers",
	"Pricey Gang",
	"Smoke Lions",
	"Kamikaze Wolfpack",
	"Raging Roos",
	"Wealthy Wolverines",
	"Bashful Iron",
	"Abiding Foxes",
	"Alcoholic Winds",
	"Taboo Heroes",
	"Vaulting Northmen",
	"Simple Marlins",
	"Loyal Coyotes",
	"Frozen Mustangs",
	"Wealthy Cats",
	"Smoke Cougars",
	"Futuristic Aardvarks",
	"Excellent Ravens",
	"Receptive Minks",
	"World Destroyers",
	"Glamorous Pirates",
};

std::string Get_Random_Team_Name(void)
{
	return Get_Random_String_From_Vector(team_names_list);
}


void Team_Sign_New_Players(Team *team)
{
	int i = 0;
	int team_size = team->Get_Team_Size();
	Player *player; /* Create null pointer to object Player for later init */
	player_position position;

	if (team_size > 0)
	{
		/* Special case for Goalkeeper */
		player = new Player(Get_Random_Player_Name(), 1, GOALKEEPER, Pass_The_Ball, Goalkeeper_Save);

		/* Sign new player in into the TEAM! */
		team->Inscribe_New_Player_In_The_Team(player);
		i++;

		for (; i < team_size; i++)
		{
			position = Get_Random_Player_Position_Enum();

			switch (position)
			{
			case DEFENDER:
				/* Average Player */
				player = new Player(Get_Random_Player_Name(), Get_Random_Player_Number(), position, Pass_The_Ball, Break_A_Leg);
				break;

			case MIDFIELDER:
				/* Average Player */
				player = new Player(Get_Random_Player_Name(), Get_Random_Player_Number(), position, Pass_The_Ball, Pass_The_Ball);
				break;

			case STRIKER:
				/* Average Player */
				player = new Player(Get_Random_Player_Name(), Get_Random_Player_Number(), position, Striker_Shoot, Pass_The_Ball);
				break;

			case WINGER:
				/* Average Player */
				player = new Player(Get_Random_Player_Name(), Get_Random_Player_Number(), position, Winger_Center, Pass_The_Ball);
				break;

			case GOALKEEPER:
				/* Not gonna be possible to get, but still*/
			case NO_VALID_POSITION:
			default:
				break;
			}

			/* Sign new player in into the TEAM! */
			team->Inscribe_New_Player_In_The_Team(player);
		}
	}
	else
	{
		/* TODO: Error, size of team is 0! */
	}
}

void Team_Report_Alignment(Team *team)
{
	int team_size = team->Get_Team_Num_Of_Players();
	Player * tmp_list_of_players;

	if (team_size > 0)
	{
		printf(">> %s\n", team->Get_Team_Name().c_str());

		tmp_list_of_players = team->Get_Team_Players();

		for (int i = 0; i < team_size; i++)
		{
			printf("\t#%i\t[%s]\t%s\n", tmp_list_of_players[i].Get_Player_Number(), Get_Position_From_Enum(tmp_list_of_players[i].Get_Player_Position()).c_str(), tmp_list_of_players[i].Get_Player_Name().c_str());
		}
	}
	else
	{
		/* TODO: Error, size of team is 0! */
	}
}