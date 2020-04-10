#include "contactsreader.h"
#include "Processor.h"
#include "dbtypes.h"
#include <QDebug>

ContactsReader::ContactsReader()
    : m_processor {new db::Processor {}}
{
}

ContactsReader::~ContactsReader()
{
}

std::vector<Contact> transformEntryToContact(const std::vector<db::DBEntry>& source){
    std::vector<Contact> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const db::DBEntry& entry) {
        return Contact {entry[0].toInt(),
                        entry[1].toString(),
                        entry[2].toString(),
                        entry[3].toString()};
    });
    return target;
}

db::DBEntry transformContactToEntry(const Contact& source){
    db::DBEntry target;
    target << source.id()
           << source.firstName()
           << source.surame()
           << source.phone();
    return target;
}


std::pair<bool, std::vector<Contact> > ContactsReader::requestContactsBrowse()
{
    db::DBResult result;
    std::vector<db::DBEntry> entries;
    std::tie(result, entries) = m_processor->requestTableData(db::DBTables::Contacts);

    return {result == db::DBResult::OK,
                transformEntryToContact(entries)};
}

std::pair <bool, int> ContactsReader::requestAddContact(const Contact &contact)
{
    db::DBResult result;
    int id = -1;
    std::tie(result, id) = m_processor->requestAddData(db::DBTables::Contacts, transformContactToEntry(contact));
    return {result == db::DBResult::OK, id};
}

bool ContactsReader::requestDeleteContact(const Contact &contact)
{
    db::DBResult result;
    result = m_processor->requestDeleteData(db::DBTables::Contacts, contact.id());
    return result == db::DBResult::OK;
}

bool ContactsReader::requestEditContact(const Contact &contact)
{
    db::DBResult result;
    result = m_processor->requestUpdateData(db::DBTables::Contacts, transformContactToEntry(contact));
    return result == db::DBResult::OK;
}
