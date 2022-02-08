#include "transactiondialog.h"
#include "ui_transactiondialog.h"

TransactionDialog::TransactionDialog(std::list<Transactions> const *l, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);


    for (auto tr : *l){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0,  new QTableWidgetItem(QString::number(tr.GetAmount())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1,  new QTableWidgetItem(QString::fromStdString(tr.getDate())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2,  new QTableWidgetItem(QString::fromStdString(tr.GetTag())));
        AddButtonToRow();
    }
}

void TransactionDialog::AddButtonToRow(){

    QWidget* pWidget = new QWidget();
    QPushButton* btn_edit = new QPushButton();
    btn_edit->setText("Törlés");
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_edit);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 3, pWidget);
    connect(btn_edit, SIGNAL(clicked()), this, SLOT(RemoveTransaction()));
}

void TransactionDialog::RemoveTransaction(int index){
    std::cout << index << std::endl;
}

void TransactionDialog::RemoveTransaction(){
    //QPushButton *btn = (QPushButton*)sender();

    QWidget *w = qobject_cast<QWidget *>(sender()->parent());
    if(w){
        int row = ui->tableWidget->indexAt(w->pos()).row();
        DeleteTransactionFromRow(row);
        DeleteRow(row);
    }

}

void TransactionDialog::DeleteRow(int row){
    ui->tableWidget->removeRow(row);
    ui->tableWidget->setCurrentCell(0, 0);
}

void TransactionDialog::DeleteTransactionFromRow(int row){
    int amount = ui->tableWidget->item(row, 0)->text().toInt();
    time_t t = QDateTime::fromString(ui->tableWidget->item(row, 1)->text(), "yyyy-M-d").toSecsSinceEpoch();
    std::string tag = ui->tableWidget->item(row, 2)->text().toStdString();
    try{
        auto main = this->parentWidget();
        auto mainwindow = (MainWindow*)main;
        mainwindow->RemoveTransaction(&t, &amount, &tag);
    } catch (std::exception ex){

    }
}




TransactionDialog::~TransactionDialog()
{
    delete ui;
}
