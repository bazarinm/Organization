#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include "Manager.h"
#include "Teamleader.h"
#include "Programmer.h"

class Company
{
public:
	Manager* CreateManager(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);
	Teamleader* CreateTeamleader(int supervisor, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);
	Programmer* CreateProgrammer(int supervisor, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);

	void DeleteManager(int manager);
	void DeleteTeamleader(int teamleader);
	void DeleteProgrammer(int programmer);

	void AppointToManager(int manager, int teamleader);
	void AppointToTeamleader(int teamleader, int programmer);
private:
	std::string name;
	std::vector<Manager*> managers;
	std::vector<Teamleader*> teamleaders;
	std::vector<Programmer*> programmers;
};

#endif

