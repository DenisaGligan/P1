#pragma once
#include <iostream>
#include "festival.h"
#include <fstream>
#include <istream>
#include <sstream>

using namespace std;

class Muzica:public Festival 
{
public:
	Muzica(const string nume, string data,string locul, int nrd, int nrv);
	Muzica();
	Muzica(const Muzica &c);
	Muzica& operator=(const Muzica &c);
	Muzica *operator->() {
		return this;
	};
	friend istream& operator>>(istream& is, Muzica& c);
	friend ostream& operator<<(ostream& os, Muzica& c);
	Muzica* readCSV(ifstream& in);
	~Muzica();
	string toString();

};	

