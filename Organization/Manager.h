#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "Employee.h"
#include "Teamleader.h"

class Manager : public Employee
{
public:
	Manager(std::string first_name, std::string last_name, std::string email, unsigned int salary);

	std::vector<Teamleader*> ListSubordinates();
private:
	std::vector<Teamleader*> subordinates;
};

#endif

