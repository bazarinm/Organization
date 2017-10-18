
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
	Teamleader loh(&person2, "Kek", "lol", "nomail", 888);
	std::cout << &person2 << std::endl;
	std::cout << loh.GetSupervisor() << std::endl;
	person.AppointSubordinate(&loh);
	std::cout << &person << std::endl;
	std::cout << loh.GetSupervisor() << std::endl;
	for_hr.push_back(&person);
	std::cout << for_hr.back()->GetPersonalInfo();
	std::cin.get();
}