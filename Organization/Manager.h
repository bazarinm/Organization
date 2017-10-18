#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "Employee.h"
class Teamleader;

class Manager : public Employee
{
public:
	Manager(const std::string& first_name, const std::string& last_name, const std::string& email, unsigned int wage);

	void AppointSubordinate(Teamleader* new_subordinate);
	void RemoveSubordinate(Teamleader* subordinate);
private:
	std::vector<Teamleader*> subordinates;
};

#endif

