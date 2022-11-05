#include "player.h"

std::vector<player_status> player_names_list = {
	{"Aristoteles", 5, 5, 5},
	{"Platon", 5, 5, 5},
	{"Socrates", 5, 5, 5},
	{"John Locke", 5, 5, 5},
	{"Immanuel Kant", 5, 5, 5},
	{"Rene Descartes", 5, 5, 5},
	{"Friedrich Nietzsche", 5, 5, 5},
	{"Confuncio", 5, 5, 5},
	{"Karl Marx", 5, 5, 5},
	{"David Hume", 5, 5, 5},
	{"Epicuro", 5, 5, 5},
	{"Ludwig Wittgenstein", 5, 5, 5},
	{"Georg Wilhelm Friedrich Hegel", 5, 5, 5},
	{"Ralph Waldo Emerson", 5, 5, 5},
	{"Baruch Spinoza", 5, 5, 5},
	{"Soren Kierkegaard", 5, 5, 5},
	{"Michel Foucault", 5, 5, 5},
	{"Jean-Jacques Rousseau", 5, 5, 5},
	{"Nicolas Maquiavelo", 5, 5, 5},
	{"Bertrand Russell", 5, 5, 5},
	{"Agustin de Hipona", 5, 5, 5},
	{"Avicena", 5, 5, 5},
	{"John Stuart Mill", 5, 5, 5},
	{"Zenon de Citio", 5, 5, 5},
	{"Martin Heidegger", 5, 5, 5},
	{"Jean-Paul Sartre", 5, 5, 5},
	{"Tomas de Aquino", 5, 5, 5},
	{"Thomas Hobbes", 5, 5, 5},
	{"Jacques Derrida", 5, 5, 5},
	{"Edmund Husserl", 5, 5, 5},
	{"Arthur Schopenhauer", 5, 5, 5},
	{"Gottfried Leibniz", 5, 5, 5},
	{"Karl Popper", 5, 5, 5},
	{"William James", 5, 5, 5},
	{"Simone de Beavoir", 5, 5, 5},
	{"Blaise Pascal", 5, 5, 5},
	{"Gottlob Frege", 5, 5, 5},
	{"Ayn Rand", 5, 5, 5},
	{"Pitagoras", 5, 5, 5},
	{"Diogenes de Sinope", 5, 5, 5},
	{"Parmenides de Elea", 5, 5, 5},
	{"Hannah Arendt", 5, 5, 5},
	{"John Dewey", 5, 5, 5},
	{"Brian Leiter", 5, 5, 5},
	{"Rubiks", 8, 8, 8},
};

std::string Get_Random_Player_Name(void)
{
	std::vector<std::string> tmp_player_names_list;

	for (int i = 0; i < player_names_list.size(); i++)
	{
		tmp_player_names_list.push_back(player_names_list[i].player_name);
	}

	return Get_Random_String_From_String_Vector(tmp_player_names_list);
}

int Get_Random_Player_Number(void)
{
	/* Number will go from 2 to 100, remember that 1's is for the Goalkeeper */
	return Get_Random_Number(98) + 2; /* Min will be 2, max 100 */
}

player_position Get_Random_Player_Position_Enum(void)
{
	int max_positions = (int)WINGER;
	return (player_position) (Get_Random_Number(max_positions - 1) + 2);	/* Min 2, Max 5*/
}


std::string Get_Position_From_Enum(player_position player_position)
{

	switch (player_position)
	{
	case GOALKEEPER:
		return "GK";

	case DEFENDER:
		return "DF";
		
	case MIDFIELDER:
		return "MD";

	case STRIKER:
		return "ST";

	case WINGER:
		return "WI";

	case NO_VALID_POSITION:
	default:
		return "";
	}
}

void Goalkeeper_Save(void)
{
	printf("GOALKEEPER JUMPS TO SAVE IT!...\n");
}

void Break_A_Leg(void)
{

}

void Winger_Center(void)
{

}

void Striker_Shoot(void)
{
	printf("Striker SHOOOOTS!...\n");
}

void Pass_The_Ball(void)
{
	printf("He passes the ball...\n");
}