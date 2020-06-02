#ifndef CONTACT_H
#define CONTACT_H
#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(int id, const QString& firstName, const QString& secondName,
            const QString& phone);

    int id() const;
    QString phone() const;
    QString firstName() const;
    QString surame() const;

    void setId(int id);
    void setPhone(const QString &phone);
    void setFirstName(const QString &firstName);
    void setSurname(const QString &surname);

private:
    int mId;
    QString mPhone;
    QString mFirstName;
    QString mSurname;
};

#endif // CONTACT_H
