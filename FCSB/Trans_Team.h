#pragma once

#include <iostream>

class Trans_Team {
private:
	std::string m_name;
	int m_contract_years, m_salary_years;

public:
	Trans_Team(std::string&, std::string&, int&, int&);
	void Print_Name();
	void Print_Contract_Years();
	void Print_Salary();
};

