#include <string>
#include "Employee.h"


Employee::Employee(std::string first_name_, std::string last_name_, std::string email_, unsigned int salary_)
	: first_name(first_name_), last_name(last_name_), email(email_), salary(salary_)
{
}

std::string Employee::GetPersonalInfo()
{
	return last_name;
}

int Employee::GetSalaryInfo()
{
	return salary;
}

