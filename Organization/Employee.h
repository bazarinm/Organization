#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Accountant.h"
#include "HR.h"

class Employee: public Accountant, public HR
{
public:
	Employee(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);

	virtual int GetWage() override;
	virtual int GetExperience() override;
	virtual int CalculateSalary() override;
	virtual void SetWage(int new_wage) override;
	virtual void UpdateExperience(int new_experience) override;

	virtual std::string GetPersonalInfo() override;
	virtual void SetFirstName(std::string new_first_name) override;
	virtual void SetLastName(std::string new_last_name) override;
	virtual void SetEmail(std::string new_email) override;
private:
	std::string first_name;
	std::string last_name;
	std::string email;
	unsigned int wage;
	unsigned int experience;
};

#endif