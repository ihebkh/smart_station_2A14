#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QDebug>
//#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_client->setModel(Etmp.afficher());
ui->CIN->setValidator(new QIntValidator(0,99999999,this));
ui->NUMTEL->setValidator(new QIntValidator(0,99999999,this));
ui->NBRJOURS->setValidator(new QIntValidator(0,31,this));

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonAjouter_clicked()
{
    QString  id=ui->ID->text();
    int cin=ui->CIN->text().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    QString adresse=ui->ADRESSE->text();
    QString dateres=ui->DATERES->text();
    int nbrjours=ui->NBRJOURS->text().toInt();
    QString avis=ui->avis2->text(); // metier


    Client C(id,cin,nom,prenom,numtel,adresse,dateres,nbrjours,avis);
bool test=C.ajouter();
if (test)
        { //Actualiser
     ui->tab_client->setModel(Etmp.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}
void MainWindow::on_id_supp_clicked()
{
    Client c;c.setid(ui->id2->text());
        bool test=Etmp.supprimer(c.get_id());
        QMessageBox msgBox;
        if (test)
                {
            //actualiser
             ui->tab_client->setModel(Etmp.afficher());
                QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                   QObject::tr("Suppression effectué\n"
                                                               "click cancel to exit."),QMessageBox::Cancel);
                }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                      QObject::tr("Suppression non effectué.\n"
                                                  "click Cancel to exit."),QMessageBox::Cancel);

}


void MainWindow::on_nbrjours_modifier_clicked()
{
    QString  id=ui->ID->text();
    int cin=ui->CIN->text().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    QString adresse=ui->ADRESSE->text();
    QString dateres=ui->DATERES->text();
    int nbrjours=ui->NBRJOURS2->text().toInt();
    QString avis=ui->avis2->text();
         Client C(id,cin,nom,prenom,numtel,adresse,dateres,nbrjours,avis);
     bool test=C.modifier(id);
     if(nbrjours<=0)
                          {
                              QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("UN VALEUR POSITIF SVP."),QMessageBox::Cancel);
                          }
     else
     {
     if (test)
             { //Actualiser
          ui->tab_client->setModel(Etmp.afficher());
             QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                QObject::tr("Modifier un Client effectué©\n"
                                                            "click cancel to exit."),QMessageBox::Cancel);
             }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("Ajout non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
 }
}


void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->id2->text();
        ui->tab_client->setModel(Etmp.rechercher(rech));
}

void MainWindow::on_trier_button_clicked()
{

        Client *c = new Client();
        ui->tab_client->setModel(c->tri());

}

void MainWindow::on_ajouteravis_clicked()
{
    QString  id=ui->id2->text();
    int cin=ui->CIN->text().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    QString adresse=ui->ADRESSE->text();
    QString dateres=ui->DATERES->text();
    int nbrjours=ui->NBRJOURS2->text().toInt();
    QString  avis=ui->avis2->text();

         Client C(id,cin,nom,prenom,numtel,adresse,dateres,nbrjours,avis);
     bool test=C.modifierv2(id);
     if(avis.isEmpty() )
                          {
                              QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("saisir votre avis."),QMessageBox::Cancel);
                          }
     else
     {
     if (test)
             { //Actualiser
          ui->tab_client->setModel(Etmp.afficher());
             QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                QObject::tr("votre avis est ajoute©\n"
                                                            "click cancel to exit."),QMessageBox::Cancel);
             }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("votre avis n est pas ajoute.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);

}
}
