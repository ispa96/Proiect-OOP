#pragma once

#include <vector>
#include <string>

#include "Player.h"

class Transfermarkt {
private:
	std::vector<Player> m_players;

public:
	void Init_Players();
	void Print_Players();
};

