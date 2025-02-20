#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed() : fix_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fix_point_value);
}

void Fixed::setRawBits( int const raw )
{
	fix_point_value = raw;
}

Fixed::Fixed(const Fixed& object)
{
	std::cout << "Copy constructor called" << std::endl;
    fix_point_value = object.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& object)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
	{
		fix_point_value = object.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    fix_point_value = number << fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
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