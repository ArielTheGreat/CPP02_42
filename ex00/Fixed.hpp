#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int fixed_ptr_value;
		static const int number_fractional_bits;
	public:
		Fixed();
		Fixed& operator=(const Fixed& C);
		Fixed(const Fixed& copy);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif