#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>

class ProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject* parent = 0);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void setTitle(const QString& string);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
private:
    QString _title;
};

#endif // PROXYMODEL_H
