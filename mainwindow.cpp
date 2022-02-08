#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Wallet *w, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->wallet = w;
    ui->setupUi(this);

    Reload();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Reload(){
    ui->summ->setText(QString::number(wallet->GetSumm()));

    auto sumByTag = wallet->GetSummbyTag();
    std::string str = "";
    for (auto e : *sumByTag){
        str += e.first + ": " + std::to_string(e.second) + "\n";
    }
    ui->label0 ->setText(QString::fromStdString(str));
    this->adjustSize();
}

bool MainWindow::AddNewTransaction(time_t *t, int *amount, std::string *tag){
    bool succes = wallet->AddTransaction(t, amount, tag, true);
    Reload();
    return succes;
}

bool MainWindow::RemoveTransaction(time_t *t, int *amount, std::string *tag){
    bool succes = wallet->RemoveTransaction(t, amount, tag);
    Reload();
    return succes;
}

std::list<std::string> MainWindow::GetTags(){
    return wallet->GetTags();
}

void MainWindow::on_pushButton_clicked()
{
    std::list<std::string> l = GetTags();
    NewTransaction newTransaction(l, this);

    newTransaction.setModal(true);
    newTransaction.exec();
}

void MainWindow::on_transactions_clicked()
{
    std::list<Transactions> const *l = wallet->GetTransactions();

    TransactionDialog trDialog(l, this);
    trDialog.setModal(true);
    trDialog.exec();
}

