#pragma once
#include "repository.h"

class service {
private:
	repository& repo;
public:
	service(repository &repo) : repo{repo}{}

	/// <summary>
	/// Adauga un locatar daca nu exista, arunca eroare altfel
	/// </summary>
	/// <param name="locatar"></param>: obiect de tip locatar
	void serviceAdaugaLocatar(const Locatar& locatar);

	/// <summary>
	/// Modifica locatarul cu acelasi nr de apartament, arunca eroare daca nu exista
	/// </summary>
	/// <param name="locatar"></param>: obiect de tip locatar
	void serviceModificaLocatar(const Locatar& locatar);

	/// <summary>
	/// Returneaza un locatar daca e existenta
	/// </summary>
	/// <param name="ap"></param> : nr de apartament
	/// <returns></returns>: Locatarul daca exista
	Locatar serviceCautaLocatar(unt ap);

	/// <summary>
	/// Sterge un locatar
	/// </summary>
	/// <param name="ap"></param> : nr de apartament
	void serviceStergeLocatar(unt ap);

	/// <summary>
	/// Filtreaza locatarii dupa tipul de apartament
	/// </summary>
	/// <param name="tip"></param> : tipul apartamentului
	/// <returns></returns>
	mvector<Locatar> serviceFiltrareTip(const string& tip) const;

	/// <summary>
	/// Filtreaza locatarii dupa suprafata apartamentului
	/// </summary>
	/// <param name="tip"></param> : suprafata apartamentului
	/// <returns></returns>
	mvector<Locatar> serviceFiltrareSuprafata(unt suprafata) const;

	//sortare
	void serviceSortare(int mod);

	mvector<Locatar> getElems();

	~service() = default;
};