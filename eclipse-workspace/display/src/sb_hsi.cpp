
#include "sb_hsi.hpp"
#include "sb_mcu.hpp"
#include "stm32f429xx.h"

namespace SB
{

Hsi::Hsi()
{
}

Hsi::~Hsi()
{
}

bool Hsi::setEnabled( bool en )
{
	if ( en )
	{
		RCC->CR |= RCC_CR_HSION;
		while ( !(RCC->CR & RCC_CR_HSIRDY) )
			;
	}
	else
	{
		RCC->CR &= ~RCC_CR_HSION;
		while ( (RCC->CR & RCC_CR_HSIRDY) )
			;
	}
	return true;
}

bool Hsi::enabled()
{
	bool en = ( (RCC->CR & RCC_CR_HSIRDY) != 0 );
	return en;
}

int Hsi::type() const
{
	return static_cast<int>( SB::HSI );
}

}
