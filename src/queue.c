#include "queue.h"
#include "lilib_config.h"

/**
 * 循环队列的数组实现
 *
 */


/**
 * 初始化循环队列
 * @param me
 * @param pbuf
 * @param maxnum
 * @return
 */
int32 circular_q_init(circular_q * me,int8 *pbuf,uint16 maxnum)
{
	me->pbuf = pbuf;
	me->head = 0;
	me->tail = 0;
	me->max_num = maxnum;
	me->cnt = 0;
	return 0;
}


/**
 * 循环队列入队
 * @param me
 * @param date
 * @return
 */
int32 circular_q_en(circular_q * me, int8 data)
{
	if (me->cnt == me->max_num)
	{
		return -1;
	}
	me->pbuf[me->tail] = data;
	me->cnt++;
	me->tail++;
	if (me->tail >= me->max_num)
	{
		me->tail = 0;
	}
	return 0;
}


/**
 * 循环队列出队
 * @param me
 * @param pdate
 * @return
 */
int32 circular_q_de(circular_q * me, int8 * pdate)
{
	if (me->cnt  == 0)
	{
		return -1;
	}
	pdate = &me->pbuf[me->head];
	me->cnt--;
	me->head++;
	if (me->head >= me->max_num)
	{
		me->head = 0;
	}
	return 0;
}

/**
 * 循环队列大数据入队
 * @param me
 * @param data
 * @param len
 * @return
 */
int32 circular_q_ens(circular_q * me, int8 *data, uint16 len)
{
	uint32 i;
	for (i = 0; i < len; i++)
	{
		circular_q_en(me,*data);
		data ++;
	}
	return 0;
}

/**
 * 循环队列大数据出队
 * @param me
 * @param data
 * @param len
 * @return
 */
int32 circular_q_des(circular_q * me, int8 *data, uint16 len)
{
	uint32 i;
	for (i = 0; i < len; i++)
	{
		circular_q_de(me,data);
		data ++;
	}
	return 0;
}
