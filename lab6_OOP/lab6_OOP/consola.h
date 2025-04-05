#pragma once
#include "produseService.h"
#include "produseRepo.h"

class Consola {
	ProduseService& service;

	void adaugaUI();

	void stergeUI();

	void modificaUI();

	void afiseazaUI(const vector<Produs>& p);

	void filtrareUI();

	void sortareUI();

public:
	Consola(ProduseService& service) : service{ service } {
	}

	Consola(const Consola& ot) = delete;

	void start_aplicatie();
};