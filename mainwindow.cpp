#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include "QrCode.hpp"
using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_client->setModel(Etmp.afficher());
    ui->CIN->setValidator(new QIntValidator(0,99999999,this));
    ui->NUMTEL->setValidator(new QIntValidator(10000000,99999999,this));
    ui->NBRETICKET->setValidator(new QIntValidator(0,100,this));
    ui->ID->setMaxLength(12);
    ui->CIN->setMaxLength(8);
    ui->NOM->setMaxLength(10);
    ui->PRENOM->setMaxLength(10);
    ui->NUMTEL->setMaxLength(10);
    ui->ADRESSE->setMaxLength(30);
    ui->NUMGUICHET->setMaxLength(2);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonAjouter_clicked()
{
    int cin=ui->CIN->text().toInt();
    QString  id=ui->ID->text();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    QString adresse=ui->ADRESSE->text();
    int nbreticket=ui->NBRETICKET->text().toInt();
    QString destination=ui->DESTINATION->text();
    int abonnement=ui->ABONNEMENT->text().toInt();
    QString numguichet=ui->NUMGUICHET->text();
    Client C(cin,id,nom,prenom,numtel,adresse,nbreticket,destination,abonnement,numguichet);
    if (nom.isEmpty() || prenom.isEmpty() || destination.isEmpty() ||adresse.isEmpty()  )
        {
            QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir les champs vides Pour continuez."),QMessageBox::Cancel);
        }
    else
    {
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
}
void MainWindow::on_id_supp_clicked()
{
    QItemSelectionModel *select = ui->tab_client->selectionModel();

           int cin =select->selectedRows(0).value(0).data().toString().toInt();
           if(Etmp.supprimer(cin))
           {
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
    int cin=ui->CIN->text().toInt();
    QString  id=ui->ID->text();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    QString adresse=ui->ADRESSE->text();
    int nbreticket=ui->NBRETICKET->text().toInt();
    QString destination=ui->DESTINATION_2->text();
    int abonnement=ui->ABONNEMENT->text().toInt();
    QString numguichet=ui->NUMGUICHET->text();
         Client C(cin,id,nom,prenom,numtel,adresse,nbreticket,destination,abonnement,numguichet);
         if (destination.isEmpty())
             {
                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir la destination svp."),QMessageBox::Cancel);
             }
         else
         {
     bool test=C.modifier(id);
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


void MainWindow::on_qrcodegen_clicked()
{
    int tabeq=ui->tab_client->currentIndex().row();
           QVariant idd=ui->tab_client->model()->data(ui->tab_client->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from CLIENT where CIN=:id");
           qry.bindValue(":CIN",id);
           qry.exec();
              QString  iden,nom,prenom,numtel,adresse,nbreticket,destination,abonnement,numguichet ,ide;

           while(qry.next()){

               id=qry.value(1).toString();
               nom=qry.value(2).toString();
               prenom=qry.value(3).toString();
               numtel=qry.value(4).toString();
               adresse=qry.value(5).toString();
               nbreticket=qry.value(6).toString();
               destination=qry.value(7).toString();
               abonnement=qry.value(8).toString();
               numguichet=qry.value(9).toString();

           }
           ide=QString(id);
                  ide="CIN:"+ide+"ID:"+iden+"NOM:"+nom+"PRENOM:"+prenom,"NUMTEL:"+numtel,"ADRESSE:"+adresse,"NBRE_TICKET:"+nbreticket,"DESTINATION:"+destination,"ABONNEMENT:"+abonnement,"NUM_GUICHET"+numguichet;
           QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

}
