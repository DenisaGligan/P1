#include "stdafx.h"
#include "Service.h"
#include <iostream>
#include <string.h>
#include "muzica.h"


/*vector <Muzica> Service::getAll() {
	//repom.loadToFile();
	return this->repom.getAll();
}*/
Service::Service()
{
	fest.setFile("dateA.csv");
}
void Service::readCSV()
{
	fest.setFile("dateA.csv");
	fest.addElementArtisti();
	fest.setFile("dateF.csv");
	fest.addElementFilme();
}
vector<Festival*> Service::gasesteData(string data)
{
	vector<Festival*> rez;
	for (int i = 0; i < fest.getAll().size(); i++) {
		if (fest.getAll()[i]->getData()==data) {
			rez.push_back(fest.getAll()[i]);
		}
	}
	return rez;
}

int Service::gasesteNume(string nume)
{
	for (int i = 0; i < fest.getAll().size(); i++) {
		if (fest.getAll()[i]->getTitlu() == nume) {
			return i;
		}
	}
	return -1;
} 

bool Service::vanzare(string nume, int nrLoc)
{
	int j = gasesteNume(nume);
	if (j < 0)
		return false;
	if (fest.elem[j]->getNrd() >= nrLoc) {
		int d = fest.elem[j]->getNrd();
		int v = fest.elem[j]->getNrv();
		fest.elem[j]->setNrd(d - nrLoc);
		fest.elem[j]->setNrv(v + nrLoc);
		return true;
	}
	return false;
}
/*
void Service::afisareM()
{
	if (repom.getLungime() == 0)
	{
		cout << "Nu sunt concerte disponibile" << endl;
	}
	else
	{
			cout << "Lista Concerte" << endl;
		for (int i = 0; i < repom.getLungime(); i++)
			cout << "Artistul este: " << repom.getAll()[i].getNume() << " in data de: " << repom.getAll()[i].getData()<< " locatia: " << repom.getAll()[i].getLocul() <<" numar locuri disponibile: "<<repom.getAll()[i].getNrd()<< " bilete vandute: "<<repom.getAll()[i].getNrv() <<endl;
	}
}
void Service::afisareF()
{
	if (repof.getLungime() == 0)
	{
		cout << "Nu sunt filme disponibile" << endl;
	}
	else
	{
		cout << "Lista Filme" << endl;
		for (int i = 0; i < repof.getLungime(); i++)
			cout << "Filmul este: " << repof.getAll()[i].getTitlu() <<" actorii: "<<repof.getAll()[i].getActori()<<" in data de: " << repof.getAll()[i].getData() << " locatia: " << repof.getAll()[i].getLocul() << " numar locuri totale: " << repof.getAll()[i].getNrd() << " bilete vandute: " << repof.getAll()[i].getNrv() << endl;
	}

}*/
int Service::logare(const string n, string p)
{
	//repom.addElem(Muzica("Inna", "22.02.2018", "cluj", 200, 30));
	
	int ok1 = 0; int ok2 = 0;
	string user;
	string parola;
	ifstream uin("users.txt");

	while (uin >> user >> parola)
	{
		if (user== n)
			ok1 = 1;
		if (parola== p)
			ok2 = 1;
		if (ok1 == 1 && ok2 == 1)
			return 1;
	}
	return 0;
	uin.close();
}
/*
int Service::cautareM(const char*n, const char* p)
{
	int ok = 0;
	for (int i = 0; i < repom.getLungime(); i++)
	{
		if (strcmp(repom.getAll()[i].getNume(), n) == 0 && strcmp(repom.getAll()[i].getData(), p) == 0)
		{
			cout << "Artistul este: " << repom.getAll()[i].getNume() << " in data de " << repom.getAll()[i].getData() << " locatia " << repom.getAll()[i].getLocul() << " numar locuri disponibile " << repom.getAll()[i].getNrd() << " bilete vandute " << repom.getAll()[i].getNrv() << endl;

			ok = 1;
			break;
		}
	}
	if (ok == 1)
		return 1;
	else
		return 0;
}
void Service::cumparareM(const char* n, const char* p)
{
	int nr, c;
	char nume[30];
	cout << "Numele cumparatorului este: "; cin >> nume;
	int ok = 1;
	for (int i = 0; i < repom.getLungime(); i++)
	{
		if (strcmp(repom.getAll()[i].getNume(), n) == 0 && strcmp(repom.getAll()[i].getData(), p) == 0)
			c = i;
	}
		if (ok ==1)
		{
			cout << "Numar de locuri dorite: ";
			cin >> nr;
			if (nr > repom.getAll()[c].getNrd()- repom.getAll()[c].getNrv())
				cout << "Nu sunt sufiecinte bilete disponibile" << endl;
			else
				ok = 0;
		}
		if (ok==0)
		{
			Muzica obj = repom.getAll()[c];
			obj.setNrv(repom.getAll()[c].getNrv() + nr);
			obj.setNrd(repom.getAll()[c].getNrd() - nr);
			repom.delElem(c);
			repom.addElem(obj);

			cout << nume << " a achizitionat un nr de " << nr << " bilete la concertul lui " << n << " mai sunt disponibile " << repom.getAll()[c].getNrd() << endl;
			cout << endl;
			cout << endl;
		}
		
}
void Service::cumparareF(const char* n, const char* p)
{
	int nr, c;
	char nume[30];
	cout << "Numele cumparatorului este: "; cin >> nume;
	int ok = 1;
	for (int i = 0; i < repof.getLungime(); i++)
	{
		if (strcmp(repof.getAll()[i].getTitlu(), n) == 0 && strcmp(repof.getAll()[i].getData(), p) == 0)
			c = i;
	}
	if (ok == 1)
	{
		cout << "Numar de locuri dorite: ";
		cin >> nr;
		if (nr > repof.getAll()[c].getNrd() - repof.getAll()[c].getNrv())
			cout << "Nu sunt sufiecinte bilete disponibile" << endl;
		else
			ok = 0;
	}
	
	if (ok == 0)
	{
		Filme obj = repof.getAll()[c];
		obj.setNrv(repof.getAll()[c].getNrv() + nr);
		obj.setNrd(repof.getAll()[c].getNrd() - nr);
		repof.delElem(c);
		repof.addElem(obj);

		cout << nume << " a achizitionat un nr de " << nr << " bilete la filmul " << n << " mai sunt disponibile " << repof.getAll()[c].getNrd() << endl;
		cout << endl;
		cout << endl;
	}

}
int Service::cautareF(const char*n, const char* p)
{
	int ok = 0;
	for (int i = 0; i < repof.getLungime(); i++)
	{
		if (strcmp(repof.getAll()[i].getTitlu(), n) == 0 && strcmp(repof.getAll()[i].getData(), p) == 0)
		{
			cout << "Titlul este: " << repof.getAll()[i].getTitlu()<<" Actori: "<<repof.getAll()[i].getActori()<< " in data de " << repof.getAll()[i].getData() << " locatia " << repof.getAll()[i].getLocul() << " numar locuri totale " << repof.getAll()[i].getNrd() << " bilete vandute " << repof.getAll()[i].getNrv() << endl;

			ok = 1;
			break;
		}
	}
	if (ok == 1)
		return 1;
	else
		return 0;
}
*/
Service::~Service()
{
}
