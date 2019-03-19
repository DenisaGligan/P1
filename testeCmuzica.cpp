#include "stdafx.h"
#include "muzica.h"
#include <assert.h>
#include <iostream>
#include "testCmuzica.h"
#include "string.h"
#include "festival.h"

using namespace std;

void testMuzica() {
	Muzica c = Muzica("Riles", "22.02.2018","cluj",10,200);
	Muzica z = Muzica("Rihanna", "11.03.2018","Bucuresti", 6, 120);

	assert(c.getTitlu()=="Riles");
	assert(c.getNrd() == 10);
	c.setNrd(2);
	assert(c.getNrd() == 2);
	c.setNrv(123);
	assert(c.getNrv() == 123);
	c.setData("11.01.2019");
	assert(c.getData()== "11.01.2019");
	c.setTitlu("Delia");
	assert(c.getTitlu() == "Delia");
	c.setLocul("Sibiu");
	//assert(strcmp(c.getLocul(), "Sibiu") == 0);
	
	Muzica p = Muzica();
	assert(p.getTitlu() =="");
	assert(p.getNrv() == 0);
	assert(p.getNrd() == 0);
	//assert(p.getData() == 0);
	//assert(p.getLocul() == 0);
	
	cout << "asserts verified clasa Muzica" << endl;
}