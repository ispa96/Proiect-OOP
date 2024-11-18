#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include "Team.h"

class Championship {
private:
	std::string m_name;
	std::vector<Team> m_teams;

public:
	Championship();
	void Run();
};

