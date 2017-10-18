
#include <vector>
#include <string>
#include <iostream>
#include "Teamleader.h"
#include "Manager.h"
#include "Programmer.h"
#include "Accountant.h"
#include "HR.h"

void main()
{
	std::vector<HR*> for_hr;
	Manager person("Mikhail", "Bazarin", "bazarinm@gmail.com", 4000);
	Manager person2("Mikhail2", "Bazarin2", "bazarinm@gmail.com2", 40002);
	Teamleader loh("Kek", "lol", "nomail", 888);
	loh.AppointSupervisor(&person);
	person.AppointSubordinate(&loh);
	std::cin.get();
}