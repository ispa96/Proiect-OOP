#pragma once

#include <iostream>

class Team {
private:
	std::string m_name;
	int m_points, m_budget;

public:
	Team();
	void Set_Name(std::string);
	void Print_Name();
	void Print_Points();
};

