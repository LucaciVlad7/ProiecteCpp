#include "Teste.h"
#include "Produse.h"
#include <assert.h>
#include "Repo.h"
#include "Validator.h"
#include "Service.h"
#include <iostream>

void Teste::testAll() {
	Repo repo = Repo("teste.txt");
	Validator val = Validator();
	Service serv = Service(repo, val);
	assert(repo.exportProduseRepo().size() == 2);
	serv.adaugaServ(Produs(3, "a", "a", 6));
	assert(serv.exportSortat().size() == 3);
}