#pragma once
#include <vector>
#include <random>
#include <fstream>
#include "locatar.h"
#include "Repository.h"

class ServiceLista {
private:
	vector<Locatar> lista;
	Repository<Locatar>& repo;
public:
	explicit ServiceLista(Repository<Locatar>& repoX):
		repo{repoX}{ }

	void adaugaLocatarInLista(unsigned int ap);
	void genereazaListaAleator(int numar);
	void golesteLista();
	void exportaListaToCSV(const string& filename) const;

	vector<Locatar> getLista();

	int getSize();
};