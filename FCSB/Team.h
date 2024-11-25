#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

class Team {
private:
	std::string m_name;
	int m_points, m_budget, m_position_in_championship;
	std::vector<std::pair<std::string, std::pair<int, int>>> m_status;
	std::vector<Player> m_players;
	std::vector<Player> m_trans_players;

public:
	Team();
	void Set_Name(std::string);
	void Print_Name();
	void Print_Points();
	void Win_Increase_Points();
	void Draw_Increase_Points();
	void Set_Position_In_Championship(int);
	void Update_Status(Team&, int&, int&);
	void Print_Status();
	void Init_Players();
	void Get_Players();
	void Win_Increase_Budget();
	void Draw_Increase_Budget();
	void Match_Increase_Budget(long long&);
	void Print_Budget();
	void Clear_Status();
	void Add_Player(Player&);
	void Update_Budget(long long);
	void Add_Trans_Player(Player&);
	void Print_Trans_Players();
	int Get_Position_In_Championship();
	int Get_Points();
	long long Get_Budget();
	std::string Get_Name();
};

