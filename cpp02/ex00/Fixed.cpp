#include "Fixed.hpp"

const int Fixed::fractional_bits = 0;

Fixed::Fixed()
	: fixed_point(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& obj)
	: fixed_point(obj.fixed_point)
{
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	(void) obj;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}
