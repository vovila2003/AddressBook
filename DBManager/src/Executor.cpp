#include "Executor.h"
#include <QDebug>
#include "dbtypes.h"
#include <QSqlError>

db::Executor::Executor()
    : m_connectionManager {ConnectionManager::instance()}
{

}

std::pair<db::DBResult,
          QSqlQuery> db::Executor::execute(const QString &queryText,
                                           const DBEntry &args)
{
    if (!m_connectionManager.isValid()) {
        qCritical() << "Database is not valid. Skip!";
        return {DBResult::FAIL, QSqlQuery {}};
    }
    QSqlQuery query {queryText};

    for (int i = 0; i < args.size(); ++i) {
        query.bindValue(i, args[i]);
    }

    DBResult result {DBResult::OK};

    if (!query.exec() && query.lastError().isValid()) {
        qCritical() << query.lastError().text() << query.lastQuery();
        result = DBResult::FAIL;
    }

    return  {result, query};
}
