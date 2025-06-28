#pragma once
#include <QString>

class Melodie {
private:
	int id;
	QString titlu;
	QString artist;
	int rank;
public:
	Melodie(int id, const QString& titlu, const QString& artist, int rank) :
		id(id), titlu(titlu), artist(artist), rank(rank) {
	}
	//getters
	int getId() const { return id; }
	QString getTitlu() const { return titlu; }
	QString getArtist() const { return artist; }
	int getRank() const { return rank; }

	//setters
	void setRank(int rank) { this->rank = rank; }
	void setTitlu(const QString& titlu) { this->titlu = titlu; }

	//suprascriere operator =
	Melodie& operator=(const Melodie&) = default;
};