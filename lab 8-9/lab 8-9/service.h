#pragma once
#include "repository.h"
#include "locatar.h"
#include "actiuneUndo.h"
#include <vector>

using std::vector;

class Service {
private:
	Repository<Locatar>& repo;
	vector<std::unique_ptr<ActiuneUndo>> undoActions;
public:
	explicit Service(Repository<Locatar>& repoX):
		repo{repoX}{ }

	void serviceAdaugaLocatar(const Locatar& locatarX);

	void serviceModifica(const Locatar& locatarX);

	Locatar serviceCautaLocatar(unsigned int ap) const;

	void serviceStergeLocatar(unsigned int ap);

	vector<Locatar> serviceFiltrareDupaTip(std::string tip) const;

	vector<Locatar> serviceFiltrareDupaSuprafata(unsigned int suprafata) const;

	void serviceSortareLocatari(int mod);

	void serviceUndo();
	
	vector<Locatar> serviceGetAllLocatari() const;

	void serviceSetAllLocatari(const vector<Locatar>& locatari) const;
};

