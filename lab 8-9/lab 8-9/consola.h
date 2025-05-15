#pragma once
#include "locatar.h"
#include "Repository.h"
#include "service.h"
#include "serviceLista.h"

class Consola{
private:
	Repository<Locatar>& repo;
	Service& service;
	ServiceLista& serviceLista;
public:
	Consola(Repository<Locatar>& repoX,Service& serviceX, ServiceLista& serviceListaX):
		repo{repoX},service{serviceX},serviceLista{serviceListaX}{ }

	void runConsola();

	void consolaAdauga();
	void consolaModificaLocatar();
	void consolaCautaLocatar();
	void consolaStergeLocatar();
	void consolaAfisare();
	void consolaSortare();
	
	void consolaAdaugaLista();

	void consolaGolesteLista();

	void consolaGenereazaLista();

	void consolaExportaLista();

	void consolaUndo();
};

