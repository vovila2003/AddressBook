#pragma once
#include "dbtypes.h"
#include <memory>

namespace db {

class Processor {
public:
    Processor();
    ~Processor();
    std::pair<DBResult, std::vector<DBEntry>> requestTableData(DBTables table);
    DBResult requestUpdateData();
    DBResult requestDeleteData(DBTables table, const db::DBEntry &entry);
    std::pair <DBResult, DBIndex> requestAddData(DBTables table, const DBEntry& entry);
private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;

};


}
