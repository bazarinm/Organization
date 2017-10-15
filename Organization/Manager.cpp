#include "Manager.h"
#include "Teamleader.h"

Manager::Manager(std::string first_name_, std::string last_name_, std::string email_, unsigned int salary_)
	: Employee(first_name_, last_name_, email_, salary_)
{}

std::vector<Teamleader*> Manager::ListSubordinates()
{
	return subordinates;
}