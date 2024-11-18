#include "Player.h"

Player::Player(std::string first_name, std::string last_name, std::string position, long long value) {
	m_first_name = first_name;
	m_last_name = last_name;
	m_position = position;
	m_value = value;
}


void Player::Get_FirstName_LastName() {
	std::cout << m_first_name << ' ' << m_last_name;
}

void Player::Get_Position() {
	std::cout << m_position;
}