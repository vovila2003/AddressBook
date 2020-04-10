#ifndef CONTACT_H
#define CONTACT_H
#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(const QString& firstName, const QString& secondName,
            const QString& phone);

    QString phone() const;
    QString firstName() const;
    QString surame() const;

    void setPhone(const QString &phone);
    void setFirstName(const QString &firstName);
    void setSurname(const QString &surname);

private:
    QString mPhone;
    QString mFirstName;
    QString mSurname;
};

#endif // CONTACT_H
