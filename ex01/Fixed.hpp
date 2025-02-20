#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <ostream>
#include <cmath>

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
        Fixed(const int number);
        Fixed(const float number);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
    friend std::ostream &operator<<(std::ostream& output_stream, const Fixed &obj);
};

#endif