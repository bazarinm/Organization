#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "Employee.h"

class Teamleader;

class Programmer : public Employee
{
public:
	Programmer(std::string first_name, std::string last_name, std::string email, unsigned int salary);

private:
};

#endif
