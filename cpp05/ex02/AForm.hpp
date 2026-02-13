#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string	&getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			const char *what() const throw();
		};

		void beSigned(const Bureaucrat &b);

		void execute(Bureaucrat const &executor) const;
		virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif