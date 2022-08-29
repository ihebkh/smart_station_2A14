#include "client.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <iostream>
using namespace std;
Client::Client()
{
cin=0;
id="";
nom="";
numtel=0;
nbreticket=0;
destination="";
abonnement=0;
nombre=0;
}
Client::Client(int cin ,QString id,QString nom,int numtel,int nbreticket,QString destination,int abonnement,int nombre)
{
  this->cin=cin;
  this->id=id;
  this->nom=nom;
  this->numtel=numtel;
  this->nbreticket=nbreticket;
  this->destination=destination;
  this->abonnement=abonnement;
  this->nombre=nombre;
}
int Client::get_cin(){return  cin;}
QString Client::get_id(){return  id;}
QString Client::get_nom(){return nom;}
int Client::get_numtel(){return  numtel;}
int Client::get_nbreticket(){return  nbreticket;}
QString Client::get_destination(){return destination;}
int Client::get_abonnement(){return  abonnement;}
int Client::get_nombre(){return  nombre;}

void  Client::setcin( int cin){this->cin=cin;}
void  Client::setid(QString id ){this->id=id;}
void  Client::setnom(QString nom){this->nom=nom;}
void  Client::setnumtel(int numtel) {this->numtel=numtel;}
void  Client::setnbreticket( int nbreticket){this->nbreticket=nbreticket;}
void  Client::setdestination(QString destination){this->destination=destination;}
void  Client::setabonnement(int abonnement) {this->abonnement=abonnement;}
void  Client::setnombre(int nombre) {this->nombre=nombre;}

bool Client::ajouter()
{
QSqlQuery query;  //récupération de données à partir de requêtes SQL
QString CINstring=QString::number(cin);  // les numeros doit des chaines pour inserer dans la bd
QString NUMTELstring=QString::number(numtel);
QString nbreticketstring=QString::number(nbreticket);
QString abonnementstring=QString::number(abonnement);

query.prepare("INSERT INTO CLIENT (CIN,ID,NOM,NUMTEL,NBRE_TICKET,DESTINATION,ABONNEMENT) "
                    "VALUES ( :CIN,:ID,:NOM,:NUMTEL,:NBRE_TICKET,:DESTINATION,:ABONNEMENT)");
query.bindValue(":CIN", CINstring); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
query.bindValue(":ID", id);
query.bindValue(":NOM", nom);
query.bindValue(":NUMTEL", NUMTELstring);
query.bindValue(":NBRE_TICKET", nbreticketstring);
query.bindValue(":DESTINATION", destination );
query.bindValue(":ABONNEMENT", abonnement);


  return query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel(); //fournir des données pour afficher des classes telles que QTableView.

model->setQuery("select CIN,ID,NOM,NUMTEL,NBRE_TICKET,DESTINATION,ABONNEMENT,NOMBRE from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRE_TICKET"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ABONNEMENT"));



    return model;
}
bool Client::supprimer(int cin )
{
QSqlQuery query;
query.prepare("Delete from client where CIN = :CIN ");
query.bindValue(0, cin);
return    query.exec();
}

bool Client::modifier(QString id)
{
    QSqlQuery query;
    QString CINstring=QString::number(cin);
    QString NUMTELstring=QString::number(numtel);
    QString nbreticketstring=QString::number(nbreticket);
    QString abonnementstring=QString::number(abonnement);
    QString nombrestring=QString::number(nombre);
    query.prepare("UPDATE client SET DESTINATION=:DESTINATION  WHERE ID=:ID");
    query.bindValue(":CIN", CINstring);
    query.bindValue(":ID", id);
    query.bindValue(":NOM", nom);
    query.bindValue(":NUMTEL", NUMTELstring);
    query.bindValue(":NBRE_TICKET", nbreticketstring);
    query.bindValue(":DESTINATION", destination );
    query.bindValue(":ABONNEMENT", abonnementstring);
    query.bindValue(":NOMBRE", nombrestring);
    return    query.exec();

}
QSqlQueryModel *Client::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from client where ID LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *Client::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM client ORDER BY NOM ");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *Client::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM client ORDER BY NOM DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}






