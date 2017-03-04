/******************************************************************************
* ��Ȩ���� (C)2013��**********���޹�˾��
*
* �ļ����ƣ�KnxIp_Routing.h
* �ļ���ʶ����
* ����ժҪ��knx ip route header file.
* ����˵����
* ��ǰ�汾��V1.00
* ��    �ߣ�     
* ������ڣ�2014��3��18��
*    
* �޸ļ�¼1��
*        �޸����ڣ�2014��3��18��
*        �� �� �ţ�V1.00
*        �� �� �ˣ�     
*        �޸����ݣ������ļ�
******************************************************************************/


#ifndef _KNXIP_ROUTING_H_
#define _KNXIP_ROUTING_H_

#ifdef __cplusplus
extern "C" {
#endif




/* route control command define. */
#define KNXIP_ROUTE_ENABLE           (0x01)
#define KNXIP_ROUTE_DISABLE          (0x00)

/* frame length */
#define ROUTING_BUSY_LENGTH           0x0C
#define ROUTING_LOSTMSG_LENGTH        0x0A

/* define parameter for routing. */
#define TX_RTBUSY_THRESHOLD_P2P      5
#define TX_RTBUSY_THRESHOLD_P2ALL    10

/* define time for busy frame count operation. */
#define BUSY_CUNT_INC                10    /* 10ms */
#define BUSY_CUNT_DEC                5     /* 5ms  */

/* routing frame position define. */
#define CMD_RT_INDI_MSGCODE_POS      6
#define CMD_RT_MSG_CTRL1_OFFSET      2

/* lost message command. */
#define CMD_RT_LOSTMSG_DEVST_POS     7
#define CMD_RT_LOSTMSG_NUM_H_POS     8
#define CMD_RT_LOSTMSG_NUM_L_POS     9

/* busy command. */
#define CMD_RT_BUSY_DEVST_POS        7
#define CMD_RT_BUSY_WAITTM_H_POS     8
#define CMD_RT_BUSY_WAITTM_L_POS     9
#define CMD_RT_BUSY_CTRL_H_POS       10
#define CMD_RT_BUSY_CTRL_L_POS       11


/******************************************************************************************************
* �������ƣ�VOID KnxIp_RtBusy_Req(BYTE *pucInBuffer)
* ����������creat Knx Ip routing busy require.
* ���������BYTE *pucInBuffer  : point to the header of the buffer.
* ���������no.
* �� �� ֵ��no.
* ����˵����the caller should set the buffer's destination device's number and the source device number.
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
VOID KnxIp_RtBusy_Req(BYTE *pucInBuffer);


/******************************************************************************************************
* �������ƣ�KNXIP_BOOL KnxIp_Svr_Route(BYTE *pucInBuffer,BYTE ucTxPoolId)
* ����������Knx Ip routing handler.
* ���������BYTE *pucInBuffer  : point to the header of the buffer.
            BYTE ucTxPoolId   : buffer��Դpool ID.
* ���������
* �� �� ֵ��BYTE* ����response��buffer������NULL��response����������Ҫ������buffer���ͷš�
* ����˵����pucBufferָ��input buffer�Ĺ���ͷ����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Route(BYTE *pucInBuffer,BYTE ucTxPoolId);

/******************************************************************************************************
* �������ƣ�VOID KnxIp_RouteCtrl(VOID)
* ����������Control routing function working according to the resume time.
* ���������no.
* ���������no.
* �� �� ֵ��no.
* ����˵����This function should be called periodically.
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                       ���� 
******************************************************************************************************/
VOID KnxIp_RouteCtrl(VOID);

/******************************************************************************************************
* �������ƣ�BYTE *KnxIp_GetRtMgmDownFrame(VOID)
* ����������get routing management down frames.
* ���������no.
* ���������no.
* �� �� ֵ��NULL / freme buffer pointer.
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
BYTE *KnxIp_GetRtMgmDownFrame(VOID);

/******************************************************************************************************
* �������ƣ�KNXIP_BOOL KnxIp_Svr_Route_Req(BYTE *pucInBuffer)
* ����������creat Knx Ip routing indication require.
* ���������BYTE *pucInBuffer  : point to the header of the buffer.
* ���������no.
* �� �� ֵ��TRUE : route it successfully.
            FALSE: route it failed(can not route it).
* ����˵����the caller should set the buffer's destination device's number and the source device number.
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Route_Req(BYTE *pucInBuffer);

/******************************************************************************************************
* �������ƣ�VOID KnxIp_Route_Init(T_KNX_IP_CORE_PARA *ptCoreData)
* ����������routing function initialization.
* ���������T_KNX_IP_CORE_PARA *ptCoreDat:KNX IP core parameter.
* �����������
* �� �� ֵ����
* ����˵����this function will be called by Knxip_core
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
VOID KnxIp_Route_Init(T_KNX_IP_CORE_PARA *ptCoreData);







#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_ROUTING_H_ */



/* end of file. */






