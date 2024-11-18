#include "Coach.h"

Coach::Coach() {
	m_age = 20;
	m_first_name = "Ispasoiu";
	m_last_name = "Robert";
	m_performance = 0.0;
}

void Coach::Update_Performance(std::string string) {
	if (string == "WIN") m_performance += 10.0;
	else if (string == "DRAW") m_performance += 7.0;
	else m_performance += 5.0;
}

void Coach::Calculate_Performance() {
	m_performance /= 15.0;
}

void Coach::Print_Performance() {
	std::cout << std::setprecision(2) << m_performance;
}