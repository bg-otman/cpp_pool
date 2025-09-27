#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
	: fixed_point(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called\n";
	fixed_point = nb << fractional_bits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called\n";
	fixed_point = roundf(nb * (1 << fractional_bits));
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		fixed_point = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)fixed_point / (1 << fractional_bits);
}

int Fixed::toInt( void ) const
{
	return fixed_point >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
