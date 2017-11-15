#include <vector>
#include <string>
#include <iostream>
//#include "Teamleader.h"
//#include "Manager.h"
//#include "Programmer.h"
#include "Accountant.h"
#include "HR.h"
#include "Company.h"

void main()
{
	Company my_company("Nova Development");
	std::vector<HR*> for_hr;
	std::vector<Accountant*> for_acc;

	my_company.CreateManager("Mikhail", "Bazarin", "bazarinm@gmail.com", 4000);
	my_company.CreateTeamleader(0, "Andrey", "Yaushev", "nomail@nomail.no", 3100);
	my_company.CreateProgrammer(0, "Name", "Surname", "kek111@yandex.com", 2300);
	//my_company.DeleteTeamleader(0);
	my_company.ListManagerSubordinates(0);

	for_hr = my_company.GetHrAccess();
	for_acc = my_company.GetAccountingAcess();
	std::cout << for_hr.at(0)->GetPersonalInfo() << std::endl;
	std::cout << for_hr.at(1)->GetPersonalInfo() << std::endl;
	for_acc.at(0)->UpdateExperience(5);
	int my_salary = for_acc.at(0)->CalculateSalary();
	for_acc.at(1)->SetWage(2600);
	for_hr.at(1)->SetFirstName("Kolya");
	for_hr.at(1)->SetLastName("Ivanov");
	std::cout << for_hr.at(1)->GetPersonalInfo() << std::endl;
	std::cout << my_company.GetProgrammer(0)->GetPersonalInfo() << std::endl;

	int n; std::cin >> n;
}