#include "employe.h"
#include "QSqlQuery"
#include <QtDebug>
#include <QMessageBox>
#include<QObject>


Employe::Employe()
{
id="";
nom="";
prenom="";
email="";
salaire=0;
message="";

}
Employe::Employe(QString id,QString nom,QString prenom,QString email,int salaire,QString message)
{
   this->id=id;
   this->nom=nom;
   this->prenom=prenom;
   this->email=email;
   this->salaire=salaire;
   this->message=message;

}




bool Employe::ajouter(){
    QSqlQuery query;
    QString salairestring=QString::number(salaire);
    query.prepare("insert into employe (id,nom,prenom,email,salaire,message) "
                        "VALUES ( :id,:nom,:prenom,:email,:salaire,:message)");
        query.bindValue(":id", id);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":email",email);
        query.bindValue(":salaire",salairestring);
        query.bindValue(":message",message);
       return query.exec();

}
bool Employe::ajouterMessage(QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE employe SET message=:message WHERE id=:id");
    query.bindValue(":id",id);
    query.bindValue(":message",message);
    return query.exec();
}
QSqlQueryModel * Employe::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,email,salaire FROM employe");


    return model;

}
QSqlQueryModel * Employe::trierprenom(){
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,email,salaire FROM employe ORDER BY prenom");

    return model;

}
QSqlQueryModel * Employe::triernom(){
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,email,salaire FROM employe ORDER BY nom");

    return model;

}
QSqlQueryModel * Employe::trieremail(){
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,email,salaire FROM employe ORDER BY email");

    return model;

}

QSqlQueryModel * Employe::afficherMessage(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT prenom,message FROM employe where message IS NOT NULL ");


    return model;

}


bool Employe::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from employe where id =:id ");
    query.bindValue(":id",id);
    return query.exec();
}
QSqlQueryModel *Employe::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from Employe where ID LIKE '"+rech+"'");
    return model;
}
