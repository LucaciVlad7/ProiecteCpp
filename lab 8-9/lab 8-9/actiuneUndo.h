#pragma once

#include "locatar.h"
#include "repository.h"

class ActiuneUndo {
public:
	virtual ~ActiuneUndo() = default;

	virtual void doUndo() = 0; 
};

class UndoAdaugaLocatar : public ActiuneUndo {
private:
	Repository<Locatar>& repo;
	unsigned int ap;
public:
	UndoAdaugaLocatar(Repository<Locatar>& repoX,unsigned int apX):
		repo{repoX},ap{apX}{ }
	void doUndo() override {
		repo.repoStergeElem(ap);
	}
};

class UndoModificaLocatar :public ActiuneUndo {
private:
	Repository<Locatar>& repo;
	Locatar locatarvechi;
public:
	UndoModificaLocatar(Repository<Locatar>& repoX,const Locatar& locatarX):
		repo{repoX},locatarvechi{locatarX}{ }
	void doUndo() override {
		repo.repoModifica(locatarvechi);
	}
};

class UndoStergeLocatar :public ActiuneUndo {
private:
	Repository<Locatar>& repo;
	Locatar locatarVechi;
public:
	UndoStergeLocatar(Repository<Locatar>& repoX,const Locatar& locatarX):
		repo{repoX},locatarVechi{locatarX}{ }
	void doUndo() override {
		repo.repoAdaugaElem(locatarVechi);
	}
};