#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "guichet.h"
#include<QMessageBox>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ng->setValidator(new QIntValidator(0, 9999, this));
     ui->tel->setValidator(new QIntValidator(0, 99999999, this));
      ui->rev_ab->setValidator(new QIntValidator(0, 9999999, this));
       ui->rev_ti->setValidator(new QIntValidator(0, 9999999, this));
        ui->id_caisse->setValidator(new QIntValidator(0, 99999999, this));
        ui->tabguichet->setModel(G.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
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

}
else
    msgBox.setText("Echec de l'Ajout");

msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{

Guichet G1; G1.setnum_guich(ui->ngsupp->text().toInt());
bool test=G1.supprimer(G1.getnum_guich());
QMessageBox msgBox;
if(test)
{msgBox.setText("Suppression avec succes");
ui->tabguichet->setModel(G.afficher());

}
else
    msgBox.setText("Echec de Supprimer");

msgBox.exec();

}

void MainWindow::on_pushButton_3_clicked()
{

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

}
else
    msgBox.setText("Echec de la modification");

msgBox.exec();
}



void MainWindow::on_pushButton_4_clicked()
{
    QString rech =ui->modng->text();
          ui->tabguichet->setModel(G.rechercher(rech));
}

void MainWindow::on_pushButton_5_clicked()
{
    Guichet *c = new Guichet();
           ui->tabguichet->setModel(c->tri());
}
