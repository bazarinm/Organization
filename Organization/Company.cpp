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
	while (programmers.size() > 0)
		DeleteProgrammer(programmers.back());
	while (teamleaders.size() > 0)
		DeleteTeamleader(teamleaders.back());
	while (managers.size() > 0)
		DeleteManager(managers.back());
}

Employee* Company::CreateManager(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	std::vector<Manager*>::iterator it;
	for (it = managers.begin(); it != managers.end(); it++)
		if ((*it)->GetPersonalInfo() == (last_name + ' ' + first_name + ", " + email))
			throw "this manager already exists";

	Manager* new_manager = new Manager(first_name, last_name, email, wage);

	managers.push_back(new_manager);
	for_hr.push_back(new_manager);
	for_acc.push_back(new_manager);
	return new_manager;
}

Employee* Company::CreateTeamleader(Employee* supervisor_, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	std::vector<Teamleader*>::iterator it;
	for (it = teamleaders.begin(); it != teamleaders.end(); it++)
		if ((*it)->GetPersonalInfo() == (last_name + ' ' + first_name + ", " + email))
			throw "this teamleader already exists";

	Manager* supervisor = GetManager(supervisor_);
	Teamleader* new_teamleader = new Teamleader(supervisor, first_name, last_name, email, wage);

	teamleaders.push_back(new_teamleader);
	for_hr.push_back(new_teamleader);
	for_acc.push_back(new_teamleader);
	return new_teamleader;
}

Employee* Company::CreateProgrammer(Employee* supervisor_, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage)
{
	std::vector<Programmer*>::iterator it;
	for (it = programmers.begin(); it != programmers.end(); it++)
		if ((*it)->GetPersonalInfo() == (last_name + ' ' + first_name + ", " + email))
			throw "this programmer already exists";

	Teamleader* supervisor = GetTeamleader(supervisor_);
	Programmer* new_programmer = new Programmer(supervisor, first_name, last_name, email, wage);

	programmers.push_back(new_programmer);
	for_hr.push_back(new_programmer);
	for_acc.push_back(new_programmer);
	return new_programmer;
}

void Company::DeleteManager(Employee* manager_)
{
	Manager* manager;
	std::vector<Manager*>::iterator it = std::find(managers.begin(), managers.end(), manager_);
	if (it != managers.end())
		manager = *it;
	else
		throw "This manager does not exist";

	std::vector<Teamleader*>::iterator jt;
	std::vector<Teamleader*> subordinates = manager->ListSubordinates();
	for (jt = subordinates.begin(); jt != subordinates.end(); jt++)
		manager->RemoveSubordinate(*jt);

	std::vector<HR*>::iterator kt = std::find(for_hr.begin(), for_hr.end(), manager);
	for_hr.erase(kt);
	std::vector<Accountant*>::iterator lt = std::find(for_acc.begin(), for_acc.end(), manager);
	for_acc.erase(lt);

	delete manager;
	managers.erase(it);
}

void Company::DeleteTeamleader(Employee* teamleader_)
{
	Teamleader* teamleader;
	std::vector<Teamleader*>::iterator it = std::find(teamleaders.begin(), teamleaders.end(), teamleader_);
	if (it != teamleaders.end())
		teamleader = *it;
	else
		throw "This teamleader does not exist";

	std::vector<Programmer*>::iterator jt;
	std::vector<Programmer*> subordinates = teamleader->ListSubordinates();
	for (jt = subordinates.begin(); jt != subordinates.end(); jt++)
		teamleader->RemoveSubordinate(*jt);
	teamleader->RemoveSupervisor();

	std::vector<HR*>::iterator kt = std::find(for_hr.begin(), for_hr.end(), teamleader);
	for_hr.erase(kt);
	std::vector<Accountant*>::iterator lt = std::find(for_acc.begin(), for_acc.end(), teamleader);
	for_acc.erase(lt);

	delete teamleader;
	teamleaders.erase(it);
}

void Company::DeleteProgrammer(Employee* programmer_)
{
	Programmer* programmer;
	std::vector<Programmer*>::iterator it = std::find(programmers.begin(), programmers.end(), programmer_);
	if (it != programmers.end())
		programmer = *it;
	else
		throw "This programmer does not exist";

	programmer->RemoveSupervisor();

	std::vector<HR*>::iterator kt = std::find(for_hr.begin(), for_hr.end(), programmer);
	for_hr.erase(kt);
	std::vector<Accountant*>::iterator lt = std::find(for_acc.begin(), for_acc.end(), programmer);
	for_acc.erase(lt);

	delete programmer;
	programmers.erase(it);
}

void Company::AppointToManager(Employee* manager_, Employee* teamleader_)
{
	Manager* manager = GetManager(manager_);
	Teamleader* teamleader = GetTeamleader(teamleader_);
	if (teamleader->GetSupervisor() == manager_)
		throw "this teamleader is already his supervisor";
	manager->AppointSubordinate(teamleader);
}

void Company::AppointToTeamleader(Employee* teamleader_, Employee* programmer_)
{
	Teamleader* teamleader = GetTeamleader(teamleader_);
	Programmer* programmer = GetProgrammer(programmer_);
	if (programmer->GetSupervisor() == teamleader_)
		throw "this programmer is already his supervisor";
	teamleader->AppointSubordinate(programmer);
}

Manager* Company::GetManager(Employee* manager_) const
{
	Manager* manager;
	std::vector<Manager*>::const_iterator it;
	for (it = managers.begin(); it != managers.end(); it++) 
		if (*it == manager_)
			break;
	if (it != managers.end())
		manager = *it;
	else
		throw "This manager does not exist";
	return manager;
}

Teamleader* Company::GetTeamleader(Employee* teamleader_) const
{
	Teamleader* teamleader;
	std::vector<Teamleader*>::const_iterator it;
	for (it = teamleaders.begin(); it != teamleaders.end(); it++) 
		if (*it == teamleader_)
			break;
	if (it != teamleaders.end())
		teamleader = *it;
	else
		throw "This teamleader does not exist";
	return teamleader;
}

Programmer* Company::GetProgrammer(Employee* programmer_) const
{
	Programmer* programmer;
	std::vector<Programmer*>::const_iterator it;
	for (it = programmers.begin(); it != programmers.end(); it++)
		if (*it == programmer_)
			break;
	if (it != programmers.end())
		programmer = *it;
	else
		throw "This programmer does not exist";
	return programmer;
}

HR* Company::GetHrAccess(Employee* employee_) const
{
	HR* employee;
	std::vector<HR*>::const_iterator it;
	for (it = for_hr.begin(); it != for_hr.end(); it++)
		if (*it == employee_)
			break;
	if (it != for_hr.end())
		employee = *it;
	else
		throw "This employee does not exist";
	return employee;
}

Accountant* Company::GetAccountingAccess(Employee* employee_) const
{
	Accountant* employee;
	std::vector<Accountant*>::const_iterator it;
	for (it = for_acc.begin(); it != for_acc.end(); it++)
		if (*it == employee_)
			break;
	if (it != for_acc.end())
		employee = *it;
	else
		throw "This employee does not exist";
	return employee;
}

//std::vector<Teamleader*> Company::ListManagerSubordinates(ID manager_) const
//{
//	Manager* manager = GetManager(manager_);
//	return manager->ListSubordinates();
//}
//
//std::vector<Programmer*> Company::ListTeamleaderSubordinates(ID teamleader_) const
//{
//	Teamleader* teamleader = GetTeamleader(teamleader_);
//	return teamleader->ListSubordinates();
//}
//
//Manager* Company::GetTeamleaderSupervisor(ID teamleader_) const
//{
//	Teamleader* teamleader = GetTeamleader(teamleader_);
//	return teamleader->GetSupervisor();
//}
//Teamleader* Company::GetProgrammerSupervisor(ID programmer_) const
//{
//	Programmer* programmer = GetProgrammer(programmer_);
//	return programmer->GetSupervisor();
//}

//std::vector<Manager*> Company::ListManagers() const
//{
//	return managers;
//}
//
//std::vector<Teamleader*> Company::ListTeamleaders() const
//{
//	return teamleaders;
//}
//
//std::vector<Programmer*> Company::ListProgrammers() const
//{
//	return programmers;
//}