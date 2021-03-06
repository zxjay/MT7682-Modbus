

/****************************************************************
	Copyright(C), 1999-2004 Raisecom, Inc.
	filename: ibc_opttype.c 烧写e2prom中光头类型的协议
	Author	: qiaoqiangguo
	version	: 1.0
	date	: 2008/6/21
	Others	:
        THIS DOCUMENT IS GENERATED BY TORNADO TOOLS refgen.exe
        EXAMPLE:
        ->torVars.bat
        ->refgen -mg -out doc uart.c
        ->cd doc
        ->htmllink
*****************************************************************/

#include "otpconfig.h"

#ifdef INCLUDE_OPTTYPE

#include "macro_common.h"
#include "trace.h"
#include "uart.h"
#include "ibc_opttype.h"
#include "ibc.h"

/*lint -save -e826*/
/*获取槽位号的函数*/
extern OTP_UINT8 svc_get_local_slot(const OTP_VOID *arg);
ibc_opttype_rcv_func	g_ibc_opttype_rcv_func;

/*******************************************************************************
*ibc_opttype_init  存储光头类型模块,初始化函数
*Input:
*Output:
*	None	
*Return:
*	None
*/
OTP_VOID ibc_opttype_init(void)
{
	g_ibc_opttype_rcv_func = NULL;
}

/*******************************************************************************
*ibc_opttype_install  存储光头类型模块,安装回调函数函数
*Input:
*Output:
*	None	
*Return:
*	None
*/
OTP_VOID ibc_opttype_install(ibc_opttype_rcv_func callback)
{
	g_ibc_opttype_rcv_func = callback;
}


/*******************************************************************************
*ibc_opttype_rcv  存储光头类型模块,接收处理函数
*Input:
*Output:
*	None	
*Return:
*	None
*/
STATUS ibc_opttype_rcv(OTP_VOID *arg, uart_protocol_type prt, OTP_UINT8 *pbuf, OTP_UINT16 len, OTP_UINT8 ver)
{
#ifdef	INCLUDE_OPPOSITE_COMM
	comm_source_info *pcommsrcinfo = (comm_source_info *)arg;
	xxx_msg_send psfunc = pcommsrcinfo->send;
#else
	xxx_msg_send psfunc = (xxx_msg_send )arg;
#endif

	S_IBC_OPTTYPE_PAYLOAD	*pPayload = NULL;
	S_IBC_OPTTYPE_ACK		ack;

	NO_USE(ver);
	
	if( UART_PRTTYPE_OPTTYPE != prt )
	{
		ASSERT(0);
		return ERROR;
	}
	if(NULL == pbuf)
	{
		ASSERT(0);
		return ERROR;
	}

	if(len != sizeof(*pPayload))
	{
		ASSERT(0);
		return ERROR;
	}

	pPayload = (S_IBC_OPTTYPE_PAYLOAD *)pbuf;

	/*lint -save -e701*/
	ack.slot = (svc_get_local_slot(arg) & 0xf) | (~(svc_get_local_slot(arg) & 0xf) << 4) ;
	/*lint -restore*/
	ack.checkSum = ack.slot;
	ack.identify = 0xfe;
	ack.checkSum += ack.identify;
	ack.data = ((pPayload->typeHigh &0xf) << 4) | (pPayload->typeLow &0xf);

	ack.checkSum += ack.data;

	if( NULL != g_ibc_opttype_rcv_func)
	{
		(OTP_VOID)g_ibc_opttype_rcv_func(pbuf);
	}
	else
	{
		ASSERT(0);
		return ERROR;
	}


	if(psfunc((OTP_UINT8 *)&ack, sizeof(ack)) != OK)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	return OK;
}

/*lint -restore*/
#endif

