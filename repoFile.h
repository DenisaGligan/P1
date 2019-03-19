#pragma once
#include "repoFestival.h"
#include "muzica.h"
#include "filme.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

class RepoFile :public Repo
{
private:
	ifstream  in;
	ofstream of;
	string fileName;
public:

	RepoFile() :Repo() { };
	RepoFile(const string fileName) {
		//Constructor cu paramentrii
		//In: numele fisierului
		//Out:-

		this->fileName = fileName;
		in.open(fileName);
		if (!in) {
			cerr << "Error in opening the file" << endl;
		}

	}
	void setFile(string fileName) {
		//Seteaza numele fisierului, desch. fisier
		//In:numele fisierului
		//Out:-
		this->fileName = fileName;
		in.close();
		in.open(fileName);
		if (!in) {
			cerr << "Error in opening the file" << endl;
		}

	}

	//Destructor, inc. fisier
	~RepoFile() {
		in.close();
		of.close();
	}
	void addElementArtisti() {
		//Adauga elemente din fisier
		//In:-
		//Out:-

		while (!in.eof()) {
			Festival* el = new Muzica();
			addElem(el->readCSV(in));
		}
	}
	void addElementFilme() {
		//Adauga elemente din fisier
		//In:-
		//Out:-
		while (!in.eof()) {
			Festival* el = new Filme();
			addElem(el->readCSV(in));
		}
	}
	void writeToFileC()
	{//Scrie in fisier CSV
		std::ofstream f("rez.csv");

		if (f.is_open() == false)
			throw ("Could not be opened");
		string s = "";
		for (auto elem : this->elem) {
			s = elem->getTitlu() + ";" + elem->getData() + ";"   + elem->getLocul() + ";" + to_string(elem->getNrd()) + ";" + to_string(elem->getNrv()) + "\n";
			f << s;
		}
		f.close();
	}

};

