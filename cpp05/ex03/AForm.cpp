#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unnamed"), _isSigned(false),
	  _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}

	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor was called for Form " << _name << std::endl;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}


const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form name: " << form.getName()
	   << ", signed: " << form.getIsSigned()
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
            throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
            throw GradeTooLowException();
	this->executeAction();
}