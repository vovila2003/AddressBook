#include "Manipulator.h"
#include "dbmapper.h"
#include <sstream>
#include <QDebug>

namespace db {

std::pair<DBResult, DBIndex> Manipulator::insertRow(const QString &tableName, const QVariantList &recordData)
{
    if (recordData.isEmpty()) {
        return {DBResult::FAIL, -1};
    }
    auto tempRecordData = recordData;
    tempRecordData.pop_front(); // remove id
    const QString& query {generateInsertQuery(tableName, static_cast<size_t>(tempRecordData.size()))};
    const auto& result {m_executor.execute(query, tempRecordData)};
    return {result.first, result.second.lastInsertId().toInt()};
}

QString Manipulator::generateBindString(size_t recordSize) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings),
                recordSize,
                "?,");
    std::string bindString = bindings.str();
    bindString.pop_back(); // remove last ","
    return QString::fromStdString(bindString);
}

QString Manipulator::generateInsertQuery(const QString &tableName, size_t recordSize) const
{
    QString query {"INSERT INTO " + tableName + " ( " + TablesMapping.at(tableName) + " ) " +
                  "Values ("};
    query += generateBindString(recordSize);
    query += ")";

    return query;
}

}
