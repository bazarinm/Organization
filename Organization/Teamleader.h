#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <vector>
#include "Employee.h"
class Manager;
class Programmer;

class Teamleader : public Employee
{
public:
	Teamleader(Manager* supervisor, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);

	void AppointSubordinate(Programmer* new_subordinate);
	void AppointSupervisor(Manager* new_supervisor);
private:
	Manager* supervisor;
	std::vector<Programmer*> subordinates;
};

#endif

