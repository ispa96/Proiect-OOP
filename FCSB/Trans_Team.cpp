#include "Trans_Team.h"

Trans_Team::Trans_Team(std::string& name1, std::string& name2, int& contract, int& salary) {
	m_name = name1;
	m_name += ' ';
	m_name += name2;

	m_contract_years = contract;
	m_salary_years = salary;
}

void Trans_Team::Print_Name() {
	std::cout << m_name;
}

void Trans_Team::Print_Contract_Years() {
	std::cout << m_contract_years;
}

void Trans_Team::Print_Salary() {
	std::cout << m_salary_years;
}