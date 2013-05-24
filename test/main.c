/*
 * main.c
 *
 *  Created on: 2013-5-24
 *      Author: lirobot
 */


#include "lilib.h"
#include "stdio.h"
#include "queue.h"
#define Q_BUF_NUM 100
circular_q test_q;

int8 q_buf[Q_BUF_NUM];
int main(void)
{
	circular_q_init(&test_q,q_buf,Q_BUF_NUM);

	return 0;
}
