#pragma once

#include <vector>

class Appointment
{
public:
	Appointment();
	Appointment(Appointment*);

	void AppointSupervisor(Appointment*);
	void AppointSubordinate(Appointment*);
protected:
	Appointment* supervisor;
	std::vector<Appointment*> subordinates;
};

