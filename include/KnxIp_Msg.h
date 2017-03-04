/******************************************************************************
* ��Ȩ���� (C)2013��**********���޹�˾��
*
* �ļ����ƣ�KnxIp_Msg.h
* �ļ���ʶ����
* ����ժҪ��knx ip message deal header file.
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


#ifndef _KNXIP_MSG_H_
#define _KNXIP_MSG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* saving space size for the key word of the buffer.
   KnxIP frame format is as below:
      ______________________________________________________________________________________________________________________________________________
     |                                      |                 |                     |               |                   |          |       |        |
     |sizeof(WORDPTR) for next frame address|1byte for Pool Id|2 byte payload length|payload address|1Byte message info.|socket No.|Ip&port|data... |
     |______________________________________|_________________|_____________________|_______________|___________________|__________|_______|________|
 */

/* reserved space in the KNX buffer for adding the KnxIp header.*/
#define TOTAL_KNX_BUFFER_HEADER_LEN  32         /* the lenght from the buffer header to the Knx subnet Msg header.from the next address to Mesage code. */


/* Service family */
#define KNX_IP_SVR_RSV               (0x01)       /* reserved.    */
#define KNX_IP_CORE_SERVICE          (0x02)       /* core service */
#define KNX_IP_MGM_SERVICE           (0x03)       /* mgm  service */
#define KNX_IP_TUNNEL_SERVICE        (0x04)       /* tunnelling service */
#define KNX_IP_ROUTE_SERVICE         (0x05)       /* routing service    */
#define KNX_IP_REMOTE_LOG            (0x06)       /* remote log service */
#define KNX_IP_REMOTE_CONFG_DIA      (0x07)       /* remote config service   */
#define KNX_IP_OBJ_SVR               (0x08)       /* obj server service      */
#define KNX_IP_SVR_MAX               (0x08)       /* Max. number of service. */


/* Definition about the protocol */
#define KNX_IP_VERSION_10            (0x10)   /* Identifier for KNXnet/IP protocol version 1.0  */
#define KNX_IP_HEADER_SIZE_10        (0x06)   /* Constant size of KNXnet/IP header as defined in protocol version 1.0 */

/* KNX IP header element's position. */
#define KNXIP_HEADER_LEN_POS                 0
#define KNXIP_HEADER_PRT_VER_POS             1
#define KNXIP_HEADER_SVR_POS                 2
#define KNXIP_HEADER_CMD_POS                 3
#define KNXIP_HEADER_LEN_H_POS               4
#define KNXIP_HEADER_LEN_L_POS               5

#define IP_ADDRESS_INFO_LEN                  6


/****************************************************
*   �ṹ����T_IP_ADDRESS_INFO
*   ������  Ip�ĵ�ַ��Ϣ(address information)
*   ������  BYTE aucIpAddInfo[IP_ADDRESS_INFO_LEN]:
                                 0-3:ip address,high->low
                                 4-5:port number,high->low
*   ���ߣ�       
*   �޸ļ�¼��
*   2013-7-24         �����ṹ��
****************************************************/
typedef struct
{
    BYTE aucIpAddInfo[IP_ADDRESS_INFO_LEN];      /* 0-3:ip address,high->low;4-5:port number,high->low */
}T_IP_ADDRESS_INFO;

/*******************************************************************************************
* �������ƣ�KNXIP_BOOL KnxIp_Svr_Rsv(BYTE *pucBuffer,BYTE ucTxPoolId)
* ����������Knx Ip ȱʡ��������ڡ�
* ���������BYTE *pucBuffer:input frame buffer.
            BYTE ucTxPoolId:pool id for transmit buffer.
* �����������
* �� �� ֵ��NULL.
* ����˵����pucBuffer points to the header of the buffer.
* �޸�����        �汾��     �޸���          �޸�����
* -----------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
*******************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Rsv(BYTE *pucBuffer,BYTE ucTxPoolId);

/****************************************************************************************************
* �������ƣ�KNXIP_BOOL KnxIp_Msg_Handler(BYTE *pucInBuffer,BYTE ucTxPoolId)
* ����������Knx Ip message������ڡ�
* ���������BYTE *pucInBuffer:ָ��KNX IP���ĵ�ͷ��.
            BYTE ucTxPoolId  :transmit buffer��Pool ID.
* ���������No.
* �� �� ֵ��BYTE* ����response��buffer����������Ҫ������buffer���ͷš�
* ����˵����pucBufferָ��buffer�Ĺ���ͷ����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Msg_Handler(BYTE *pucInBuffer,BYTE ucTxPoolId);


#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_MSG_H_ */



/* end of file. */






