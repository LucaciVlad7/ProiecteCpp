#include "serviceLista.h"

void ServiceLista::golesteLista() {
	this->lista.clear();
}

void ServiceLista::adaugaLocatarInLista(unsigned int ap) {
	Locatar locatar = this->repo.repoCautaElem(ap);
	this->lista.push_back(locatar);
}

void ServiceLista::genereazaListaAleator(int numar) {
	vector<Locatar> loc = this->repo.repoGetAllElems();
	if (loc.empty())
		throw ServiceError("Nu exista locatari salvati pentru a genera o lista\n");

	lista.clear();
	std::mt19937 mt{ std::random_device{}() };
	for (int i = 0; i < numar; i++) {
		std::uniform_int_distribution<> dist(0, static_cast<int>(loc.size() - 1));
		const int rndNr = dist(mt);
		lista.push_back(loc[rndNr]);
	}
}

void ServiceLista::exportaListaToCSV(const string& filename) const {
	std::ofstream fout(filename);
	if (!fout) {
		throw ServiceError("Eroare la deschiderea fișierului pentru export!");
	}

	fout << "ID,Denumire,Destinatie,Tip,Pret\n";

	for (const auto& loc : lista) {
		fout << loc.getApartament() << ","
			<< loc.getProprietar() << ","
			<< loc.getSuprafata() << ","
			<< loc.getTip() << "\n";
	}

	fout.close();
}

vector<Locatar> ServiceLista::getLista() {
	return this->lista;
}

int ServiceLista::getSize() {
	return this->lista.size();
}