#pragma once
#include <vector>
#include <memory>
#include "contact.h"


namespace db {
class Processor;
}

class ContactsReader
{
public:
    ContactsReader();
    ~ContactsReader();
    std::pair<bool,
             std::vector<Contact> > requestContactsBrowse();
    std::pair<bool, int> requestAddContact(const Contact& contact);
    bool requestDeleteContact(const Contact& contact);
    bool requestEditContact(const Contact& contact);
private:
    std::unique_ptr<db::Processor> m_processor;
};
