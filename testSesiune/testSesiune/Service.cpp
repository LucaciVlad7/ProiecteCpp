#include "Service.h"
/*
Constructor
param: Repo
*/
Service::Service(Repo& repo):repo{repo}{
	currentList = repo.getAllMelodii();
}

/*
Returneaza lista din repo sortata crescator dupa rank
param: -
return: std::vector<Melodie>
*/
const std::vector<Melodie>& Service::sortareRank() {
	currentList = repo.getAllMelodii();
	std::sort(currentList.begin(), currentList.end(), [](const Melodie& a, const Melodie& b) {
		return a.getRank() < b.getRank();
		});
	return currentList;
}

/*
Calculeaza nr de melodii cu acelasi rank
param: rank-int
return: int 
*/
int Service::melodiiCuAcelasiRank(int rank) {
	int contor = 0;
	for (const auto& m : currentList) {
		if (m.getRank() == rank) {
			contor++;
		}
	}
	return contor;
}

/*
Returneaza lista din repo
param: -
return: std::vector<Melodie>
*/
const std::vector<Melodie>& Service::importMelodii() {
	return repo.getAllMelodii();
}

/*
Modifica rankul dupa id
param: id-int,rank-int
*/
void Service::modificaRank(int id, int rank) {
	repo.modificaRank(id, rank);
}

/*
Modifica titlul dupa id
param: id-int,titlu-QString
*/
void Service::modificaTitlu(int id, QString titlu) {
	repo.modificaTitlu(id, titlu);
}

/*
Sterge entitate dupa id
param:id-int
Arunca eroare daca nu exista id-ul sau daca este ultima melodie a unui artist
*/
void Service::stergereMelodie(int id) {
	repo.stergeRepo(id);
}