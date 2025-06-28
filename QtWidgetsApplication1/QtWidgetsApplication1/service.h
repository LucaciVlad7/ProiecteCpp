#pragma once
#include "repository.h"
#include "AbstractRepo.h"
#include "locatar.h"
#include "actiuneUndo.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <map>

using std::vector;

class Service {
private:
	AbstractRepo<Locatar>& repo;
	vector<std::unique_ptr<ActiuneUndo>> undoActions;
public:
	explicit Service(AbstractRepo<Locatar>& repoX) :
		repo{ repoX } {}

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

	std::map<string, int> serviceGetTipuri() const;
};

