#include <string>
#include "Employee.h"


Employee::Employee(const std::string& first_name_, const std::string& last_name_, const std::string& email_, unsigned int wage)
	: first_name(first_name_), last_name(last_name_), email(email_), wage(wage), experience(0)
{}


int Employee::GetWage() const
{
	return wage;
}

int Employee::GetExperience() const
{
	return experience;
}

int Employee::CalculateSalary() const
{
	return wage*experience;
}

void Employee::SetWage(int new_wage)
{
	wage = new_wage;
}

void Employee::UpdateExperience(int new_experience)
{
	experience = new_experience;
}

std::string Employee::GetPersonalInfo() const
{
	return last_name + ' ' + first_name + ", " + email;
}

void Employee::SetFirstName(const std::string& new_first_name)
{
	first_name = new_first_name;
}
void Employee::SetLastName(const std::string& new_last_name)
{
	last_name = new_last_name;
}
void Employee::SetEmail(const std::string& new_email)
{
	email = new_email;
}


