#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H
#include <QAbstractListModel>
#include <vector>
#include "contact.h"
#include "contactsreader.h"

class ContactModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactModel();

    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Q_INVOKABLE bool addData(const QString& name, const QString& surname, const QString& phone);
    Q_INVOKABLE bool editData(int index, const QString& name, const QString& surname, const QString& phone);
    Q_INVOKABLE bool deleteData(int index);
    void debug();

private:
    ContactsReader mContactsReader;
    std::vector<Contact> mContacts;
    enum ContactRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        SurnameRole,
        PhoneNumberRole
    };
    bool updateContacts();

};

#endif // CONTACTMODEL_H
