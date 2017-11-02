#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QDateTime>
#include "SMD_Sort_pcap.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button_Read,SIGNAL(clicked(bool)),this,SLOT(on_button_Read_clicked()));
    connect(ui->button_Sort,SIGNAL(clicked(bool)),this,SLOT(on_button_Sort_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_Read_clicked()
{
    ui->listWidget->clear();

    QString path = ui->lineEdit->text();
    std::string pat = path.toStdString();
    xx.ReadPack(pat.c_str());

    for(int n = 0; n < xx.pack_head.size();n++)
    {
        char *dat = new char[6];
        memset(dat,0,6);

        char *dat1 = new char[10];
        memset(dat1,0,10);

        itoa(n + 1, dat1, 10);
        itoa(xx.pack_head.data()[n].caplen, dat, 10);

        QString t("Packet# ");

        t.push_back(dat1);
        t.push_back("; Length: ");
        t.push_back(dat);
        t.push_back("; ");
        t.push_back(xx.pack_body.data()[n].c_str());

        ui->listWidget->addItem(t);

        delete [] dat;
        delete [] dat1;
    }

}

void MainWindow::on_button_Sort_clicked()
{
    ui->listWidget->clear();

    QDateTime start = QDateTime::currentDateTime();
    xx.BubbleSortLen();

    QDateTime finish = QDateTime::currentDateTime();

    int secs = finish.secsTo(start);

    start.addSecs(secs);

    int msecs = finish.time().msecsTo(start.time());
    int msecs_Durat = secs * 1000 + msecs;

    QString time_Algoritm = QString::number(msecs);

    for(int m = 0; m < xx.pack_head.size(); m++)
    {
        char *dat = new char[6];
        memset(dat,0,6);

        char *dat1 = new char[10];
        memset(dat1,0,10);

        itoa(m + 1, dat1, 10);
        itoa(xx.pack_head.data()[m].caplen, dat, 10);

        QString t("Packet# ");

        t.push_back(dat1);
        t.push_back("; Length: ");
        t.push_back(dat);
        t.push_back("; ");
        t.push_back(xx.pack_body.data()[m].c_str());

        ui->listWidget->addItem(t);

        delete [] dat;
        delete [] dat1;
    }

}

void MainWindow::on_button_Clear_clicked()
{
    ui->listWidget->clear();
}
