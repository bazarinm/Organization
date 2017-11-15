#include <vector>
#include <string>
#include "Teamleader.h"
#include "Programmer.h"
#include "Manager.h"

Teamleader::Teamleader(Manager* supevisor_, const std::string& first_name_, const std::string& last_name_, const std::string& email_, unsigned int wage_)
	: Employee(first_name_, last_name_, email_, wage_) {
	supervisor = nullptr;
	AppointSupervisor(supevisor_);
}

void Teamleader::AppointSubordinate(Programmer* new_subordinate)
{
	std::vector<Programmer*>::iterator it;
	for (it = subordinates.begin(); it != subordinates.end(); it++)
		if (*it == new_subordinate)
			break;
	if (it == subordinates.end()) {
		subordinates.push_back(new_subordinate);
		new_subordinate->AppointSupervisor(this);
	}
}

void Teamleader::AppointSupervisor(Manager* new_supervisor)
{
	if (supervisor != new_supervisor) {
		RemoveSupervisor();
		supervisor = new_supervisor;
		new_supervisor->AppointSubordinate(this);
	}
}

void Teamleader::RemoveSubordinate(Programmer* subordinate)
{
	std::vector<Programmer*>::iterator it;
	for (it = subordinates.begin(); it != subordinates.end(); it++)
		if (*it == subordinate) {
			subordinates.erase(it);
			subordinate->RemoveSupervisor();
			break;
		}
}

void Teamleader::RemoveSupervisor()
{
	if (supervisor != nullptr) {
		Manager* temp_supervisor = supervisor;
		supervisor = nullptr;
		temp_supervisor->RemoveSubordinate(this);
	}
}

std::vector<Programmer*> Teamleader::ListSubordinates() const
{
	return subordinates;
}

Manager* Teamleader::GetSupervisor() const
{
	return supervisor;
}

