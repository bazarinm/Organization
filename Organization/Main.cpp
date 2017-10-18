
#include <vector>
#include <string>
#include <iostream>
#include "Teamleader.h"
#include "Manager.h"
#include "Programmer.h"
#include "Accountant.h"
#include "HR.h"
#include "Company.h"

void main()
{
	Company my_company("Nova Development");
	std::vector<HR*> for_hr;
	std::vector<Accountant*> for_acc;
	
	//Manager my_manager = *(my_company.CreateManager("Mikhail", "Bazarin", "bazarinm@gmail.com", 4000));
	//Teamleader my_teamleader = *(my_company.CreateTeamleader(0, "Andrey", "Yaushev", "nomail@nomail.no", 3100));
	//Programmer my_programmer = *(my_company.CreateProgrammer(0, "Name", "Surname", "kek111@yandex.com", 2300));

	for_hr.push_back(my_company.CreateManager("Mikhail", "Bazarin", "bazarinm@gmail.com", 4000));
	for_acc.push_back(my_company.CreateTeamleader(0, "Andrey", "Yaushev", "nomail@nomail.no", 3100));
	for_hr.push_back(my_company.CreateProgrammer(0, "Name", "Surname", "kek111@yandex.com", 2300));

	std::cout << for_hr.at(0)->GetPersonalInfo() << std::endl;
	for_hr.at(2)->SetFirstName("Kolya");
	for_hr.at(2)->SetLastName("Ivanov");

	std::cout << for_hr.at(2)->GetPersonalInfo() << std::endl;
	std::cout << my_company.GetProgrammer(0)->GetPersonalInfo() << std::endl;

	int n; std::cin >> n;
}