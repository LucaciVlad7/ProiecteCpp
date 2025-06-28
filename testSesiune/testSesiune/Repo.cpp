#include "Repo.h"
#include "Exceptii.h"
#include <QFile>
#include <QTextStream>

/*
Constructor
param: filename
*/
Repo::Repo(const QString& filename) :filename(filename) {
	loadFromFile();
}

/*
citeste din fisier
*/
void Repo::loadFromFile() {
	melodii.clear();
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly)) {
		QTextStream in(&file);
		while (!in.atEnd()) {
			QString line = in.readLine();
			QStringList parts = line.split(',');
			if (parts.size() == 4) {
				int id = parts[0].toInt();
				QString titlu = parts[1];
				QString artist = parts[2];
				int rank = parts[3].toInt();
				melodii.emplace_back(id, titlu, artist, rank);
			}
		}
		file.close();
	}
}

/*
scrie in fisier
*/
void Repo::saveToFile() {
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly)) {
		QTextStream out(&file);
		for (const auto& j : melodii) {
			out << j.getId() << ","
				<< j.getTitlu() << ","
				<< j.getArtist() << ","
				<< j.getRank() << "\n";
		}
		file.close();
	}
}

/*
Modifica rankul dupa id
param: id-int,rank-int
*/
void Repo::modificaRank(int id, int rank) {
	for (auto& m : melodii) {
		if (m.getId() == id) {
			m.setRank(rank);
			break;
		}
	}
	saveToFile();
}

/*
Modifica titlul dupa id
param: id-int,titlu-QString
*/
void Repo::modificaTitlu(int id, QString titlu) {
	for (auto& m : melodii) {
		if (m.getId() == id) {
			m.setTitlu(titlu);
			break;
		}
	}
	saveToFile();
}

/*
Sterge entitate dupa id
param:id-int
Arunca eroare daca nu exista id-ul sau daca este ultima melodie a unui artist
*/
void Repo::stergeRepo(int id) {
	QString artist;
	bool gasit = false;
	for (const auto& m : melodii) {
		if (m.getId() == id) {
			artist = m.getArtist();
			gasit = true;
			break;
		}
	}

	if (!gasit) {
		throw RepoError("Nu exista id-ul!");
	}

	int count = 0;
	for (const auto& m : melodii) {
		if (m.getArtist() == artist) {
			count++;
		}
	}

	if (count == 1) {
		throw RepoError("Nu se poate șterge: este ultima melodie a acestui artist.");
	}

	for (auto it = melodii.begin(); it != melodii.end(); ++it) {
		if (it->getId() == id) {
			melodii.erase(it);
			saveToFile();
			return;
		}
	}

	throw RepoError("Nu exista id-ul!");
}

/*
Returneaza lista cu obiecte din repo
param: -
return: std::vector<Melodie>
*/
const std::vector<Melodie>& Repo::getAllMelodii() const {
	return melodii;
}