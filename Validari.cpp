#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "muzica.h"
#include "stdafx.h"
#include "validari.h"
using namespace std;
int validariMuzica(const string n, string d, string l, int nd, int nv)
{
	
	for (int i = 0; i < n.size(); i++)
		if ((n[i] >= 65 && n[i] <= 90) || (n[i] >= 97 && n[i] <= 123)|| n[i] == ' ')
			;
		else
			return 0;
	
			
	for (int i = 0; i < l.size(); i++)
		if ((l[i] >= 65 && l[i] <= 90) || (l[i] >= 97 && l[i] <= 123) || l[i] == ' ')
			;
		else
			return 0;
			
	
	for (int i = 0; i < d.size(); i++)
		if (d[i] > 57 || d[i] < 48 || d[i] != '.')
			;
		else
			return 0;
	return 1;

}
int validariFilme(const string  n, string a, string d, string l, int nd, int nv)
{
	int ok = 1;
	for (int i = 0; i < n.size(); i++)
		if ((n[i] >= 65 && n[i] <= 90) || (n[i] >= 97 && n[i] <= 123) || n[i] == ' '||n[i]=='-')
			;
		else
			return 0;
	
	for (int i = 0; i < l.size(); i++)
		if ((l[i] >= 65 && l[i] <= 90) || (l[i] >= 97 && l[i] <= 123) || l[i] == ' '||l[i] == '-')
			;
		else
			return 0;
	
	for (int i = 0; i < a.size(); i++)
		if ((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 123) || a[i] == ' '||a[i] == '-')
			;
		else
			return 0;
	
	for (int i = 0; i < d.size(); i++)
		if (d[i] > 57 || d[i] < 49 || d[i] != '.')
			;
		else
			return 0;
	//cout << ok;
	return 1;

}