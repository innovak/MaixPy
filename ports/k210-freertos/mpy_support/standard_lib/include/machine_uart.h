#ifndef __MACHINE_UART_H__
#define __MACHINE_UART_H__

#include "mpconfigboard.h"
#include "stdint.h"
#include "py/obj.h"
#include "uart.h"
typedef struct _machine_uart_obj_t {
    mp_obj_base_t base;
	uint8_t uart_num;
    uint32_t baudrate;
    uint8_t bitwidth;
    uart_parity_t parity;
    uart_stopbit_t stop;
	bool active : 1;
	bool attached_to_repl: 1;
	bool rx_int_flag: 1;
	uint16_t read_buf_len;             
    uint16_t read_buf_head;    
    uint16_t read_buf_tail;
	uint16_t timeout;
	uint16_t timeout_char;
	uint16_t data_len;
    uint8_t *read_buf;
} machine_uart_obj_t;

void uart_attach_to_repl(machine_uart_obj_t *self, bool attached);

#endif

