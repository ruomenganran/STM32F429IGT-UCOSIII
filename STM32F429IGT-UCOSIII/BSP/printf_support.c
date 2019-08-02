#include "printf_support.h"

#pragma import(__use_no_semihosting)                 
struct __FILE 
{ 
	int handle; 
};
FILE __stdout;       
void _sys_exit(int x) 
{ 
	x = x; 
}
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);
	USART1->DR = (uint8_t) ch;      
	return ch;
}

int _write(int fd, char *ptr, int len)
{
    if (fd > 2){
        return -1;
    }
    HAL_UART_Transmit(&huart1, ptr, len, 500);
    return len;
}

