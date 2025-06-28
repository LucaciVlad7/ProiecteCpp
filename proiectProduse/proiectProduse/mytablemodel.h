#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Produse.h"

class MyTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<Produs> produse;

    int numarVocale(const QString& nume) const;

    int limitaPret = 100;
public:
    MyTableModel(QObject* parent = nullptr);

    void setProduse(const std::vector<Produs>& prod);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setLimitaPret(int val);
};
