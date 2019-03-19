#include "stdafx.h"
#include <string.h>
#include "muzica.h"
#include <iostream>
using namespace std;

Muzica::Muzica(const string n, string d , string l,int nd,int nv) {
	this->titlu = n;
	this->locul = l;
	this->data = d;
	this->nrd = nd;
	this->nrv = nv;
}
Muzica::Muzica()
{
	this->titlu = "";
	this->locul = "";
	this->data = "";
	this->nrd = 0;
	this->nrv = 0;
}

Muzica& Muzica::operator=(const Muzica &c) {
	this->data = c.data;
	this->nrd = c.nrd;
	this->nrv = c.nrv;
	this->titlu = c.titlu;
	this->locul = c.locul;
	return *this;
}
Muzica::Muzica(const Muzica &c) {
	this->data = c.data;
	this->nrd = c.nrd;
	this->nrv = c.nrv;
	this->titlu = c.titlu;
	this->locul = c.locul;
}
 
Muzica::~Muzica()
{

}

istream& operator>>(istream& is, Muzica& c) {
	//Operator >>
	is >> c.titlu >> c.data >> c.locul >> c.nrd >> c.nrv;
	return is;
}
ostream& operator<<(ostream& os, Muzica& c) {
	//Operator<<
	os << c.titlu << "," << c.data<< c.locul << "," << c.nrd << "," << c.nrv << ",";
	return os;
}
Muzica* Muzica::readCSV(ifstream& in) {
	//Citeste obiectul dintr-un fisier CSv
	//In:fisierul
	//Out:adresa
	getline(in, titlu, ',');
	getline(in, data, ',');
	getline(in, locul, ',');
	string d;
	getline(in, d, ',');
	this->nrd = atoi(d.c_str());
	string e;
	getline(in, e, '\n');
	this->nrv = atoi(e.c_str());
	validariMuzica(titlu, data, locul, nrd, nrv);
	return this;
}
string Muzica::toString() {
	//Obiectul transformat intr-un sir de caractere
	string s = titlu + " " + data + " " + locul + " " + to_string(nrd) + " " + to_string(nrv) + "; ";

	return s;
}
/*istream & operator >>(istream & is, Muzica &art)
{
	char* numes[30];
	is >> numes;
	art.nume = new char[strlen(numes) + 1];
	strcpy(art.numeArtist, nume);
	is >> art.dataSpectacol >> art.locSpectacol >> art.nrLocDisponibile >> art.nrLocVandute;
	return is;
}*/



