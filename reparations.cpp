#include "reparations.h"

#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
Reparations::Reparations()
{
   id_reparation="";
   piece="";
   panne="";
   date_dispo="";
   date_debut="";
   facture="";
   email="";
};
Reparations::Reparations(QString id_reparation,QString piece,QString panne,QString date_dispo,QString date_debut,QString facture ,QString email)
{
this->id_reparation=id_reparation;
this->piece=piece;
this->panne=panne;
this->date_dispo=date_dispo;
this->date_debut=date_debut;
this->facture=facture;
this->email=email;
};
QString Reparations::getid_reparation() {return id_reparation;}
QString Reparations::getpiece(){return piece;}
QString Reparations::getpanne(){return panne;}
QString Reparations::getdate_dispo(){return date_dispo;}
QString Reparations::getdate_debut(){return date_debut;}
QString Reparations::getfacture() {return facture;}
QString Reparations::getemail() {return email;}

void Reparations::setid_reparation(QString id_reparation){this->id_reparation=id_reparation;}
void Reparations::setpiece(QString piece){this->piece=piece;}
void Reparations::setpanne(QString panne){this->panne=panne;}
void Reparations::setdate_dispo(QString date_dispo){this->date_dispo=date_dispo;}
void Reparations::setdate_debut(QString date_debut){this->date_debut=date_debut;}
void Reparations::setfacture(QString facture){this->facture=facture;}
void Reparations::setemail(QString email){this->email=email;}
bool Reparations::ajouter()
{//bool test=false;
    QSqlQuery query;


          query.prepare("INSERT INTO REPARATION (ID_REPARATION, PIECE,PANNE, DATE_DISPO,DATE_DEBUT,FACTURE) "
                        "VALUES (:ID_REPARATION, :PIECE,:PANNE,:DATE_DISPO,:DATE_DEBUT, :FACTURE )");
          query.bindValue(":ID_REPARATION", id_reparation);
          query.bindValue(":PIECE", piece);
          query.bindValue(":PANNE",panne);
          query.bindValue(":DATE_DISPO", date_dispo);
          query.bindValue(":DATE_DEBUT",date_debut);
          query.bindValue(":FACTURE", facture);
          return query.exec();

}

bool Reparations::supprimer(QString id_reparation )
{
QSqlQuery query;
query.prepare("DELETE FROM REPARATION  WHERE ID_REPARATION=:ID_REPARATION ");
query.bindValue(0, id_reparation);
return    query.exec();
}

QSqlQueryModel * Reparations::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM REPARATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_REPARATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIECE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PANNE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DISPO"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTURE"));
        return model;
    }



    bool Reparations::modifier(QString id_reparation)
    {
        QSqlQuery query;



        query.prepare("UPDATE REPARATION SET PIECE=:PIECE WHERE ID_REPARATION=:ID_REPARATION");
        query.bindValue(":ID_REPARATION", id_reparation);
        query.bindValue(":PIECE", piece);
        query.bindValue(":PANNE",panne);
        query.bindValue(":DATE_DEBUT",date_debut);
        query.bindValue(":DATE_DISPO", date_dispo);
        query.bindValue(":FACTURE", facture);
        return query.exec();
    }


    QSqlQueryModel *Reparations::rechercher(QString rech)
    {
        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from REPARATION where ID_REPARATION LIKE '"+rech+"%'");
        return model;
    }

    QSqlQueryModel *Reparations::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM REPARATION ORDER BY PANNE ");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    QSqlQueryModel *Reparations::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM REPARATION ORDER BY PANNE DESC");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    int Reparations::calculer()
    {
        int rows=0;
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM REPARATION");
        query.exec();

        if(query.next()){
            rows = query.value(0).toInt();
        }

        return rows;
    }

