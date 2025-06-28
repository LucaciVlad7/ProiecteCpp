#pragma once
#include <vector>
#include <random>
#include <fstream>
#include "locatar.h"
#include "AbstractRepo.h"
#include "Exceptii.h"
class ServiceLista {
private:
	vector<Locatar> lista;
	AbstractRepo<Locatar>& repo;
public:
	explicit ServiceLista(AbstractRepo<Locatar>& repoX) :
		repo{ repoX } {
	}

	void adaugaLocatarInLista(unsigned int ap);
	void genereazaListaAleator(int numar);
	void golesteLista();
	void exportaListaToCSV(const string& filename) const;
	void exportaLista(const string& filename, int mod) const;
	vector<Locatar> getLista();

	int getSize();
};