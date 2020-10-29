#ifndef COMMONDATA_H
#define COMMONDATA_H
#include <deque>
#include <QMutex>
#include <QWaitCondition>
#include <QThread>
#include <iostream>
#include <vector>

#define SIZE 1000
std::deque<int> myDeque(SIZE);
QMutex consumerMutex;
QMutex producerMutex;
QWaitCondition dequeIsFull;
QWaitCondition dequeIsEmpty;


#endif COMMONDATA_H

