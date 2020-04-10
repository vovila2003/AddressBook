#include "contactmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactModel::ContactModel()
{
    const bool updateResult {updateContacts()};
    if (!updateResult) {
        qWarning() << "Update failed";
    }
}

void ContactModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<ContactModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}

int ContactModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(mContacts.size());
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }
    const Contact& contact {mContacts.at(static_cast<size_t>(index.row()))};
    switch (role) {
    case ContactRoles::NameRole: {
        return QVariant::fromValue(contact.firstName());
    }
    case ContactRoles::SurnameRole: {
        return QVariant::fromValue(contact.surame());
    }
    case ContactRoles::PhoneNumberRole: {
        return QVariant::fromValue(contact.phone());
    }
    default: {
        return true;
    }
    }
}

QHash<int, QByteArray> ContactModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContactRoles::NameRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNumberRole] = "phoneNumber";
    return roles;
}

bool ContactModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return false;
    }

    switch (role) {
    case ContactRoles::NameRole: {
        mContacts.at(static_cast<size_t>(index.row())).setFirstName(value.toString());
        break;
    }
    case ContactRoles::SurnameRole: {
        mContacts.at(static_cast<size_t>(index.row())).setSurname(value.toString());
        break;
    }
    case ContactRoles::PhoneNumberRole: {
        mContacts.at(static_cast<size_t>(index.row())).setPhone(value.toString());
        break;
    }
    default: {
        return false;
    }
    }
    emit dataChanged(index, index, QVector<int>() << role);
    return true;
}

bool ContactModel::addData(const QString &name, const QString &surname, const QString &phone)
{
    bool result = false;
    int id = -1;
    auto newContact {Contact(id, name, surname, phone)};
    std::tie(result, id) = mContactsReader.requestAddContact(newContact); // insert to db
    qDebug() << "debuging2: " << result << id;
    if (!result) {
        return result;
    }
    newContact.setId(id);
    int index = static_cast<int>(mContacts.size());
    this->beginInsertRows(QModelIndex(), index, index);
    mContacts.push_back(newContact);
    result = this->insertRow(index);
    this->endInsertRows();
    index = static_cast<int>(mContacts.size());
    emit dataChanged(createIndex(index, 0), createIndex(index, 0), QVector<int>() << IdRole << NameRole << SurnameRole << PhoneNumberRole);

    return result;
}

bool ContactModel::editData(int index, const QString &name, const QString &surname, const QString &phone)
{
    if (!this->index(index, 0).isValid()){
        return false;
    }
    bool result = true;
    result &= setData(this->index(index, 0), name, NameRole);
    result &= setData(this->index(index, 0), surname, SurnameRole);
    result &= setData(this->index(index, 0), phone, PhoneNumberRole);
    return result;
}

bool ContactModel::deleteData(int index)
{
    if (index < 0 || !this->index(index, 0).isValid()) {
        return false;
    }
    this->beginRemoveRows(QModelIndex(), index, index);
    mContacts.erase(mContacts.begin() + index);
    std::vector<Contact>(mContacts).swap(mContacts);
    this->removeRow(index);
    this->endRemoveRows();
    emit dataChanged(createIndex(index,0), createIndex(static_cast<int>(mContacts.size()), 0), QVector<int>() << NameRole << SurnameRole << PhoneNumberRole);
    return true;
}

void ContactModel::debug()
{
    qDebug() << "Contact's list:-----------------------";
    for (auto ind : mContacts){
        qDebug() << ind.firstName() << ind.surame() << ind.phone();
    }
}

bool ContactModel::updateContacts()
{
    bool requestResult {false};
    std::vector<Contact> contactsResult;
    std::tie(requestResult, contactsResult) = mContactsReader.requestContactsBrowse();
    if (requestResult) {
        mContacts.swap(contactsResult);
        emit dataChanged(createIndex(0,0), createIndex(static_cast<int>(mContacts.size()), 0));
    }
    return requestResult;
}
