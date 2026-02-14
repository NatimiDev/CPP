#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		AForm* makeShrubberyForm(const std::string &target);
		AForm* makeRobotomyForm(const std::string &target);
		AForm* makePresidentialForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &formTarget);
};

#endif