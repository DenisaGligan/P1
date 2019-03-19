#pragma once
#include "repoM.h"
#include "muzica.h"
#include "repoF.h"
#include "filme.h"
#include "repoFile.h"
#include "festival.h"
class Service
{
public:
	//RepoM<Muzica> &repom;
	//RepoF<Filme> &repof;
	RepoFile  fest;
public:
	Service();
	void readCSV();
	//vector <Muzica> getAll();
	vector<Festival*> gasesteData(string data);
	bool vanzare(string nume, int nrLoc);
	int gasesteNume(string nume);
	//void afisareM();
	//void afisareF();
	int logare(const string n,string p);
	//int cautareM(const char* n, const char* p);
	//void cumparareM(const char* n, const char* p);
	//int cautareF(const char* n, const char* p);
	//void cumparareF(const char* n, const char* p);
	
	~Service();
};

