#pragma once
#include "commonData.h"
class producer : public QThread
{
public:
	void run();
	void put();
};

