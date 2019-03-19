#pragma once
#include "repo.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
template <class T>
class RepoM:public Repository<T> {
private:
	string numeFisier;
public:
	RepoM<T>(string nume);
	void saveToFile();
	void loadToFile();
	~RepoM();



};
template<class T>
inline RepoM<T>::RepoM(string nume)
{  //constructor
	this->numeFisier = nume;
	loadToFile();
}
template <class T>
void RepoM<T>::saveToFile()
{
	ofstream fout(numeFisier);
	for (unsigned i = 0; i < this->elem.size(); ++i)
		fout << this->getAll()[i].getNume()<<" "<< this->getAll()[i].getData() << " " << this->getAll()[i].getLocul() << " " << this->getAll()[i].getNrd()<< " " << this->getAll()[i].getNrv()<< endl;

	fout.close();
}
template<class T>
void RepoM<T>::loadToFile()
{
	ifstream fin(numeFisier);
	int nrv;
	char nume[30];
	char data[30];
	char locul[30];
	int nrd;
	// T el;
	//while (fin >> el)
	while (fin >> nume >> data>>locul>>nrd>>nrv)
	{
		//this->elem.push_back(el);
		if (validariMuzica(nume, data, locul, nrd, nrv) == 1)
			this->elem.push_back(Muzica(nume, data, locul, nrd, nrv));
		else
			cout << "Detaliile spectacolelor sunt incorect introduse";
	}
}


template<class T>
RepoM<T>::~RepoM()
{
	saveToFile();
}


