#include "Processor.h"
#include "Selector.h"
#include "dbmapper.h"
#include "Manipulator.h"
#include <mutex>

namespace db {

struct Processor::ProcessorPrivate {
    Selector selector;
    Manipulator manipulator;



/*
#ifdef BUILD_TESTS
    std::once_flag initialized;
    void insertMockData();
#endif
*/


};

Processor::Processor()
    : m_d {new ProcessorPrivate {}}
{
}

Processor::~Processor()
{

}
/*
#ifdef BUILD_TESTS
void Processor::ProcessorPrivate::insertMockData() {
    manipulator.insertRow("Contacts", {{"Vladimir", "Shalaginov", "+3625485623"}});
    manipulator.insertRow("Contacts", {{"Ivan", "Shalaginov", "+43523453"}});
    manipulator.insertRow("Contacts", {{"Nikita", "Shalaginov", "+1454243"}});
    manipulator.insertRow("Contacts", {{"Egor", "Shalaginov", "+233438438"}});
    manipulator.insertRow("Contacts", {{"Olga", "Shalaginova", "+14624842344"}});
}
#endif
*/

std::pair<DBResult, std::vector<DBEntry> > Processor::requestTableData(DBTables table)
{
    /*
#ifdef BUILD_TESTS
    auto inserter = [this] {
        m_d->insertMockData();
    };
    std::call_once(m_d->initialized, inserter);
#endif
*/
    const auto& result {m_d->selector.selectAll(TableMapper.at(table))};
    return result;
}


}
