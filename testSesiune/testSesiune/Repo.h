#pragma once
#include "Melodii.h"
#include <iostream>

class Repo{
private:
	QString filename;
	std::vector<Melodie> melodii;
public:
	/*
	Constructor
	param: filename
	*/
	Repo(const QString& filename);

	/*
	citeste din fisier
	*/
	void loadFromFile();

	/*
	scrie in fisier
	*/
	void saveToFile();

	/*
	Sterge entitate dupa id
	param:id-int
	Arunca eroare daca nu exista id-ul sau daca este ultima melodie a unui artist
	*/
	void stergeRepo(int id);

	/*
	Modifica rankul dupa id
	param: id-int,rank-int
	*/
	void modificaRank(int id, int rank);

	/*
	Modifica titlul dupa id
	param: id-int,titlu-QString
	*/
	void modificaTitlu(int id,QString titlu);

	/*
	Returneaza lista cu obiecte din repo
	param: -
	return: std::vector<Melodie>
	*/
	const std::vector<Melodie>& getAllMelodii() const ;
};

