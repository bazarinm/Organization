#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Programmer.h"

class Teamleader : public Employee
{
public:
	Teamleader(std::string first_name, std::string last_name, std::string email, unsigned int salary);
private:
	Manager* supervisor;
	std::vector<Programmer*> subordinates;
};

#endif

