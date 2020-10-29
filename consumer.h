#pragma once
#include "commonData.h"
class consumer : public QThread
{
public:
	void run();
	void get();
};

