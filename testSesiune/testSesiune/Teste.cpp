#include "Teste.h"
#include "Melodii.h"
#include <assert.h>
#include "Repo.h"
#include "Service.h"
#include <iostream>

void teste_dom() {
	Melodie m1 = Melodie(1, "titlu", "artist", 5);
	assert(m1.getId() == 1);
	assert(m1.getTitlu() == "titlu");
	assert(m1.getArtist() == "artist");
	assert(m1.getRank() == 5);
}

void teste_repo() {
	Repo repo = Repo("teste.txt");
	std::vector<Melodie> lis = repo.getAllMelodii();
	assert(lis.size() == 5);
	repo.stergeRepo(5);
	std::vector<Melodie> lis1 = repo.getAllMelodii();
	assert(lis1.size() == 4);

	repo.modificaRank(1, 100);
	std::vector<Melodie> l = repo.getAllMelodii();
	assert(l[0].getRank() == 100);
	repo.modificaTitlu(1, "titluNou");
}

void teste_service() {
	Repo repo = Repo("teste.txt");
	Service serv = Service(repo);
	std::vector<Melodie> listaS = serv.sortareRank();
	assert(listaS[0].getRank() == 3);
	assert(serv.melodiiCuAcelasiRank(3) == 2);
}

void Teste::testeAll() {
	teste_dom();
	teste_repo();
	teste_service();
}