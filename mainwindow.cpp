#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "caisse.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tab_caisse->setModel(cai.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int idcaisse=ui->la_caisse->text().toInt();
    int sommecaisse=ui->la_somme->text().toInt();
   /* int idgarage=ui->iddegarage->text().toInt();
    int idemploye=ui->idemp->text().toInt();
    int facture=ui->lafacture->text().toInt();
    int salaire=ui->salairedelemp->text().toInt();*/


caisse C(idcaisse,sommecaisse/*,idgarage,idemploye,facture,salaire*/);
bool test=C.ajouter();
if (test)
        { //Actualiser
     ui->tab_caisse->setModel(cai.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_supp_clicked()
{
    QItemSelectionModel *select = ui->tab_caisse->selectionModel();

           int idcaisse =select->selectedRows(0).value(0).data().toString().toInt();
           if(cai.supp(idcaisse))
           {
               ui->tab_caisse->setModel(cai.afficher());
               QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                  QObject::tr("Suppression effectué\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_recherche_clicked()
{
    QString rech =ui->idcaisse2->text();
        ui->tab_caisse->setModel(cai.rechercher(rech));
}

void MainWindow::on_tri_clicked()
{
    caisse *c = new caisse();
    ui->tab_caisse->setModel(c->tri());
}


void MainWindow::on_update_clicked()
{

    int idcaisse=ui->idcaisse2_2->text().toInt();
    int sommecaisse=ui->sommecaisse2->text().toInt();
    caisse C(idcaisse,sommecaisse);

    bool test = cai.update(idcaisse,sommecaisse);

            if(test)

            {
                ui->tab_caisse->setModel(cai.afficher());


                QMessageBox::information(nullptr, QObject::tr("update "),
                                         QObject::tr("Patient modifie\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
            }

        }


























