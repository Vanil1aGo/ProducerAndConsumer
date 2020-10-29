#include <QtCore/QCoreApplication>
#include "commonData.h"
#include "producer.h"
#include "consumer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


	producer *p1;
	producer *p2;
	producer *p3;                      //创建生产者对象
	producer *p4;
	producer *p5;

	consumer *c1;                       // 创建消费者对象
	consumer *c2;

	p1 = new producer();
	p2 = new producer();
	p3 = new producer();                 //为生产者对象在堆上申请内存空间
	p4 = new producer();
	p5 = new producer();

	c1 = new consumer();                 //为消费者对象在堆上申请内存空间
	c2 = new consumer();

	std::vector<producer*> v;            //生产者对象的vector容器 并初始化
	std::vector<consumer*> c;                     //消费者对象的vector容器 并初始化

	std::vector<producer*>::iterator itv = v.begin();                 //生产者迭代器 指向生产者容器第一个对象
	std::vector<consumer*>::iterator itc = c.begin();                 //消费者迭代器 指向消费者容器第一个对象

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
