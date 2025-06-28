#pragma once
#include <QAbstractTableModel>
#include "Service.h"

class MelodiiModel :public QAbstractTableModel {
	Q_OBJECT
private:
	Service& service;
public:
	MelodiiModel(Service& srv) : service{ srv } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return service.sortareRank().size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return {};

        const auto& melodii = service.sortareRank();
        const Melodie& m = melodii.at(index.row());

        switch (index.column()) {
        case 0: return m.getId();
        case 1: return m.getTitlu();
        case 2: return m.getArtist();
        case 3: return m.getRank();
        case 4: return service.melodiiCuAcelasiRank(m.getRank());
        default: return {};
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "ID";
            case 1: return "Titlu";
            case 2: return "Artist";
            case 3: return "Rank";
            case 4: return "Nr. cu același Rank";
            }
        }
        return {};
    }

    void actualizeaza() {
        beginResetModel();
        endResetModel();
    }
};