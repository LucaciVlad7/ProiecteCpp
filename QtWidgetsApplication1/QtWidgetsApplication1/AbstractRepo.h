#pragma once
#include <vector>

using namespace std;
template<typename TElem>
class AbstractRepo {
public:
	virtual ~AbstractRepo() = default;
	virtual void repoAdaugaElem(const TElem& elemX) = 0;
	virtual void repoModifica(const TElem& elemX) = 0;
	virtual TElem repoCautaElem(unsigned int ap) = 0;
	virtual void repoStergeElem(unsigned int ap) = 0;
	virtual void repoSetAllElems(const vector<TElem>& elemsX)=0;
	virtual vector<TElem> repoGetAllElems() = 0;
	virtual int repoGetSize() = 0;
};