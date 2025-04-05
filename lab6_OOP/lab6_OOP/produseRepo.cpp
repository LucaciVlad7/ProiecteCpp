#include "produseRepo.h"
#include "produse.h"
#include <iostream>
#include <sstream>

using std::ostream;
using std::stringstream;

void ProduseRepo::store(const Produs& p) {
	if (exist(p)) {
		for (int i = 0; i < int(produse.size()); i++) {
			if (produse[i].getId() == int(p.getId())) {
				produse[i].setCantitate(produse[i].getCantitate() + p.getCantitate());
				return;
			}
		}
	}
	produse.push_back(p);
}

void ProduseRepo::deleteProdus(unsigned int id) {
	if (id >= 0) {
		int poz_delete = -1;
		for (int i = 0; i < int(produse.size()); i++) {
			if (produse[i].getId() == id) {
				poz_delete = i;
				break;
			}
		}
		if (poz_delete == 0) {
			produse.erase(produse.begin(), produse.begin() + 1);
		}
		else {
			produse.erase(produse.begin() + poz_delete);
		}
	}
	else {
		throw ProduseRepoException("Id-ul nu poate fi negativ!");
	}
}

void ProduseRepo::modifyProdusPrice(unsigned int id, unsigned int newPrice) {
	if (id >= 0) {
		for (int i = 0; i < (int)produse.size(); i++) {
			if (produse[i].getId() == id) {
				produse[i].setPrice(newPrice);
				return;
			}
		}
		throw ProduseRepoException("Nu exista produs cu id-ul dat!");
	}
	else {
		throw ProduseRepoException("Id-ul nu poate fi negativ!");
	}
}

void ProduseRepo::modifyProdusCantitate(unsigned int id, unsigned int newCantitate) {
	if (id >= 0) {
		for (int i = 0; i < (int)produse.size(); i++) {
			if (produse[i].getId() == id) {
				produse[i].setCantitate(newCantitate);
				return;
			}
		}
		throw ProduseRepoException("Nu exista produs cu id-ul dat!");
	}
	else {
		throw ProduseRepoException("Id-ul nu poate fi negativ!");
	}
}

const Produs& ProduseRepo::searchProdus(unsigned int id) {
	if (id >= 0) {
		for (int i = 0; i < (int)produse.size(); i++) {
			if (produse[i].getId() == id) {
				return produse[i];
			}
		}
		throw ProduseRepoException("Nu exista produs cu id-ul dat!");
	}
	else {
		throw ProduseRepoException("Id-ul nu poate fi negativ!");
	}
}

const Produs& ProduseRepo::find(unsigned int id) const{
	for (const auto& m : produse) {
		if (m.getId() == id) {
			return m;
		}
	}
	throw ProduseRepoException("Nu exista produs cu id-ul dat!(ID: " + std::to_string(id) + " a fost introdus)");
}

bool ProduseRepo::exist(const Produs& p) const {
	try {
		find(p.getId());
		return true;
	}
	catch (ProduseRepoException&) {
		return false;
	}
}

const vector<Produs>& ProduseRepo::getAll() const noexcept {
	return produse;
}



ostream& operator<<(ostream& out, const ProduseRepoException& ex) {
	out << ex.msg;
	return out;
}