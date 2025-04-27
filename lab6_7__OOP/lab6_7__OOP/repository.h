#pragma once

#include "mvector.h"
#include "Locatar.h"
#define TElem Locatar
#define unt unsigned int

class repository {
public:
	mvector<TElem> elems;
	int (*get_id)(const TElem&);

public:
	repository(int (*getIdElem)(const TElem&)) : get_id(getIdElem) {}

	/// Adauga un element in repo
	/// <param name="elem"></param> : element generic
	void adaugaElem(const TElem& elem);

	/// Suprascrie elementul cu acelasi nr de apartament sau arunca eroare in cazul in care nu exista
	/// <param name="elem"></param>: element generic
	void modificaElem(const TElem& elem);

	/// Returneaza elementul din repository cu nr de apartament dat ca parametru sau arunca eroare
	/// daca nu il gaseste
	/// <param name="ap"></param>: nr de apartament
 	/// <returns></returns>: elementul cu nr de apartament dat ca parametru daca exista
	TElem cautaElem(const unt& ap);


	/// <summary>
	/// Sterge elementul cu nr de apartament identic cu cel dat, arunca eroare altfel
	/// </summary>
	/// <param name="ap"></param>: nr de apartament al elementului care trebuie sters
	void stergeElem(const unt& ap);

	/// <summary>
	/// Verifica daca exista elementul cautat
	/// </summary>
	/// <param name="ap"></param>: nr de apartament al elementului
	/// <returns></returns>: true daca exista elemetul, false altfel
	bool existaElem(const unt& ap);

	///Returneaza toate elementele intr-un vector
	mvector<TElem> getAllElems();

	mvector<TElem> setElems(const mvector<TElem>& elemsnew);

	//Pt. teste
	unt getSize() const;
};