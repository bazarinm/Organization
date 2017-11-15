#include <string>
#include <vector>
#include "Manager.h"
#include "Teamleader.h"

Manager::Manager(const std::string& first_name_, const std::string& last_name_, const std::string& email_, unsigned int wage_)
	: Employee(first_name_, last_name_, email_, wage_)
{}

void Manager::AppointSubordinate(Teamleader* new_subordinate)
{
	std::vector<Teamleader*>::iterator it;
	for (it = subordinates.begin(); it != subordinates.end(); it++)
		if (*it == new_subordinate)
			break;
	if (it == subordinates.end()) {
		subordinates.push_back(new_subordinate);
		new_subordinate->AppointSupervisor(this);
	}
}

void Manager::RemoveSubordinate(Teamleader* subordinate)
{
	std::vector<Teamleader*>::iterator it;
	for (it = subordinates.begin(); it != subordinates.end(); it++)
		if (*it == subordinate) {
			subordinates.erase(it);
			subordinate->RemoveSupervisor();
			break;
		}
}

std::vector<Teamleader*> Manager::ListSubordinates() const
{
	return subordinates;
}