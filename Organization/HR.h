#ifndef HR_H
#define HR_H

#include <string>

class HR
{
public:
	virtual std::string GetPersonalInfo() const = 0;
	virtual void SetFirstName(const std::string& new_first_name) = 0;
	virtual void SetLastName(const std::string& new_last_name) = 0;
	virtual void SetEmail(const std::string& new_email) = 0;
};

#endif

