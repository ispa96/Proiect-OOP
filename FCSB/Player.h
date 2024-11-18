#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Player {
private:
	std::string m_first_name, m_last_name;
	std::string m_position;
	long long m_value, m_salary;

public:
	Player(std::string, std::string, std::string, long long);
	void Get_FirstName_LastName();
	void Get_Position();
};

