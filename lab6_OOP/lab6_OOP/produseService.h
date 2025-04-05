#pragma once

#include "produse.h"
#include "produseRepo.h"
#include <string>
#include <vector>

#include <functional>
#include "validator.h"

using std::vector;
using std::function;

class ProduseService {
	ProduseRepo& repo;
	ProduseValidator& validator;

	vector<Produs> generalSort(bool(*maiMicF)(const Produs&, const Produs&));

public:
	ProduseService(ProduseRepo& repo, ProduseValidator& validator) : repo{ repo }, validator{ validator } {
	}

	ProduseService(const ProduseService& ot) = delete;

	const vector<Produs>& getAll() const {
		return repo.getAll();
	}

	void add_service(int id, const string tip, const string producator, const string model, int pret, int cantitate);

	void delete_service(int id);

	void modify_service_price(int id, int pret);

	void modify_service_cantitate(int id, int cantitate);

	const Produs& search_service(int id);

	vector<Produs> filtrare(function<bool(const Produs&)> fct);

	vector<Produs> filtrare_pret(int pret);
	
	vector<Produs> filtrare_cantitate(int cantitate);

	vector<Produs> filtrare_producator(const std::string& producator);

	vector<Produs> sortare_pret_cresc();

	vector<Produs> sortare_pret_descresc();

	vector<Produs> sortare_cantitate_cresc();

	vector<Produs> sortare_cantitate_descresc();
};