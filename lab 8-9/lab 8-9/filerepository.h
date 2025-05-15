#pragma once
#include <fstream>

#include "Repository.h"

using namespace std;

template<typename TElem>
class FileRepository : public Repository<TElem> {
private:
	string filename;

	void loadFromFile() {
		ifstream fin(this->filename);
		if (!fin.is_open()) {
			Repository<TElem>::repoSetAllElems({});
			return;
		}

		string line;
		vector<TElem> elems;
		while (getline(fin, line)) {
			TElem elem = TElem::lineToTElem(line);
			elems.push_back(elem);
		}
		Repository<TElem>::repoSetAllElems(elems);
		fin.close();
	}

	void storeToFile() {
		ofstream fout(this->filename);

		for (const auto& elem : Repository<TElem>::repoGetAllElems()) {
			string line = TElem::TElemToLine(elem);
			fout << line << endl;
		}
		fout.close();
	}

public:
	explicit FileRepository(const string& filenameX) :Repository<TElem>(), filename{ filenameX } {
		this->loadFromFile();
	}

	~FileRepository() override {
		this->storeToFile();
	}

	void repoAdaugaElem(const TElem& elemX) override {
		Repository<TElem>::repoAdaugaElem(elemX);
		this->storeToFile();
	}

	void repoModifica(const TElem& elemX) override {
		Repository<TElem>::repoModifica(elemX);
		this->storeToFile();
	}

	TElem repoCautaElem(unsigned int ap) override {
		return Repository<TElem>::repoCautaElem(ap);
	}
	void repoStergeElem(unsigned int ap) override {
		Repository<TElem>::repoStergeElem(ap);
		this->storeToFile();
	}

	void repoSetAllElems(const vector<TElem>& elemsX) override {
		Repository<TElem>::repoSetAllElems(elemsX);
		this->storeToFile();
	}

};