/******************************************************************************
* ��Ȩ���� (C)2013��**********���޹�˾��
*
* �ļ����ƣ�pub.h
* �ļ���ʶ����
* ����ժҪ�����ļ�ΪǶ��ʽϵͳ����������塣
* ����˵����
* ��ǰ�汾��V1.00
* ��    �ߣ�      
* ������ڣ�2013��7��24��
*    
* �޸ļ�¼1��
*        �޸����ڣ�2013��7��24��
*        �� �� �ţ�V1.00
*        �� �� �ˣ�      
*        �޸����ݣ�������������.
******************************************************************************/


#ifndef _PUB_H_
#define _PUB_H_

#ifdef __cplusplus
extern "C" {
#endif

/* socket NO. define. */
#define COM_MULTCAST_SCK_NO                    0    /* sokcet for sytem multicast.224.0.23.12 */
#define DATA_POINT_SCK_NO                      1    /* socket for data point.            */
#define CTRL_POINT_SCK0_NO                     2    /* socket for port0's control point. */
#define COM_MULTCAST_SCK_USER_NO               3    /* socket for user mul-address.user defined mul-address. */
#define ERROR_SCK_NO                           0xff /* wrong socket No. */

#define GROUP_DATA_INDICATION        (0x54)
#define GROUP_DATA_READ              (0x55)
#define GROUP_DATA_WRITE             (0x56)
/* eth 2 knx's core service(service code 0x02) command */
#define SEARCH_REQUEST               (0x01)
#define SEARCH_RESPONSE              (0x02)
#define DESCRIPTION_REQUEST          (0x03)
#define DESCRIPTION_RESPONSE         (0x04)
#define CONNECT_REQUEST              (0x05)
#define CONNECT_RESPONSE             (0x06)
#define CONNECTIONSTATE_REQUEST      (0x07)
#define CONNECTIONSTATE_RESPONSE     (0x08)
#define DISCONNECT_REQUEST           (0x09)
#define DISCONNECT_RESPONSE          (0x0A)
#define MAX_CORE_SVR_COMMAND_NUM     (0x0A)

/* service command(service code 0x03). */
#define DEVICE_CONFIGURATION_REQUEST (0x10)
#define DEVICE_CONFIGURATION_ACK     (0x11)

/* service (service code 0x04) command. */
#define TUNNELING_REQUEST            (0x20)
#define TUNNELING_ACK                (0x21)

/* service (service code 0x05) command. */
#define ROUTING_INDICATION           (0x30)
#define ROUTING_LOST_MESSAGE         (0x31)
#define ROUTING_BUSY                 (0x32)

#define REMOTE_DIAGNOSTIC_REQUEST    (0x40)
#define REMOTE_DIAGNOSTIC_RESPONSE   (0x41)
#define REMOTE_BASIC_CONFIG_REQUEST  (0x42)
#define REMOTE_RESET_REQUEST         (0x43)

/* connect type */
#define KNX_IP_CONNECT_NONE          (0x00)
#define DEVICE_MGMT_CONNECTION       (0x03)
#define TUNNEL_CONNECTION            (0x04)
#define REMLOG_CONNECTION            (0x06)
#define REMCONF_CONNECTION           (0x07)
#define OBJSVR_CONNECTION            (0x08)
#define KNX_IP_CONNECT_ALL           (0xff)

/* return code define. */
#define E_CMD_SUCCESSFUL                      0x00        /* command successfully.          */
#define E_COMMAND_FAILED                      0x01        /* command failed.                */
#define E_CONNECT_ACTIVE                      0x02        /* there is an active connection. */
#define E_CONNECT_ID_WRONG                    0x03        /* connection ID wrong.           */
#define E_COMMAND_PARA                        0x04        /* parameter is wrong.            */


/************************** ͨ�÷����붨�� ********************************/
#define SW_OK               ((WORD32)0x00000000)  /* �����ɹ� */
#define SW_ERR              ((WORD32)0xffffffff)  /* ����ʧ�� */
#define SW_INVALID_PARA     ((WORD32)0xfffffffe)  /* �Ƿ����� */
#define SW_NOT_SUPPORT      ((WORD32)0xfffffffd)  /* �Ƿ����� */

/******************************* ͨ�����ݽṹ���� ***************************/





#ifdef __cplusplus
}
#endif

#endif /* _COMMON_H_ */

/* End-of-file */


