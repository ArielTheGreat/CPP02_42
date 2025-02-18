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
	std::cout << "getRawBits member function called" << std::endl;
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
