#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <string>
#include <vector>
#include "Employee.h"

class Teamleader;

class Programmer : public Employee
{
public:
	Programmer(Teamleader* supervisor, const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);

	void AppointSupervisor(Teamleader* new_supervisor);
	void RemoveSupervisor();
	Teamleader* GetSupervisor() const;
private:
	Teamleader* supervisor;
};

#endif
