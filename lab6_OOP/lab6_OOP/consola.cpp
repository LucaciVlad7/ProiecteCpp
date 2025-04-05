#include "consola.h"

#include "Produse.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::ws;

void Consola::afiseazaUI(const vector<Produs>& p) {
	if(p.size()!=0)
		cout << "Produsele sunt: \n";
	else
		cout << "Nu exista produse\n";
	for (const auto& produs : p) {
		cout << "Id: " + std::to_string(produs.getId()) + " Tip: " + produs.getTip() + " Producator: "
			+ produs.getProducator() + " Model: " + produs.getModel() + " Pret: " + std::to_string(produs.getPret()) +
			" Cantitate: " + std::to_string(produs.getCantitate()) << "\n";
	}
	cout << '\n';
}

void Consola::adaugaUI() {
	unsigned int id, pret, cantitate;
	std::string tip, producator, model;
	cout << "Introduceti id: ";
	cin >> id;
	cout << "Introduceti tip: ";
	cin >> tip;
	cout << "Introduceti producator: ";
	cin >> producator;
	cout << "Introduceti model: ";
	cin >> model;
	cout << "Introduceti pret: ";
	cin >> pret;
	cout << "Introduceti cantitate: ";
	cin >> cantitate;
	service.add_service(id, tip, producator, model, pret, cantitate);
}

void Consola::stergeUI() {
	unsigned int id;
	cout << "Introduceti id-ul produsului pe care doriti sa il  stergeti: ";
	cin >> id;
	service.delete_service(id);
	cout << "Produsul a fost sters cu succes!\n";
}

void Consola::modificaUI() {
	cout << "Introduceti tipul de moficare dorit(1. Pret sau 2. Cantitate): ";
	unsigned int optiune=-1;
	while (true) {
		cin >> optiune;
		if (1<=optiune<=2) {
			if (optiune == 1) {
				unsigned int pret,id;
				cout << "Introduceti id produsului dorit: ";
				cin >> id;
				cout << "Introduceti pretul dorit: ";
				cin >> pret;
				service.modify_service_price(id, pret);
				break;
			}
			else if (optiune == 2) {
				unsigned int cantitate, id;
				cout << "Introduceti id produsului dorit: ";
				cin >> id;
				cout << "Introduceti cantitatea dorita: ";
				cin >> cantitate;
				service.modify_service_cantitate(id, cantitate);
				break;
			}
		}
	}
}

void Consola::filtrareUI() {
	cout << "Introduceti tipul de filtrare dorita(1. Pret, 2. Cantitate sau 3. Producator): ";
	unsigned int optiune = -1;
	while (true) {
		cin >> optiune;
		if (1 <= optiune <= 3) {
			if (optiune == 1) {
				unsigned int pret;
				cout << "Introduceti pretul dorit: ";
				cin >> pret;
				afiseazaUI(service.filtrare_pret(pret));
				break;
			}
			else if (optiune == 2) {
				unsigned int cantitate;
				cout << "Introduceti cantitatea dorita: ";
				cin >> cantitate;
				afiseazaUI(service.filtrare_cantitate(cantitate));
				break;
			}
			else if (optiune == 3) {
				std::string producator = "";
				cin >> producator;
				afiseazaUI(service.filtrare_producator(producator));
				break;
			}
		}
	}
}

void Consola::sortareUI() {
	cout << "Introduceti criteriu dupa care se va sorta(1. Pret sau 2. Cantitate): ";
	unsigned int optiune = -1;
	while (true) {
		cin >> optiune;
		if (1 <= optiune <= 2) {
			if (optiune == 1) {
				unsigned int opt;
				cout << "Introduceti tipul de sortare dorit(1. Crescator sau 2. Descrescator): ";
				while (true) {
					cin >> opt;
					if (1 <= opt <= 2) {
						if (opt == 1) {
							afiseazaUI(service.sortare_pret_cresc());
							break;
						}
						else if (opt == 2) {
							afiseazaUI(service.sortare_pret_descresc());
							break;
						}
					}
				}
				break;
			}
			else if (optiune == 2) {
				unsigned int opt;
				cout << "Introduceti tipul de sortare dorit(1. Crescator sau 2. Descrescator): ";
				while (true) {
					cin >> opt;
					if (1 <= opt <= 2) {
						if (opt == 1) {
							afiseazaUI(service.sortare_cantitate_cresc());
							break;
						}
						else if (opt == 2) {
							afiseazaUI(service.sortare_cantitate_descresc());
							break;
						}
					}
				}
				break;
			}
		}
	}
}

void Consola::start_aplicatie() {
	while (true) {
		cout << "Meniu:\n";
		cout << "1.Adauga produs\n2.Sterge produs\n3.Modifica pret/cantitate\n4.Filtrare produse\n5.Sortare produse\n6.Afisare produse\n0.Oprirea aplicatie\n";
		int comanda;
		std::cout << "Introduceti comanda dorita!" << std::endl;
		cin >> comanda;
		cout << "\n";
		try {
			switch (comanda)
			{
			case 1:
				adaugaUI();
				break;
			case 2:
				stergeUI();
				break;
			case 3:
				modificaUI();
				break;
			case 4:
				filtrareUI();
				break;
			case 5:
				sortareUI();
				break;
			case 6:
				afiseazaUI(service.getAll());
				break;
			case 0:
				cout << "Aplicatia se va opri\n";
				return;
			default:
				cout<<"Comanda Invalida\n";
			}
		}
		catch (const ProduseRepoException& ex) {
			cout << ex << "\n";
		}
		catch (const ValidateException& ex) {
			cout << ex << "\n";
		}
	}
}