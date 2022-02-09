#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/wallet.h"
#include "newtransaction.h"
#include <list>
#include <transactiondialog.h>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Wallet *w, QWidget *parent = nullptr);
    ~MainWindow();
    bool AddNewTransaction(time_t *t, int *amount, std::string *tag);
    bool RemoveTransaction(time_t *t, int *amount, std::string *tag);
    std::list<std::string> GetTags();
    std::list<Transactions> GetTransactions();

private slots:
    void on_pushButton_clicked();

    void on_transactions_clicked();

private:
    void CreateChart(const std::map<std::string, int> *map);
    void Reload();
    Ui::MainWindow *ui;
    Wallet *wallet;
    QChartView *chartView;
};

#endif // MAINWINDOW_H
