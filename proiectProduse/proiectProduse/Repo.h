#pragma once
#include "Produse.h"

class Repo{
private:
	QString filename;
	std::vector<Produs> produse;
public:
	Repo(const QString& filename);

	void loadFromFile();
	void saveToFile();
	std::vector<Produs> exportProduseRepo() const;
	void adaugaRepo(const Produs& p);
};

