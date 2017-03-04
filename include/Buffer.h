/******************************************************************************
* ��Ȩ���� (C)2013��**********���޹�˾��
*
* �ļ����ƣ�buffer.h
* �ļ���ʶ����
* ����ժҪ������������ͷ�ļ�
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


#ifndef _BUFFER_H_
#define _BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Attention:The follow definition should be redefined in BoardCtrl.h according to the realistic scenario. */
#ifndef TOTAL_BUFFER_SIZE
    #define TOTAL_BUFFER_SIZE (2048)   /* the total size of buffer pool. */
#endif

/* MCU_SIZE should be defined in configure.h */
#define DATA_BUF_ADDRESS_ALIGNMENT(x)  ((BYTE*)((((WORDPTR)(x))+MCU_SIZE-1) & (~(MCU_SIZE-1))))  /* align the address of the buffer. */
#define DATA_BUF_SIZE_ALIGNMENT(x)     (((x)+MCU_SIZE-1) & (~(MCU_SIZE-1)))                      /* align the size of the buffer.    */

/* The Max. number of pools. */
#define MAX_BUFFER_POOL_NUM         (16)

/* Pool ID definition. */
#define POOL_ID_NULL              (0)
#define POOL_ID_ERROR             (0xff)
#define SET_POOL_ACLLOC_FLAG      (0x01)    /* set alloc flag.      */
#define CLR_POOL_ACLLOC_FLAG      (0xFE)    /* release aclloc flag. */
#define SET_POOL_FREE_FLAG        (0x02)    /* set free flag.       */
#define CLR_POOL_FREE_FLAG        (0xFD)    /* release free flag.   */
#define SET_POOL_IN_FLAG          (0x04)    /* set input flag.      */
#define CLR_POOL_IN_FLAG          (0xFB)    /* release input flag.  */

/****************************************************
*   �ṹ����T_BUFFER_MGM
*   ������  buffer����ṹ
*   ������  
    BYTE    ucUseFlg;              Bit0:alloc Pool's flag
                                   Bit1:free pool's flag
                                   Bit2:In buffer's flag
    BYTE    *pucPoolHeader;        the current free buffer point
    BYTE    *pucPoolEnd;           the current free buffer end  
    BYTE    *pucBufferIn;          the buffer for input         
    BYTE    *pucBufLastIn;         the last in buffer           
*   ���ߣ�       
*   ˵��:
       (1) buffer frame format is as below:
              |sizeof(WORDPTR)|1 byte for pool ID| data ....|
       (2) buffer size shold be >= (Max. data size + sizeof(WORDPTR) + 1)
       (3) the byte for pool ID in frame is defined as below:
              bit0~bit3:the source pool's ID;
              bit4~bit7:the destination pool's ID;
*   �޸ļ�¼��
*   2013-7-24         �����ṹ��
****************************************************/
typedef struct
{
    BYTE    ucUseFlg;              /* Bit0:alloc Pool's flag,
                                      Bit1:free pool's flag,
                                      Bit2:In buffer's flag;         */
    BYTE    *pucPoolHeader;        /* the current free buffer point. */
    BYTE    *pucPoolEnd;           /* the current free buffer end.   */
    BYTE    *pucBufferIn;          /* the buffer for input.          */
    BYTE    *pucBufLastIn;         /* the last in buffer.            */
}T_BUFFER_MGM;

/****************************************************
*   �ṹ����T_BUFFER_HEADER
*   ������  bufferͷ��
*   ������  
            BYTE *pucNext : next buffer's address.
            BYTE ucPoolId : buffer's pool ID.
*   �޸ļ�¼��
*   2013-7-24         �����ṹ��
****************************************************/
#pragma pack(1)
typedef struct
{
    BYTE *pucNext;     /* next buffer's address */
    BYTE ucPoolId;     /* buffer's pool ID.     */
}T_BUFFER_HEADER;
#pragma pack()

/**************************************************************************
* �������ƣ�VOID Buffer_Pool_Init(VOID)
* ������������ʼ��buffer�ء�
* �����������
* �����������
* �� �� ֵ����
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
VOID Buffer_Pool_Init(VOID);

/**************************************************************************
* �������ƣ�BYTE Buffer_Pool_Alloc(WORD16 wBufferSize,WORD16 wBufferNum)
* ������������buffer�ܳ��з���һ��buffer�ӳأ��ӳصĴ�СΪbuffer���Ⱥ͸���
            �ĳ˻���
* ���������WORD16 wBufferSize : һ��buffer�Ĵ�С
            WORD16 wBufferNum  : buffer�ĸ���
* �����������
* �� �� ֵ��POOL_ID_NULL  : buffer�ӳط���ʧ��
                            ����Ϊ����ɹ����POOL ID
* ����˵����wBufferSize > sizeof(WORDPTR) + 1
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
BYTE Buffer_Pool_Alloc(WORD16 wBufferSize,WORD16 wBufferNum);

/**************************************************************************
* �������ƣ�BYTE* Buffer_Alloc(BYTE ucPoolId)
* ������������buffer�ӳ��з���һ��buffer��
* ���������BYTE ucPoolId : pool Id.
* �����������
* �� �� ֵ��NULL  : buffer�ӳط���ʧ��
                    �������ɹ���bufferָ��
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
BYTE* Buffer_Alloc(BYTE ucPoolId);

/**************************************************************************
* �������ƣ�BYTE* Buffer_Free(BYTE ucPoolId)
* �����������ͷ�һ��buffer��pool�С�
* ���������BYTE ucPoolId : pool Id.
* �����������
* �� �� ֵ��NULL  : buffer�ӳ��ͷ�ʧ��
                    �ͷųɹ��������ӳ���buffer
* ����˵�������ں������������£�����ֵ������Ϊbuffer�ص��׵�ַ���м��㡣
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
BYTE* Buffer_Free(BYTE ucPoolId,BYTE *pucBuffer);

/**************************************************************************
* �������ƣ�BYTE* Buffer_Insert(BYTE ucPoolId,BYTE *pucBuffer)
* ������������buffer���в���һ��buffer��
* ���������BYTE ucPoolId : pool Id.
            BYTE *pucBuffer:buffer.
* �����������
* �� �� ֵ��NULL  : ����bufferʧ��
                    ����ɹ������ص�ǰbuffer����buffer��
* ����˵�������ں������������£�����ֵ������Ϊbuffer�����׵�ַ���м��㡣
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
BYTE* Buffer_Insert(BYTE ucPoolId,BYTE *pucBuffer);

/**************************************************************************
* �������ƣ�BYTE* Buffer_GetHeader(BYTE ucPoolId)
* ������������buffer���е�һ��buffer��
* ���������BYTE ucPoolId : pool Id.
* �����������
* �� �� ֵ��NULL  : ��ȡbufferʧ��
                    ��ȡ�ɹ������ص�ǰbuffer��
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
BYTE* Buffer_Get(BYTE ucPoolId);

/**************************************************************************
* �������ƣ�VOID Buffer_Pool_Quit(VOID)
* ����������release all malloc resources.
* �����������
* �����������
* �� �� ֵ����
* ����˵����
* �޸�����        �汾��     �޸���          �޸�����
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        ����  
**************************************************************************/
VOID Buffer_Pool_Quit(VOID);

#ifdef __cplusplus
}
#endif

#endif /* _BUFFER_H_ */



/* end of file. */

