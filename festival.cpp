#include "stdafx.h"
#include "festival.h"

Festival::Festival()
{
}
string Festival::getData()
{
	return this->data;
}
string Festival::getLocul()
{
	return this->locul;
}
int Festival::getNrd()
{
	return this->nrd;
}
int Festival::getNrv()
{
	return this->nrv;
}
string Festival::getTitlu()
{
	return this->titlu;
}

void Festival::setData(string t)
{
	this->data = t;
}
void Festival::setNrd(int nd)
{
	this->nrd = nd;
}
void Festival::setNrv(int nv)
{
	this->nrv = nv;
}
void Festival::setTitlu(const string t) {
	this->titlu = t;
}
void Festival::setLocul(string t) {
	this->locul = t;
}

Festival::~Festival()
{
}