#include "Transfermarkt.h"

#include <fstream>

std::ifstream finn("Transfermarkt.in");

void Transfermarkt::Init_Players() {
	std::string line;

	while (std::getline(finn, line)) {
		unsigned int ant = 0, cnt = 0;
		std::string first_name, last_name, position;
		unsigned int value = line[line.size() - 1] - '0';

		for (unsigned int i = 0; i < line.size(); i++) {
			if (!isdigit(line[i]) and !isalpha(line[i])) {
				cnt++;

				if (cnt == 1) first_name = line.substr(ant, i - ant);
				else if (cnt == 2) last_name = line.substr(ant, i - ant);
				else if (cnt == 3) position = line.substr(ant, i - ant);

				ant = i + 1;
			}
		}

		// std::cout << first_name << ' ' << last_name << ' ' << position << ' ' << value << '\n';

		/// creeaza jucatorul cu datele respective si il baga pe Transfermarkt 
		Player p(first_name, last_name, position, value);
		m_players.emplace_back(p);
	}
}

void Transfermarkt::Print_Players() {
	for (auto& player : m_players) {
		std::cout << "[NAME]: ";
		player.Get_FirstName_LastName();
		std::cout << "\n[POSITION]: ";
		player.Get_Position();
		std::cout << "\n[VALUE]: ";
		player.Get_Value();
		
		if (player.Get_Value_Number() == 1)
			std::cout << " milion de euro";
		else std::cout << " milioane de euro";
		std::cout << "\n\n";
	}
}