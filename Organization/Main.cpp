
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
	for_hr.push_back(&person);
	std::cout << for_hr.back()->GetPersonalInfo();
	std::cin.get();
}