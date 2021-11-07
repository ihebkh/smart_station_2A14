#include "reparations.h"


Reparations::Reparations()
{
   id_reparation=0;
   piece="";
   panne="";
   date_dispo="";
   date_debut="";
   facture="";
};
Reparations::Reparations(int id_reparation,QString piece,QString panne,QString date_dispo,QString date_debut,QString facture )
{
this->id_reparation=id_reparation;
this->facture=facture;
this->piece=piece;
this->panne=panne;
this->date_dispo=date_dispo;
this->date_debut=date_debut;
};
int Reparations::getid_reparation() {return id_reparation;}
QString Reparations::getpiece(){return piece;}
QString Reparations::getpanne(){return panne;}
QString Reparations::getdate_dispo(){return date_dispo;}
QString Reparations::getdate_debut(){return date_debut;}
QString Reparations::getfacture() {return facture;}

void Reparations::setid_reparation(int id_reparation){this->id_reparation=id_reparation;}
void Reparations::setpiece(QString piece){this->piece=piece;}
void Reparations::setfacture(QString facture){this->facture=facture;}
void Reparations::setpanne(QString panne){this->panne=panne;}
void Reparations::setdate_dispo(QString date_dispo){this->date_dispo=date_dispo;}
void Reparations::setdate_debut(QString date_debut){this->date_debut=date_debut;}

bool Reparations::ajouter()
{//bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(id_reparation);

          query.prepare("INSERT INTO Reparation (id_reparation, piece,panne,date_dispo, date_debut,facture) "
                        "VALUES (:id_reparation, :piece, :facture, :panne,:date_dispo,:date_debut)");
          query.bindValue(":id_reparation", id_string);
          query.bindValue(":piece", piece);
          query.bindValue(":facture", facture);
          query.bindValue(":panne",panne);
          query.bindValue(":date_dispo", date_dispo);
          query.bindValue(":date_debut",date_debut);
          return query.exec();
};
QSqlQueryModel * Reparations::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM reparation");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reparation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("piece"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("panne"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_dispo"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_debut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("facture"));
        return model;
    }
    bool Reparations::supprimer(int id )
    {
    QSqlQuery query;
    query.prepare("Delete from client where id =:id_reparation ");
    query.bindValue(0, id);
    return    query.exec();
    };




