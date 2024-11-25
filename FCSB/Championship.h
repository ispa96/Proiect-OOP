#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include "Transfermarkt.h"
#include "Team.h"
#include "Coach.h"
#include "Trans_Team.h"

class Championship {
private:
	std::string m_name;
	std::vector<Team> m_teams;

public:
	Championship();
	void Init_Championship();
	void Run();
	void Play_Matches();
	void Transfer_Window();
	void Leave_Or_Stay();
	void Exit_Transfer_Window();
	void Info_First_Half();
	void Info_Second_Half();
};