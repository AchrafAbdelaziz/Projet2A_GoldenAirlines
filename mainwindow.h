#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"compagnie.h"
#include"offre.h"

#include <QMainWindow>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void on_pushButton_2_clicked();
void on_pb_ajouter_clicked();


void on_pb_ajouter_3_clicked();

void on_pb_ajouter_2_clicked();

void on_pb_ajouter_4_clicked();

void on_pb_ajouter_5_clicked();

void on_pb_ajouter_6_clicked();

void on_pb_ajouter_7_clicked();

void on_pb_ajouter_8_clicked();

private:
    Ui::MainWindow *ui;
    compagnie tmpcompagnie;
    offre tmpoffre;
compagnie tmpcomp;
};
#endif // MAINWINDOW_H
