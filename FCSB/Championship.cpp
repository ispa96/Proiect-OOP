#include "Championship.h"

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::ifstream fin("Echipe_Superliga.in");

Championship::Championship() {
	m_name = "SUPERLIGA";
}

static bool cmp(Team& t1, Team& t2) {
	return t1.Get_Points() > t2.Get_Points();
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

	int index = 0;
	for (auto& team : m_teams)
		std::cout << ++index << ". ", team.Print_Name(), std::cout << ' ', team.Print_Points(), std::cout << " pts.\n", Sleep(50);
	std::cout << '\n';

	std::cout << "[WARNING]: Apasa [ENTER] pentru derularea primelor 15 etape de campionat!";
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
	srand(static_cast <unsigned int> (time(0)));

	for (int i = 0; i < m_teams.size() - 1; i++) {
		for (int j = i + 1; j < m_teams.size(); j++) {
			/// o sa joace m_teams[i] cu m_teams[j]

			int goals1 = rand() % 6 + 1;
			int goals2 = rand() % 6 + 1;
			// std::cout << goals1 << ' ' << goals2 << '\n';

			if (goals1 > goals2) {	/// a castigat m_teams[i]
				m_teams[i].Win_Increase_Points();
			}
			else if (goals1 == goals2) {	/// s a terminat egal
				m_teams[i].Draw_Increase_Points();
				m_teams[j].Draw_Increase_Points();
			}
			else {	/// a castigat m_teams[j]
				m_teams[j].Win_Increase_Points();
			}
		}
	}

	sort(m_teams.begin(), m_teams.end(), cmp);
	std::cout << "[WARNING]: Asa arata clasamentul dupa primele 15 meciuri !\n\n";

	index = 0;
	for (auto& team : m_teams)
		team.Set_Position_In_Championship(index + 1), std::cout << ++index << ". ", team.Print_Name(), std::cout << ' ', team.Print_Points(), std::cout << " pts.\n", Sleep(50);
	std::cout << '\n';

	std::cout << "[WARNING]: Echipa ta se afla pe locul ";
	for (auto& team : m_teams) {
		if (team.Get_Name() == "FCSB") {
			std::cout << team.Get_Position_In_Championship();
			break;
		}
	}
	std::cout << ".\n";

	std::cout << "[WARNING': Apasa [ENTER] pentru a trece in perioada de transferuri !";
	std::getline(std::cin, str);
	system("cls");

	std::cout << "[WARNING]: Ne aflam in perioada de transferuri!\n";
	std::cout << "[WARNING]: Apasa [ENTER] pentru afisarea jucatorilor transferabili !\n";
	std::getline(std::cin, str);
}