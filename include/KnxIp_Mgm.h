/******************************************************************************
* ��Ȩ���� (C)2013��**********���޹�˾��
*
* �ļ����ƣ�KnxIp_Mgm.h
* �ļ���ʶ����
* ����ժҪ��knx ip management header file.
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


#ifndef _KNXIP_MGM_H_
#define _KNXIP_MGM_H_

#ifdef __cplusplus
extern "C" {
#endif


/* offset for Mgm request frame. */
#define CMD_MGM_REQUEST_CHNLID_POS              7
#define CMD_MGM_REQUEST_SEQNO_POS               8
#define CMD_MGM_REQUEST_MSGCODE_POS             10

/* offset for Mgm ACK frame. */
#define CMD_MGM_ACK_CHNLID_POS                  7
#define CMD_MGM_ACK_SEQNO_POS                   8
#define CMD_MGM_ACK_STS_POS                     9


/* overtime for MGM. */
#define KNX_SUBNET_DOWN_TIME                    5         /* KNX subnet down time 5s. */
#define KNX_IPNET_DOWN_TIME                     5         /* IP net down time 5s.     */







/******************************************************************************************************
* �������ƣ�KNXIP_BOOL KnxIp_Svr_Mgm(BYTE *pucInBuffer,BYTE ucSrcPoolId)
* ����������Knx Ip management ������ڡ�
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
KNXIP_BOOL KnxIp_Svr_Mgm(BYTE *pucInBuffer,BYTE ucSrcPoolId);

/******************************************************************************************************
* �������ƣ�VOID KnxIp_Mgm_Init(T_KNX_IP_CORE_PARA *ptCoreData)
* ����������Device management initialization.
* ���������T_KNX_IP_CORE_PARA *ptCoreDat:KNX IP core parameter.
* �����������
* �� �� ֵ����
* ����˵����this function will be called by Knxip_core
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
VOID KnxIp_Mgm_Init(T_KNX_IP_CORE_PARA *ptCoreData);

/******************************************************************************************************
* �������ƣ�VOID KnxIp_Mgm_DisCnect(BYTE ucCnectId,T_KNXIP_PORT_PARA *ptPtrPara)
* ����������Device management disconnection handle,set the data for mgm disconnection response.
* ���������BYTE ucCnectId :connection ID
            T_KNXIP_PORT_PARA *ptPtrPara:port's parameter.
* ���������
* �� �� ֵ��VOID
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
VOID KnxIp_Mgm_DisCnect(BYTE ucCnectId,T_KNXIP_CNECT_PARA *ptPtrPara);

/******************************************************************************************************
* �������ƣ�BYTE KnxIp_Svr_Mgm_Req(BYTE *pucInBuffer)
* ����������Knx Ip ����management require��ڡ�
* ���������BYTE *pucInBuffer: point to the header of buffer.
* ���������
* �� �� ֵ��E_COMMAND_FAILED/E_CMD_SUCCESSFUL.
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        ���� 
******************************************************************************************************/
BYTE KnxIp_Svr_Mgm_Req(BYTE *pucInBuffer);




#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_MGM_H_ */



/* end of file. */






