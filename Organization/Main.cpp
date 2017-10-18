
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
	Company my_company;
	std::vector<HR*> for_hr;
	//for_hr.push_back(my_company.CreateManager("Mikhail", "Bazarin", "bazarinm@gmail.com", 4000));
	//for_hr.push_back(my_company.CreateTeamleader(0, "Kek", "lol", "nomail", 888));
	Manager ya("Mikhail", "Bazarin", "bazarinm@gmail.com", 4000);
	Teamleader on(&ya, "Mikhail", "Bazarin", "bazarinm@gmail.com", 4000);
	ya.RemoveSubordinate(&on);
	//std::cout << for_hr.at(0)->GetPersonalInfo() << std::endl;
	//std::cout << for_hr.at(1)->GetPersonalInfo() << std::endl;

	int n; std::cin >> n;
}