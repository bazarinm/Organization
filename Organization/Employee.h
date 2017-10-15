#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Accountant.h"
#include "HR.h"

class Employee: public Accountant, public HR
{
public:
	Employee(std::string first_name, std::string last_name, std::string email, unsigned int salary);

	virtual int GetSalaryInfo() override;
	virtual std::string GetPersonalInfo() override;
private:
	std::string first_name;
	std::string last_name;
	std::string email;
	unsigned int salary;
	unsigned int experience;
};

#endif