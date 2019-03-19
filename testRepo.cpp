#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include "muzica.h"
#include "repo.h"
#include "repoM.h"
#include "validari.h"
#include "testRepo.h"
#include "filme.h"

using namespace std;

void testRepo() {

	Repository <Muzica> repo;
	Repository <Filme> repo2;
	Muzica c = Muzica("Antonia", "22.02.2018","Cluj", 10, 200);
	repo.addElem(c);
	Muzica p = Muzica("Inna", "11.03.2018","Sibiu", 6, 120);
	repo.addElem(p);
	assert(repo.getLungime() == 2);
	Filme f = Filme("TheLoft", "James", "22.05.2018", "cluj", 50, 25);
	repo2.addElem(f);
	assert(repo2.getLungime() == 1);
	//cout << repo.getLungime() << endl;
	cout << "asserts verified repo" << endl;
	
}