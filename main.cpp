#include <QtCore/QCoreApplication>
#include "commonData.h"
#include "producer.h"
#include "consumer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


	producer *p1;
	producer *p2;
	producer *p3;                      //���������߶���
	producer *p4;
	producer *p5;

	consumer *c1;                       // ���������߶���
	consumer *c2;

	p1 = new producer();
	p2 = new producer();
	p3 = new producer();                 //Ϊ�����߶����ڶ��������ڴ�ռ�
	p4 = new producer();
	p5 = new producer();

	c1 = new consumer();                 //Ϊ�����߶����ڶ��������ڴ�ռ�
	c2 = new consumer();

	std::vector<producer*> v;            //�����߶����vector���� ����ʼ��
	std::vector<consumer*> c;                     //�����߶����vector���� ����ʼ��

	std::vector<producer*>::iterator itv = v.begin();                 //�����ߵ����� ָ��������������һ������
	std::vector<consumer*>::iterator itc = c.begin();                 //�����ߵ����� ָ��������������һ������

	for (itv; itv != v.end(); itv++)
	{
		(*itv)->start();
	}
	for (itc; itc != c.end(); itc++)
	{
		(*itc)->start();
	}
	for (int i = 0; i < 5; i++)
	{
		v[i]->wait();
	}
	for (int i = 0; i < 2; i++)
	{
		c[i]->wait();
	}

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete c1;
	delete c2;



    return a.exec();
}
