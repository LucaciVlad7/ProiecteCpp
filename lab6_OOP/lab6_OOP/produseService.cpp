#include "produseService.h"
#include <functional>
#include <algorithm>
#include <assert.h>

void ProduseService::add_service(int id, const string tip, const string producator, const string model, int pret, int cantitate) {
	Produs p{ id, tip, producator, model, pret, cantitate };
	validator.validate(p);
	repo.store(p);
}

void ProduseService::delete_service(int id) {
	repo.deleteProdus(id);
}

void ProduseService::modify_service_price(int id, int pret) {
	repo.modifyProdusPrice(id, pret);
}

void ProduseService::modify_service_cantitate(int id, int cantitate) {
	repo.modifyProdusCantitate(id, cantitate);
}

const Produs& ProduseService::search_service(int id) {
	return repo.searchProdus(id);
}

vector<Produs> ProduseService::filtrare(function<bool(const Produs&)> fct) {
	vector<Produs> rezultat;
	for (const auto& produs : repo.getAll()) {
		if (fct(produs)) {
			rezultat.push_back(produs);
		}
	}
	return rezultat;
}

vector<Produs> ProduseService::filtrare_pret(int pret) {
	return filtrare([pret](const Produs& p) noexcept {
		return p.getPret() >= pret;
		});
} 

vector<Produs> ProduseService::filtrare_cantitate(int cantitate) {
	return filtrare([cantitate](const Produs& p) noexcept {
		return p.getCantitate() >= cantitate;
		});
}

vector<Produs> ProduseService::filtrare_producator(const std::string& producator) {
	return filtrare([producator](const Produs& p) noexcept {
		return p.getProducator()== producator;
		});
}

vector<Produs> ProduseService::sortare_pret_cresc() {
	auto copie = repo.getAll();
	std::sort(copie.begin(), copie.end(), compareCantitate);
	return copie;
}

vector<Produs> ProduseService::sortare_pret_descresc() {
	auto copie = repo.getAll();
	std::sort(copie.begin(), copie.end(), compareCantitate);
	std::reverse(copie.begin(), copie.end());
	return copie;
}

vector<Produs> ProduseService::sortare_cantitate_cresc() {
	auto copie = repo.getAll();
	std::sort(copie.begin(), copie.end(), compareCantitate);
	return copie;
}

vector<Produs> ProduseService::sortare_cantitate_descresc() {
	auto copie = repo.getAll();
	std::sort(copie.begin(), copie.end(), compareCantitate);
	std::reverse(copie.begin(), copie.end());
	return copie;
}

vector<Produs> ProduseService::generalSort(bool(*maiMicF)(const Produs&, const Produs&)) {
	vector<Produs> copie = repo.getAll(); 
	for (size_t i = 0;i < copie.size();i++) {
		for (size_t j = i + 1;j < copie.size();j++) {
			if (!maiMicF(copie[i], copie[j])) {
				Produs aux = copie[i];
				copie[i] = copie[j];
				copie[j] = aux;
			}
		}
	}
	return copie;
}