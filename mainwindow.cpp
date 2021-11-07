#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reparations.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_id->setValidator(new QIntValidator(0,999999999,this));
    ui->tab_reparation->setModel(R.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id_reparation=ui->le_id->text().toInt();
    QString piece=ui->le_piece->text();
    QString panne=ui->le_panne->text();
    QString facture=ui->l_facture->text();
    QString date_dispo=ui->le_dispo->text();
    QString date_debut=ui->le_debut->text();
 Reparations R(id_reparation,piece,panne,facture,date_dispo,date_debut);
 bool test=R.ajouter();
 if (test)
         { //Actualiser
      ui->tab_reparation->setModel(R.afficher());
         QMessageBox:: information(nullptr, QObject::tr("OK"),
                                            QObject::tr("Ajout effectué\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
         }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "click Cancel to exit."),QMessageBox::Cancel);
 }



void MainWindow::on_pb_supprimer_clicked()
{
 Reparations R;
R.setid_reparation(ui->le_id_supp->text().toInt());
bool test=R.supprimer(R.getid_reparation());
QMessageBox msgBox;
if (test)
{
    msgBox.setText("Suppression avec succes.");
    ui->tab_reparation->setModel(R.afficher());
}else
 msgBox.setText("Echec de suppresion.");

msgBox.exec();

}
