#ifndef HR_H
#define HR_H

#include <string>

class HR
{
public:
	virtual std::string GetPersonalInfo() = 0;
	virtual void SetFirstName(std::string new_first_name) = 0;
	virtual void SetLastName(std::string new_last_name) = 0;
	virtual void SetEmail(std::string new_email) = 0;
};

#endif

