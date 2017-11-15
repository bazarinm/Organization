#include <vector>
#include <string>
#include <iostream>

#include "Company.h"

void main()
{
	Company my_company("Nova Development");

	Employee* mymanager = my_company.CreateManager("Mikhail", "Bazarin", "bazarinm@gmail.com", 65000);
	Employee* myteamleader = my_company.CreateTeamleader(mymanager, "Andrey", "Yaushev", "nomail@nomail.no", 45000);
	Employee* myteamleader2 = my_company.CreateTeamleader(mymanager, "Vova", "Smirnov", "email@email.em", 45000);
	Employee* myprogrammer = my_company.CreateProgrammer(myteamleader, "Name", "Surname", "kek111@yandex.com", 30000);
	my_company.AppointToTeamleader(myteamleader2, myprogrammer);
	my_company.AppointToTeamleader(myteamleader, myprogrammer);
	my_company.AppointToTeamleader(myteamleader2, myprogrammer);
	//my_company.AppointToTeamleader(myteamleader2, myprogrammer);
	//Employee* another = my_company.CreateProgrammer(myteamleader2, "Name", "Surname", "kek111@yandex.com", 2300);

	std::cout << my_company.GetHrAccess(mymanager)->GetPersonalInfo() << std::endl;
	my_company.GetAccountingAccess(myteamleader)->UpdateExperience(5);
	std::cout << my_company.GetAccountingAccess(myteamleader)->CalculateSalary() << std::endl;
	my_company.GetHrAccess(myprogrammer)->SetFirstName("Kolya");
	my_company.GetHrAccess(myprogrammer)->SetLastName("Ivanov");
	std::cout << my_company.GetHrAccess(myprogrammer)->GetPersonalInfo() << std::endl;
	std::cout << myprogrammer->GetPersonalInfo() << std::endl;

	int n; std::cin >> n;
}