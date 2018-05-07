#include "hal/soc/soc.h"
#include "board.h"
#include "uart_port.h"
#include <project.h>

#include <stdio.h>
#include <k_api.h>
#include <aos\kernel.h>

uart_dev_t uart_0;

static uart_dev_t console_uart={
  .port=STDIO_UART,
};

int default_UART_Init(void)
{
    uart_0.port                = STDIO_UART;
    uart_0.config.baud_rate    = STDIO_UART_BAUDRATE;
    uart_0.config.data_width   = DATA_WIDTH_8BIT;
    uart_0.config.parity       = NO_PARITY;
    uart_0.config.stop_bits    = STOP_BITS_1;
    uart_0.config.flow_control = FLOW_CONTROL_DISABLED;

    return hal_uart_init(&uart_0);
}

#if defined (__CC_ARM) && defined(__MICROLIB)
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#elif defined(__ICCARM__)
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#else
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#define GETCHAR_PROTOTYPE int __io_getchar(void)

PUTCHAR_PROTOTYPE;
GETCHAR_PROTOTYPE;
    
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
    /* Add an explicit reference to the floating point printf library to allow
    the usage of floating point conversion specifier. */
    __asm (".global _printf_float");
    /***************************************************************************
    * Function Name: _write
    ***************************************************************************/
    __attribute__((weak)) int _write (int fd, const char *ptr, int len)
    {
        int nChars = 0;
        (void)fd;
        if (ptr != NULL)
        {
            for (/* Empty */; nChars < len; ++nChars)
            {
                if(*ptr == '\n')
                {
                    __io_putchar('\r');
                }
                __io_putchar((uint32_t)*ptr);
                ++ptr;
            }
        }
        return (nChars);
    }
    
    __asm (".global _scanf_float");
    __attribute__((weak)) int _read (int fd, char *ptr, int len)
    {
        int nChars = 0;
        (void)fd;
        if (ptr != NULL)
        {
            for(/* Empty */;nChars < len;++ptr)
            {
                *ptr = (char)__io_getchar();
                ++nChars;
                if(*ptr == '\n')
                {
                    break;
                }
            }
        }
        return (nChars);
    }    
#endif /* defined (__CC_ARM) && defined(__MICROLIB) */

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  if (ch == '\n') {
    hal_uart_send(&console_uart, (void *)"\r", 1, 30000);
  }
  hal_uart_send(&console_uart, &ch, 1, 30000);
  return ch;
}

/**
  * @brief  Retargets the C library scanf function to the USART.
  * @param  None
  * @retval None
  */
GETCHAR_PROTOTYPE
{
  /* Place your implementation of fgetc here */
  /* e.g. readwrite a character to the USART2 and Loop until the end of transmission */
  uint8_t ch = 0;
  uint32_t recv_size;
  hal_uart_recv(&console_uart, &ch, 1, 30000);
  return ch;
}



int32_t hal_uart_init(uart_dev_t *uart)
{
    switch(uart->port)
    {
        case UART3:
        SCB3_Start();
        break;
        
        default:
        break;
    }
    return 0;
}

int32_t hal_uart_send(uart_dev_t *uart, const void *data, uint32_t size, uint32_t timeout)
{
    uint32 *pdata = (uint32 *)data;
    uint32 i = 0;

    (void)timeout;
    
    switch(uart->port)
    {
        case UART3:
        for(i = 0; i < size; i++)
        {
            SCB3_UartPutChar(*pdata);
            break;
        }
        
        default:
        break;
    }
    return 0;
}

int32_t hal_uart_recv(uart_dev_t *uart, void *data, uint32_t expect_size, uint32_t timeout)
{
    uint32 *pdata = (uint32 *)data;
    uint32 i = 0;
    
    (void)timeout;
    
    switch(uart->port)
    {
        case UART3:
        for(i = 0; i < expect_size; i++)
        {
            *pdata = SCB3_UartGetChar();
        }
        break;
        
        default:
        break;
    }

    return 0;
}

int32_t hal_uart_recv_II(uart_dev_t *uart, void *data, uint32_t expect_size,
                      uint32_t *recv_size, uint32_t timeout)
{
    return 0;
}

int32_t hal_uart_finalize(uart_dev_t *uart)
{
    (void)uart;
    
    return 0;
}
