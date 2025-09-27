#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_point;
		static const int fractional_bits;
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		Fixed	operator+(const Fixed& obj)		const;
		Fixed	operator-(const Fixed& obj)		const;
		Fixed	operator*(const Fixed& obj)		const;
		Fixed	operator/(const Fixed& obj)		const;
		Fixed	operator++( void );
		Fixed	operator++( int );
		Fixed	operator--( void );
		Fixed	operator--( int );
		bool	operator<(const Fixed& obj)		const;
		bool	operator>(const Fixed& obj)		const;
		bool	operator>=(const Fixed& obj)	const;
		bool	operator<=(const Fixed& obj)	const;
		bool	operator==(const Fixed& obj)	const;
		bool	operator!=(const Fixed& obj)	const;
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed& min(Fixed& obj1, Fixed& obj2);
		static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static Fixed& max(Fixed& obj1, Fixed& obj2);
		static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
