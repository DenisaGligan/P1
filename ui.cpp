#include "stdafx.h"
#include "ui.h"
#include <iostream>
#include <string.h>

void ui::showMenu()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "   MENIU" << endl;
	cout << "0. Logout" << endl;
	//cout << "1. Cautare Concert" << endl;
	//cout << "2. Cautare Film" << endl;

}
ui::~ui()
{
}
void ui::afiseaza(vector<Festival*> v) {
	//Afiseaza elementele unul vector de adrese
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->toString() << endl;
	}
}
void ui::run()
{
	while (true)
	{
		int op;
		char user[30], parola[30];
		cout << "1.Logare " << endl;
		cout << "0.Inchidere aplicatie" << endl;
		cout << "Alege optiunea: ";
		cin >> op;
		switch (op)
		{
		case 0:
			return;
			break;
		case 1:
			cout << "Username: "; cin >> user; cout << endl;
			cout << "Parola: "; cin >> parola; cout << endl;
			if (service.logare(user, parola) == 0)
				cout << "Username sau parola incorecta" << endl;
			else
			{
				int ok = 1;
				while (ok == 1)
				{
					int opt;
					string artist;
					string data;
					//service.afisareF();
					//cout << endl;
					////cout << endl;
					//service.afisareM();
					afiseaza(service.fest.getAll());
					showMenu();
					cout << "Optiunea aleasa este: ";
					cin >> opt;
					switch (opt)
					{
					case 0:
						ok = 0;
						cout << "Te-ai delogat cu succes" << endl;
						break;
					case 1:
						cout << "Numele artisutului: "; cin >> artist;
						cout << "Data Spectacolului: "; cin >> data;
						if (service.cautareM(artist, data) == 0)
						{
							cout << "Nu exista concert conform datelor introduse. " << endl;
							cout << endl;
							cout << endl;
						}
						else
						{
							int op1;
							cout << "1.Cumpara bilet " << endl;
							cout << "2.Nu cumpar bilet" << endl;
							cout << "Alege optiunea: "; cin >> op1;
							if (op1 ==2)
							{
								cout << endl;
						
							}
							else
							{
								service.cumparareM(artist, data);
							}
						}
						break;
					case 2:
						cout << "Numele Filmului: "; cin >> artist;
						cout << "Data Spectacolului: "; cin >> data;
						if (service.cautareF(artist, data) == 0)
						{
							cout << "Nu exista film conform datelor introduse" << endl;
							cout << endl;
							cout << endl;
						}
						else
						{
							int op1;
							cout << "1.Cumpara bilet " << endl;
							cout << "2.Nu cumpar bilet" << endl;
							cout << "Alege optiunea: "; cin >> op1;
							if (op1 == 2)
							{
								cout << endl;
							}
							else
							{
								service.cumparareF(artist, data);
							}

						}


						break;

					default:
						cout << "Optiune invalida";
						break;
					}
				}

			}
			break;
		default:
			cout << "optiune invalida" << endl;
			break;
		}

	}
	//service.afisareF();
	//service.afisareM();
}
