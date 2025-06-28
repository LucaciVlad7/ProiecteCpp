#pragma once
#include "Repo.h"
#include "Validator.h"

class Service{
public:
	Repo& repo;
	Validator& val;
	std::vector<Produs> listServ;
public:
	Service(Repo& repo, Validator& val);
	std::vector<Produs> exportSortat();
	void adaugaServ(const Produs& p);
};

