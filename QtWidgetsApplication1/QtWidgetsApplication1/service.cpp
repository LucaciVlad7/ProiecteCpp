#include "service.h"
#include "validator.h"
#include <algorithm>
#include <map>

void Service::serviceAdaugaLocatar(const Locatar& locatarX) {
	Validator::valideazaLocatari(locatarX);
	this->repo.repoAdaugaElem(locatarX);

	undoActions.push_back(std::make_unique<UndoAdaugaLocatar>(this->repo, locatarX.getApartament()));
}

void Service::serviceModifica(const Locatar& locatarX) {
	Validator::valideazaLocatari(locatarX);
	Locatar locatarVechi = this->repo.repoCautaElem(locatarX.getApartament());
	this->repo.repoModifica(locatarX);

	undoActions.push_back(std::make_unique<UndoModificaLocatar>(this->repo, locatarVechi));
}

Locatar Service::serviceCautaLocatar(unsigned int ap) const {
	return this->repo.repoCautaElem(ap);
}

void Service::serviceStergeLocatar(unsigned int ap) {
	Locatar locatarVechi = this->repo.repoCautaElem(ap);
	this->repo.repoStergeElem(ap);
	undoActions.push_back(std::make_unique<UndoStergeLocatar>(this->repo, locatarVechi));
}

vector<Locatar> Service::serviceFiltrareDupaTip(std::string tip) const {
	vector<Locatar> rez;
	auto oferte = this->repo.repoGetAllElems();

	std::copy_if(oferte.begin(), oferte.end(), std::back_inserter(rez),
		[&tip](const Locatar& locatar) {
			return locatar.getTip() == tip;
		});

	return rez;
}

vector<Locatar> Service::serviceFiltrareDupaSuprafata(unsigned int suprafata) const {
	vector<Locatar> rez;
	auto oferte = this->repo.repoGetAllElems();

	std::copy_if(oferte.begin(), oferte.end(), std::back_inserter(rez),
		[&suprafata](const Locatar& locatar) {
			return locatar.getSuprafata() >= suprafata;
		});

	return rez;
}

void Service::serviceSortareLocatari(const int mod) {
	vector<Locatar> locatarLista = this->repo.repoGetAllElems();

	if (mod == 1) {
		sort(locatarLista.begin(), locatarLista.end(),
			[](const Locatar& loc1, const Locatar& loc2) {
				return loc1.getProprietar() < loc2.getProprietar();
			});
	}
	if (mod == 2) {
		sort(locatarLista.begin(), locatarLista.end(),
			[](const Locatar& loc1, const Locatar& loc2) {
				return loc1.getSuprafata() < loc2.getSuprafata();
			});
	}
	if (mod == 3) {
		sort(locatarLista.begin(), locatarLista.end(),
			[](const Locatar& loc1, const Locatar& loc2) {
				return loc1.getTip() < loc2.getTip() ||
					(loc1.getTip() == loc2.getTip() &&
						loc1.getSuprafata() < loc2.getSuprafata());
			});
	}
	this->repo.repoSetAllElems(locatarLista);
}

void Service::serviceUndo() {
	if (this->undoActions.empty())
		throw ServiceError("Nu exista nicio operatie de undo!\n");

	undoActions.back()->doUndo();
	undoActions.pop_back();
}

vector<Locatar> Service::serviceGetAllLocatari() const {
	return this->repo.repoGetAllElems();
}

std::map<string, int> Service::serviceGetTipuri() const {
	auto locatari=this->repo.repoGetAllElems();
	map<string, int> tipuri;
	for (auto loc : locatari) {
		tipuri[loc.getTip()]++;
	}
	return tipuri;
}

void Service::serviceSetAllLocatari(const vector<Locatar>& locatariX) const {
	this->repo.repoSetAllElems(locatariX);
}