#pragma once
#include <vector>
#include "AbstractRepo.h"
#include "Exceptii.h"
using std::vector;
using std::to_string;

template<typename TElem>
class Repository : public AbstractRepo<TElem> {
private:
	vector<TElem> elems;

public:
	virtual ~Repository() = default;

	virtual void repoAdaugaElem(const TElem& elemX) {
		for (const auto& elem : elems) {
			if (elem.getApartament() == elemX.getApartament()) {
				throw RepoError("Deja exsta un locatar care locuieste la apartamentul: " + to_string(elemX.getApartament()) + "!\n");

			}
		}
		elems.push_back(elemX);
	}

	virtual void repoModifica(const TElem& elemX) {
		for (auto& elem : elems) {
			if (elem.getApartament() == elemX.getApartament()) {
				elem = elemX;
				return;
			}
		}
		throw RepoError("Nu exista locatarul cautat, apartamentul: " + to_string(elemX.getApartament()) + "!\n");
	}

	virtual TElem repoCautaElem(unsigned int ap) {
		auto it = find_if(this->elems.begin(), this->elems.end(),
			[ap](const TElem& elem) {
				return elem.getApartament() == ap;
			});

		if (it != elems.end()) {
			return *it;
		}

		throw RepoError("Nu exista locatarul cautat, apartamentul " + to_string(ap) + "!\n");
	}

	virtual void repoStergeElem(unsigned int ap) {
		for (auto it = elems.begin(); it != elems.end(); ++it) {
			if (it->getApartament() == ap) {
				elems.erase(it);
				return;
			}
		}
		throw RepoError("Nu exista locatarul cautat, apartamentul " + to_string(ap) + "!\n");
	}

	vector<TElem> repoGetAllElems() {
		return this->elems;
	}

	virtual void repoSetAllElems(const vector<TElem>& elemsX) {
		this->elems = elemsX;
	}

	int repoGetSize() {
		return this->elems.size();
	}
};

