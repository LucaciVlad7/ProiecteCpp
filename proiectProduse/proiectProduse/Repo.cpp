#include "Repo.h"
#include <QFile>
#include <QTextStream>
#include "Exceptii.h"

Repo::Repo(const QString& filename) :
	filename{ filename } {
	loadFromFile();
}

void Repo::loadFromFile() {
	produse.clear();
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly)) {
		QTextStream in(&file);
		while (!in.atEnd()) {
			QString line = in.readLine();
			QStringList parts = line.split(',');
			if (parts.size() == 4) {
				int id = parts[0].toInt();
				QString nume = parts[1];
				QString tip = parts[2];
				double pret = parts[3].toDouble();
				produse.emplace_back(id, nume, tip, pret);
			}
		}
		file.close();
	}
}

void Repo::saveToFile() {
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly)) {
		QTextStream out(&file);
		for (const auto& j : produse) {
			out << j.getId() << ","
				<< j.getNume() << ","
				<< j.getTip() << ","
				<< j.getPret() << "\n";
		}
		file.close();
	}
}

std::vector<Produs> Repo::exportProduseRepo() const {
	return produse;
}

void Repo::adaugaRepo(const Produs& p) {
	for (const auto& pr : produse) {
		if (p.getId() == pr.getId()) {
			throw RepoError("Exista deja");
		}
	}
	produse.push_back(p);
	saveToFile();
}