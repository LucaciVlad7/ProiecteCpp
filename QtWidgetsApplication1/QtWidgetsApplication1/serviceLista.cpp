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

void ServiceLista::exportaLista(const string& filename, int mod) const {
    // Deschide fișierul pentru scriere
    std::ofstream fout(filename);
    if (!fout) {
        throw ServiceError("Eroare la deschiderea fișierului pentru export!");
    }

    if (mod == 1) {
        fout << "Apartament,Proprietar,Suprafata,Tip\n";

        for (const auto& oferta : lista) {
            fout << oferta.getApartament() << ","
                << oferta.getProprietar() << ","
                << oferta.getSuprafata() << ","
                << oferta.getTip() << ",";
        }
    }
    if (mod == 2) {
        // Scriem începutul fișierului HTML
        fout << "<!DOCTYPE html>\n";
        fout << "<html>\n";
        fout << "<head>\n";
        fout << "  <meta charset=\"UTF-8\">\n";
        fout << "  <title>Lista de oferte</title>\n";
        fout << "  <style>\n"
            "    table { border-collapse: collapse; width: 100%; }\n"
            "    th, td { border: 1px solid #ddd; padding: 8px; }\n"
            "    th { background-color: #f2f2f2; }\n"
            "  </style>\n";
        fout << "</head>\n";
        fout << "<body>\n";
        fout << "  <h1>Cos de oferte</h1>\n";

        // Scriem un tabel cu oferte
        fout << "  <table>\n";
        fout << "    <tr>\n";
        fout << "      <th>Id</th>\n";
        fout << "      <th>Denumire</th>\n";
        fout << "      <th>Destinatie</th>\n";
        fout << "      <th>Tip</th>\n";
        fout << "      <th>Pret</th>\n";
        fout << "    </tr>\n";

        // Iterăm prin vectorul de oferte și le scriem rând cu rând
        for (const auto& oferta : this->lista) {
            fout << "    <tr>\n";
            fout << "      <td>" << oferta.getApartament() << "</td>\n";
            fout << "      <td>" << oferta.getProprietar() << "</td>\n";
            fout << "      <td>" << oferta.getSuprafata() << "</td>\n";
            fout << "      <td>" << oferta.getTip() << "</td>\n";
            fout << "    </tr>\n";
        }

        // Închidem tabelul și documentul HTML
        fout << "  </table>\n";
        fout << "</body>\n";
        fout << "</html>\n";
    }
}

int ServiceLista::getSize() {
	return this->lista.size();
}