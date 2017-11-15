#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>

#include "Manager.h"
#include "Teamleader.h"
#include "Programmer.h"
#include "HR.h"
#include "Accountant.h"

using ID = void*;

class Company
{
public:
	Company();
	Company(const std::string& name);
	~Company();

	Employee* CreateManager(const std::string& first_name,
		                    const std::string& last_name,
						    const std::string& email, unsigned int wage);
	Employee* CreateTeamleader(Employee* supervisor, const std::string& first_name,
							   const std::string& last_name, const std::string& email, unsigned int wage);
	Employee* CreateProgrammer(Employee* supervisor, const std::string& first_name,
							   const std::string& last_name, const std::string& email, unsigned int wage);

	void DeleteManager(Employee* manager);
	void DeleteTeamleader(Employee* teamleader);
	void DeleteProgrammer(Employee* programmer);

	void AppointToManager(Employee* manager, Employee* teamleader);
	void AppointToTeamleader(Employee* teamleader, Employee* programmer);

	Manager* GetManager(Employee* manager) const;
	Teamleader* GetTeamleader(Employee* teamleader) const;
	Programmer* GetProgrammer(Employee* programmer) const;

	HR* GetHrAccess(Employee* employee) const;
	Accountant* GetAccountingAccess(Employee* employee) const;

	//std::vector<Teamleader*> ListManagerSubordinates(ID manager) const;
	//std::vector<Programmer*> ListTeamleaderSubordinates(ID teamleader) const;

	//Manager* GetTeamleaderSupervisor(ID teamleader) const;
	//Teamleader* GetProgrammerSupervisor(ID programmer) const;

	//std::vector<Manager*> ListManagers() const;
	//std::vector<Teamleader*> ListTeamleaders() const;
	//std::vector<Programmer*> ListProgrammers() const;
private:
	std::string name;
	std::vector<Manager*> managers;
	std::vector<Teamleader*> teamleaders;
	std::vector<Programmer*> programmers;
	std::vector<HR*> for_hr;
	std::vector<Accountant*> for_acc;
};

#endif

