#include "Fixed.hpp"

Fixed::Fixed()
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
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_ptr_value = raw;
}

Fixed& Fixed::operator=(const Fixed& C)
{
    this->fixed_ptr_value = C.getRawBits();
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
}