// lab 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "testCmuzica.h"
#include "testeCfilme.h"
#include "testRepo.h"
#include "repoM.h"
#include "testevalidari.h"
#include "Service.h"
#include "ui.h"


int main()
{
	testMuzica();
	testFilme();
	testRepo();
	testvalidariMuzica();
	testvalidariFilme();
	RepoM <Muzica> repom("m.txt");
	RepoF <Filme> repof("f.txt");
	Service service(repom,repof);
	ui ui(service);
	ui.run();

    return 0;
}

