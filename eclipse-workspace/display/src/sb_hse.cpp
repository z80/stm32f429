
#include "sb_hse.hpp"
#include "sb_mcu.hpp"
#include "stm32f429xx.h"

namespace SB
{

Hse::Hse()
{
}

Hse::~Hse()
{
}

bool Hse::setEnabled( bool en )
{
	if ( en )
	{
		RCC->CR |= RCC_CR_HSEON;
		while ( !(RCC->CR & RCC_CR_HSERDY) )
			;
	}
	else
	{
		RCC->CR &= ~RCC_CR_HSEON;
		while ( (RCC->CR & RCC_CR_HSERDY) )
			;
	}
	return true;
}

bool Hse::enabled()
{
	bool en = ( (RCC->CR & RCC_CR_HSERDY) != 0 );
	return en;
}

int Hse::type() const
{
	return static_cast<int>( SB::HSE );
}

}

