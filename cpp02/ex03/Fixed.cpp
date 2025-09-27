#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
	: fixed_point(0)
{
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed::Fixed(const int nb)
{
	fixed_point = nb << fractional_bits;
}

Fixed::Fixed(const float nb)
{
	fixed_point = roundf(nb * (1 << fractional_bits));
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this != &obj) 
		fixed_point = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
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

/* comparison operators */

bool Fixed::operator<(const Fixed& obj) const
{
	return (fixed_point < obj.getRawBits());
}

bool Fixed::operator>(const Fixed& obj) const
{
	return (fixed_point > obj.getRawBits());
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return (fixed_point >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return (fixed_point <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed& obj) const
{
	return (obj.getRawBits() == fixed_point);
}

bool Fixed::operator!=(const Fixed& obj) const
{
	return (obj.getRawBits() != fixed_point);
}

/* arithmetic operators */

Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed result;
	result.setRawBits(fixed_point + obj.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed result;
	result.setRawBits(fixed_point - obj.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	Fixed result;
	result.setRawBits((fixed_point * obj.getRawBits()) >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& obj) const
{
	Fixed result;
	result.setRawBits((fixed_point << fractional_bits) / obj.fixed_point);
	return result;
}

/*  increment/decrement operators */

Fixed Fixed::operator++( void ) // pre-increment
{
	setRawBits(fixed_point + 1);
	return *this;
}

Fixed Fixed::operator++( int ) // post-increment
{
	Fixed temp(*this);
	setRawBits(fixed_point + 1);
	return temp;
}

Fixed Fixed::operator--( void ) // pre-decrement
{
	setRawBits(fixed_point - 1);
	return *this;
}

Fixed Fixed::operator--( int ) // post-decrement
{
	Fixed temp(*this);
	setRawBits(fixed_point - 1);
	return temp;
}

/////

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}
