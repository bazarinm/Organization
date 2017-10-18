#include <vector>
#include "Company.h"
#include "Teamleader.h"
#include "Manager.h"
#include "Programmer.h"

Manager* Company::CreateManager(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	Manager* new_manager = new Manager(first_name, last_name, email, wage);
	managers.push_back(new_manager);
	return new_manager;
}

Teamleader* Company::CreateTeamleader(int supervisor_, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	Manager* supervisor = managers.at(supervisor_);
	Teamleader* new_teamleader = new Teamleader(supervisor, first_name, last_name, email, wage);
	teamleaders.push_back(new_teamleader);
	return new_teamleader;
}

Programmer* Company::CreateProgrammer(int supervisor_, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	Teamleader* supervisor = teamleaders.at(supervisor_);
	Programmer* new_programmer = new Programmer(supervisor, first_name, last_name, email, wage);
	programmers.push_back(new_programmer);
	return new_programmer;
}

void Company::DeleteManager(int manager_)
{
	Manager* manager = managers.at(manager_);
	std::vector<Teamleader*>::iterator jt;
	std::vector<Teamleader*> subordinates = manager->ListSubordinates();
	for (jt = subordinates.begin(); jt != subordinates.end(); jt++)
		(*jt)->RemoveSupervisor();
	delete manager;
	std::vector<Manager*>::iterator it;
	std::vector<Manager*>::iterator it = managers.begin();
	managers.erase(it + manager_);
}

void Company::DeleteTeamleader(int teamleader_)
{
	Teamleader* teamleader = teamleaders.at(teamleader_);
	std::vector<Programmer*>::iterator jt;
	std::vector<Programmer*> subordinates = teamleader->ListSubordinates();
	for (jt = subordinates.begin(); jt != subordinates.end(); jt++) 
		(*jt)->RemoveSupervisor();
	teamleader->RemoveSupervisor();
	delete teamleader;
	std::vector<Teamleader*>::iterator it = teamleaders.begin();
	teamleaders.erase(it + teamleader_);
}

void Company::DeleteProgrammer(int programmer_)
{
	Programmer* programmer = programmers.at(programmer_);
	programmer->RemoveSupervisor();
	delete programmer;
	std::vector<Programmer*>::iterator it = programmers.begin();
	programmers.erase(it + programmer_);
}