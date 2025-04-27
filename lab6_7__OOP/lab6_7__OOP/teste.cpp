#include "Locatar.h"
#include <assert.h>
#include <iostream>

#include "repository.h"
#include "teste.h"
#include "mvector.h"
#include "validator.h"
#include "service.h"

using std::string;
using std::cout;

void testeDomeniu() {
	string proprietar = "Vlad";
	string tip = "tip";
	unsigned int apartament = 24;
	unsigned int suprafata = 70;
	Locatar locatar1(apartament, proprietar, suprafata, tip);

	assert(locatar1.getApartament() == 24);
	assert(locatar1.getProprietar() == "Vlad");
	assert(locatar1.getSuprafata() == 70);
	assert(locatar1.getTip() == "tip");

	string proprietar1 = "Vlad1";
	string tip1 = "tip1";
	unsigned int apartament1 = 241;
	unsigned int suprafata1 = 701;

	locatar1.setApartament(apartament1);
	assert(locatar1.getApartament() == 241);

	locatar1.setProprietar(proprietar1);
	assert(locatar1.getProprietar() == "Vlad1");

	locatar1.setSuprafata(suprafata1);
	assert(locatar1.getSuprafata() == 701);

	locatar1.setTip(tip1);
	assert(locatar1.getTip() == "tip1");
}

void testeRepository() {
	repository repo([](const TElem& locatar) -> int { return locatar.getApartament(); });

	string proprietar = "Vlad";
	string tip = "tip";
	unsigned int apartament = 24;
	unsigned int suprafata = 70;
	Locatar locatar1{ apartament, proprietar, suprafata, tip };

	assert(locatar1.getApartament() == 24);
	assert(locatar1.getProprietar() == "Vlad");
	assert(locatar1.getSuprafata() == 70);
	assert(locatar1.getTip() == "tip");

	assert(repo.getSize() == 0);
	repo.adaugaElem(locatar1);
	assert(repo.getSize() == 1);

	assert(repo.cautaElem(24) == locatar1);

	string proprietar1 = "Vlad2";
	string tip1 = "tip2";
	unsigned int apartament1 = 24;
	unsigned int suprafata1 = 702;
	Locatar locatar2{ apartament1, proprietar1, suprafata1, tip1 };

	repo.modificaElem(locatar2);
	assert(repo.cautaElem(24) == locatar2);

	repo.stergeElem(24);
	assert(repo.getSize() == 0);

	repo.adaugaElem(locatar1);
	assert(repo.existaElem(24) == true);
}

void testeVector() {
	mvector<int> v;

	int el1 = 5;
	int el2 = 10;
	int el3 = 7;

	assert(v.getSize() == 0);
	v.push_back(el1);
	assert(v.getSize() == 1);

	assert(v.back() == el1);

	v.pop_back();
	assert(v.getSize() == 0);

	v.push_back(el1);
	v.push_back(el2);
	v.push_back(el3);
	assert(v.getSize() == 3);
	v.pop(1);
	assert(v[0] == el1);
	assert(v[1] == el3);
}

void testeValidator() {
	unsigned int ap = 24;
	unsigned int suprafata = 100;
	string proprietar = "Vlad";
	string tip = "tip";
	Locatar locatar{ ap,proprietar,suprafata,tip };
	string erori = validator::validatorLocatar(locatar);
	assert(erori.empty());

	unsigned int ap1 = 0;
	unsigned int suprafata1 = 0;
	string proprietar1;
	string tip1;
	Locatar locatar1{ ap1,proprietar1,suprafata1,tip1 };
	string erori1 = validator::validatorLocatar(locatar1);
	assert(erori1 == "Numarul apartamentului invalid\n"
					"Numele proprietarului nu poate fi vid\n"
					"Suprafata trebuie sa fie numar pozitiv\n"
					"Tipul nu poate fi vid\n");
}

void testeService() {
	repository repo([](const TElem& locatar) -> int { return locatar.getApartament(); });
	service serv(repo);

	string proprietar = "Vlad";
	string tip = "tip";
	unsigned int apartament = 24;
	unsigned int suprafata = 70;
	Locatar locatar1(apartament, proprietar, suprafata, tip);

	try {
		serv.serviceAdaugaLocatar(locatar1);
	}
	catch (...) {
		assert(false);
	}
	try {
		serv.serviceAdaugaLocatar(locatar1);
		assert(false);
	}
	catch(const runtime_error& e){
		assert(string(e.what()) == "Deja exista un locatar in acest apartament\n");
	}

	string proprietar1;
	string tip1;
	unsigned int apartament1 = 0;
	unsigned int suprafata1 = 0;
	Locatar locatar2(apartament1, proprietar1, suprafata1, tip1);

	try {
		serv.serviceAdaugaLocatar(locatar2);
		assert(false);
	}
	catch (const runtime_error& e) {
		assert(string(e.what()) == "Numarul apartamentului invalid\n"
			"Numele proprietarului nu poate fi vid\n"
			"Suprafata trebuie sa fie numar pozitiv\n"
			"Tipul nu poate fi vid\n");
	}

	string proprietar2 = "Vlad1";
	string tip2 = "tip1";
	unsigned int apartament2 = 24;
	unsigned int suprafata2 = 700;

	Locatar locatar3(apartament2, proprietar2, suprafata2, tip2);

	try {
		serv.serviceModificaLocatar(locatar3);
	}
	catch(...){
		assert(false);
	}

	Locatar locatar4(apartament1, proprietar1, suprafata1, tip1);
	try {
		serv.serviceModificaLocatar(locatar4);
		assert(false);
	}
	catch (const runtime_error& e) {
		assert(string(e.what()) == "Numarul apartamentului invalid\n"
			"Numele proprietarului nu poate fi vid\n"
			"Suprafata trebuie sa fie numar pozitiv\n"
			"Tipul nu poate fi vid\n");
	}

	Locatar locatar5(5, proprietar, suprafata, tip);
	try {
		serv.serviceModificaLocatar(locatar5);
		assert(false);
	}
	catch (const runtime_error& e) {
		assert(string(e.what()) == "Nu exista locatarul dorit!\n");
	}
	
	try {
		Locatar aux = serv.serviceCautaLocatar(24);
		assert(aux == locatar3);
	}
	catch (...) {
		assert(false);
	}

	try {
		serv.serviceCautaLocatar(100);
		assert(false);
	}
	catch(const runtime_error& e){
		assert(string(e.what()) == "Nu exista locatarul cautat!\n");
	}

	try {
		serv.serviceStergeLocatar(24);
	}
	catch (...) {
		assert(false);
	}
	
	string proprietar5 = "1";
	string tip5 = "2";
	unsigned int apartament5 = 5;
	unsigned int suprafata5 = 1;
	Locatar locatar8(apartament5, proprietar5, suprafata5, tip5);

	string proprietar6 = "1";
	string tip6 = "1";
	unsigned int apartament6 = 6;
	unsigned int suprafata6 = 1;
	Locatar locatar9(apartament6, proprietar6, suprafata6, tip6);

	string proprietar7 = "1";
	string tip7 = "1";
	unsigned int apartament7 = 7;
	unsigned int suprafata7 = 1;
	Locatar locatar10(apartament7, proprietar7, suprafata7, tip7);

	serv.serviceAdaugaLocatar(locatar8);
	serv.serviceAdaugaLocatar(locatar9);
	serv.serviceAdaugaLocatar(locatar10);

	mvector<Locatar> lista(serv.serviceFiltrareTip(tip7));
	assert(lista[0] == locatar9);
	assert(lista[1] == locatar10);

	mvector<Locatar> lista1(serv.serviceFiltrareSuprafata(suprafata6));
	assert(lista[0] == locatar9);
	assert(lista[1] == locatar10);

	serv.serviceSortare(1);
	repo.setElems(repo.getAllElems());
	mvector<Locatar> soratate = serv.getElems();
}

void runAlltests() {
	testeDomeniu();
	testeVector();
	testeRepository();
	testeValidator();
	testeService();
}