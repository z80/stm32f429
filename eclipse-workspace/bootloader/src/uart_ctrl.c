
#include "uart_ctrl.h"

#include "stm32f4xx_hal.h"
#include "stm32f429i_discovery.h"

UART_HandleTypeDef UartHandle;

int __io_putchar(int ch)
{
	uartPutch( (uint8_t)ch );
	return ch;
}

int __io_getchar(void)
{
	return 0;
}

void uartInit( void )
{
	// Enable clock.
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.Pin       = GPIO_PIN_10;
	GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull      = GPIO_NOPULL;
	GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init( GPIOA, &GPIO_InitStruct);

	/* UART RX GPIO pin configuration  */
	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	UartHandle.Instance        = USART1;

	UartHandle.Init.BaudRate     = 9600;
	UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits     = UART_STOPBITS_1;
	UartHandle.Init.Parity       = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode         = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	uint8_t res = (HAL_UART_DeInit(&UartHandle) != HAL_OK) ? 0 : 1;
	res = (HAL_UART_Init(&UartHandle) != HAL_OK) ? 0 : 1;
}

void uartPutch( uint8_t ch )
{
	uint8_t res = (HAL_UART_Transmit( &UartHandle, (uint8_t*)&ch, 1, 5000 )!= HAL_OK) ? 0 : 1;
}



