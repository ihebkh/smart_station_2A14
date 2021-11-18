#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <employe.h>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_envoyer_clicked();

    void on_pb_tri_prenom_clicked();

    void on_pb_tri_email_clicked();

    void on_pb_tri_nom_clicked();


    void on_pb_recherche_clicked();

private:
    Ui::MainWindow *ui;
   Employe E;
};

#endif // MAINWINDOW_H
