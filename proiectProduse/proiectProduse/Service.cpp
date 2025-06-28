#include "Service.h"
#include <iostream>

Service::Service(Repo& repo, Validator& val) :
	repo{ repo }, val{ val } {
	listServ = repo.exportProduseRepo();
}

void Service::adaugaServ(const Produs& p) {
	val.valideaza(p);
	repo.adaugaRepo(p);
	listServ = repo.exportProduseRepo();
}

std::vector<Produs> Service::exportSortat() {
	listServ = repo.exportProduseRepo();
	std::sort(listServ.begin(), listServ.end(), [](const Produs& a, const Produs& b) {
		return a.getPret() < b.getPret();
		});
	return listServ;
}