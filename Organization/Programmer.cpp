#include <vector>
#include <string>
#include "Programmer.h"
#include "Teamleader.h"

Programmer::Programmer(Teamleader* supervisor_, const std::string& first_name_, const std::string& last_name_, const std::string& email_, unsigned int wage_)
	: Employee(first_name_, last_name_, email_, wage_) {
	AppointSupervisor(supervisor_);
}

void Programmer::AppointSupervisor(Teamleader* new_supervisor)
{
	if (supervisor != new_supervisor) {
		RemoveSupervisor();
		supervisor = new_supervisor;
		new_supervisor->AppointSubordinate(this);
	}
}

void Programmer::RemoveSupervisor()
{
	if (supervisor != nullptr) {
		Teamleader* temp_supervisor = supervisor;
		supervisor = nullptr;
		temp_supervisor->RemoveSubordinate(this);
	}
}

Teamleader* Programmer::GetSupervisor() const
{
	return supervisor;
}
