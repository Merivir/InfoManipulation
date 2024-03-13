#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "user.h"

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onDeserializeClicked();
    void onSerializeClicked();

private:
    User user;

    QPushButton* s;
    QPushButton* d;
    QLineEdit* name;
    QDateEdit* birthday;
    QSpinBox* age;
    QLabel* nameLabel;
    QLabel* ageLabel;
    QLabel* birthdayLabel;
};
#endif // MAINWINDOW_H
