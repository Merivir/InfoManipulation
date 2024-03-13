#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , nameLabel(new QLabel("name"))
    , ageLabel(new QLabel("age"))
    , birthdayLabel(new QLabel("birthday"))
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout* Layout = new QHBoxLayout(this);
    QVBoxLayout* leftLayout = new QVBoxLayout(this);
    QVBoxLayout* rightLayout = new QVBoxLayout(this);

    s = new QPushButton("S", this);
    d = new QPushButton("D", this);

    rightLayout->addWidget(s);
    rightLayout->addWidget(d);

    connect(s, &QPushButton::clicked, this, &MainWindow::onSerializeClicked);
    connect(d, &QPushButton::clicked, this, &MainWindow::onDeserializeClicked);

    name = new QLineEdit(this);
    birthday = new QDateEdit(this);
    birthday->setDate(QDate::currentDate());
    age = new QSpinBox(this);

    leftLayout->addWidget(nameLabel);
    leftLayout->addWidget(name);
    leftLayout->addWidget(ageLabel);
    leftLayout->addWidget(age);
    leftLayout->addWidget(birthdayLabel);
    leftLayout->addWidget(birthday);

    Layout->addLayout(leftLayout);
    Layout->addLayout(rightLayout);

    centralWidget->setLayout(Layout);
}


void MainWindow::onSerializeClicked() {
    user.setName(name->text());
    user.setAge(QString::number(age->value()));
    user.setBirthday(birthday->date().toString("yyyy-MM-dd"));
    user.serialize();
}

void MainWindow::onDeserializeClicked() {
    user.deserialize();
    name->setText(user.getName());
    age->setValue(user.getAge());
    birthday->setDate(user.getBirthday());
}



MainWindow::~MainWindow()
{
}

