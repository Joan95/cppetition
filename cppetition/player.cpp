#include "player.h"
#include "aux_functions.h"

std::vector<std::string> player_names_list = {
	"Aristoteles",
	"Platon",
	"Socrates",
	"John Locke",
	"Immanuel Kant",
	"Rene Descartes",
	"Friedrich Nietzsche",
	"Confuncio",
	"Karl Marx",
	"David Hume",
	"Epicuro",
	"Ludwig Wittgenstein",
	"Georg Wilhelm Friedrich Hegel",
	"Ralph Waldo Emerson",
	"Baruch Spinoza",
	"Soren Kierkegaard",
	"Michel Foucault",
	"Jean-Jacques Rousseau",
	"Nicolas Maquiavelo",
	"Bertrand Russell",
	"Agustin de Hipona",
	"Avicena",
	"John Stuart Mill",
	"Zenon de Citio",
	"Martin Heidegger",
	"Jean-Paul Sartre",
	"Tomas de Aquino",
	"Thomas Hobbes",
	"Jacques Derrida",
	"Edmund Husserl",
	"Arthur Schopenhauer",
	"Gottfried Leibniz",
	"Karl Popper",
	"William James",
	"Simone de Beavoir",
	"Blaise Pascal",
	"Gottlob Frege",
	"Ayn Rand",
	"Pitagoras",
	"Diogenes de Sinope",
	"Parmenides de Elea",
	"Hannah Arendt",
	"John Dewey",
	"Brian Leiter"
};

std::string Get_Random_Player_Name(void)
{
	return player_names_list[Get_Random_Number(player_names_list.size())];
}

int Get_Random_Player_Number(void)
{
	/* Number will go from 2 to 100, remember that 1's is for the Goalkeeper */
	return Get_Random_Number(98) + 2; /* Min will be 2, max 100 */
}