#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent)
{
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex titleIndex = sourceModel()->index(source_row, 0, source_parent);
    bool isContains = (((sourceModel()->data(titleIndex)).toString()).contains(_title, Qt::CaseInsensitive));
    if (isContains)
        return true;
    else
        return false;
}

void ProxyModel::setTitle(const QString& string)
{
    _title = string;
    invalidateFilter();
}
