#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>

class User {
public:
    User();

    //setText

    void setName(const QString &n);
    void setAge(const QString &a);
    void setBirthday(const QString &b);

    QString getName() const;
    int getAge() const;
    QDate getBirthday() const;

    bool serialize();
    bool deserialize();

private:
    const QString filePath = "/home/merivirabyan/InfoManipulating/file.txt";
    QString name;
    int age;
    QDate birthday;
};

#endif // USER_H
