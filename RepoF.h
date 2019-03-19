#pragma once
#include "repo.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "validari.h"

using namespace std;

template <class T>
class RepoF :public Repository<T> {
private:
	string numeFisier;
public:
	RepoF<T>(string nume);
	void saveToFile();
	void loadToFile();
	~RepoF();

};
template<class T>
inline RepoF<T>::RepoF(string nume)
{  //constructor
	this->numeFisier = nume;
	loadToFile();
}
template <class T>
void RepoF<T>::saveToFile()
{
	ofstream fout(numeFisier);
	for (unsigned i = 0; i < this->elem.size(); ++i)
		fout << this->getAll()[i].getTitlu() << " " <<this->getAll()[i].getActori()<<" "<<this->getAll()[i].getData() << " " << this->getAll()[i].getLocul() << " " << this->getAll()[i].getNrd() << " " << this->getAll()[i].getNrv() << endl;

	fout.close();
}
template<class T>
void RepoF<T>::loadToFile()
{
	ifstream fin(numeFisier);
	int nrv;
	char nume[30];
	char data[30];
	char locul[30];
	char actori[30];
	int nrd;
	// T el;
	//while (fin >> el)
	while (fin >> nume >>actori>> data >> locul >> nrd >> nrv)
	{
		//this->elem.push_back(el);
		if (validariFilme(nume, actori, data, locul, nrd, nrv) == 1)
			this->elem.push_back(Filme(nume, actori, data, locul, nrd, nrv));
		else
			cout << "Detaliile Filmelor sunt incorect introduse" << endl;
	}
}

template<class T>
RepoF<T>::~RepoF()
{
	saveToFile();
}