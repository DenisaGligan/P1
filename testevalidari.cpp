#include "stdafx.h"
#include <assert.h>
#include "validari.h"
#include "testevalidari.h"
#include <iostream>
using namespace std;

void testvalidariMuzica()
{
	assert(validariMuzica("Riles", "22.23.2018", "cluj", 3, 4) == 1);
	cout << "test validari muzica "<<endl;
}
void testvalidariFilme()
{
	int a= validariFilme("The Loft", "James", "22.02.2018", "Cluj", 10, 200);
	assert(a == 1);
	cout << "teste validari filme"<<endl;

}