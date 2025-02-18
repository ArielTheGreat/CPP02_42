#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					fix_point_value;
		static const int	fractional_bits;
	public:
		Fixed();
		Fixed(const Fixed& object);
		Fixed &operator=(const Fixed& object);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif