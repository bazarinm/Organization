#include <vector>
#include <string>
#include "Company.h"
#include "Teamleader.h"
#include "Manager.h"
#include "Programmer.h"

Company::Company()
	: name("My Company")
{}

Company::Company(const std::string& name_)
	: name(name_)
{}

Company::~Company()
{
	int i;
	for (i = 0; i < managers.size(); i++)
		DeleteManager(i);
	for (i = 0; i < teamleaders.size(); i++)
		DeleteTeamleader(i);
	for (i = 0; i < programmers.size(); i++)
		DeleteProgrammer(i);
}

Manager* Company::CreateManager(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	Manager* new_manager = new Manager(first_name, last_name, email, wage);
	managers.push_back(new_manager);
	for_hr.push_back(new_manager);
	for_acc.push_back(new_manager);
	return new_manager;
}

Teamleader* Company::CreateTeamleader(int supervisor_, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	Manager* supervisor = managers.at(supervisor_);
	Teamleader* new_teamleader = new Teamleader(supervisor, first_name, last_name, email, wage);
	teamleaders.push_back(new_teamleader);
	for_hr.push_back(new_teamleader);
	for_acc.push_back(new_teamleader);
	return new_teamleader;
}

Programmer* Company::CreateProgrammer(int supervisor_, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	Teamleader* supervisor = teamleaders.at(supervisor_);
	Programmer* new_programmer = new Programmer(supervisor, first_name, last_name, email, wage);
	programmers.push_back(new_programmer);
	for_hr.push_back(new_programmer);
	for_acc.push_back(new_programmer);
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
	std::vector<Manager*>::iterator it = managers.begin();
	managers.erase(it + manager_);
	std::vector<HR*>::iterator kt;
	for (kt = for_hr.begin(); kt != for_hr.end(); kt++)
		if (*kt == manager) {
			for_hr.erase(kt);
			break;
		}
	std::vector<Accountant*>::iterator lt;
	for (lt = for_acc.begin(); lt != for_acc.end(); lt++)
		if (*lt == manager) {
			for_acc.erase(lt);
			break;
		}
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
	std::vector<HR*>::iterator kt;
	for (kt = for_hr.begin(); kt != for_hr.end(); kt++)
		if (*kt == teamleader) {
			for_hr.erase(kt);
			break;
		}
	std::vector<Accountant*>::iterator lt;
	for (lt = for_acc.begin(); lt != for_acc.end(); lt++)
		if (*lt == teamleader) {
			for_acc.erase(lt);
			break;
		}
}

void Company::DeleteProgrammer(int programmer_)
{
	Programmer* programmer = programmers.at(programmer_);
	programmer->RemoveSupervisor();
	delete programmer;
	std::vector<Programmer*>::iterator it = programmers.begin();
	programmers.erase(it + programmer_);
	std::vector<HR*>::iterator kt;
	for (kt = for_hr.begin(); kt != for_hr.end(); kt++)
		if (*kt == programmer) {
			for_hr.erase(kt);
			break;
		}
	std::vector<Accountant*>::iterator lt;
	for (lt = for_acc.begin(); lt != for_acc.end(); lt++)
		if (*lt == programmer) {
			for_acc.erase(lt);
			break;
		}
}

void Company::AppointToManager(int manager_, int teamleader_)
{
	Manager* manager = managers.at(manager_);
	Teamleader* teamleader = teamleaders.at(teamleader_);
	manager->AppointSubordinate(teamleader);
}

void Company::AppointToTeamleader(int teamleader_, int programmer_)
{
	Teamleader* teamleader = teamleaders.at(teamleader_);
	Programmer* programmer = programmers.at(programmer_);
	teamleader->AppointSubordinate(programmer);
}

std::vector<Manager*> Company::ListManagers()
{
	return managers;
}

std::vector<Teamleader*> Company::ListTeamleaders()
{
	return teamleaders;
}

std::vector<Programmer*> Company::ListProgrammers()
{
	return programmers;
}

Manager* Company::GetManager(int manager_)
{
	return managers.at(manager_);
}

Teamleader* Company::GetTeamleader(int teamleader_)
{
	return teamleaders.at(teamleader_);
}

Programmer* Company::GetProgrammer(int programmer_)
{
	return programmers.at(programmer_);
}

std::vector<Teamleader*> Company::ListManagerSubordinates(int manager_)
{
	Manager* manager = managers.at(manager_);
	return manager->ListSubordinates();
}

std::vector<Programmer*> Company::ListTeamleaderSubordinates(int teamleader_)
{
	Teamleader* teamleader = teamleaders.at(teamleader_);
	return teamleader->ListSubordinates();
}

Manager* Company::GetTeamleaderSupervisor(int teamleader_)
{
	Teamleader* teamleader = teamleaders.at(teamleader_);
	return teamleader->GetSupervisor();
}
Teamleader* Company::GetProgrammerSupervisor(int programmer_)
{
	Programmer* programmer = programmers.at(programmer_);
	return programmer->GetSupervisor();
}

std::vector<HR*> Company::GetHrAccess()
{
	return for_hr;
}

std::vector<Accountant*> Company::GetAccountingAcess()
{
	return for_acc;
}