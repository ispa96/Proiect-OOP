#include "Team.h"

Team::Team() {
	m_points = 0;
	m_budget = 0;
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