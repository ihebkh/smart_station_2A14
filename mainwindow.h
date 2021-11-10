#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "caisse.h"
#include <QMainWindow>

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
    void on_pb_ajouter_clicked();

    void on_supp_clicked();

    void on_recherche_clicked();

    void on_tri_clicked();

    void on_update_clicked();

private:
    Ui::MainWindow *ui;
    caisse cai;
};
#endif // MAINWINDOW_H
