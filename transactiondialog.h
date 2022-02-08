#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QtWidgets>


namespace Ui {
class TransactionDialog;
}

class TransactionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionDialog(std::list<Transactions> const *l, QWidget *parent = nullptr);
    ~TransactionDialog();

private:
    Ui::TransactionDialog *ui;
    void AddButtonToRow();
    void DeleteTransactionFromRow(int row);
    void DeleteRow(int row);
private slots:
    void RemoveTransaction(int index);
    void RemoveTransaction();
};

#endif // TRANSACTIONDIALOG_H
