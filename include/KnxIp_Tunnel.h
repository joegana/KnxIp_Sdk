/******************************************************************************
* ��Ȩ���� (C)2013��**********���޹�˾��
*
* �ļ����ƣ�KnxIp_Tunnel.h
* �ļ���ʶ����
* ����ժҪ��knx ip tunneling header file.
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


#ifndef _KNXIP_TUNNEL_H_
#define _KNXIP_TUNNEL_H_

#ifdef __cplusplus
extern "C" {
#endif



/* offset of the input buffer of tunnelling. */
#define CMD_TNL_REQ_CNECT_ID_POS         7
#define CMD_TNL_REQ_SEQ_NO_POS           8
#define CMD_TNL_REQ_MSG_CODE_POS         10
#define CMD_TNL_MSG_CTRL1_OFFSET         2

/* offset of the ACK of tunnelling. */
#define CMD_TNL_ACK_CNECT_ID_POS         7
#define CMD_TNL_ACK_SEQ_NO_POS           8
#define CMD_TNL_ACK_STS_POS              9






/******************************************************************************************************
* �������ƣ�VOID KnxIp_Tunnel_Init(T_KNX_IP_CORE_PARA *ptCoreData)
* ����������Device management initialization.
* ���������BYTE ucPrtNo:Knx ports number.
            T_KNX_IP_CORE_PARA *ptCoreDat:KNX IP core parameter.
* �����������
* �� �� ֵ����
* ����˵����this function will be called by Knxip_core
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
VOID KnxIp_Tunnel_Init(T_KNX_IP_CORE_PARA *ptCoreData);

/******************************************************************************************************
* �������ƣ�KNXIP_BOOL KnxIp_Svr_Tunnel(BYTE *pucInBuffer,BYTE ucSrcPoolId)
* ����������Knx Ip tunnelling ������ڡ�
* ���������BYTE *pucInBuffer: point to the header of buffer.
            BYTE ucSrcPoolId : buffer��Դpool ID.
* ���������
* �� �� ֵ��BYTE* ����response��buffer������NULL��response.
            if return NULL,the caller should release the input buffer.
            if return the response buffer,the caller should not release the input buffer.
* ����˵����pucBufferָ��buffer��ͷ����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Tunnel(BYTE *pucInBuffer,BYTE ucSrcPoolId);

/******************************************************************************************************
* �������ƣ�VOID KnxIp_Tunnel_DisCnect(BYTE *pucIn,BYTE ucCnectId,T_KNXIP_PORT_PARA *ptPtrPara)
* ����������Device management disconnection handle,set the data for mgm disconnection response.
* ���������BYTE ucCnectId :connection ID
            T_KNXIP_PORT_PARA *ptPtrPara:port's parameter.
* ���������BYTE *pucBuffer:response frame data.
* �� �� ֵ��VOID
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
VOID KnxIp_Tunnel_DisCnect(BYTE ucCnectId,T_KNXIP_CNECT_PARA *ptPtrPara);

/******************************************************************************************************
* �������ƣ�BYTE KnxIp_Svr_Tnl_Req(BYTE *pucInBuffer)
* ����������Knx Ip ����tunnelling require��ڡ�
* ���������BYTE *pucInBuffer: point to the header of buffer.
* ���������
* �� �� ֵ��E_COMMAND_FAILED/E_CMD_SUCCESSFUL.
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
BYTE KnxIp_Svr_Tnl_Req(BYTE *pucInBuffer);




#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_TUNNEL_H_ */



/* end of file. */






