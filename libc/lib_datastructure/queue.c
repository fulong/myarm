/**
 *  \file	queue.c
 *  \brief  这里的队列是循环队列，因为非循环队列，并不实际，所以只写了循环队列。
 *  按队列的两种存储方式写，由
 *  开关宏 LINK_STORAGE_ENABLE 使用链式存储。
 *  开关宏 LINEAR_STORAGE_ENABLE 使用线性存储。
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       Sep 4, 2012 9:59:21 PM
 */

#include "queue.h"

/**
 * @brief  初始化队列，建立一个空队列Q
 * @param queue *Q，要初始化的队列对象
 * @param INT8U type 如果ALL_STORAGE_ENABLE，打开的话要赋予这个变量某些值，以确定这个队列的类型
 * 这个参数可以取得到以下的值：\n
 * @arg LINEAR_TYPE
 * @arg LINK_TYPE
 * @retval 无
 * \date Sep 5, 2012 11:22:30 PM
 * @note 参数，type在ALL_STORAGE_ENABLE宏打开的时候才存在的
 */
BOOLEAN InitQueue(queue *Q
#ifdef ALL_STORAGE_ENABLE
               , INT8U mytype
#endif
               )
{
	if(Q->isExist == 255 || Q->isExist == 1)
	{
		return FALSE;
	}
	Q->isExist = 1;
	Q->cur_size = 0;
#ifdef ALL_STORAGE_ENABLE
	Q->lk_rear = Q->lk_front;
	Q->ln_front = 0;
	Q->ln_rear = 0;
	Q->type = mytype;
#else
#ifdef LINK_STORAGE_ENABLE
	Q->lk_rear =Q->lk_front;
#endif
#ifdef LINEAR_STORAGE_ENABLE
	Q->ln_front = 0;
	Q->ln_rear = 0;
#endif
#endif
	return TRUE;
}

/**
 * @brief 若队列Q存在，则销毁
 * @param queue *Q:将要销毁的队列对象
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval 返回函数执行状态。false,代表队列不存在
 * \date Sep 5, 2012 11:45:22 PM
 * @note 销毁后将不能再次使用这个变量。
 */
BOOLEAN DestroyQueue(queue *Q)
{
	if(Q->isExist == 255)
	{
		return FALSE;
	}
	Q->isExist = 255;
	return TRUE;
}
/**
 * @brief  若队列Q存在，则清空.
 * @param queue *Q:将要清空的队列对象.
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval 返回执行状态。FALSE，代表队列不存在
 * \date Sep 5, 2012 11:57:43 PM
 * @note
 */
BOOLEAN ClearQueue(queue *Q)
{
	if(Q->isExist == 255)
	{
		return FALSE;
	}
#ifdef ALL_STORAGE_ENABLE
	if(Q->type == LINK_TYPE)
	{
		Q->lk_front=Q->lk_rear ;
	}
	else if(Q->type == LINEAR_TYPE)
	{
		Q->ln_front = 0;
		Q->ln_rear = 0;
	}
	else
	{
		return FALSE; //Q->type类型不对，返回错误.
	}
#else
#ifdef LINK_STORAGE_ENABLE
	 Q->lk_front=Q->lk_rear;
#endif
#ifdef LINEAR_STORAGE_ENABLE
	Q->ln_front = 0;
	Q->ln_rear = 0;
#endif
#endif
	Q->cur_size =0;
	return TRUE;
}
/**
 * @brief  若队列Q为空，则返回ture，否则返回false
 * @param queue *Q:将要查询的队列对象.
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval
 * \date Sep 6, 2012 1:06:14 AM
 * @note
 */
BOOLEAN QueueEmpty(queue *Q)
{
	if(Q->isExist == 255 || Q->cur_size != 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
/**
 * @brief  若队列Q存在且非空，则e返回队头元素
 * @param queue *Q,将返回的队列对象
 * @param QElemType *e 将返回队列头元素的传递对象
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval 函数执行的状态
 * \date Sep 6, 2012 1:11:42 AM
 * @note
 */
BOOLEAN GetQHead(queue *Q , QElemType *e)
{
	if(Q->isExist == 255 || Q->cur_size == 0)
	{
		return FALSE;
	}
#ifdef ALL_STORAGE_ENABLE
	if(Q->type == LINK_TYPE)
	{
		*e = Q->lk_front->date;
	}
	else if(Q->type == LINEAR_TYPE)
	{
		*e = Q->data[Q->ln_front];
	}
	else
	{
		return FALSE; //Q->type类型不对，返回错误.
	}
#else
#ifdef LINK_STORAGE_ENABLE
	*e = Q->lk_front->date;
#endif
#ifdef LINEAR_STORAGE_ENABLE
	*e = Q->data[Q->ln_front];
#endif
#endif
	return TRUE;
}
/**
 * @brief  若队列Q存在，则返回队列长度
 * @param queue *Q 将要查询的队列对象
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval 队列的长度
 * \date Sep 6, 2012 1:18:35 AM
 * @note
 */
INT32U QueueLength(queue *Q)
{
	if(Q->isExist == 255)
	{
		return FALSE;
	}
	return Q->cur_size;
}
/**
 * @brief  若队列Q存在，则将元素e插入进队列Q中，并成为队尾元素。
 * @param queue *Q 将要将e插进去的队列对象
 * @param QElemType e 插进去的队列对象的元素
 * @param Link_QueuePtr QNode 入列的结点
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval 返回状态
 * \date Sep 6, 2012 1:30:01 AM
 * @note
 */
BOOLEAN EnQueue(queue *Q , QElemType e
#ifdef ALL_STORAGE_ENABLE
               , Link_QueuePtr QNode
#else
#ifdef LINK_STORAGE_ENABLE
               , Link_QueuePtr QNode
#endif
#endif
               )
{
	if(Q->isExist == 255)
	{
		return FALSE;
	}
#ifdef ALL_STORAGE_ENABLE
	if(Q->type == LINK_TYPE)
	{
		QNode->date = e;
		if(Q->cur_size == 0)
		{
			Q->lk_front = QNode;
			Q->lk_rear = QNode;
			QNode->next=Q->lk_rear;
		}
		Q->lk_rear->next = QNode;
		Q->lk_rear = QNode;
		Q->cur_size++;
	}
	else if(Q->type == LINEAR_TYPE)
	{
		if(Q->cur_size == LINEAR_MAXSIZE)/*队列满的判断*/
		{
			return FALSE;
		}
		Q->data[Q->ln_rear] = e;
		Q->ln_rear = (Q->ln_rear + 1) % LINEAR_MAXSIZE;
		Q->cur_size++;
	}
	else
	{
		return FALSE; //Q->type类型不对，返回错误.
	}
#else
#ifdef LINK_STORAGE_ENABLE
	QNode->date = e;
	if(Q->cur_size == 0)
	{
		Q->lk_front = QNode;
		Q->lk_rear = QNode;
	}
	Q->lk_rear->next = QNode;
	Q->lk_rear = QNode;
	Q->cur_size++;
#endif
#ifdef LINEAR_STORAGE_ENABLE
	if(Q->cur_size == LINEAR_MAXSIZE)/*队列满的判断*/
	{
		return FALSE;
	}
	Q->data[Q->ln_rear] = e;
	Q->ln_rear = (Q->ln_rear+1)%LINEAR_MAXSIZE;
	Q->cur_size++;
#endif
#endif
	return TRUE;
}
/**
 * @brief  若队列Q存在，则删除Q队列中的队头元素，并用e返回该值
 * @param queue *Q 将要将e出队列的队列对象
 * @param QElemType e 从队列出来的对象元素
 * 这个参数可以取得到以下的值：\n
 * @arg
 * @retval 返回状态
 * \date Sep 6, 2012 1:30:07 AM
 * @note
 */
BOOLEAN DeQueue(queue *Q , QElemType *e)

{
	if(Q->isExist == 255)
	{
		return FALSE;
	}
	if(Q->cur_size == 0) //如果队列为空，则不能弹出元素
	{
		return FALSE;
	}
#ifdef ALL_STORAGE_ENABLE
	if(Q->type == LINK_TYPE)
	{
		*e = Q->lk_front->date;
		Q->lk_front = Q->lk_front->next;
		Q->cur_size--;
	}
	else if(Q->type == LINEAR_TYPE)
	{
		*e = Q->data[Q->ln_front];
		Q->ln_front = (Q->ln_front + 1) % LINEAR_MAXSIZE;
		Q->cur_size--;
	}
	else
	{
		return FALSE; //Q->type类型不对，返回错误.
	}
#else
#ifdef LINK_STORAGE_ENABLE
	*e = Q->lk_front->date;
	Q->lk_front = Q->lk_front->next;
	Q->cur_size--;
#endif
#ifdef LINEAR_STORAGE_ENABLE
	*e=Q->data[Q->ln_front];
	Q->ln_front = (Q->ln_front + 1) % LINEAR_MAXSIZE;
	Q->cur_size--;
#endif
#endif
	return TRUE;
}

