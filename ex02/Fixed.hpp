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
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed& operator--();
		Fixed& operator++();
		Fixed operator--(int);
		Fixed operator++(int);
		static Fixed& min(Fixed &value_1, Fixed &value_2);
		static const Fixed& min(Fixed const &value_1, Fixed const &value_2);
		static Fixed& max(Fixed &value_1, Fixed &value_2);
		static const Fixed& max(Fixed const &value_1, Fixed const &value_2);
    friend std::ostream &operator<<(std::ostream& output_stream, const Fixed &obj);
};

#endif