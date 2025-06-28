#include "consola.h"
#include <iomanip>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int citesteInt(const string& mesaj) {
	string input;

	while (true) {
		cout << mesaj;
		getline(cin, input);

		if (input.empty()) {
			cout << "Introduceti o valoare!\n";
			continue;
		}

		try {
			int valoare = stoi(input);
			return valoare;
		}
		catch (const invalid_argument&) {
			cout << "Trebuie sa introduceti un numar intreg valid!\n";
		}
		catch (const out_of_range&) {
			cout << "Numarul este prea mare!\n";
		}
	}
}

double citesteDouble(const string& mesaj) {
	string input;

	while (true) {
		cout << mesaj;
		getline(cin, input);

		if (input.empty()) {
			cout << "Introduceti o valoare!\n";
			continue;
		}

		try {
			double valoare = stod(input);
			return valoare;
		}
		catch (const invalid_argument&) {
			cout << "Trebuie sa introduceti un numar valid!\n";
		}
		catch (const out_of_range&) {
			cout << "Numarul este prea mare!\n";
		}
	}
}

Locatar citesteLocatar() {
	cin.ignore();
	cout << "Numarul apartamentului: ";
	unsigned int ap;
	cin >> ap;
	cout << "Proprietarul: ";
	string pr;
	cin >> pr;
	cout << "Suprafata: ";
	unsigned int sup;
	cin >> sup;
	cout << "Tipul apartamentului: ";
	string tip;
	cin >> tip;
	return Locatar(ap, pr, sup, tip);
}

void afiseazaLocatar(const Locatar& loc) {

	cout << "╔══════════════════════════════════════════════╗" << endl;
	cout << "║               Detalii Locatar                ║" << endl;
	cout << "╠══════════════════════════════════════════════╣" << endl;
	cout << "║ Apartament:   " << std::setw(32) << std::left << loc.getApartament() << " ║" << endl;
	cout << "║ Proprietar: " << std::setw(32) << std::left << loc.getProprietar() << " ║" << endl;
	cout << "║ Suprafata:        " << std::setw(32) << std::left << loc.getSuprafata() << " ║" << endl;
	cout << "║ Tip:       " << std::setw(32) << std::left << std::fixed << std::setprecision(2) << loc.getTip() << " ║" << endl;
	cout << "╚══════════════════════════════════════════════╝" << endl;
}

void Consola::consolaAdauga() {
	Locatar locatar = citesteLocatar();
	this->service.serviceAdaugaLocatar(locatar);
	cout << "Locatar adaugat cu succes!\n";
}

void Consola::consolaModificaLocatar() {
	Locatar locatar = citesteLocatar();
	this->service.serviceModifica(locatar);
	cout << "Locatar modificat cu succes!\n";
}

void Consola::consolaCautaLocatar() {
	unsigned int ap;
	cout << "Numarului apartamentului dorit: ";
	cin >> ap;
	Locatar loc = this->service.serviceCautaLocatar(ap);
	cout << "Locatar gasit!\n";
	afiseazaLocatar(loc);
}

void Consola::consolaStergeLocatar() {
	unsigned int ap;
	cout << "Numarului apartamentului dorit: ";
	cin >> ap;
	this->service.serviceStergeLocatar(ap);
	cout << "Locatar sters!\n";
}

void Consola::consolaAfisare() {
	cout << "Lista cu locatari:\n";
	for (const auto& loc : this->service.serviceGetAllLocatari()) {
		afiseazaLocatar(loc);
	}
}

void Consola::consolaFiltrare() {
	cout << "Alegeti un mod de filtrare(1/2):\n1. Dupa tip\n2. Dupa suprafata\n";
	int mod = citesteInt(">>>");
	if (mod == 1) {
		cout << "Introduceti tipul dorit: ";
		string tip;
		cin >> tip;
		cout << "Lista filtrata:\n";
		for (const auto& loc : this->service.serviceFiltrareDupaTip(tip)) {
			afiseazaLocatar(loc);
		}
	}
	else if (mod == 2) {
		int nr= citesteInt("Introduceti suprfata: ");
		if (nr < 0)
			nr = (-1) * nr;
		unsigned int suprafata=nr;
		cout << "Lista filtrata:\n";
		for (const auto& loc : this->service.serviceFiltrareDupaSuprafata(suprafata)) {
			afiseazaLocatar(loc);
		}
	}
	else {
		cout << "Mod invalid!\n";
	}
}

void Consola::consolaSortare() {
	cout << "Alegeti modul de sortare(1/2/3):\n 1:Dupa Proprietar\n2.Dupa Suprafata\n3.Dupa Tip si Suprafata";
	unsigned int mod;
	cin >> mod;
	if (mod != 1 && mod != 2 && mod != 3) {
		cout << "Modul invalid!\n";
		return;
	}
	cout << "Lista: \n";
	this->service.serviceSortareLocatari(mod);
	this->consolaAfisare();
}

void Consola::consolaAdaugaLista() {
	unsigned int ap;
	cout << "Apartamentul dorit: ";
	cin >> ap;
	this->serviceLista.adaugaLocatarInLista(ap);
	cout << "Locatar adaugat!\n";
}

void Consola::consolaGolesteLista() {
	this->serviceLista.golesteLista();
	cout << "Lista golita!\n";
}

void Consola::consolaGenereazaLista() {
	int numar;
	cout << "Introduceti nr de locuitor\n";
	cin >> numar;
	this->serviceLista.genereazaListaAleator(numar);
	cout << "Lista generata cu succes!\n";
}

void Consola::consolaExportaLista() {
	string filename;
	cout << "Introduceti fisierul in care se face exportul";
	cin >> filename;
	this->serviceLista.exportaListaToCSV(filename);
	cout << "Lista exportata!\n";
}

void Consola::consolaUndo() {
	this->service.serviceUndo();
	cout << "Undo realizat cu succes!\n";
}

void Consola::consolaListeazaLista() {
	cout << "Lista locatari:\n";
	for (const auto& locatar : this->serviceLista.getLista()) {
		afiseazaLocatar(locatar);
	}
}

void Consola::runConsola() {
	while (true) {
		try {
			cout << ">>> ";
			string comanda;
			cin >> comanda;

			if (comanda == "adauga")
				consolaAdauga();
			else if (comanda == "cauta")
				consolaCautaLocatar();
			else if (comanda == "modifica")
				consolaModificaLocatar();
			else if (comanda == "sterge")
				consolaStergeLocatar();
			else if (comanda == "afiseaza")
				consolaAfisare();
			else if (comanda == "sortare")
				consolaSortare();
			else if (comanda == "adaugaLista")
				consolaAdaugaLista();
			else if (comanda == "golesteLista")
				consolaGolesteLista();
			else if (comanda == "genereazaLista")
				consolaGenereazaLista();
			else if (comanda == "exportaLista")
				consolaExportaLista();
			else if (comanda == "afiseazaLista")
				consolaListeazaLista();
			else if (comanda == "undo")
				consolaUndo();
			else if (comanda == "exit")
				break;
			else
				cout << "Comanda invalida!\n";
		}
		catch (const ValidationError& error) {
			cout << "Eroare validare date!\n" << error.getMessage();
		}
		catch (const RepoError& error) {
			cout << "Eroare repository!\n" << error.getMessage();
		}
		catch (const ServiceError& error) {
			cout << "Eroare service!\n" << error.getMessage();
		}
		catch (...) {
			cout << "Eroare necunoscută!\n";
		}
	}
}