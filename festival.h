#pragma once
#include <iostream>
#include "validari.h"
#include <string>

using namespace std;

class Festival {
protected:
	string titlu;
	string data;
	string locul;
	int nrd;
	int nrv;
public:
	Festival();
	string getTitlu();
	string getLocul();
	string getData();
	int getNrd();
	int getNrv();
	void setTitlu(string t);
	void setLocul(string t);
	void setData(string t);
	void setNrd(int nrd);
	void setNrv(int nrv);
	virtual string toString() = 0;
	virtual Festival *operator->() {
		return this;
	}
	virtual Festival* readCSV(ifstream& in) = 0;
	~Festival();
};