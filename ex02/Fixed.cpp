#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed() : fix_point_value(0)
{
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return (fix_point_value);
}

void Fixed::setRawBits( int const raw )
{
	fix_point_value = raw;
}

Fixed::Fixed(const Fixed& object)
{
    fix_point_value = object.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& object)
{
	if (this != &object)
	{
		fix_point_value = object.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int number)
{
    fix_point_value = number << fractional_bits;
}

Fixed::Fixed(const float number)
{
	this->fix_point_value = static_cast<int>(std::roundf(number * (1 << fractional_bits)));
}

int Fixed::toInt(void) const
{
    return (fix_point_value >> fractional_bits);
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->fix_point_value) / (1 << fractional_bits);
}

std::ostream &operator<<(std::ostream &output_stream, const Fixed &obj)
{
	output_stream << obj.toFloat();
    return output_stream;
}


bool Fixed::operator>(const Fixed &other) const
{
	if (this->fix_point_value > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fix_point_value < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fix_point_value <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fix_point_value >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fix_point_value == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fix_point_value != other.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.fix_point_value = (this->fix_point_value + other.fix_point_value) >> fractional_bits;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.fix_point_value = (this->fix_point_value - other.fix_point_value) >> fractional_bits;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.fix_point_value = (this->fix_point_value * other.fix_point_value) >> fractional_bits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.fix_point_value = (this->fix_point_value / other.fix_point_value) >> fractional_bits;
	return result;
}

Fixed& Fixed::operator--()
{
	this->fix_point_value--;
	return (*this);
}

Fixed& Fixed::operator++()
{
	this->fix_point_value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fix_point_value--;
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fix_point_value++;
	return (tmp);
}

Fixed& Fixed::min(Fixed &value_1, Fixed &value_2)
{
	return (value_1 < value_2 ? value_1 : value_2);
}

const Fixed& Fixed::min(Fixed const &value_1, Fixed const &value_2)
{
	return (value_1 < value_2 ? value_1 : value_2);
}

Fixed& Fixed::max(Fixed &value_1, Fixed &value_2)
{
	return (value_1 > value_2 ? value_1 : value_2);
}

const Fixed& Fixed::max(Fixed const &value_1, Fixed const &value_2)
{
	return (value_1 > value_2 ? value_1 : value_2);
}
