#include "produse.h"


string Produs::to_string_print() {
	return "Id: " + std::to_string(this->id) + " Tip: " + this->tip + " Producator: " 
		+ this->producator + " Model: " + this->model + " Pret: " + std::to_string(this->pret) +
		" Cantitate: " + std::to_string(this->cantitate);
}

bool comparePret(Produs p1, Produs p2) {
	return p1.getPret() < p2.getPret();
}

bool compareCantitate(Produs p1, Produs p2) {
	return p1.getCantitate() < p2.getCantitate();
}