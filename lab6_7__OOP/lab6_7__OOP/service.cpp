#include "service.h"

#include "iostream"
#include <ostream>

#include "validator.h"

void service::serviceAdaugaLocatar(const Locatar& locatar) {
	string erori = validator::validatorLocatar(locatar);
	if (!erori.empty())
		throw runtime_error(erori);
	if(this->repo.existaElem(locatar.getApartament()))
		throw runtime_error("Deja exista un locatar in acest apartament\n");

	this->repo.adaugaElem(locatar);
}

void service::serviceModificaLocatar(const Locatar& locatar) {
	string erori = validator::validatorLocatar(locatar);
	if (!erori.empty())
		throw runtime_error(erori);

	if (!this->repo.existaElem(locatar.getApartament()))
		throw runtime_error("Nu exista locatarul dorit!\n");

	this->repo.modificaElem(locatar);
}

Locatar service::serviceCautaLocatar(unt ap) {
	if (!this->repo.existaElem(ap))
		throw runtime_error("Nu exista locatarul cautat!\n");
	return this->repo.cautaElem(ap);
}

void service::serviceStergeLocatar(const unt ap) {
	if (!this->repo.existaElem(ap))
		throw runtime_error("Nu exista locatarul cautat!\n");
	this->repo.stergeElem(ap);
}

mvector<Locatar> service::serviceFiltrareSuprafata(unt suprafata) const {
	mvector<Locatar> oferteFiltrare(this->repo.getAllElems());
	for (int i = 0;i < oferteFiltrare.getSize();i++) {
		if (oferteFiltrare[i].getSuprafata() < suprafata) {
			oferteFiltrare.pop(i);
			i--;
		}
	}
	return oferteFiltrare;
}

mvector<Locatar> service::serviceFiltrareTip(const string& tip) const {
	mvector<Locatar> oferteFiltrare(this->repo.getAllElems());
	for (int i = 0;i < oferteFiltrare.getSize();i++) {
		if (oferteFiltrare[i].getTip() != tip) {
			oferteFiltrare.pop(i);
			i--;
		}
	}
	return oferteFiltrare;
}

/// Sortare dupa diferite criterii
/// @param mod :
///     - 1 sortare dupa denumire
///     - 2 sortare dupa destinatie
///     - 3 sortare dupa tip si pret
void service::serviceSortare(const int mod) {
	mvector<Locatar> locatarLista(this->repo.getAllElems());
	for (int i = 0; i < locatarLista.getSize() - 1; i++) {
		for (int j = i + 1; j < locatarLista.getSize(); j++) {
			if ((mod == 1 && locatarLista[j].getProprietar() < locatarLista[i].getProprietar()) ||
				(mod == 2 && locatarLista[j].getSuprafata() < locatarLista[i].getSuprafata())
				|| (mod == 3 && (locatarLista[j].getTip() < locatarLista[i].getTip() ||
					(locatarLista[j].getTip() == locatarLista[i].getTip() &&
						locatarLista[j].getSuprafata() < locatarLista[i].getSuprafata())))) {
				Locatar locatarAux = locatarLista[j];
				locatarLista[j] = locatarLista[i];
				locatarLista[i] = locatarAux;
			}
		}
	}
	this->repo.setElems(locatarLista);
}

mvector<Locatar> service::getElems() {
	return this->repo.getAllElems();
}