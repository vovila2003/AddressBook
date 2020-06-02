#include "contact.h"

Contact::Contact(int id, const QString &firstName, const QString &secondName, const QString &phone)
    : mId {id},
      mPhone {phone},
      mFirstName {firstName},
      mSurname {secondName}
{

}

QString Contact::phone() const
{
    return mPhone;
}

QString Contact::firstName() const
{
    return mFirstName;
}

QString Contact::surame() const
{
    return mSurname;
}

void Contact::setPhone(const QString &phone)
{
    mPhone = phone;
}

void Contact::setFirstName(const QString &firstName)
{
    mFirstName = firstName;
}

void Contact::setSurname(const QString &surname)
{
    mSurname = surname;
}

int Contact::id() const
{
    return mId;
}

void Contact::setId(int id)
{
    mId = id;
}
