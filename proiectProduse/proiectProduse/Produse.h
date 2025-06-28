#pragma once
#include <QString>

class Produs {
private:
	int id;
	QString nume;
	QString tip;
	double pret;
public:
	Produs(int id,QString nume,QString tip,double pret):
		id{id},nume{nume},tip{tip},pret{pret}{ }

	int getId() const { return id; }
	QString getNume() const { return nume; }
	QString getTip() const { return tip; }
	double getPret() const { return pret; }
};