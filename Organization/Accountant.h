#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

class Accountant
{
public:
	virtual int GetWage() = 0;
	virtual int GetExperience() = 0;
	virtual int CalculateSalary() = 0;
	virtual void SetWage(int new_wage) = 0;
	virtual void UpdateExperience(int new_experience) = 0;
};

#endif

