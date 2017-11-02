#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "struct.h"
#include "SMD_Sort_pcap.h"
#include <pcap.h>

namespace Ui

{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_button_Read_clicked();

private slots:
    void on_button_Sort_clicked();

    void on_button_Clear_clicked();

private:
    Ui::MainWindow *ui;
public:
    SMD_Sort_pcap xx;

};

#endif
