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
	void CreateManager(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);
	void CreateTeamleader(Manager* supervisor, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);
	void CreateProgrammer(Teamleader* supervisor, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);

private:
	std::string name;
	std::vector<Manager> managers;
	std::vector<Teamleader> teamleaders;
	std::vector<Programmer> programmers;
};

#endif

