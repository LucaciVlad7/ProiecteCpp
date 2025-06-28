#include "mytablemodel.h"
#include "QBrush"
MyTableModel::MyTableModel(QObject* parent) : QAbstractTableModel(parent) {}

void MyTableModel::setProduse(const std::vector<Produs>& prod) {
    produse = prod;
    std::sort(produse.begin(), produse.end(), [](const Produs& a, const Produs& b) {
        return a.getPret() < b.getPret();
        });
    beginResetModel();
    endResetModel();
}

int MyTableModel::rowCount(const QModelIndex&) const {
    return static_cast<int>(produse.size());
}

int MyTableModel::columnCount(const QModelIndex&) const {
    return 5; // id, nume, tip, pret, numar vocale
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const {
    if (role == Qt::DisplayRole) {
        const auto& p = produse[index.row()];
        switch (index.column()) {
        case 0: return p.getId();
        case 1: return p.getNume();
        case 2: return p.getTip();
        case 3: return p.getPret();
        case 4: return numarVocale(p.getNume());
        default: return {};
        }
        if (role == Qt::BackgroundRole) {
            if (p.getPret() <= limitaPret) {
                return QBrush(Qt::red);
            }
        }
    }
    return {};
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "ID";
        case 1: return "Nume";
        case 2: return "Tip";
        case 3: return "Pret";
        case 4: return "Nr. Vocale";
        }
    }
    return {};
}

int MyTableModel::numarVocale(const QString& nume) const {
    int count = 0;
    for (auto c : nume.toLower()) {
        if (QString("aeiouăîâ").contains(c)) {
            ++count;
        }
    }
    return count;
}

void MyTableModel::setLimitaPret(int val) {
    limitaPret = val;
    emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
}