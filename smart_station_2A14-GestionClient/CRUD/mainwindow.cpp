#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include "QrCode.hpp"
#include "avis.h"
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include "guichet.h"
#include "notif.h"
#include<QIntValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include "exporterexcel.h"
#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include "smtp.h"
#include <QSsl>
#include <QErrorMessage>
#include <QSound>
#include <QTimer>
#include <QDateTime>
#include "vehicule.h"
#include <QMediaPlayer>
#include "employe.h"
#include "arduino.h"
#include "QMovie"



using namespace QtCharts;
using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint32 pos){
        ui->VolumeMediaDisplay->setValue(pos);
    });
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint32 dur){
        ui->VolumeMediaDisplay->setMaximum(dur);
    });

   // QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\home.wav");
    this->setStyleSheet("");
       QFile file("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\stylesheets\\SyNet.qss");
       file.open(QFile::ReadOnly);
       QString styleSheet = QLatin1String(file.readAll());
       //MainWindow.setStyleSheet(styl);
       qApp->setStyleSheet(styleSheet);
    ui->tab_client->setModel(Etmp.afficher());
    ui->CIN_2->setValidator(new QIntValidator(0,99999999,this));
    ui->NUMTEL->setValidator(new QIntValidator(0,99999999,this));
    ui->NBRETICKET->setValidator(new QIntValidator(0,100,this));
    ui->ID->setMaxLength(5);
    ui->NOM->setMaxLength(10);
    ui->NOM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
    ui->ng->setValidator(new QIntValidator(0, 9999, this));
     ui->tel->setValidator(new QIntValidator(0, 99999999, this));
      ui->rev_ab->setValidator(new QIntValidator(0, 9999999, this));
       ui->rev_ti->setValidator(new QIntValidator(0, 9999999, this));
        ui->id_caisse->setValidator(new QIntValidator(0, 99999999, this));
        ui->tabguichet->setModel(G.afficher());
 QPixmap pix("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\carte-fidelite.png");
 ui->label_4->setPixmap(pix);
 ui->pushButtonAjouter->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->id_supp->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->nbrjours_modifier->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-modifier-24"));
ui->rechercher_button->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-rechercher-plus-24"));
ui->qrcodegen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-qr-code-24"));
ui->statsmed_3->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-document-statistique-24"));
ui->ajouteravis->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->supprimeravis_2->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->modifieravis_3->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-modifier-24"));
ui->pushButton_35->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\parametre"));
ui->pushButton_32->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\sortir"));
ui->dec->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\deccc"));
ui->ajouterrayen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->supprimerrayen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->modifierrayen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-modifier-24"));
ui->rechercherayen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-rechercher-plus-24"));
ui->trierrayen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\58938"));
ui->imprimerrayen->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\printing"));
ui->qrcodegen_2->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-qr-code-24"));
ui->statsmed_3->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
ui->ajouterdaadaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->pushButton_33->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->pushButton_34->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-modifier-24"));
ui->statistiquedaadaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
ui->trierdaadaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\58938"));
ui->imprimerdaadaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\printing"));
ui->statistiquedaadaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
ui->excel_3->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\excel"));
ui->localiserdaadaaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\place"));
ui->ajouteremploye->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->supprimeempoye->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->prenomtri->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\58938"));
ui->emailtri->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\58938"));
ui->nomtri->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\58938"));
ui->pdfaziz->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\printing"));
ui->envoyeremploye->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-chat-24"));
ui->stataziz->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
ui->rechercheremploye->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-rechercher-plus-24"));
ui->ajoutertey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->supprimertey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->modifiertey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-modifier-24"));
ui->imprimertey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\printing"));
ui->stattey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
ui->supprimertey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->tritey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\58938"));
ui->excel_2->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\excel"));
ui->recherhcetey->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-rechercher-plus-24"));
ui->ajouterismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-add-30.png"));
ui->supprimerismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-supprimer-30"));
ui->modifierismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-modifier-24"));
ui->imprimerismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\printing"));
ui->appliquerstatismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
ui->rechercherismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-rechercher-plus-24"));
ui->envoyermailismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\mail-send"));
ui->calculerismael->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\calculator"));
ui->rechercherdaadaa->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-rechercher-plus-24"));
ui->excel->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\excel"));
ui->afficherstat->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\afficherstat"));
QPixmap pix2("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_18->setPixmap(pix2);
QPixmap pix3("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_6->setPixmap(pix3);
QPixmap pix4("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_20->setPixmap(pix4);
QPixmap pix5("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_19->setPixmap(pix5);
QPixmap pix6("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_18->setPixmap(pix6);
QPixmap pix7("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_17->setPixmap(pix7);
QPixmap pix8("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\customer");
ui->label_16->setPixmap(pix8);
ui->OpenMedia->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-upload-24"));
ui->MuteMedia->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\mute"));
ui->PauseMedia->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\video-pause-button"));
ui->PlayMedia->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\icons8-play-24"));
ui->StopMedia->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\traffic-signal"));
ui->quitttter->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\sortir"));
ui->Login->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\enter"));
ui->resetlogin->setIcon(QIcon("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\xddd"));

//date w temp
QTimer *timer=new QTimer(this);
connect(timer, SIGNAL(timeout()),this,SLOT(showtime()));
timer->start();

QDate date=QDate::currentDate();
QString datetext=date.toString();
ui->daaate->setText(datetext);
ui->date->setText(datetext);



}

void MainWindow::showtime()
{
    QTime time=QTime::currentTime();
       QString time_text=time.toString("hh : mm : ss");
    ui->temp_2->setText(time_text);
       ui->temp->setText(time_text);
}
void MainWindow::animation()
{
    QLabel bien;
    ui->bien->clear();
    QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\bienvenue");
    ui->bien->setMovie(movie);
    movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonAjouter_clicked()
{
QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
       notifyIcon-> show ();
       notifyIcon-> showMessage ( "ajouté logistique avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
       QString strStream;
       QTextStream out(&strStream);
    int cin=ui->CIN_2->text().toInt(); // .toint() : chaine --> entier
    QString  id=ui->ID->text();
    QString nom=ui->NOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    int nbreticket=ui->NBRETICKET->text().toInt();
    QString destination=ui->DESTINATION->currentText();
    int abonnement=ui->ABONNEMENT->text().toInt();
    QString avis=ui->avis2->text();
    int nombre=ui->nbtspoints->text().toInt();
    Client C(cin,id,nom,numtel,nbreticket,destination,abonnement,nombre);
    if (nom.isEmpty()) //empty vide
    { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
    }

    else
    {
bool test=C.ajouter();
if (test)
        { //Actualiser
     ui->tab_client->setModel(Etmp.afficher());
        QMessageBox:: information(nullptr, QObject::tr("DESTINATION"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("DESTINATION"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}
}
void MainWindow::on_id_supp_clicked()
{
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QItemSelectionModel *select = ui->tab_client->selectionModel(); //pour selctionner la ligne

           int cin =select->selectedRows(0).value(0).data().toString().toInt();
           if(Etmp.supprimer(cin))
           {
               ui->tab_client->setModel(Etmp.afficher());
               QMessageBox:: information(nullptr, QObject::tr("DESTINATION"),
                                                  QObject::tr("Suppression effectué\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("DESTINATION"),
                                     QObject::tr("Suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
           }
/* void MainWindow::on_pushButtonSupprimer_clicked()
{  Client c;c.setCIN(ui->identifiant->text());
   bool test=Etmp.supprimer(c.get_cin());
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
}}
  */
void MainWindow::on_nbrjours_modifier_clicked()
{
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    int cin=ui->CIN_2->text().toInt();
    QString  id=ui->identifiant->text();
    QString nom=ui->NOM->text();
    int numtel=ui->NUMTEL->text().toInt();
    int nbreticket=ui->NBRETICKET->text().toInt();
    QString destination=ui->destination->text();
    int abonnement=ui->ABONNEMENT->text().toInt();
    int nombre=ui->ABONNEMENT->text().toInt();
         Client C(cin,id,nom,numtel,nbreticket,destination,abonnement,nombre);
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
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString rech =ui->identifiant->text();
        ui->tab_client->setModel(Etmp.rechercher(rech));
}

void MainWindow::on_trier_button_clicked()
{
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");

        Client *c = new Client();
        ui->tab_client->setModel(c->tri());

}


void MainWindow::on_qrcodegen_clicked()
{
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    int tabeq=ui->tab_client->currentIndex().row(); //selectionner le ligne
           QVariant idd=ui->tab_client->model()->data(ui->tab_client->model()->index(tabeq,0)); // selctionner la case
           QString id= idd.toString();
           QSqlQuery qry; // fournir les donnes
           qry.prepare("select * from CLIENT where CIN=:id");
           qry.bindValue(":CIN",id);
           qry.exec(); //execution
              QString  iden,nom,adresse,nbreticket,destination,abonnement ,ide; //convertir les donnes en chaine du caractere

           while(qry.next()){

               id=qry.value(1).toString();
               nom=qry.value(2).toString();
               adresse=qry.value(3).toString();
               nbreticket=qry.value(4).toString();
               destination=qry.value(5).toString();
               abonnement=qry.value(6).toString();

           }
           ide=QString(id);
                  ide="CIN:"+ide+"ID:"+iden+"NOM:"+nom+"ADRESSE:"+adresse +"NBRE_TICKET:"+nbreticket+"DESTINATION:"+destination+"ABONNEMENT:"+abonnement; // importer les donnes depuis la base
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
           im=im.scaled(200,200); //size
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im)); //importation

}


void MainWindow::on_ajouteravis_clicked()
{
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "ajouté logistique avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);
    QString idd=ui->id3->text();
     QString AVis=ui->avis2->text();
    avis A( idd, AVis);
    if( AVis.isEmpty()&& AVis=="excellent"&& AVis=="bien"&& AVis=="mauvais"&& AVis=="moyen"&& AVis=="EXCELLENT"&& AVis=="BIEN"&& AVis=="MAUVAIS"&& AVis=="MOYEN")
                         {
                             QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir l'avis."),QMessageBox::Cancel);
                         }

    else
    {
bool test=A.ajouterv2();
if (test)
        { //Actualiser
    ui->tab_avis->setModel(AA.afficherv2());

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

void MainWindow::on_radioButton_croissant_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
     ui->tab_client->setModel(Etmp.tri());
}

void MainWindow::on_radioButton_dcroissant_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
     ui->tab_client->setModel(Etmp.trid());
}


void MainWindow::on_supprimeravis_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QItemSelectionModel *select = ui->tab_avis->selectionModel(); //pour selctionner la ligne

           QString idd =select->selectedRows(0).value(0).data().toString();
           if(AA.supprimerv2(idd))
           {
               ui->tab_avis->setModel(AA.afficherv2());
               QMessageBox:: information(nullptr, QObject::tr("DESTINATION"),
                                                  QObject::tr("Suppression effectué\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("DESTINATION"),
                                     QObject::tr("Suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_modifieravis_3_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString  idd=ui->id3->text();
    QString AVis=ui->avis2->text();
         avis A( idd, AVis);
         if (AVis.isEmpty()&& AVis=="excellent"&& AVis=="bien"&& AVis=="mauvais"&& AVis=="moyen"&& AVis=="EXCELLENT"&& AVis=="BIEN"&& AVis=="MAUVAIS"&& AVis=="MOYEN")
             {
                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir la destination svp."),QMessageBox::Cancel);
             }
         else
         {
     bool test=A.modifierv2(idd);
     if (test)
             { //Actualiser
          ui->tab_avis->setModel(AA.afficherv2());
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
// stat sur les destinations
void MainWindow::on_statsmed_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from CLIENT where DESTINATION='Rades' ");
     int number1=model->rowCount(); // calculer la somme where destination rades
     model->setQuery("select * from CLIENT where DESTINATION='Ezzahra' ");
     int number2=model->rowCount();
     model->setQuery("select * from CLIENT where DESTINATION='Hammem lif' ");
     int number3=model->rowCount(); // calculer le nombre de voyage pour hammem lif
     model->setQuery("select * from CLIENT where DESTINATION='Autre' ");
     int number4=model->rowCount();
     int total=number1+number2+number3+number4;
     QString a = QString("rades  "+QString::number((number1*100)/total,'f',2)+"%" ); // 12.00
     QString b = QString("ezzahra "+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("hammem lif "+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("autre "+QString::number((number4*100)/total,'f',2)+"%" );
     QPieSeries *series = new QPieSeries();
     series->append(a,number1); // te9sem char gra
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0); //  bib doura
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("pourcentage sur les destinations "+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}


void MainWindow::on_destination_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Client *c = new Client();
    ui->tab_client->setModel(c->tri());
}

void MainWindow::on_tab_client_activated(const QModelIndex &index)
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");

        QSqlQuery query ;

        QString val=ui->tab_client->model()->data(index).toString();
          query.prepare("Select ID,NBRE_TICKET,NOMBRE from CLIENT where ID=:ID ");
          query.bindValue(":ID",val);


          if(query.exec())
             {
                 while(query.next())
                 {
                     QString ch=query.value(1).toString() ;//CH NOMBRE TICKET

                         int i=ch.toInt() ;
                         float  ff=query.value(2).toFloat() ;

                          if(i<10)
                            { ff=i+10; }
                          else if((i>20)&&(i<30))
                           {ff=i+20 ;}
                          else if((i>30)&&(i<40))
                           {ff=i+30 ;}
                          else if((i>40)&&(i<50))
                           {ff=i+40 ;}
                          else if((i>50)&&(i<60))
                           {ff=i+50 ;}
                          else if((i>60)&&(i<70))
                           {ff=i+60 ;}
                          else if((i>70)&&(i<80))
                           {ff=i+70 ;}
                          else if((i>80)&&(i<90))
                           {ff=i+80 ;}
                              else
                              ff=i+90;





                   ui->nbtspoints-> QLineEdit::setText(QString::number(ff)) ;


                 }
             }

}
//cleint
void MainWindow::on_pushButton_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_8_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_10_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_7_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_9_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_12_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_13_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_11_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_14_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_17_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_19_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_16_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(4);
}
// erreur logistique !!!!
void MainWindow::on_pushButton_20_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_22_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_25_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_23_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
   ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_24_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_28_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_26_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_27_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_30_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_29_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_31_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_38_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_39_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_40_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_41_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_42_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_69_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
  ui->stackedWidget->setCurrentIndex(6);
  QLabel animationxd;
  ui->animationxd->clear();
  QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
  ui->animationxd->setMovie(movie);
  movie->start();
}

void MainWindow::on_pushButton_70_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
ui->stackedWidget->setCurrentIndex(6);
QLabel animationxd;
ui->animationxd->clear();
QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
ui->animationxd->setMovie(movie);
movie->start();
}

void MainWindow::on_pushButton_71_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(6);
    QLabel animationxd;
    ui->animationxd->clear();
    QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
    ui->animationxd->setMovie(movie);
    movie->start();
}

void MainWindow::on_pushButton_72_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(6);
    QLabel animationxd;
    ui->animationxd->clear();
    QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
    ui->animationxd->setMovie(movie);
    movie->start();
}

void MainWindow::on_pushButton_73_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(6);
    QLabel animationxd;
    ui->animationxd->clear();
    QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
    ui->animationxd->setMovie(movie);
    movie->start();
}

void MainWindow::on_pushButton_63_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_64_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_67_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_65_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_66_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_68_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_supprimertey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
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

void MainWindow::on_recherhcetey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString rech =ui->recherhcetey->text();
        ui->tab_caisse->setModel(cai.rechercher(rech));
}

void MainWindow::on_imprimertey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
        notifyIcon-> show ();
        notifyIcon-> showMessage ( " Caisse " , " Finance PDF " , QSystemTrayIcon :: Information, 15000 );
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_caisse->model()->rowCount();
        const int columnCount = ui->tab_caisse->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             <<  QString("<title>%1</title>\n").arg("Title")
              <<  "</head>\n"
               <<"<body bgcolor=#ffffff link=#5000A0>\n"

                 //     "<align='right'> " << datefich << "</align>"
              <<"<center> <H1>Responsable des Finances</H1></br></br>Liste des caisse </br></br><table border=1 cellspacing=0 cellpadding=2>\n";


        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tab_caisse->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_caisse->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_caisse->isColumnHidden(column)) {
                    QString data = ui->tab_caisse->model()->data(ui->tab_caisse->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
                "</body>\n"
                "</html>\n";



        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setPaperSize(QPrinter::A4);
        printer->setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(printer);

        QPrinter *p=new QPrinter();
        QPrintDialog dialog(p,this);
        if(dialog.exec()== QDialog::Rejected)
        {
            return;
        }
}

void MainWindow::on_tritey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    caisse *c = new caisse();
    ui->tab_caisse->setModel(c->tri());
}

void MainWindow::on_stattey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from FINANCE where SOMMECAISSE > 100 ");
       int number1=model->rowCount();
       model->setQuery("select * from FINANCE where SOMMECAISSE < 100 ");
       int number2=model->rowCount();
       int total=number1+number2;
       QString a = QString("caisse > 100  "+QString::number((number1*100)/total,'f',2)+"%" );
       QString b = QString("caisse < 100 "+QString::number((number2*100)/total,'f',2)+"%" );

       QPieSeries *series = new QPieSeries();
       series->append(a,number1);
       series->append(b,number2);

       if (number1!= 0)
       {
           QPieSlice *slice = series->slices().at(0);
           slice->setLabelVisible();
           slice->setPen(QPen());
       }
       if (number2!=0)
       {
                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1);
                //slice1->setExploded();
                slice1->setLabelVisible();
       }

               // Create the chart widget
               QChart *chart = new QChart();
               // Add data to chart with title and hide legend
               chart->addSeries(series);
               chart->setTitle("Pourcentage Par Somme des caisse "+ QString::number(total));
               chart->legend()->hide();
               // Used to display the chart
               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               chartView->show();

}

void MainWindow::on_ajoutertey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "ajouté logistique avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);
    int idcaisse=ui->caisseajou->text().toInt();
    int sommecaisse=ui->sommeajou->text().toInt();
    int idemploye=ui->idemployeajou->text().toInt();
    int salaire=ui->salaireajou->text().toInt();
    int idgarage=ui->idgaraajou->text().toInt();
    int facture=ui->numfactajou->text().toInt();



caisse C(idcaisse,sommecaisse,idemploye,salaire,idgarage,facture);
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


void MainWindow::on_modifiertey_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    int idcaisse=ui->caissemod->text().toInt();
    int sommecaisse=ui->sommemod->text().toInt();
    int idemploye=ui->idemployemod->text().toInt();
    int salaire=ui->salairemod->text().toInt();
    int idgarage=ui->idgaragemod->text().toInt();
    int facture=ui->facturemod->text().toInt();



        bool test = cai.update(idcaisse,sommecaisse,idemploye,salaire,idgarage,facture);

                if(test)

                {
                    ui->tab_caisse->setModel(cai.afficher());


                    QMessageBox::information(nullptr, QObject::tr("update "),
                                             QObject::tr("Caisse modifie\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);
                }

}

void MainWindow::on_ajouterdaadaa_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");

    int num_guich=ui->ng->text().toInt();
    int tel_guich=ui->tel->text().toInt();
    int revenue_ab=ui->rev_ab->text().toInt();
    int revenue_ti=ui->rev_ti->text().toInt();
    int id_caisse=ui->id_caisse->text().toInt();
    QString adress_guich=ui->ad->text();
Guichet G(num_guich,tel_guich,revenue_ab,revenue_ti,id_caisse, adress_guich);
bool test=G.ajouter();
QMessageBox msgBox;
if(test)
{msgBox.setText("Ajouter avec succes");
ui->tabguichet->setModel(G.afficher());
notif m("GUICHET","Guichet ajouter avec succees");

              m.afficher();
}
else
    msgBox.setText("Echec de l'Ajout");
notif m("GUICHET","Guichet non ajouter avec succees");

              m.afficher();

msgBox.exec();


}


void MainWindow::on_pushButton_33_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Guichet G1; G1.setnum_guich(ui->ngsupp->text().toInt());
    bool test=G1.supprimer(G1.getnum_guich());
    QMessageBox msgBox;
    if(test)
    {msgBox.setText("Suppression avec succes");
    ui->tabguichet->setModel(G.afficher());
    notif m("GUICHET","Guichet supprimer avec succees");

                  m.afficher();
    }
    else
        msgBox.setText("Echec de Supprimer");
    notif m("GUICHET","Guichet non suprimer avec succees");

                  m.afficher();

    msgBox.exec();

}

void MainWindow::on_pushButton_34_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    int num_guich=ui->modng->text().toInt();
    int tel_guich=ui->tel->text().toInt();
    int revenue_ab=ui->rev_ab->text().toInt();
    int revenue_ti=ui->rev_ti->text().toInt();
    int id_caisse=ui->id_caisse->text().toInt();
    QString adress_guich=ui->modadd->text();
Guichet G(num_guich,tel_guich,revenue_ab,revenue_ti,id_caisse, adress_guich);
bool test=G.modifier(adress_guich);
QMessageBox msgBox;
if(test)
{msgBox.setText("Modifcation effectué");
ui->tabguichet->setModel(G.afficher());
notif m("GUICHET","Guichet modifier avec succees");

              m.afficher();
}
else
    msgBox.setText("Echec de la modification");
notif m("GUICHET","Guichet non modifier avec succees");

              m.afficher();

msgBox.exec();
}

void MainWindow::on_trierdaadaa_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Guichet *c = new Guichet();
           ui->tabguichet->setModel(c->tri());
}

void MainWindow::on_rechercherdaadaa_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString rech =ui->rechng->text();
          ui->tabguichet->setModel(G.rechercher(rech));
}

void MainWindow::on_imprimerdaadaa_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( " Guichet " , " Guichet PDF " , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);

           const int rowCount = ui->tabguichet->model()->rowCount();
           const int columnCount = ui->tabguichet->model()->columnCount();

           out <<  "<html>\n"
                   "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("Title")
                 <<  "</head>\n"
                  <<"<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                 <<"<center> <H1>Responsable des Guichets</H1></br></br>Liste des guichets </br></br><table border=1 cellspacing=0 cellpadding=2>\n";


           // headers
           out << "<thead><tr bgcolor=#f0f0f0>";
           for (int column = 0; column < columnCount; column++)
               if (!ui->tabguichet->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tabguichet->model()->headerData(column, Qt::Horizontal).toString());
           out << "</tr></thead>\n";

           // data table
           for (int row = 0; row < rowCount; row++) {
               out << "<tr>";
               for (int column = 0; column < columnCount; column++) {
                   if (!ui->tabguichet->isColumnHidden(column)) {
                       QString data = ui->tabguichet->model()->data(ui->tabguichet->model()->index(row, column)).toString().simplified();
                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                   }
               }
               out << "</tr>\n";
           }
           out <<  "</table>\n"
                   "</body>\n"
                   "</html>\n";



           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
           QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
           printer->setOutputFormat(QPrinter::PdfFormat);
           printer->setPaperSize(QPrinter::A4);
           printer->setOutputFileName(fileName);

           QTextDocument doc;
           doc.setHtml(strStream);
           doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
           doc.print(printer);

           QPrinter *p=new QPrinter();
           QPrintDialog dialog(p,this);
           if(dialog.exec()== QDialog::Rejected)
           {
               return;
           }
}

void MainWindow::on_statistiquedaadaa_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from GUICHET where REVENUE_AB > 100 ");
           int number1=model->rowCount();
           model->setQuery("select * from GUICHET where REVENUE_AB < 100 ");
           int number2=model->rowCount();
           int total=number1+number2;
           QString a = QString("le revenue de labonnement > 100  "+QString::number((number1*100)/total,'f',2)+"%" );
           QString b = QString("le revenue de labonnement < 100 "+QString::number((number2*100)/total,'f',2)+"%" );

           QPieSeries *series = new QPieSeries();
           series->append(a,number1);
           series->append(b,number2);

           if (number1!= 0)
           {
               QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());
           }
           if (number2!=0)
           {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
           }

                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Pourcentage Par Somme des caisse "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   chartView->show();
}

void MainWindow::on_localiserdaadaaa_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");

    QString loc =ui->locng->text();
    ui->tableloc->setModel(G.afficherv2(loc));
}

void MainWindow::on_excel_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        exportExcel obj(fileName, "mydata", ui->tab_client);

        //colums to export
        obj.addField(0, "CIN", "char(20)");
        obj.addField(1, "ID", "char(20)");
        obj.addField(2, "NOM", "char(20)");
        obj.addField(3, "NUMTEL", "char(20)");
        obj.addField(4, "NBRE_TICKET", "char(20)");
        obj.addField(5, "DESTINATION", "char(20)");
        obj.addField(6, "ABONNEMENT", "char(20)");

        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}

void MainWindow::on_excel_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        exportExcel obj(fileName, "mydata", ui->tab_client);

        //colums to export
        obj.addField(0, "IDCAISSE", "char(20)");
        obj.addField(1, "SOMMECAISSE", "char(20)");
        obj.addField(2, "IDEMPLOYE", "char(20)");
        obj.addField(3, "SALAIRE", "char(20)");
        obj.addField(4, "IDGARAGE", "char(20)");
        obj.addField(5, "FACTURE", "char(20)");
        obj.addField(6, "ABONNEMENT", "char(20)");
        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}

void MainWindow::on_excel_3_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;
        exportExcel obj(fileName, "mydata", ui->tab_client);

        //colums to export
        obj.addField(0, "NUM_GUICH", "char(20)");
        obj.addField(1, "TEL_GUICH", "char(20)");
        obj.addField(2, "REVENUE_AB", "char(20)");
        obj.addField(3, "REVENUE_TI", "char(20)");
        obj.addField(4, "ID_CAISSE", "char(20)");
        obj.addField(5, "ADRESS_GUICH", "char(20)");
        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }

}

void MainWindow::on_cancel_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    this->close();
}

void MainWindow::on_Applytheme_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "theme est changé avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);
    QString item;
    item=ui->listheme->currentItem()->text();
    if(item=="Normal")
    {
        QFile file("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\stylesheets\\Fibary.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        //MainWindow.setStyleSheet(styl);
        qApp->setStyleSheet(styleSheet);
    }

    if(item=="Dark")
    {
        QFile file("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\stylesheets\\Combinear.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        //MainWindow.setStyleSheet(styl);
        qApp->setStyleSheet(styleSheet);
    }

}

void MainWindow::on_pushButton_74_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
        ui->stackedWidget->setCurrentIndex(6);
        QLabel animationxd;
        ui->animationxd->clear();
        QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
        ui->animationxd->setMovie(movie);
        movie->start();
}

void MainWindow::on_pushButton_35_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_32_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QMessageBox::StandardButton reply = QMessageBox :: question (this,
                               "EXIT","Do you really want to exit?",
                            QMessageBox :: Yes | QMessageBox :: No);
        if (reply == QMessageBox :: Yes)
            {QApplication ::quit();}
        else {
            qDebug() <<"No is clicked";
             }

}

void MainWindow::on_ajouterismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "ajouté logistique avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);
    QString id_reparation=ui->id_reparation->text();
        QString piece=ui->piece->text();
        QString panne=ui->panne->currentText();
        QString date_debut=ui->date_debut->text();
        QString date_dispo=ui->date_dispo->text();
        QString facture=ui->facture1->text();
        QString email=ui->email1->text();
     Reparations R(id_reparation,piece,panne,date_dispo,date_debut,facture,email);
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

void MainWindow::on_imprimerismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString strStream;
                                 QTextStream out(&strStream);

                                 const int rowCount = ui->tab_reparation->model()->rowCount();
                                 const int columnCount = ui->tab_reparation->model()->columnCount();
                                 QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                                 out <<"<html>\n"
                                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                     << "<title>ERP - COMmANDE LIST<title>\n "
                                     << "</head>\n"
                                     "<body bgcolor=#ffffff link=#5000A0>\n"
                                     "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                                     "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                       "</br> </br>";
                                 // headers
                                 out << "<thead><tr bgcolor=#d6e5ff>";
                                 for (int column = 0; column < columnCount; column++)
                                     if (!ui->tab_reparation->isColumnHidden(column))
                                         out << QString("<th>%1</th>").arg(ui->tab_reparation->model()->headerData(column, Qt::Horizontal).toString());
                                 out << "</tr></thead>\n";

                                 // data table
                                 for (int row = 0; row < rowCount; row++) {
                                     out << "<tr>";
                                     for (int column = 0; column < columnCount; column++) {
                                         if (!ui->tab_reparation->isColumnHidden(column)) {
                                             QString data =ui->tab_reparation->model()->data(ui->tab_reparation->model()->index(row, column)).toString().simplified();
                                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                         }
                                     }
                                     out << "</tr>\n";
                                 }
                                 out <<  "</table>\n"
                                     "</body>\n"
                                     "</html>\n";

                                 QTextDocument *document = new QTextDocument();
                                 document->setHtml(strStream);

                                 QPrinter printer;

                                 QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                                 if (dialog->exec() == QDialog::Accepted) {
                                     document->print(&printer);
                                 }

                                 delete document;

}

void MainWindow::on_rechercherismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString rech =ui->ID_REPARATION->text();
           ui->tab_reparation->setModel(R.rechercher(rech));
}

void MainWindow::on_modifierismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString id_reparation=ui->ID_REPARATION->text();
       QString piece=ui->PIECE->text();
       QString panne=ui->panne->currentText();
       QString date_dispo=ui->date_dispo->text();
       QString date_debut=ui->date_debut->text();
       QString facture=ui->facture1->text();
       QString email=ui->email1->text();

       Reparations R(id_reparation,piece,panne,date_debut,date_dispo,facture,email);

       if (piece.isEmpty())
                    {
                        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir le piece svp."),QMessageBox::Cancel);
                    }
                else
                {
            bool test=R.modifier(id_reparation);

            if (test)
                    { //Actualiser
                 ui->tab_reparation->setModel(R.afficher());
                    QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                       QObject::tr("Modifier la reparation effectué©\n"
                                                                   "click cancel to exit."),QMessageBox::Cancel);
                    }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                          QObject::tr("Ajout non effectué.\n"

                                              "click Cancel to exit."),QMessageBox::Cancel);}
}

void MainWindow::on_supprimerismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Reparations R;
      R.setid_reparation(ui->ID_REPARATION->text());
      bool test=R.supprimer(R.getid_reparation());

      if (test)
      {
          ui->tab_reparation->setModel(R.afficher());
          QMessageBox::information( nullptr, QObject::tr("supprimé"),
                      QObject::tr("deleted successfully.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }else
          QMessageBox::critical(nullptr, QObject::tr("pas supprimé"),
                      QObject::tr("Delete failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_radioButton_croissant_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
     ui->tab_reparation->setModel(R.tri());
}

void MainWindow::on_radioButton_dcroissant_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->tab_reparation->setModel(R.trid());
}

void MainWindow::on_calculerismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Reparations R;
           int nbr_v;
           nbr_v=R.calculer();
           ui->res_calc->display(nbr_v);
}

/*void MainWindow::on_exitismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QMessageBox::StandardButton reply = QMessageBox :: question (this,
                                   "EXIT","Voulez-vous vraiment sortir ?",
                                QMessageBox :: Yes | QMessageBox :: No);
            if (reply == QMessageBox :: Yes)
                {QApplication ::quit();}
            else {
                qDebug() <<"No is clicked";
                 }
}*/

void MainWindow::on_appliquerstatismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from REPARATION where PANNE='panne de batterie' ");
        int number1=model->rowCount();
        model->setQuery("select * from REPARATION where PANNE='fuite du joint' ");
        int number2=model->rowCount();
        model->setQuery("select * from REPARATION where PANNE='refroidissement' ");
        int number3=model->rowCount(); // calculer le nombre de panne pour refroidissement
       model->setQuery("select * from REPARATION where PANNE='roues' ");
             int number4=model->rowCount();
             model->setQuery("select * from REPARATION where PANNE='huile moteur' ");
             int number5=model->rowCount();
        model->setQuery("select * from REPARATION where DESTINATION='autre' ");
        int number6=model->rowCount();
        int total=number1+number2+number3+number4+number5+number6;
        QString a = QString("panne de batterie  "+QString::number((number1*100)/total,'f',2)+"%" );
        QString b = QString("fuite du joint "+QString::number((number2*100)/total,'f',2)+"%" );
        QString c = QString("refroidissement"+QString::number((number3*100)/total,'f',2)+"%" );
        QString d = QString("roues" +QString::number((number4*100)/total,'f',2)+"%" );

         QString e = QString("huile moteur" +QString::number((number5*100)/total,'f',2)+"%" );

        QString f = QString("autre "+QString::number((number6*100)/total,'f',2)+"%" );
        QPieSeries *series = new QPieSeries();
        series->append(a,number1);
        series->append(b,number2);
        series->append(c,number3);
        series->append(d,number4);
        series->append(e,number5);
        series->append(f,number6);
        if (number1!= 0)
        {
            QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());
        }
        if (number2!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }
        if(number3!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice2 = series->slices().at(2);
                 //slice1->setExploded();
                 slice2->setLabelVisible();
        }
        if(number4!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice3 = series->slices().at(3);
                 //slice1->setExploded();
                 slice3->setLabelVisible();
        }
        if(number5!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice4 = series->slices().at(4);
                 //slice1->setExploded();
                 slice4->setLabelVisible();
        }
        if(number6!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice5 = series->slices().at(5);
                 //slice1->setExploded();
                 slice5->setLabelVisible();
        }
                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                chart->setTitle("Pourcentage Par Type DE PANNE :Nombre Des PANNE "+ QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
}

void MainWindow::on_envoyermailismael_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
              connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

              smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::on_Login_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "login avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);
    if((ui->loginLineEdit->text()=="iheb")&&(ui->motDePasseLineEdit->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(2);
    if ((ui->loginLineEdit->text()=="teymour")&&(ui->motDePasseLineEdit->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(4);
    if ((ui->loginLineEdit->text()=="farouk")&&(ui->motDePasseLineEdit->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(6);
    if ((ui->loginLineEdit->text()=="aziz")&&(ui->motDePasseLineEdit->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(3);
    if ((ui->loginLineEdit->text()=="ismael")&&(ui->motDePasseLineEdit->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(5);
    if ((ui->loginLineEdit->text()=="rayen")&&(ui->motDePasseLineEdit->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(0);
    if ((ui->loginLineEdit->text()=="admin")&&(ui->motDePasseLineEdit->text()=="admin"))
        ui->stackedWidget->setCurrentIndex(6);
    QLabel animationxd;
    ui->animationxd->clear();
    QMovie *movie = new QMovie("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\image\\choisir-une-option");
    ui->animationxd->setMovie(movie);
    movie->start();


}

void MainWindow::on_resetlogin_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_dec_clicked()
{
    QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
        QMessageBox::StandardButton reply = QMessageBox :: question (this,
                                       "EXIT","Voulez-vous deconnecter ?",
                                    QMessageBox :: Yes | QMessageBox :: No);
                if (reply == QMessageBox :: Yes)
                    {ui->stackedWidget->setCurrentIndex(8);}
                else {
                    qDebug() <<"No is clicked";
                     }
}

void MainWindow::on_quitttter_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QMessageBox::StandardButton reply = QMessageBox :: question (this,
                               "EXIT","Do you really want to exit?",
                            QMessageBox :: Yes | QMessageBox :: No);
        if (reply == QMessageBox :: Yes)
            {QApplication ::quit();}
        else {
            qDebug() <<"No is clicked";
             }

}

void MainWindow::on_ajouterrayen_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "ajouté logistique avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);
    QString  matricule=ui->le_matricule->text();
    QString  marque=ui->le_marque->currentText();
    QString model=ui->le_model->text();
    QString etat=ui->le_etat->text();

    vehicule vv(matricule,marque,model,etat);




    bool test=vv.ajouter();
    if (test)
            { //Actualiser
         ui->tab_vehicule->setModel(v.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("Ajout effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_supprimerrayen_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QItemSelectionModel *select = ui->tab_vehicule->selectionModel();

           QString mat =select->selectedRows(0).value(0).data().toString();
           QString matric= ui->le_matricule2->text();
           if(v.supprimer(matric))
           {
               ui->tab_vehicule->setModel(v.afficher());
               QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                  QObject::tr("Suppression effectué\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_modifierrayen_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString mat=ui->le_matricule2->text();
    QString  marq=ui->le_marque->currentText();
    QString modl=ui->le_model->text();
    QString etatv=ui->le_etat2->text();


         vehicule c;
         if (mat.isEmpty())
             {
                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir la matricule svp."),QMessageBox::Cancel);
             }
         else
         {
     bool test=v.modifier(mat,etatv);
     if (test)
             { //Actualiser
          ui->tab_vehicule->setModel(v.afficher());
             QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                QObject::tr("Modification de vehicule effectué©\n"
                                                            "click cancel to exit."),QMessageBox::Cancel);
             }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("Ajout non effectué.\n"

                                       "click Cancel to exit."),QMessageBox::Cancel);
}
}

void MainWindow::on_rechercherayen_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString rech =ui->le_matricule2->text();
        ui->tab_vehicule->setModel(v.rechercher(rech));
}



void MainWindow::on_trierrayen_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    vehicule *v = new vehicule();
    ui->tab_vehicule->setModel(v->tri());
}

void MainWindow::on_qrcodegen_2_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    int tabeq=ui->tab_vehicule->currentIndex().row();
           QVariant x=ui->tab_vehicule->model()->data(ui->tab_vehicule->model()->index(tabeq,0));
           QString matt= x.toString();
           QSqlQuery qry;
           qry.prepare("select * from vehicule where mat=:matt");
           qry.bindValue(":mat",matt);
           qry.exec();
              QString  iden,marque,model,etat ,ide;

           while(qry.next()){

               matt=qry.value(1).toString();
               marque=qry.value(2).toString();
               model=qry.value(3).toString();
               etat=qry.value(4).toString();





           }
           ide=QString(matt);
                  ide="matricule:"+matt+"marque:"+marque+"model:"+model,"etat:"+etat;
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

void MainWindow::on_afficherstat_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from vehicule where marque ='BMW' ");
     int number1=model->rowCount();
     model->setQuery("select * from vehicule where marque='PEUGEOT' ");
     int number2=model->rowCount();
     model->setQuery("select * from vehicule where marque='RENAULT' ");
     int number3=model->rowCount(); // calculer le nombre de voiture de marque RENAULT
    model->setQuery("select * from vehicule where marque='OPEL' ");
          int number4=model->rowCount();
          model->setQuery("select * from vehicule where marque='CHEVROLET' ");
          int number5=model->rowCount();
     model->setQuery("select * from vehicule where marque='Autre' ");
     int number6=model->rowCount();
     int total=number1+number2+number3+number4+number5+number6;
     QString a = QString("BMW"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("PEUGEOT"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("RENAULT"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("OPEL" +QString::number((number4*100)/total,'f',2)+"%" );

      QString e = QString("CHEVROLET" +QString::number((number5*100)/total,'f',2)+"%" );

     QString f = QString("Autre "+QString::number((number6*100)/total,'f',2)+"%" );
     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par marque de voitures :Nombre Des MARQUE "+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();
}

void MainWindow::on_imprimerrayen_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString strStream;
                             QTextStream out(&strStream);

                             const int rowCount = ui->tab_vehicule->model()->rowCount();
                             const int columnCount = ui->tab_vehicule->model()->columnCount();
                             QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                             out <<"<html>\n"
                                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 << "<title>ERP - COMmANDE LIST<title>\n "
                                 << "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"
                                 "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                                 "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                   "</br> </br>";
                             // headers
                             out << "<thead><tr bgcolor=#d6e5ff>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!ui->tab_vehicule->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(ui->tab_vehicule->model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tab_vehicule->isColumnHidden(column)) {
                                         QString data =ui->tab_vehicule->model()->data(ui->tab_vehicule->model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table>\n"
                                 "</body>\n"
                                 "</html>\n";

                             QTextDocument *document = new QTextDocument();
                             document->setHtml(strStream);

                             QPrinter printer;

                             QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                             if (dialog->exec() == QDialog::Accepted) {
                                 document->print(&printer);
                             }

                             delete document;
}


void MainWindow::on_MuteMedia_clicked()
{
    if(ui->MuteMedia->text()=="Mute")
    {
        mMediaPlayer->setMuted(true);
        ui->MuteMedia->setText("Unmute");
    }else{
        mMediaPlayer->setMuted(false);
        ui->MuteMedia->setText("Mute");
    }

}

void MainWindow::on_StopMedia_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    mMediaPlayer->stop();
}

void MainWindow::on_PauseMedia_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    mMediaPlayer->pause();
}

void MainWindow::on_PlayMedia_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    mMediaPlayer->play();
}
void on_VolumeMediaControl_valueChanged(int value);

void on_VolumeMediaDisplay_valueChanged(int value);

void on_VolumeMediaControl_actionTriggered(int action);

void MainWindow::on_OpenMedia_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString filename = QFileDialog::getOpenFileName(this,"OpenMedia");
        if(filename.isEmpty())
        {
            return;
        }
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
        mMediaPlayer->setVolume(ui->VolumeMediaControl->value());
        on_PlayMedia_clicked();
}

/*void MainWindow::on_VolumeMediaControl_actionTriggered(int action)
{
ui->VolumeMediaDisplay->setValue(value);
    mMediaPlayer->setVolume(value);
}*/


void MainWindow::on_VolumeMediaControl_valueChanged(int value)
{
    ui->VolumeMediaDisplay->setValue(value);
        mMediaPlayer->setVolume(value);
}

void MainWindow::on_ajouteremploye_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
           notifyIcon-> show ();
           notifyIcon-> showMessage ( "ajouté employé avec succees" , "" , QSystemTrayIcon :: Information, 15000 );
           QString strStream;
           QTextStream out(&strStream);

    QString id=ui->le_id->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    int salaire=ui->le_salaire->text().toInt();
    QString message="";


    Employe E(id,nom,prenom,email,salaire,message);
    bool test=E.ajouter();
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() ||id.isEmpty()  )
        {
            QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir les champs vides Pour continuez."),QMessageBox::Cancel);
        }
            if(test)
            {
                 ui->tab_employe->setModel(E.afficher());
                QMessageBox:: information(nullptr, QObject::tr("ajout"),
                                                   QObject::tr("Ajout effectué\n"
                                                               "click cancel to exit."),QMessageBox::Cancel);
                }
            else

                QMessageBox::critical(nullptr, QObject::tr("erreur"),
                                      QObject::tr("Ajout non effectué.\n"
                                                  "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_supprimeempoye_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Employe E1;E1.setid(ui->le_id_supp->text());
    QMessageBox msgbox;
    bool test=E1.supprimer(E1.getid());
    if(test)
    { msgbox.setText("suppresion effectué");
        ui->tab_employe->setModel(E.afficher());
    }



    else


        msgbox.setText("probleme de suppresion");

        msgbox.exec();
}

void MainWindow::on_prenomtri_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->tab_employe->setModel(E.trierprenom());
}

void MainWindow::on_emailtri_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->tab_employe->setModel(E.trieremail());
}

void MainWindow::on_nomtri_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    ui->tab_employe->setModel(E.triernom());
}

void MainWindow::on_envoyeremploye_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    Employe E2;
    E2.setid(ui->le_id_chat->text());
    E2.setmessage(ui->le_message->text());
    QMessageBox msgbox;
    bool test=E2.ajouterMessage(E2.getid());
    if(test)
    {
        msgbox.setText("un nouveau message");
        ui->tab_message->setModel(E2.afficherMessage());
    }
    else
        msgbox.setText("probleme d'envoie de message");
    msgbox.exec();
}

void MainWindow::on_rechercheremploye_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString rech =ui->le_id_rech->text();
        ui->tab_rech->setModel(E.rechercher(rech));
}

void MainWindow::on_statsmed_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from CLIENT where DESTINATION='Rades' ");
         int number1=model->rowCount(); // calculer la somme where destination rades
         model->setQuery("select * from CLIENT where DESTINATION='Ezzahra' ");
         int number2=model->rowCount();
         model->setQuery("select * from CLIENT where DESTINATION='Hammem lif' ");
         int number3=model->rowCount(); // calculer le nombre de voyage pour hammem lif
         model->setQuery("select * from CLIENT where DESTINATION='Autre' ");
         int number4=model->rowCount();
         int total=number1+number2+number3+number4;
         QString a = QString("Rades  "+QString::number((number1*100)/total,'f',2)+"%" ); // 12.00
         QString b = QString("Ezzahra "+QString::number((number2*100)/total,'f',2)+"%" );
         QString c = QString("Hammem lif "+QString::number((number3*100)/total,'f',2)+"%" );
         QString d = QString("Autre "+QString::number((number4*100)/total,'f',2)+"%" );
         QPieSeries *series = new QPieSeries();
         series->append(a,number1); // te9sem char gra
         series->append(b,number2);
         series->append(c,number3);
         series->append(d,number4);
         if (number1!= 0)
         {
             QPieSlice *slice = series->slices().at(0); //  bib doura
             slice->setLabelVisible();
             slice->setPen(QPen());
         }
         if (number2!=0)
         {
                  // Add label, explode and define brush for 2nd slice
                  QPieSlice *slice1 = series->slices().at(1);
                  //slice1->setExploded();
                  slice1->setLabelVisible();
         }
         if(number3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
         if(number4!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice3 = series->slices().at(3);
                  //slice1->setExploded();
                  slice3->setLabelVisible();
         }
                 // Create the chart widget
                 QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle(" 4 Destinations ");//+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();
}





void MainWindow::on_stataziz_clicked()
{QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from EMPLOYE where (SALAIRE<1000) ");
         int number1=model->rowCount(); // calculer la somme where destination rades
         model->setQuery("select * from EMPLOYE where (SALAIRE>1000 and SALAIRE<2000) ");
         int number2=model->rowCount();
         model->setQuery("select * from CLIENT where DESTINATION='Hammem lif' ");
         int number3=model->rowCount(); // calculer le nombre de voyage pour hammem lif
         model->setQuery("select * from EMPLOYE where (SALAIRE>2000) ");
         int number4=model->rowCount();
         int total=number1+number2+number3+number4;
         QString a = QString("salaire inf a 1000  "+QString::number((number1*100)/total,'f',2)+"%" ); // 12.00
         QString b = QString("salaire sup a 1000 et a inf 2000 "+QString::number((number2*100)/total,'f',2)+"%" );
         QString c = QString("salaire sup a 2000 "+QString::number((number3*100)/total,'f',2)+"%" );
         QString d = QString("Autre "+QString::number((number4*100)/total,'f',2)+"%" );
         QPieSeries *series = new QPieSeries();
         series->append(a,number1); // te9sem char gra
         series->append(b,number2);
         series->append(c,number3);
         series->append(d,number4);
         if (number1!= 0)
         {
             QPieSlice *slice = series->slices().at(0); //  bib doura
             slice->setLabelVisible();
             slice->setPen(QPen());
         }
         if (number2!=0)
         {
                  // Add label, explode and define brush for 2nd slice
                  QPieSlice *slice1 = series->slices().at(1);
                  //slice1->setExploded();
                  slice1->setLabelVisible();
         }
         if(number3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
         if(number4!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice3 = series->slices().at(3);
                  //slice1->setExploded();
                  slice3->setLabelVisible();
         }
                 // Create the chart widget
                 QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle(" salaire ");//+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();
}

void MainWindow::on_pdfaziz_clicked()
{
   QSound::play("C:\\Users\\IHEB\\Desktop\\aa\\smart_station_2A14-GestionClient\\CRUD\\musique\\click.wav");
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tab_employe->model()->rowCount();
    const int columnCount =ui->tab_employe->model()->columnCount();
    out << "<h2 align=left> E HEALTH APPLICATION  </h2>";
    out << "<h2 align=right> UTOPIA SOFTWARES </h2>";

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("chambre")
          <<  "</head>\n"
              "<body bgcolor=lightblue link=#5000A0>\n"

              "<h1>Liste des chambre</h1>"



              "<table border=1 cellspacing=0 cellpadding=2>\n";


    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_employe->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_employe->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";
    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_employe->isColumnHidden(column)) {
                QString data = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }
}
