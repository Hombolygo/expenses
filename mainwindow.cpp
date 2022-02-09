#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Wallet *w, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->wallet = w;
    ui->setupUi(this);
    chartView = new QChartView();
    chartView->setRubberBand(QChartView::RectangleRubberBand);
    ui->chartwidget->addWidget(chartView);


    Reload();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Reload(){
    ui->summ->setText(QString::number(wallet->GetSumm()));

    const std::map<std::string, int> * sumByTag = wallet->GetSummbyTag();
    ui->label0->clear();
    for (auto e : *sumByTag){
        ui->label0->addItem(QString::fromStdString(e.first + ": " + std::to_string(e.second)));
    }

    CreateChart(sumByTag);
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

void MainWindow::CreateChart(const std::map<std::string, int> * map){
    QPieSeries *series = new QPieSeries();

    for (auto e : *map){
        series->append(QString::fromStdString(e.first), e.second);
    }

    for (int i = 0; i < map->size(); i++){
        series->slices().at(i)->setLabelVisible();
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chartView->setChart(chart);

}

void MainWindow::on_transactions_clicked()
{
    std::list<Transactions> const *l = wallet->GetTransactions();

    TransactionDialog trDialog(l, this);
    trDialog.setModal(true);
    trDialog.exec();
}

