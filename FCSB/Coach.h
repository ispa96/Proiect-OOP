#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class Coach {
private:
	std::string m_first_name, m_last_name;
	int m_age;
	double m_performance;

public:
	Coach();
	void Update_Performance(std::string);
	void Calculate_Performance();
	void Print_Performance();
};

