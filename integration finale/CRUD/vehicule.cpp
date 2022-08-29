#include "vehicule.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
vehicule::vehicule()
{
matricule = "";
marque ="";
model= "";
etat = "";
};
vehicule::vehicule(QString matricule,QString marque,QString model,QString etat )
{
  this->matricule=matricule;
  this->marque=marque;
  this->model=model;
  this->etat=etat;

};
QString vehicule::get_matricule(){return  matricule;}
QString vehicule::get_marque(){return  marque;}
QString vehicule::get_model(){return  model;}
QString vehicule::get_etat(){return  etat;}

void  vehicule::setmat(QString matricule){this->matricule=matricule;}
void  vehicule::setmarque(QString marque){this->marque=marque;}
void  vehicule::setmodel(QString model){this->model=model;}
void  vehicule::setetat(QString etat){this->etat=etat;}


bool vehicule::ajouter()
{

QSqlQuery query;

query.prepare("INSERT INTO VEHICULE(MATRICULE,MARQUE,MODEL,ETAT) "
                    "VALUES ( :MATRICULE,:MARQUE, :MODEL, :ETAT)");
query.bindValue(":MATRICULE", matricule);
query.bindValue(":MARQUE", marque);
query.bindValue(":MODEL", model);
query.bindValue(":ETAT", etat);

  return query.exec();
}

QSqlQueryModel * vehicule::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from vehicule");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("model"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));

    return model;
}

bool vehicule::supprimer(QString matricule )
{
QSqlQuery query;
query.prepare("Delete from vehicule where matricule = :matricule ");
query.bindValue(0, matricule);
return    query.exec();
}

bool vehicule::modifier(QString matricule,QString etat)
{

    QSqlQuery query;
    query.prepare("UPDATE vehicule SET etat=:etat  WHERE matricule=:matricule");
    query.bindValue(":matricule", matricule);
    query.bindValue(":etat", etat);

    return    query.exec();

}
QSqlQueryModel *vehicule::rechercher(QString mattt)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from vehicule where matricule LIKE '"+mattt+"%'");
    return model;
}

QSqlQueryModel * vehicule::tri()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from vehicule order by matricule asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}










