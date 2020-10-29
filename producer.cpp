#include "producer.h"

void producer::run() 
{
	put();                      //重写run方法调用put函数
	std::cout << "创建一个消费者线程" << std::endl;
}

void producer::put()
{
	producerMutex.lock();
	if (myDeque.size() >= SIZE)                         //判断 如果队列满了 阻塞 
	{
		dequeIsFull.wait(&producerMutex);
	}
	else 
	{
		myDeque.push_front(1);
		dequeIsEmpty.wakeAll();                         //向队列头插入一个“1” ，唤醒被阻塞的消费者线程
	}
	producerMutex.unlock();
}