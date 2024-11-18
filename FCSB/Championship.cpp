#include "Championship.h"
#include <fstream>

std::ifstream fin("Echipe_Superliga.in");

Championship::Championship() {
	m_name = "SUPERLIGA";
}

void Championship::Run() {
	std::string str;
	std::cout << "--- Bun venit la noul tau club ! ---\n";
	std::cout << "Apasa [ENTER] pentru a incepe aventura !\n";
	std::getline(std::cin, str);
	system("cls");

	std::string aux = "*******";
	for (int i = 0; i < aux.size(); i++)
		std::cout << aux[i], Sleep(100);
	std::cout << ' ';

	for (int i = 0; i < m_name.size(); i++)
		std::cout << m_name[i], Sleep(100);
	std::cout << ' ';

	for (int i = 0; i < aux.size(); i++)
		std::cout << aux[i], Sleep(100);
	std::cout << '\n';

	std::cout << "\n[WARNING]: Prima parte a SUPERLIGII va contine primele 15 meciuri din acest sezon.\n[WARNING]: Multa Bafta !!!\n";
	std::cout << "[WARNING]: Asa arata tabloul cu echipele inainte de inceperea partidelor:\n\n";

	std::string name;
	while (std::getline(fin, name)) {
		Team team;
		team.Set_Name(name);
		m_teams.emplace_back(team);
	}

	for (auto& team : m_teams)
		team.Print_Points(), std::cout << " pts. ", team.Print_Name(), std::cout << '\n';
	std::cout << '\n';

	std::cout << "[WARNING]: Apasa [ENTER] pentru derularea primei jumatati de campionat!";
	std::getline(std::cin, str);
	system("cls");

	int times = 0, it = 1;
	std::cout << '\n';

	while (times != 30) {
		system("cls");
		std::cout << "-------------------------------";
		std::cout << '\n';
		std::cout << '|';
		for (unsigned int j = 0; j < it - 1; j++)
			std::cout << char(35);
		for (unsigned int j = 0; j < 29 - times; j++)
			std::cout << ' ';
		std::cout << "|";
		std::cout << '\n';
		std::cout << "-------------------------------";

		times++;
		it++;
		Sleep(30);
	}
	system("cls");

	/// acum trebuie sa simulez primele 15 meciuri pentru fiecare echipa

}