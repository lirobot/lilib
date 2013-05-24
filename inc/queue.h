#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "lilib.h"

typedef struct _circular_q 
{
	int8 *pbuf;
	uint16 tail;
	uint16 head;
	uint16 cnt;
	uint16 max_num;
}circular_q;



/**
 * 操作宏定义
 */


extern int32 circular_q_init(circular_q * me,int8 *pbuf,uint16 maxnum);
extern int32 circular_q_en(circular_q * me, int8 data);
extern int32 circular_q_de(circular_q * me, int8 * pdate);
extern int32 circular_q_ens(circular_q * me, int8 *data, uint16 len);
extern int32 circular_q_des(circular_q * me, int8 *data, uint16 len);
#endif 
