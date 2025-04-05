#pragma once
#include "produse.h"

#include <vector>
#include <string>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;

class ProduseRepo {
	vector<Produs> produse;

	bool exist(const Produs& p) const;

public:
	ProduseRepo() = default;
	
	//nu permitem copierea de obiecte
	ProduseRepo(const ProduseRepo& repo) = delete;

	
	/*Salvare produs
	* arunca eroare daca mai exista un produs cu acelasi id
	*/
	void store(const Produs& p);

	//sterge medicament dupa id
	void deleteProdus(unsigned int id);

	//inlocuieste pretul produsului cu id-ul introdus, cu al doilea parametru
	void modifyProdusPrice(unsigned int id, unsigned int newPrice);

	//inlocuieste cantiatea produsului cu id-ul introdus, cu al doilea parametru
	void modifyProdusCantitate(unsigned int id, unsigned int newCantitate);
	

	//cauta produsul dupa id
	const Produs& searchProdus(unsigned int id);

	//gaseste produsul dupa id
	const Produs& find(unsigned int id) const;

	//returneaza produsele salvate
	const vector<Produs>& getAll() const noexcept;
};

class ProduseRepoException {
	string msg;
public:
	ProduseRepoException(string m) : msg{ m } {

	}

	friend ostream& operator<<(ostream& out, const ProduseRepoException& ex);
};

ostream& operator<<(ostream& out, const ProduseRepoException& ex);