#include "consumer.h"

void consumer::run() 
{
	get();                       //重写run函数调用get()函数；
	std::cout << "创建一个生产者线程" << std::endl;
}

void consumer::get()
{
	consumerMutex.lock();
	if (myDeque.size() > 0)                          //判断 如果队列中元素大于0 从尾部删除一个元素 唤醒被阻塞的生产者进程
	{
		myDeque.pop_back();                
		dequeIsFull.wakeAll();
	}
	else
	{
		dequeIsEmpty.wait(&consumerMutex);           //判断 如果队列中没有元素  阻塞生产者线程
	}
	consumerMutex.unlock();
}