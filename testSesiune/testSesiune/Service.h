#pragma once
#include "Repo.h"
#include <iostream>

class Service{
private:
	Repo& repo;
	std::vector<Melodie> currentList;
public:
	/*
	Constructor
	param: Repo
	*/
	Service(Repo& repo);

	/*
	Returneaza lista din repo sortata crescator dupa rank
	param: -
	return: std::vector<Melodie>
	*/
	const std::vector<Melodie>& sortareRank();

	/*
	Returneaza lista din repo cu obiecte
	param: -
	return: std::vector<Melodie>
	*/
	const std::vector<Melodie>& importMelodii();

	/*
	Calculeaza nr de melodii cu acelasi rank
	param: rank - int
	return: int
	*/
	int melodiiCuAcelasiRank(int rank);


	/*
	Modifica rankul dupa id
	param: id - int,rank - int
	*/
	void modificaRank(int id, int rank);

	/*
	Modifica titlul dupa id
	param: id - int,titlu - QString
	*/
	void modificaTitlu(int id, QString titlu);

	/*
	Sterge entitate dupa id
	param:id - int
	Arunca eroare daca nu exista id-ul sau daca este ultima melodie a unui artist
	*/
	void stergereMelodie(int id);
};

