#ifndef NEWTRANSACTION_H
#define NEWTRANSACTION_H

#include <list>
#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class NewTransaction;
}

class NewTransaction : public QDialog
{
    Q_OBJECT

public:
    NewTransaction(std::list<std::string> tags, QWidget *parent = nullptr);
    ~NewTransaction();

private slots:
    void on_exitButton_clicked();
    void on_saveButton_clicked();

private:

    Ui::NewTransaction *ui;
};

#endif // NEWTRANSACTION_H
