#include "employe.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pb_ajouter_clicked()
{
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


void MainWindow::on_pb_supprimer_clicked()
{
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

void MainWindow::on_pb_envoyer_clicked()
{
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

void MainWindow::on_pb_tri_prenom_clicked()
{
ui->tab_employe->setModel(E.trierprenom());


}

void MainWindow::on_pb_tri_email_clicked()
{
    ui->tab_employe->setModel(E.trieremail());

}

void MainWindow::on_pb_tri_nom_clicked()
{
    ui->tab_employe->setModel(E.triernom());

}




void MainWindow::on_pb_recherche_clicked()
{
    QString rech =ui->le_id_rech->text();
        ui->tab_rech->setModel(E.rechercher(rech));
}
