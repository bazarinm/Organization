#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "Teamleader.h"
#include "Employee.h"

class Programmer : public Employee
{
public:
	Programmer(std::string first_name, std::string last_name, std::string email, unsigned int salary);
private:
	Teamleader* supervisor;
};

#endif
