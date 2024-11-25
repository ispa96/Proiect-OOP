#include "Championship.h"

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::ifstream fin("Echipe_Superliga.in");
std::ifstream ff("Echipe_Interesate_de_Mine.in");

Coach coach;
bool leave_team = false;

/// for sort function
static bool cmp(Team& t1, Team& t2) {
	return t1.Get_Points() > t2.Get_Points();
}

/// loading bar
static void Sleep_Animation() {
	int times = 0, it = 1;

	while (times != 30) {
		system("cls");
		std::cout << "-------------------------------";
		std::cout << '\n';
		std::cout << '|';
		for (int j = 0; j < it - 1; j++)
			std::cout << char(35);
		for (int j = 0; j < 29 - times; j++)
			std::cout << ' ';
		std::cout << "|";
		std::cout << '\n';
		std::cout << "-------------------------------";

		times++;
		it++;
		Sleep(30);
	}
	system("cls");
}


/// constuctor 
Championship::Championship() {
	m_name = "SUPERLIGA";
}


/// start of championship (add teams to championship + info)
void Championship::Init_Championship() {
	std::string str;
	std::cout << "--- Bun venit la FCSB, noul tau club ! ---\n\n";
	std::cout << "Vei participa la primul tau sezon ca antrenor !\n";
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

	Sleep_Animation();
}


/// simulate matches
void Championship::Play_Matches() {
	srand(static_cast <unsigned int> (time(0)));

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
}


/// possible transfer (for coach/me)
void Championship::Leave_Or_Stay() {
	std::cout << "[WARNING]: Perioada de transferuri inca nu s-a incheiat!\n";
	std::cout << "[WARNING]: Aveti o oferta de a va transfera la alta echipa!\n";
	std::cout << "[WARNING]: Mai jos este lista detaliile contractului: \n";

	std::string name1, name2;
	int contract_years, salary_years;
	std::vector<Trans_Team> teams;

	while (ff >> name1 >> name2 >> contract_years >> salary_years) {
		Trans_Team team(name1, name2, contract_years, salary_years);
		teams.emplace_back(team);
	}

	srand(static_cast <unsigned int> (time(0)));
	int random_index = rand() % 4, value;
	std::string string;

	std::cout << "\n==========================================";
	std::cout << "\n[TEAM_NAME]: ";
	teams[random_index].Print_Name();
	std::cout << "\n[YEARS]: ";
	teams[random_index].Print_Contract_Years();
	std::cout << " ani de contract \n[SALARY]: ";
	teams[random_index].Print_Salary();
	std::cout << " milioane de euro / an\n==========================================\n\n";

	std::cout << "[WARNING]: Acceptati ?\n";
	std::cout << "[WARNING]: Apasati '1' pentru 'DA', respectiv '0' pentru 'NU' !\n";
	std::cin >> value;

	if (value == 1) {
		leave_team = true;
		system("cls");
		std::cout << "[WARNING]: MULTUMIM PENTRU TOT CE ATI FACUT PENTRU NOI !\n[WARNING]: VA DORIM MULT NOROC LA NOUA ECHIPA!\n";
		std::cin.get();
		std::cin.get();
		system("cls");
	}
}


/// simulate transfers
void Championship::Transfer_Window() {
	int my_index = 0, index = 0;
	std::string str;

	for (auto& team : m_teams) {
		if (team.Get_Name() == "FCSB") {
			my_index = index;
			break;
		}

		index++;
	}

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
		Sleep_Animation();

		int trans_players = 0;
		for (int i = 0; i < 7; i++) {
			Player player = transfermarkt.Get_Player(i);

			if (m_teams[my_index].Get_Budget() - (player.Get_Value_Number() * 1000000) >= 0) {
				trans_players++;
				m_teams[my_index].Add_Trans_Player(player);
				m_teams[my_index].Add_Player(player);

				m_teams[my_index].Add_Player(player);
				m_teams[my_index].Update_Budget(player.Get_Value_Number() * 1000000);
			}
			else break;
		}

		std::cout << "[WARNING]: Ati transferat " << trans_players << " jucatori :\n\n";
		m_teams[my_index].Print_Trans_Players();
		std::cout << "[WARNING]: Acum bugetul echipei este estimat la ";
		m_teams[my_index].Print_Budget();
		std::cout << " euro !\n";
	}
	else { /// else nu face nimic ( pot sa printez un mesaj ca nu s a transferat niciun jucator)
		system("cls");
		std::cout << "[WARNING]: Nu ati transferat niciun jucator!\n";
	}

	Leave_Or_Stay();
}


/// finish transfer window
void Championship::Exit_Transfer_Window() {
	system("cls");
	std::cout << "[WARNING]: SUNTEM BUCUROSI CA ATI ALES SA CONTINUATI CU NOI!\n[WARNING]: Apasati [ENTER] pentru a continua sezonul!\n";
	std::cin.get();
	std::cin.get();
	system("cls");

	std::cout << "[WARNING]: Reincep partidele!\n";
	std::cout << "[WARNING]: Urmeaza ultimele 15 etape din campionatul curent!\n";
	std::cout << "[WARNING]: Multa bafta !!!\n";
	std::cout << "[WARNING]: Apasa [ENTER] pentru derularea ultimelor 15 meciuri de campionat!\n";
	std::cin.ignore();

	Sleep_Animation();
}


/// info about first results
void Championship::Info_First_Half() {
	std::cout << "[WARNING]: Asa arata clasamentul dupa primele 15 meciuri !\n\n";

	int index = 0;
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

	m_teams[my_index].Print_Status();
	m_teams[my_index].Clear_Status();

	std::cout << "\n[WARNING]: Apasa [ENTER] pentru a vedea lotul curent al echipei!\n";
	std::string str;
	std::getline(std::cin, str);
	system("cls");

	std::cout << "[WARNING]: Acesta este lotul echipei tale inainte de perioada de transferuri:\n\n";
	m_teams[my_index].Init_Players();
	m_teams[my_index].Get_Players();

	std::cout << "\n[WARNING]: Apasa [ENTER] pentru a trece in perioada de transferuri !\n";
	std::getline(std::cin, str);
	system("cls");
}


/// info about second results + per total
void Championship::Info_Second_Half() {
	std::cout << "[WARNING]: Asa arata clasamentul dupa ultimele 15 meciuri !\n\n";

	int index = 0;
	for (auto& team : m_teams)
		team.Set_Position_In_Championship(index + 1), std::cout << ++index << ". ", team.Print_Name(), std::cout << ' ', team.Print_Points(), std::cout << " pts.\n", Sleep(50);
	std::cout << '\n';

	int my_index = 0;
	index = 0;

	for (auto& team : m_teams) {
		if (team.Get_Name() == "FCSB") {
			my_index = index;
			break;
		}

		index++;
	}

	std::cout << "[WARNING]: Acestea sunt rezultatele obtinute de echipa ta in a doua jumatate a SUPERLIGII:\n\n";
	m_teams[my_index].Print_Status();

	std::cout << "\n\n[WARNING]: Sezonul este GATA...\n";
	std::cout << "[WARNING]: Apasa [ENTER] pentru a vedea realizarile tale in Superliga!\n";
	std::cin.ignore();
	system("cls");

	std::cout << "[WARNING]: Rating-ul tau final, dupa 30 de meciuri in campionat este ";
	coach.Calculate_Performance();
	coach.Print_Performance();
	std::cout << ".\n";
	std::cout << "[WARNING]: Echipa ta a terminat pe locul ";
	for (auto& team : m_teams) {
		if (team.Get_Name() == "FCSB") {
			my_index = index;
			std::cout << team.Get_Position_In_Championship();
			break;
		}

		index++;
	}
	std::cout << ".\n";
	std::cout << "[WARNING]: FELICITARI !!!";
	std::cin.ignore();
	system("cls");
}


/// everything...
void Championship::Run() {
	Init_Championship();

	/// ------------------------------------------------------------------------------- PRIMA PARTE A CAMPIONATULUI --------------------------------------------------------------------

	Play_Matches();
	Info_First_Half();

	/// ------------------------------------------------------------------------------- PERIOADA DE TRANSFERURI --------------------------------------------------------------------

	Transfer_Window();
	if (leave_team) return;
	Exit_Transfer_Window();

	/// ----------------------------------------------------------------------------- A DOUA PARTE A CAMPIONATULUI ----------------------------------------------------------------------------------------
	
	Play_Matches();
	Info_Second_Half();
}