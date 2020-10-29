#include "producer.h"

void producer::run() 
{
	put();                      //��дrun��������put����
	std::cout << "����һ���������߳�" << std::endl;
}

void producer::put()
{
	producerMutex.lock();
	if (myDeque.size() >= SIZE)                         //�ж� ����������� ���� 
	{
		dequeIsFull.wait(&producerMutex);
	}
	else 
	{
		myDeque.push_front(1);
		dequeIsEmpty.wakeAll();                         //�����ͷ����һ����1�� �����ѱ��������������߳�
	}
	producerMutex.unlock();
}