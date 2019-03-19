#pragma once
#include "Service.h"
class ui
{
private:
	Service service;
	void showMenu();
public:
	ui();
	void afiseaza(vector<Festival*> v);
	void run();
	~ui();
};

