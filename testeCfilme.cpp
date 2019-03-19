#include "stdafx.h"
#include "filme.h"
#include <assert.h>
#include <iostream>
#include "testeCfilme.h"
#include "string.h"

using namespace std;

void testFilme() {
	Filme c = Filme("Lord of the Rings","Brad Pitt", "Cluj", "22.02.2018", 10, 200);
	Filme z = Filme("Titanic","Leonardo DiCaprio, Kate Winslet", "Bucuresti", "11.03.2018", 6, 120);

	//assert(strcmp(c.getActori(), "Brad Pitt") == 0);
	assert(c.getNrv() == 200);
	c.setNrd(3);
	assert(c.getNrd() == 3);
	c.setNrv(123);
	assert(c.getNrv() == 123);
	c.setData("11.01.2019");
	//assert(strcmp(c.getData(), "11.01.2019") == 0);
	c.setTitlu("AAA");
	//assert(strcmp(c.getTitlu(), "AAA") == 0);
	c.setLocul("Sibiu");
	assert(c.getLocul()== "Sibiu");
	c.setActori("MMMM, BBBB");
	//(strcmp(c.getActori(), "MMMM, BBBB") == 0);

	Filme p = Filme();
	assert(p.getTitlu() == "");
	assert(p.getNrv() == 0);
	assert(p.getNrd() == 0);
	assert(p.getData() == "");
	assert(p.getLocul() == "");
	assert(p.getActori() == "");


	cout << "asserts verified clasa Filme" << endl;
}