#include "consumer.h"

void consumer::run() 
{
	get();                       //��дrun��������get()������
	std::cout << "����һ���������߳�" << std::endl;
}

void consumer::get()
{
	consumerMutex.lock();
	if (myDeque.size() > 0)                          //�ж� ���������Ԫ�ش���0 ��β��ɾ��һ��Ԫ�� ���ѱ������������߽���
	{
		myDeque.pop_back();                
		dequeIsFull.wakeAll();
	}
	else
	{
		dequeIsEmpty.wait(&consumerMutex);           //�ж� ���������û��Ԫ��  �����������߳�
	}
	consumerMutex.unlock();
}