/**
 *  \file	queue.h
 *  \brief  这里的队列是循环队列，因为非循环队列，并不实际，所以只写了循环队列。
 *  按队列的两种存储方式写，由
 *  开关宏 LINK_STORAGE_ENABLE 使用链式存储。
 *  开关宏 LINEAR_STORAGE_ENABLE 使用线性存储。
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       Sep 4, 2012 10:07:02 PM
 *  \note 默认的是打开 LINK_STORAGE_ENABLE 这个宏
 */


#ifndef QUEUE_H_
#define QUEUE_H_
#include "../../user/user_configure/configure.h"

typedef int QElemType;//根据实际情况变化
//选择存储方式
#define LINK_STORAGE_ENABLE
#define LINEAR_STORAGE_ENABLE

#ifdef LINK_STORAGE_ENABLE
#ifdef LINEAR_STORAGE_ENABLE
/*两种存储方式都使用*/
#define ALL_STORAGE_ENABLE
#define LINEAR_TYPE	70
#define LINK_TYPE		80
#endif
#endif
//各种存储结构所需要的数据结构声明和宏
#ifdef LINEAR_STORAGE_ENABLE
#define LINEAR_MAXSIZE				20
#endif
#ifdef  LINK_STORAGE_ENABLE
typedef struct Link_QNode /*结点结构*/
{
	QElemType date;
	struct Link_QNode *next;
}Link_QNode,*Link_QueuePtr;
#endif
typedef struct
{
#ifdef ALL_STORAGE_ENABLE
	QElemType data[LINEAR_MAXSIZE];
	INT8U type;
	Link_QueuePtr lk_front;/*链队列头指针*/
	Link_QueuePtr lk_rear;/*链队列尾指针*/
	INT32U ln_front;/*头指针*/
	INT32U ln_rear;/*尾指针，如果队列没有满的话，指向尾元素的下一个位置*/
#else
#ifdef  LINK_STORAGE_ENABLE
	Link_QueuePtr lk_front;/*链队列头指针*/
	Link_QueuePtr lk_rear;/*链队列尾指针*/
#endif
#ifdef LINEAR_STORAGE_ENABLE
	QElemType data[LINEAR_MAXSIZE];
	INT32U ln_front;/*头指针*/
	INT32U ln_rear;/*尾指针，如果队列没有满的话，指向尾元素的下一个位置*/
#endif
#endif
	INT32U cur_size;
	BOOLEAN isExist;//非255:存在，已经初始化。255:已经被销毁，不能使用。
}queue;


extern BOOLEAN InitQueue(queue *Q
#ifdef ALL_STORAGE_ENABLE
					,INT8U type
#endif
);/*初始化队列，建立一个空队列Q*/
extern BOOLEAN DestroyQueue(queue *Q);/*若队列Q存在，则销毁*/
extern BOOLEAN ClearQueue(queue *Q);/*若队列Q存在，则清空*/
extern BOOLEAN QueueEmpty(queue *Q);/*若队列Q为空，则返回ture，否则返回false*/
extern BOOLEAN GetQHead(queue *Q,QElemType *e);/*若队列Q存在且非空，则e返回队头元素*/
extern BOOLEAN EnQueue(queue *Q,QElemType e
#ifdef ALL_STORAGE_ENABLE
					,Link_QueuePtr QNode
#else
#ifdef LINK_STORAGE_ENABLE
					,Link_QueuePtr QNode
#endif
#endif
);/*若队列Q存在，则将元素e插入进队列Q中，并成为队尾元素。*/
extern BOOLEAN DeQueue(queue *Q,QElemType *e);/*若队列Q存在，则删除Q队列中的队头元素，并用e返回该值*/
extern INT32U	QueueLength(queue *Q);/*若队列Q存在，则返回队列长度*/
#endif /* QUEUE_H_ */
