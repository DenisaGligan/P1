#include <iostream>
#include "stdafx.h"
#include <string.h>
#include "filme.h"
using namespace std;

Filme::Filme(const string n, string a, string d, string l, int nd, int nv) {
	this->titlu = n;
	this->locul = l;
	this->actori = a;
	this->data = d;
	this->nrd = nd;
	this->nrv = nv;
}
Filme::Filme()
{
	this->titlu = "";
	this->actori = "";
	this->locul = "";
	this->data = "";
	this->nrd = 0;
	this->nrv = 0;
}

Filme& Filme::operator=(const Filme &c) {
	this->titlu = c.titlu;
	this->locul = c.locul;
	this->actori = c.actori;
	this->data = c.data;
	this->nrd = c.nrd;
	this->nrv = c.nrv;
	return *this;
}
Filme::Filme(const Filme &c) {
	this->titlu = c.titlu;
	this->locul = c.locul;
	this->actori = c.actori;
	this->data = c.data;
	this->nrd = c.nrd;
	this->nrv = c.nrv;
}

string Filme::getActori()
{
	return this->actori;
}

void Filme::setActori(string t) {
	this->actori = t;
}
Filme::~Filme()
{
}

string Filme::toString() {
	//Transforma obiectul in string
	string s = titlu + " " + actori + " " + data + "; " + locul + " " + to_string(nrd) + " " + to_string(nrv) + "; ";
	return s;
}
istream& operator>>(istream& is, Filme& c) {

	//Suprascriere operator de intrare
	is >> c.titlu >> c.actori>> c.data >> c.locul >> c.nrd >> c.nrv;
	return is;
}
ostream& operator<<(ostream& os, Filme& c) {
	//Operator<<
	os << c.titlu << "," << c.actori << "," << c.data << "," << c.locul << "," << c.nrd << "," << c.nrv << ",";
	return os;
}

Filme* Filme::readCSV(ifstream& in) 
{
	getline(in, titlu, ',');
	getline(in, actori, ',');
	getline(in, data, ',');
	getline(in, locul, ',');
	string d;
	getline(in, d, ',');
	this->nrd = atoi(d.c_str());
	string e;
	getline(in, e, '\n');
	this->nrv = atoi(e.c_str());
	validariFilme(titlu,actori, data, locul, nrd, nrv);
	return this;
}

