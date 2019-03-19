#pragma once
#include "muzica.h"
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Repository
{
protected:
	vector <T> elem;
public:

	void addElem(const T &st);
	vector <T> getAll();
	T get(int poz);
	int getLungime();
	void delElem(int poz);

};
template <class T>
T Repository<T>::get(int poz)
{
	return elem[poz];
}

template <class T>
void Repository<T>::addElem(const T &st)
{
	elem.push_back(st);
	
}
template <class T>

vector <T> Repository<T>::getAll()
{
	return this->elem;
}
template <class T>
int Repository<T>::getLungime()
{
	
	return this->elem.size();
}
template <class T>
void Repository<T>::delElem(int poz)
{
	
	this->elem.erase(this->elem.begin() + poz);
}