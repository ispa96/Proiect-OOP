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
	int Get_Position_In_Championship();
	int Get_Points();
	std::string Get_Name();
};

