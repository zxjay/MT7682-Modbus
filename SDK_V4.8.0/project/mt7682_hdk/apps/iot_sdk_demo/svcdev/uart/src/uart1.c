/****************************************************************
	Copyright(C), 1999-2004 Raisecom, Inc.
	filename: uart1.c，串口1驱动函数文件
	Author	: qiaoqiangguo
	version	: 1.0
	date	: 2008/6/21
	Others	:
        THIS DOCUMENT IS GENERATED BY TORNADO TOOLS refgen.exe
        EXAMPLE:
        ->torVars.bat
        ->refgen -mg -out doc uart1.c
        ->cd doc
        ->htmllink
*****************************************************************/
#include "pocket_hub_config.h"

#ifdef INCLUDE_UART1 

/*#include "string.h"
#include "macro_common.h"
#include "stm32f10x.h"
#include "misc.h"
#include "uart.h"
#include "uart1.h"
#include "ibc.h"
*/

#include "string.h"

#include "type_common.h"
#include "uart_common.h"
#include "uart1.h"
#include "ibc.h"


/*uart1的接收缓存*/
OTP_UINT8	g_uart1_rcv_buf[UART1_RCV_BUFLEN];
/*uart1的发送缓存*/
OTP_UINT8	g_uart1_send_buf[UART1_SEND_BUFLEN];

uart_info 	g_uart1_info;

#ifdef	INCLUDE_OPPOSITE_COMM
comm_source_info g_uart1_comm_src_info;
#endif


/******************************************************************************************
*uart1_rs232_init		--串口初始化函数
*--
*Input:
*	prt		--协议类型
*	rcv 		--信息接收函数
*	opttypercv --光头类型烧写信息接收函数
*Output:
*	无
*Return:
*	OK/ERROR	表示执行成功与否
*
*/
STATUS uart1_rs232_init(uart_protocol_type prt, 
							uart_rcv_func rcv,
							uart_rcv_func opttypercv)
{

	/*清数据结构*/
	memset(&g_uart1_info, 0, sizeof(g_uart1_info));

	/*记录报文处理协议*/
	g_uart1_info.prt = prt;
	/*记录接收报文处理函数*/
	g_uart1_info.rinfo.rproc.rcv = rcv;
	
#ifdef INCLUDE_OPTTYPE
	g_uart1_info.rinfo.opttype.rcv = opttypercv;
#else
	NO_USE(opttypercv);
#endif

#ifdef INCLUDE_OPPOSITE_COMM
	/*响应消息的发送函数*/
	g_uart1_comm_src_info.send = (xxx_msg_send)uart1_msg_send;
	g_uart1_comm_src_info.comm_obj = comm_to_uart1;
	g_uart1_info.arg = &g_uart1_comm_src_info;
#else
	g_uart1_info.arg = (OTP_VOID *)uart1_msg_send;
#endif

	/*接收和发送指针执行相应的缓冲区*/
	g_uart1_info.rinfo.rproc.pdata = g_uart1_rcv_buf;
	g_uart1_info.rinfo.rproc.datalen = UART1_RCV_BUFLEN;
	g_uart1_info.sinfo.pdata = g_uart1_send_buf;
	g_uart1_info.sinfo.datalen = UART1_SEND_BUFLEN;

	return OK;
}

/*******************************************************************************
*uart1_rcv_process  接收报文处理，按照相应的协议，对接收缓冲区的报文进行处理，并调用
*		注册的rcv处理函数；
*Input:
*	None
*Output:
*	None	
*Return:
*	OK/ERROR，表示执行成功和失败
*/
STATUS uart1_rcv_process(void)
{
	return uart_rcv_process(g_uart1_info.arg, g_uart1_info.prt, &g_uart1_info.rinfo);
}


/*******************************************************************************
*uart1_msg_send 发送报文处理
*Input:
*	buf		--需要发送的数据指针
*	buflen	--发送的数据长度
*Output:
*	None	
*Return:
*	OK/ERROR，表示执行成功和失败
*/
STATUS uart1_msg_send(const OTP_UINT8 *buf, OTP_UINT32 buflen)
{
	/*参数检查*/
	if(buf == NULL)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	if(buflen == 0)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	
	if(uart_msg_send(UART1_ID, &g_uart1_info, buf, buflen) != OK)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	
	return OK;
}

#endif


