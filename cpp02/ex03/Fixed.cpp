#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _value(value << _fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value): _value(roundf(value * (1 << _fractionalBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_value = to_copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// 6 comparison operators
bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result._value = (static_cast<long>(this->_value) * other._value) >> this->_fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result._value = (static_cast<long>(this->_value) << this->_fractionalBits) / other._value;
	return result;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
		
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_value >> this->_fractionalBits;

}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
