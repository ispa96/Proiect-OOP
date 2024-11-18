#include "Team.h"

#include <fstream>

std::ifstream read("FCSB.in");

Team::Team() {
	m_points = 0;
	m_budget = 0;
	m_position_in_championship = 0;
}

void Team::Set_Name(std::string name) {
	m_name = name;
}

void Team::Print_Name() {
	std::cout << m_name;
}

void Team::Print_Points() {
	std::cout << m_points;
}

void Team::Win_Increase_Points() {
	m_points += 3;
}

void Team::Draw_Increase_Points() {
	m_points++;
}

int Team::Get_Points() {
	return m_points;
}

std::string Team::Get_Name() {
	return m_name;
}

void Team::Set_Position_In_Championship(int position) {
	m_position_in_championship = position;
}

int Team::Get_Position_In_Championship() {
	return m_position_in_championship;
}

void Team::Update_Status(Team& other_team, int& goals1, int& goals2) {
	m_status.emplace_back(std::make_pair(other_team.Get_Name(), std::make_pair(goals1, goals2)));
}

void Team::Print_Status() {
	for (auto& match : m_status) {
		std::cout << "vs. " << match.first << ' ' << match.second.first << " - " << match.second.second << '\n';
	}
}

void Team::Init_Players() {
	std::string line;

	while (std::getline(read, line)) {
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

		std::cout << first_name << ' ' << last_name << ' ' << position << ' ' << value << '\n';

		/// creeaza jucatorul cu datele respective si il baga pe Transfermarkt 
		Player p(first_name, last_name, position, value);
		m_players.emplace_back(p);
	}
}

void Team::Get_Players() {
	for (auto& player : m_players) {
		std::cout << "[NAME]: ";
		player.Get_FirstName_LastName();
		std::cout << "\n[POSITION]: ";
		player.Get_Position();
		std::cout << "\n\n";
	}
}