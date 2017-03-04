/******************************************************************************
* ��Ȩ���� (C)2013���Ͼ�**********����ϵͳ���޹�˾��
*
* �ļ����ƣ�KnxIp_Ll.h
* �ļ���ʶ����
* ����ժҪ��knx ip core header file.
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


#ifndef _KNXIP_LL_H_
#define _KNXIP_LL_H_

#ifdef __cplusplus
extern "C" {
#endif

#define KNXIP_TX_LOSTMSG_ON       1        /* we need to send RT_LOST_MSG frame.      */
#define KNXIP_TX_LOSTMSG_OFF      0        /* we not need to send RT_LOST_MSG frame. */
#define KNXIP_TX_BUSY_ON          1        /* we need to send RT_BUSY_MSG frame.      */
#define KNXIP_TX_BUSY_OFF         0        /* we not need to send RT_BUSY_MSG frame. */

/******************************************************************************************
* �������ƣ�VOID KnxIp_Ll_Init(VOID)
* ����������init. the knx ip link layer parameter.
* ���������no.
* ���������no.
* �� �� ֵ��no.
* ����˵����no.
* �޸�����     �汾��     �޸���      �޸�����
* ----------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   ����
******************************************************************************************/
VOID KnxIp_Ll_Init(VOID);

/******************************************************************************************
* �������ƣ�WORD32 KnxIp_Recv(VOID)
* ����������Receive socket's data in polling way.It will poll all socket in turn.
* ���������no.
* ���������no.
* �� �� ֵ��no.
* ����˵����this function will insert the input frame into the socket's receiving pool.
* �޸�����     �汾��     �޸���      �޸�����
* ----------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   ����
******************************************************************************************/
VOID KnxIp_Recv(VOID);

/******************************************************************************************
* �������ƣ�VOID KnxIp_Send(VOID)
* ����������Send socket's data in polling way.It will poll all socket in turn.
* ���������no.
* ���������no.
* �� �� ֵ��no.
* ����˵����
* �޸�����     �汾��     �޸���      �޸�����
* ----------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   ����
******************************************************************************************/
VOID KnxIp_Send(VOID);

/**************************************************************************************************************************
* �������ƣ�WORD32 KnxIp_SckReg(T_IP_DEV_REG tIpDevReg)
* ������������KNX Ip��·��ע��Socket��socket�Ŵ�0��ʼ���������ע�ᡣ
* ���������T_IP_DEV_REG tIpDevReg:ע���socket�豸����,
                BYTE ucDevNo                                       socket��,COM_MULTCAST_SCK_NO ~ COM_MULTCAST_SCK_USER_NO.    
                WORD16 wRxBufferNum                                ���ڽ��յ�buffer����.
                WORD16 wTxBufferNum                                ���ڷ��͵�buffer����.
                WORD16 wBufferSize                                 ÿ��buffer�ĳ���.
                WORD16 (*pfReceive)(BYTE ucDevNo,BYTE *pucBuffer)  �豸�Ľ��պ���
                    BYTE ucDevNo    : socket��,��0��ʼ. 
                    BYTE *pucBuffer : ���յ����ݴ�ŵ�bufferָ��.
                WORD16 (*pfSend)(BYTE ucDevNo,BYTE *pucBuffer,WORD16 wLength) �豸�ķ��ͺ���
                    BYTE ucDevNo    : socket��,��0��ʼ.
                    BYTE *pucBuffer : �������ݵĴ��bufferָ��.
                    WORD16 wLength  : �������ݵĳ���.
* ���������
* �� �� ֵ��SW_OK ��ע��ɹ���
            SW_ERR��ע��ʧ�ܣ�
* ����˵��:
* �޸�����     �汾��     �޸���      �޸�����
* -------------------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   ����
***************************************************************************************************************************/
WORD32 KnxIp_SckReg(T_IP_DEV_REG *ptIpDevReg);





#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_LL_H_ */



/* end of file. */


