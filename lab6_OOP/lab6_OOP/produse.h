#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;

class Produs {
	unsigned int id;
	std::string tip;
	std::string producator;
	std::string model;
	unsigned int pret;
	unsigned int cantitate;
public:
	Produs(int id, const string tip, const string producator, const string model, int pret, int cantitate) : id(id), tip(tip), producator(producator), model(model), pret(pret), cantitate(cantitate) {
	
	}

	//constructor de copiere
	Produs(const Produs& p) : id(p.id), tip(p.tip), producator(p.producator), model(p.model), pret(p.pret), cantitate(p.cantitate) {
		//std::cout << "copiere" << std::endl;
	}

	unsigned int getId() const {
		return id;
	}

	string getTip() const{
		return tip;
	}

	string getProducator() const{
		return producator;
	}

	string getModel() const {
		return model;
	}

	unsigned int getPret() const{
		return pret;
	}

	unsigned int getCantitate() const {
		return cantitate;
	}

	void setCantitate(int newCantitate) { cantitate = newCantitate; }

	void setPrice(int price) { pret = price; }

	string to_string_print();
};

bool comparePret(Produs p1, Produs p2);

bool compareCantitate(Produs p1, Produs p2);