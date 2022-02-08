#include "newtransaction.h"
#include "ui_newtransaction.h"

NewTransaction::NewTransaction(std::list<std::string> tags, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTransaction)
{

    ui->setupUi(this);
    ui->amount->setPlaceholderText("2000");
    ui->amount->setValidator( new QIntValidator(0, INT_MAX, this) );
    ui->date->setDate(QDate::currentDate());

    for (auto tag : tags) {
        ui->tagBox->addItem(QString::fromStdString(tag));
    }
}


NewTransaction::~NewTransaction()
{
    delete ui;
}

void NewTransaction::on_exitButton_clicked()
{
    close();
}


void NewTransaction::on_saveButton_clicked()
{
    auto amount = ui->amount->text().toInt();
    auto t = ui->date->dateTime().toSecsSinceEpoch();
    auto tag = ui->tagBox->currentText().toStdString();


    try{
        auto main = this->parentWidget();
        auto mainwindow = (MainWindow*)main;
        mainwindow->AddNewTransaction(&t, &amount, &tag);
    } catch (std::exception ex){
        throw "EXCEPTION: ONLY WORK FROM MAIN WINDOW!";
    }

    close();
}

