#pragma once
#include "Locatar.h"
#include "AbstractRepo.h"
#include "service.h"
#include "serviceLista.h"
#include "Exceptii.h"

class Consola{
private:
	AbstractRepo<Locatar>& repo;
	Service& service;
	ServiceLista& serviceLista;

public:
	Consola(AbstractRepo<Locatar>& repoX, Service& serviceX, ServiceLista& serviceListaX) :
		repo{ repoX }, service{ serviceX }, serviceLista{ serviceListaX } {
	}

	void runConsola();

	void consolaAdauga();
	void consolaModificaLocatar();
	void consolaCautaLocatar();
	void consolaStergeLocatar();
	void consolaAfisare();
	void consolaFiltrare();
	void consolaSortare();

	void consolaAdaugaLista();

	void consolaGolesteLista();

	void consolaGenereazaLista();

	void consolaExportaLista();

	void consolaListeazaLista();

	void consolaUndo();
};

