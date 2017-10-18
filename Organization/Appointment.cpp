#include "Appointment.h"
#include <vector>

Appointment::Appointment()
{
	supervisor = nullptr;
}

Appointment::Appointment(Appointment* supervisor_)
{
	AppointSupervisor(supervisor_);
}

void Appointment::AppointSupervisor(Appointment* supervisor_)
{
	supervisor = supervisor_;
	supervisor->AppointSubordinate(this);
}
void Appointment::AppointSubordinate(Appointment* subordinate_)
{
	std::vector<Appointment*>::iterator it;
	for (it = subordinates.begin(); it != subordinates.end(); it++)
		if (*it == subordinate_)
			break;
	if (it == subordinates.end()) {
		subordinates.push_back(subordinate_);
		subordinate_->AppointSupervisor(this);
	}
	return;
}