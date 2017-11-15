#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include "Manager.h"
#include "Teamleader.h"
#include "Programmer.h"

//using ID = void*;

class Company
{
public:
	Company();
	Company(const std::string& name);
	~Company();

	Manager* CreateManager(const std::string& first_name,
		                   const std::string& last_name,
						   const std::string& email, unsigned int wage);
	Teamleader* CreateTeamleader(int supervisor, const std::string& first_name, 
								 const std::string& last_name, const std::string& email, unsigned int wage);
	Programmer* CreateProgrammer(int supervisor, const std::string& first_name, 
								 const std::string& last_name, const std::string& email, unsigned int wage);

	void DeleteManager(int manager);
	void DeleteTeamleader(int teamleader);
	void DeleteProgrammer(int programmer);

	void AppointToManager(int manager, int teamleader);
	void AppointToTeamleader(int teamleader, int programmer);

	std::vector<Manager*> ListManagers() const;
	std::vector<Teamleader*> ListTeamleaders() const;
	std::vector<Programmer*> ListProgrammers() const;

	Manager* GetManager(int manager) const;
	Teamleader* GetTeamleader(int teamleader) const;
	Programmer* GetProgrammer(int programmer) const;

	std::vector<Teamleader*> ListManagerSubordinates(int manager) const ;
	std::vector<Programmer*> ListTeamleaderSubordinates(int teamleader) const;

	Manager* GetTeamleaderSupervisor(int teamleader) const;
	Teamleader* GetProgrammerSupervisor(int programmer) const;

	std::vector<HR*> GetHrAccess() const ;
	std::vector<Accountant*> GetAccountingAcess() const;
private:
	std::string name;
	std::vector<Manager*> managers;
	std::vector<Teamleader*> teamleaders;
	std::vector<Programmer*> programmers;
	std::vector<HR*> for_hr;
	std::vector<Accountant*> for_acc;
};

#endif

