#include "ui.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
#include <stdexcept>

void uiAdauga(service& serv) {
    unsigned int ap, sup;
    string tip, propr;
    cout << "Introduceti numarul apartamentului: ";
    cin >> ap;
    cout << "Introduceti proprietarul: ";
    cin >> propr;
    cout << "Introduceti suprafata: ";
    cin >> sup;
    cout << "Introduceti tipul: ";
    cin >> tip;
    Locatar locatar{ ap,propr,sup,tip };
    serv.serviceAdaugaLocatar(locatar);
    cout << "Locatarul a fost adauga\n";
}

void uiModifica(service& serv) {
    unsigned int ap, sup;
    string tip, propr;
    cout << "Introduceti numarul apartamentului: ";
    cin >> ap;
    cout << "Introduceti proprietarul: ";
    cin >> propr;
    cout << "Introduceti suprafata: ";
    cin >> sup;
    cout << "Introduceti tipul: ";
    cin >> tip;
    Locatar locatar{ ap,propr,sup,tip };
    serv.serviceModificaLocatar(locatar);
    cout << "Locatarul a fost modificat!\n";
}

void afisareLocatar(const Locatar& locatar) {
    cout << " - Nr. apartament: " << locatar.getApartament() << "\n";
    cout << " - Proprietar: " << locatar.getProprietar() << "\n";
    cout << " - Suprafata: " << locatar.getSuprafata() << "\n";
    cout << " - Tip: " << locatar.getTip() << "\n";
}

void uiCauta(service& serv) {
    unsigned int ap;
    cout << "Introduceti numarul apartamentului: \n";
    cin >> ap;
    Locatar locatarCautat = serv.serviceCautaLocatar(ap);
    afisareLocatar(locatarCautat);
}

void uiSterge(service& serv) {
    unsigned int ap;
    cout << "Nr. aprtamanetului: ";
    cin >> ap;
    serv.serviceStergeLocatar(ap);
    cout << "Locatarul a fost sters!\n";
}

void uiFiltrare(const service& serv) {
    cout << "Alegeti modul de filtrare:\n1. Dupa Tip\n2. Dupa Suprafata\n>>>";
    int mod;
    cin >> mod;
    cin.ignore();
    if (mod == 1) {
        string tip;
        cout << "Introduceti Tipul: ";
        cin >> tip;
        mvector<Locatar> locatari(serv.serviceFiltrareTip(tip));
        if (locatari.getSize() == 0) {
            cout << "Nu exista apartamente de tipul: " << tip << "!\n";
        }
        for (int i = 0;i < locatari.getSize();i++)
            afisareLocatar(locatari[i]);
    }
    if (mod == 2) {
        unsigned int sup;
        cout << "Introduceti Suparafata: ";
        cin >> sup;
        mvector<Locatar> locatari(serv.serviceFiltrareSuprafata(sup));
        if (locatari.getSize() == 0) {
            cout << "Nu exista apartamente cu suprafata mai mare decat: " << sup << "!\n";
        }
        for (int i = 0;i < locatari.getSize();i++)
            afisareLocatar(locatari[i]);
    }
}

void uiAfiseazaTot(mvector<Locatar> loc) {
    for (int i = 0; i < loc.getSize(); i++)
        afisareLocatar(loc[i]);
}

void uiSortare(service& serv) {
    cout << "Alegeti modul de sortare:\n1. Dupa Proprietar\n2. Dupa Suprata\n3. Dupa tip si Suprafata>>>";
    int mod;
    cin >> mod;
    if (1 <= mod && mod <= 3) {
        cout << "Mod invalid\n";
    }
    else {
        serv.serviceSortare(mod);
        uiAfiseazaTot(serv.getElems());
    }
}


void ui::runApp() {
    while (true) {
        try {
            string comand;
            cout << "Introduceti Comanda: ";
            cin >> comand;
            if (comand == "adauga")
                uiAdauga(this->serv);
            if (comand == "modifica")
                uiModifica(this->serv);
            if (comand == "cauta")
                uiCauta(this->serv);
            if (comand == "sterge")
                uiSterge(this->serv);
            if (comand == "filtrare")
                uiFiltrare(this->serv);
            if (comand == "sortare")
                uiSortare(this->serv);
            if (comand == "exit")
                exit(0);
            else
                cout << "Comanda nu exista";


        }
        catch (const std::runtime_error& e) {
            cout << e.what() << endl;
        }

    }
}