#pragma once
#include "Executor.h"
#include "dbtypes.h"
namespace db {

class Manipulator
{
public:
    std::pair<DBResult, DBIndex> insertRow(const QString& tableName,
                                           const QVariantList& recordData);
    DBResult deleteRow(const QString& tableName, DBIndex id);
    DBResult updateRow(const QString& tableName, const QVariantList& recordData);
private:
    Executor m_executor;
    QString generateBindString(size_t recordSize) const;
    QString generateInsertQuery(const QString& tableName, size_t recordSize) const;
    QString generateDeleteQuery(const QString& tableName, int id) const;
    QString generateUpdateQuery(const QString& tableName, int id) const;
};

}
