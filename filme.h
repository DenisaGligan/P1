#pragma once
#include "festival.h"
#include <vector>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;

class Filme :public Festival
{
private:
	string actori;
public:
	Filme(const string titlu, string actori, string data, string locul, int nrd, int nrv);
	Filme();
	Filme(const Filme &c);
	Filme& operator=(const Filme &c);
	string getActori();
	void setActori(string t);
	Filme *operator->() {
		return this;
	};
	friend istream& operator>>(istream& is, Filme& c);
	Filme* readCSV(ifstream& in);
	friend ostream& operator<<(ostream& os, Filme &c);
	string toString();
	~Filme();

};
