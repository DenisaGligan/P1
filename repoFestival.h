#pragma once
#include <vector>
#include "festival.h"

using namespace std;

class Repo
{
public:
	vector<Festival*> elem;
public:
	void addElem(Festival* el)
	{
		this->elem.push_back(el);
	}
	Repo(){
	}
	vector<Festival*> getAll()
	{
		return this->elem;
	}
	void delElem(int poz)
	{
		this->elem.erase(this->elem.begin() + poz);
	}
	~Repo() {
		//destructor
		this->elem.~vector();
	}

};
