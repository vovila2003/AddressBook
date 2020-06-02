#pragma once
#include "dbtypes.h"
#include <memory>

namespace db {

class Processor {
public:
    Processor();
    ~Processor();
    std::pair<DBResult, std::vector<DBEntry>> requestTableData(DBTables table);
    DBResult requestUpdateData(DBTables table, const db::DBEntry &entry);
    DBResult requestDeleteData(DBTables table, db::DBIndex id);
    std::pair<DBResult, DBIndex> requestAddData(DBTables table, const db::DBEntry &entry);
private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;

};


}
