#pragma once

#include <iostream>

class Team {
private:
	std::string m_name;
	int m_points, m_budget, m_position_in_championship;

public:
	Team();
	void Set_Name(std::string);
	void Print_Name();
	void Print_Points();
	void Win_Increase_Points();
	void Draw_Increase_Points();
	void Set_Position_In_Championship(int);
	int Get_Position_In_Championship();
	int Get_Points();
	std::string Get_Name();
};

