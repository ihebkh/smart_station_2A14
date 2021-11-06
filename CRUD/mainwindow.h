#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonAjouter_clicked();

    void on_id_supp_clicked();


    void on_nbrjours_modifier_clicked();

    void on_rechercher_button_clicked();

    void on_trier_button_clicked();

    void on_ajouteravis_clicked();

private:
    Ui::MainWindow *ui;
    Client Etmp;
};

#endif // MAINWINDOW_H
