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
		std::cout << aux[i], Sleep(75);
	std::cout << ' ';

	for (int i = 0; i < m_name.size(); i++)
		std::cout << m_name[i], Sleep(75);
	std::cout << ' ';

	for (int i = 0; i < aux.size(); i++)
		std::cout << aux[i], Sleep(75);
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

	std::cout << "[WARNING]: Apasa [ENTER] pentru derularea primelor 15 etape de campionat!\n";
	std::getline(std::cin, str);
	system("cls");

	int times = 0, it = 1;

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

	/// ------------------------------------------------------------------------------- PRIMA PARTE A CAMPIONATULUI --------------------------------------------------------------------

	/// acum trebuie sa simulez primele 15 meciuri pentru fiecare echipa
	srand(static_cast <unsigned int> (time(0)));
	Coach coach;

	for (int i = 0; i < m_teams.size() - 1; i++) {
		for (int j = i + 1; j < m_teams.size(); j++) {
			/// o sa joace m_teams[i] cu m_teams[j]

			long long supporters = rand() % 30000 + 1;	/// 30k
			if (supporters < 15000)
				supporters += 15000;
			supporters *= 10;

			m_teams[i].Match_Increase_Budget(supporters);
			m_teams[j].Match_Increase_Budget(supporters);

			int goals1 = rand() % 6;
			int goals2 = rand() % 6;
			// std::cout << goals1 << ' ' << goals2 << '\n';

			if (goals1 > goals2) {	/// a castigat m_teams[i]
				m_teams[i].Win_Increase_Points();
				m_teams[i].Win_Increase_Budget();

				m_teams[i].Update_Status(m_teams[j], goals1, goals2);
				m_teams[j].Update_Status(m_teams[i], goals2, goals1);

				if (m_teams[i].Get_Name() == "FCSB")
					coach.Update_Performance("WIN");
				if (m_teams[j].Get_Name() == "FCSB")
					coach.Update_Performance("LOSE");
			}
			else if (goals1 == goals2) {	/// s a terminat egal
				m_teams[i].Draw_Increase_Points();
				m_teams[j].Draw_Increase_Points();
				m_teams[i].Draw_Increase_Budget();
				m_teams[j].Draw_Increase_Budget();

				m_teams[i].Update_Status(m_teams[j], goals1, goals2);
				m_teams[j].Update_Status(m_teams[i], goals1, goals2);

				if (m_teams[i].Get_Name() == "FCSB")
					coach.Update_Performance("DRAW");
				if (m_teams[j].Get_Name() == "FCSB")
					coach.Update_Performance("DRAW");
			}
			else {	/// a castigat m_teams[j]
				m_teams[j].Win_Increase_Points();
				m_teams[j].Win_Increase_Budget();

				m_teams[i].Update_Status(m_teams[j], goals1, goals2);
				m_teams[j].Update_Status(m_teams[i], goals2, goals1);

				if (m_teams[i].Get_Name() == "FCSB")
					coach.Update_Performance("LOSE");
				if (m_teams[j].Get_Name() == "FCSB")
					coach.Update_Performance("WIN");
			}
		}
	}

	sort(m_teams.begin(), m_teams.end(), cmp);
	std::cout << "[WARNING]: Asa arata clasamentul dupa primele 15 meciuri !\n\n";

	index = 0;
	for (auto& team : m_teams)
		team.Set_Position_In_Championship(index + 1), std::cout << ++index << ". ", team.Print_Name(), std::cout << ' ', team.Print_Points(), std::cout << " pts.\n", Sleep(50);
	std::cout << '\n';

	int my_index = 0;
	index = 0;

	std::cout << "[WARNING]: Rating-ul tau ca antrenor este ";
	coach.Calculate_Performance();
	coach.Print_Performance();
	std::cout << ".\n";
	std::cout << "[WARNING]: Echipa ta se afla pe locul ";
	for (auto& team : m_teams) {
		if (team.Get_Name() == "FCSB") {
			my_index = index;
			std::cout << team.Get_Position_In_Championship();
			break;
		}

		index++;
	}
	std::cout << ".\n";
	std::cout << "[WARNING]: Acestea sunt rezultatele obtinute de echipa ta in prima jumatate a SUPERLIGII:\n\n";
	for (auto& team : m_teams) {
		if (team.Get_Name() == "FCSB") {
			team.Print_Status();
			break;
		}
	}

	std::cout << "\n[WARNING]: Apasa [ENTER] pentru a vedea lotul curent al echipei!\n";
	std::getline(std::cin, str);

	std::cout << "\n[WARNING]: Acesta este lotul echipei tale inainte de perioada de transferuri:\n\n";
	m_teams[my_index].Init_Players();
	m_teams[my_index].Get_Players();

	std::cout << "\n[WARNING]: Apasa [ENTER] pentru a trece in perioada de transferuri !\n";
	std::getline(std::cin, str);
	system("cls");

	/// ------------------------------------------------------------------------------- PERIOADA DE TRANSFERURI --------------------------------------------------------------------

	std::cout << "[WARNING]: Ne aflam in perioada de transferuri!\n";
	std::cout << "[WARNING]: Bugetul echipei tale este in valoare de ";
	m_teams[my_index].Print_Budget();
	std::cout << " euro!\n";
	std::cout << "[WARNING]: Apasa [ENTER] pentru afisarea jucatorilor transferabili !\n";
	std::getline(std::cin, str);

	Transfermarkt transfermarkt;
	transfermarkt.Init_Players();
	transfermarkt.Print_Players();
	transfermarkt.Sort_Players();

	std::cout << "[WARNING]: Doresti sa transferi jucatori ?\n";
	std::cout << "[WARNING]: Apasa '1', daca doresti, respectiv '0', daca nu doresti !\n";
	bool value = 0;
	std::cin >> value;

	if (value == 1) {
		times = 0;
		it = 1;

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

		int trans_players = 0;
		for (int i = 0; i < 7; i++) {
			Player player = transfermarkt.Get_Player(i);

			if (m_teams[my_index].Get_Budget() - (player.Get_Value_Number() * 1000000) >= 0) {
				trans_players++;
				m_teams[my_index].Add_Trans_Player(player);
				m_teams[my_index].Add_Player(player);

				m_teams[my_index].Add_Player(player);
				m_teams[my_index].Update_Budget(player.Get_Value_Number()* 1000000);
				// m_teams[my_index].Print_Budget();
				// std::cout << '\n';
			}
			else break;
		}

		std::cout << "[WARNING]: Ati transferat " << trans_players << " jucatori :\n\n";
		m_teams[my_index].Print_Trans_Players();
		std::cout << "[WARNING]: Acum bugetul echipei este estimat la ";
		m_teams[my_index].Print_Budget();
		std::cout << " euro !\n";
	}
	/// else nu face nimic

	std::cout << "[WARNING]: Perioada de transferuri s-a incheiat!\n";
	std::cout << "[WARNING]: Urmeaza cea de-a doua jumatate a sezonului!\n";
	std::cout << "[WARNING]: Multa Bafta !!!\n";
	std::cout << "[WARNING]: Apasa [ENTER] pentru reinceperea campionatului!\n";
	std::getline(std::cin, str);
}