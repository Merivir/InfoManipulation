#include "user.h"

#include <QFile>
#include <QDataStream>
#include <QTextStream>


User::User() : age(0) {}

void User::setName(const QString &n) { name = n; }
void User::setAge(const QString &a) { age = a.toInt(); }
void User::setBirthday(const QString &b) { birthday = QDate::fromString(b, "yyyy-MM-dd"); }


int User::getAge() const { return age; }
QString User::getName() const { return name; }
QDate User::getBirthday() const { return birthday; }

bool User::serialize() {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
       return false;
    }

    QTextStream out(&file);
    out << name << '\n' << age << '\n' << birthday.toString("yyyy-MM-dd") << '\n';
    file.close();
    return true;
}

bool User::deserialize() {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    name = in.readLine();
    QString ageString = in.readLine();
    age = ageString.toInt();
    QString birthdayString = in.readLine();
    birthday = QDate::fromString(birthdayString, "yyyy-MM-dd");

    file.close();
    return true;
}
