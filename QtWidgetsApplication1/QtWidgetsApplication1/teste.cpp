#include "teste.h"
#include "repository.h"
#include <assert.h>
#include "filerepository.h"
#include "validator.h"
#include "service.h"
#include "serviceLista.h"
#include <algorithm>

void testeDomeniu() {

	Locatar locatar1(1, "propr1", 1, "tip1");

	assert(locatar1.getApartament() == 1);
	assert(locatar1.getProprietar() == "propr1");
	assert(locatar1.getSuprafata() == 1);
	assert(locatar1.getTip() == "tip1");

	Locatar locatar2(locatar1);

	assert(locatar2.getApartament() == 1);
	assert(locatar2.getProprietar() == "propr1");
	assert(locatar2.getSuprafata() == 1);
	assert(locatar2.getTip() == "tip1");

	Locatar locatar3(0, "", 0, "");
	locatar3 = locatar2;

	locatar3.setApartament(3);
	locatar3.setProprietar("propr3");
	locatar3.setSuprafata(3);
	locatar3.setTip("tip3");

	assert(locatar3.getApartament() == 3);
	assert(locatar3.getProprietar() == "propr3");
	assert(locatar3.getSuprafata() == 3);
	assert(locatar3.getTip() == "tip3");
}

void testeRepo() {
	Repository<Locatar> repo;
	assert(repo.repoGetSize() == 0);

	Locatar locatar1(1, "propr1", 1, "tip1");
	repo.repoAdaugaElem(locatar1);
	assert(repo.repoGetSize() == 1);

	try {
		repo.repoAdaugaElem(locatar1);
		assert(false);
	}
	catch (const RepoError& error) {
		assert(error.getMessage() == "Deja exsta un locatar care locuieste la apartamentul: 1!\n");
	}
	assert(repo.repoCautaElem(1) == locatar1);

	try {
		repo.repoCautaElem(2);
		assert(false);
	}
	catch (const RepoError& error) {
		assert(error.getMessage() == "Nu exista locatarul cautat, apartamentul 2!\n");
	}

	Locatar locatar2(1, "propr2", 2, "tip2");
	repo.repoModifica(locatar2);
	assert(repo.repoCautaElem(1) == locatar2);
	Locatar locatar3(3, "propr3", 3, "tip3");
	try {
		repo.repoModifica(locatar3);
		assert(false);
	}
	catch (const RepoError& error) {
		assert(error.getMessage() == "Nu exista locatarul cautat, apartamentul: 3!\n");
	}
	repo.repoStergeElem(1);
	assert(repo.repoGetSize() == 0);

	try {
		repo.repoStergeElem(2);
		assert(false);
	}
	catch (const RepoError& error) {
		assert(error.getMessage() == "Nu exista locatarul cautat, apartamentul 2!\n");
	}
}

void testeFileRepo() {
	string testFile = "test.txt";
	remove(testFile.c_str());

	FileRepository<Locatar> repo{ testFile };
	assert(repo.repoGetAllElems().empty());

	Locatar locatar1(1, "propr1", 1, "tip1");
	repo.repoAdaugaElem(locatar1);
	assert(repo.repoGetAllElems().size() == 1);

	Locatar locatar2(2, "propr2", 2, "tip2");
	repo.repoAdaugaElem(locatar2);
	assert(repo.repoGetAllElems().size() == 2);

	Locatar locatar3(2, "propr3", 3, "tip3");
	repo.repoModifica(locatar3);

	Locatar gasit = repo.repoCautaElem(2);
	assert(gasit.getProprietar() == "propr3");

	repo.repoStergeElem(2);
	assert(repo.repoGetAllElems().size() == 1);

	vector<Locatar> lista = {
		Locatar{3,"pr3",3,"t3"},
		Locatar{4,"pr4",4,"t4"}
	};
	repo.repoSetAllElems(lista);
	assert(repo.repoGetAllElems().size() == 2);
	remove(testFile.c_str());
}

void testeValidator() {
	Locatar locatar1(1, "p1", 1, "t1");
	try {
		Validator::valideazaLocatari(locatar1);
		assert(true);
	}
	catch (const ValidationError& error) {
		assert(false);
	}

	Locatar locatar2(0, "", 0, "");
	try {
		Validator::valideazaLocatari(locatar2);
		assert(false);
	}
	catch (const ValidationError& error) {
		assert(error.getMessage() == "Numarul apartamentului invalid\n"
			"Numele proprietarului nu poate fi vid\n"
			"Suprafata trebuie sa fie numar pozitiv\n"
			"Tipul nu poate fi vid\n");
	}

}

void testeService() {
	Repository<Locatar> repo;
	Service service{ repo };
	Locatar locatar1(1, "pr1", 1, "tip1");

	service.serviceAdaugaLocatar(locatar1);
	assert(service.serviceGetAllLocatari().size() == 1);

	Locatar locatar0(0, "", 0, "");
	try {
		service.serviceAdaugaLocatar(locatar0);
		assert(false);
	}
	catch (const ValidationError& error) {
		assert(error.getMessage() == "Numarul apartamentului invalid\n"
			"Numele proprietarului nu poate fi vid\n"
			"Suprafata trebuie sa fie numar pozitiv\n"
			"Tipul nu poate fi vid\n");
	}

	Locatar locatar2(1, "pr2", 2, "t2");
	try {
		service.serviceAdaugaLocatar(locatar2);
		assert(false);
	}
	catch (const RepoError& error) {
		assert(error.getMessage() == "Deja exsta un locatar care locuieste la apartamentul: 1!\n");
	}

	Locatar locatar3 = service.serviceCautaLocatar(1);
	assert(locatar3 == locatar1);

	try {
		service.serviceCautaLocatar(999);
		assert(false);
	}
	catch (const RepoError& error) {
		assert(error.getMessage() == "Nu exista locatarul cautat, apartamentul 999!\n");
	}

	Locatar locatar4(1, "p4", 4, "t4");
	service.serviceModifica(locatar4);
	assert(service.serviceCautaLocatar(1) == locatar4);

	try {
		service.serviceModifica(locatar0);
		assert(false);
	}
	catch (const ValidationError& error) {
		assert(error.getMessage() == "Numarul apartamentului invalid\n"
			"Numele proprietarului nu poate fi vid\n"
			"Suprafata trebuie sa fie numar pozitiv\n"
			"Tipul nu poate fi vid\n");
	}

	Locatar locatar5(999, "p5", 5, "t5");
	try {
		service.serviceModifica(locatar5);
		assert(false);
	}
	catch (const RepoError& error) {}

	service.serviceStergeLocatar(1);
	assert(service.serviceGetAllLocatari().empty());

	Locatar l1(1, "p1", 1, "t1");
	Locatar l2(2, "p2", 70, "t1");
	Locatar l3(3, "p3", 80, "t3");
	service.serviceAdaugaLocatar(l1);
	service.serviceAdaugaLocatar(l2);
	service.serviceAdaugaLocatar(l3);

	auto filtrateTip = service.serviceFiltrareDupaTip("t1");
	assert(filtrateTip.size() == 2);
	assert(filtrateTip[0].getApartament() == 1);
	assert(filtrateTip[1].getApartament() == 2);

	auto filtrateTip1 = service.serviceFiltrareDupaTip("da");
	assert(filtrateTip1.empty());

	auto filtruSuprafata = service.serviceFiltrareDupaSuprafata(70);
	assert(filtruSuprafata.size() == 2);
	assert(filtruSuprafata[0].getApartament() == 2);
	assert(filtruSuprafata[1].getApartament() == 3);

	service.serviceSortareLocatari(1);
	auto sortPropr = service.serviceGetAllLocatari();
	assert(sortPropr.size() == 3);
	assert(std::is_sorted(sortPropr.begin(), sortPropr.end(),
		[](const Locatar& l1, const Locatar& l2) {
			return l1.getProprietar() < l2.getProprietar();
		}));

	service.serviceSortareLocatari(2);
	auto sortSuprafata = service.serviceGetAllLocatari();
	assert(sortSuprafata.size() == 3);
	assert(std::is_sorted(sortSuprafata.begin(), sortSuprafata.end(),
		[](const Locatar& l1, const Locatar& l2) {
			return l1.getSuprafata() < l2.getSuprafata();
		}));

	Locatar l4(4, "p3", 80, "t3");
	service.serviceAdaugaLocatar(l4);

	service.serviceSortareLocatari(3);
	auto sortTipSiSuprafata = service.serviceGetAllLocatari();
	assert(sortTipSiSuprafata.size() == 4);
	assert(std::is_sorted(sortTipSiSuprafata.begin(), sortTipSiSuprafata.end(),
		[](const Locatar& loc1, const Locatar& loc2) {
			return loc1.getTip() < loc2.getTip() ||
				(loc1.getTip() == loc2.getTip() &&
					loc1.getSuprafata() < loc2.getSuprafata());
		}));

	vector<Locatar> locatariNoi = { l1,l2 };
	service.serviceSetAllLocatari(locatariNoi);
	assert(service.serviceGetAllLocatari().size() == 2);
}

void testeLista() {
	Repository<Locatar> repo;
	Service service{ repo };
	ServiceLista serviceLista{ repo };

	Locatar l1(1, "Vlad", 72, "Apartament");
	Locatar l2(2, "Alex", 40, "Garsoniera");
	Locatar l3(3, "Andrei", 120, "Penthouse");

	service.serviceAdaugaLocatar(l1);
	service.serviceAdaugaLocatar(l2);
	service.serviceAdaugaLocatar(l3);

	serviceLista.adaugaLocatarInLista(1);
	assert(serviceLista.getSize() == 1);

	serviceLista.adaugaLocatarInLista(2);
	assert(serviceLista.getSize() == 2);

	auto listaLoc = serviceLista.getLista();
	assert(listaLoc[0].getApartament() == 1);
	assert(listaLoc[1].getApartament() == 2);

	try {
		serviceLista.adaugaLocatarInLista(99);
		assert(false);
	}
	catch (const RepoError& error) {}

	serviceLista.golesteLista();
	assert(serviceLista.getSize() == 0);

	serviceLista.genereazaListaAleator(2);
	assert(serviceLista.getSize() == 2);

	serviceLista.golesteLista();
	repo.repoSetAllElems({});

	try {
		serviceLista.genereazaListaAleator(10);
		assert(false);
	}
	catch (const ServiceError& error) {}
}

void Teste::testAll() {
	testeDomeniu();
	testeRepo();
	testeFileRepo();
	testeValidator();
	testeService();
	testeLista();
	std::cout << "Testele trec!\n";
}