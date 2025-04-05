#include "produseRepo.h"
#include "produse.h"
#include "validator.h"
#include "produseService.h"
#include <iostream>
#include <sstream>
#include <assert.h>

using std::ostream;

void test_store() {
	ProduseRepo repo;
	repo.store(Produs(1, "tip1", "producator1", "model1", 100, 10));
	assert(repo.getAll().size() == 1);
	repo.store(Produs(1, "tip1", "producator1", "model1", 100, 10));
	assert(repo.getAll().size() == 1);
	assert(repo.getAll()[0].getCantitate() == 20);
	cout << "Test store passed" << std::endl;
}

void test_delete() {
	ProduseRepo repo;
	repo.store(Produs(1, "tip1", "producator1", "model1", 100, 10));
	repo.store(Produs(2, "tip2", "producator2", "model2", 200, 20));
	repo.deleteProdus(1);
	assert(repo.getAll().size() == 1);
	assert(repo.getAll()[0].getId() == 2);
	cout << "Test delete passed" << std::endl;
}

void test_modify() {
	ProduseRepo repo;
	repo.store(Produs(1, "tip1", "producator1", "model1", 100, 10));
	repo.store(Produs(2, "tip2", "producator2", "model2", 200, 20));
	assert(repo.getAll().size() == 2);
	repo.modifyProdusPrice(1, 150);
	repo.modifyProdusCantitate(2, 30);
	vector<Produs> produse = repo.getAll();
	assert(produse[0].getPret() == 150);
	assert(produse[1].getCantitate() == 30);
	cout << "Test modify passed" << std::endl;
}

void test_search() {
	ProduseRepo repo;
	repo.store(Produs(1, "tip1", "producator1", "model1", 100, 10));
	assert(repo.getAll().size() == 1);
	repo.store(Produs(2, "tip2", "producator2", "model2", 200, 20));
	try {
		repo.searchProdus(-3);
		assert(false);
	}
	catch (ProduseRepoException& ex) {
		assert(true);
	}
	cout << "Test search passed" << std::endl;
}

void repo_test(){
	test_store();
	test_delete();
	test_modify();
	test_search();
	std::cout << "Repo Tests Passed" << std::endl;
}

void validator_test() {
	ProduseValidator validator;
	Produs p1(-1, "tip1", "producator1", "model1", 100, 10);
	try {
		validator.validate(p1);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("Id invalid\n")>=0);
	}
	cout << "Test id invalid passed" << std::endl;
	Produs p2(1, "", "producator1", "model1", 100, 10);
	try {
		validator.validate(p2);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("Tip invalid\n")>=0);
	}
	cout << "Test tip invalid passed" << std::endl;
	Produs p3(1, "tip1", "producator1", "model1", 100, 10);
	try {
		validator.validate(p3);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("Producator invalid\n") >= 0);
	}
	cout << "Test producator invalid passed" << std::endl;
	Produs p4(1, "tip1", "producator1", "", 100, 10);
	try {
		validator.validate(p4);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("Model invalid\n") >= 0);
	}
	cout << "Test model invalid passed" << std::endl;
	Produs p5(1, "tip1", "producator1", "model1", -100, 10);
	try {
		validator.validate(p5);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("Model invalid\n") >= 0);
	}
	cout << "Test pret invalid passed" << std::endl;
	Produs p6(1, "tip1", "producator1", "model1", 100, -10);
	try {
		validator.validate(p6);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("Cantitate invalida\n") >= 0);
	}
	cout << "Test cantitate invalid passed" << std::endl;
}

void teste_service_add() {
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	service.add_service(1, "tip1", "producator1", "model1", 100, 10);
	assert(service.getAll().size() == 1);
	std::cout << "Test add service passed" << std::endl;
}

void teste_service_delete() {
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	service.add_service(1, "tip1", "producator1", "model1", 100, 10);
	service.add_service(2, "tip2", "producator2", "model2", 200, 20);
	service.delete_service(1);
	assert(service.getAll().size() == 1);
	assert(service.getAll()[0].getId() == 2);
	std::cout << "Test delete service passed" << std::endl;
}

void teste_modify_service() {
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	service.add_service(1, "tip1", "producator1", "model1", 100, 10);
	service.add_service(2, "tip2", "producator2", "model2", 200, 20);
	service.modify_service_price(1, 150);
	service.modify_service_cantitate(2, 30);
	vector<Produs> produse = service.getAll();
	assert(produse[0].getPret() == 150);
	assert(produse[1].getCantitate() == 30);
	std::cout << "Test modify service passed" << std::endl;
}

void teste_cauta_service() {
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	service.add_service(1, "tip1", "producator1", "model1", 100, 10);
	service.add_service(2, "tip2", "producator2", "model2", 200, 20);

	service.search_service(1);
	try {
		service.search_service(-3);
		assert(false);
	}
	catch (ProduseRepoException& ex) {
		assert(true);
	}
	std::cout << "Test search service passed" << std::endl;
}

void teste_filtrare() {
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	service.add_service(1, "tip1", "producator1", "model1", 100, 10);
	service.add_service(2, "tip2", "producator2", "model2", 200, 20);
	service.add_service(3, "tip3", "producator3", "model3", 300, 30);
	assert(service.filtrare_pret(150).size() == 2);
	assert(service.filtrare_cantitate(20).size() == 2);
	std::cout << "Test filtrare passed" << std::endl;
}
void test_sort() {
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	service.add_service(1, "tip1", "producator1", "model1", 100, 10);
	service.add_service(2, "tip2", "producator2", "model2", 200, 20);
	service.add_service(3, "tip3", "producator3", "model3", 300, 30);
	assert(service.getAll().size() == 3);
	vector<Produs> lista = service.sortare_pret_cresc();
	assert(lista[0].getId() == 1);
	vector<Produs> lista1 = service.sortare_cantitate_descresc();
	assert(lista1[0].getId() == 3);
	vector<Produs> lista3 = service.sortare_cantitate_cresc();
	assert(lista3[0].getId() == 1);
	vector<Produs> lista4 = service.sortare_cantitate_descresc();
	assert(lista4[0].getId() == 3);
	std::cout << "Test sort passed" << std::endl;
}


void teste_service() {
	teste_service_add();
	teste_service_delete();
	teste_modify_service();
	teste_cauta_service();
	teste_filtrare();
	test_sort();
	std::cout << "Service Tests Passed" << std::endl;
}

void test_all() {
	repo_test();
	validator_test();
	teste_service();
	std::cout << "All tests Passed" << std::endl;
}