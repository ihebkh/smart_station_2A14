#include "client.h"
Client::Client()
{
cin=0;
id="";
nom="";
prenom="";
numtel=0;
adresse="";
nbreticket=0;
destination="";
abonnement=0;
numguichet="";
// avis="";
}
Client::Client(int cin ,QString id,QString nom,QString prenom,int numtel,QString adresse,int nbreticket,QString destination,int abonnement,QString numguichet /*,QString avis*/ )
{
  this->cin=cin;
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->numtel=numtel;
  this->adresse=adresse;
  this->nbreticket=nbreticket;
  this->destination=destination;
  this->abonnement=abonnement;
  this->numguichet=numguichet;

}
int Client::get_cin(){return  cin;}
QString Client::get_id(){return  id;}
QString Client::get_nom(){return nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_numtel(){return  numtel;}
QString Client::get_adresse(){return adresse;}
int Client::get_nbreticket(){return  nbreticket;}
QString Client::get_destination(){return destination;}
int Client::get_abonnement(){return  abonnement;}
QString Client::getnumguichet(){return numguichet;}

void  Client::setcin( int cin){this->cin=cin;}
void  Client::setid(QString id ){this->id=id;}
void  Client::setnom(QString nom){this->nom=nom;}
void  Client::setprenom(QString prenom){this->prenom=prenom;}
void  Client::setnumtel(int numtel) {this->numtel=numtel;}
void  Client::setadresse(QString adresse) {this->adresse=adresse;}
void  Client::setnbreticket( int nbreticket){this->nbreticket=nbreticket;}
void  Client::setdestination(QString destination){this->destination=destination;}
void  Client::setabonnement(int abonnement) {this->abonnement=abonnement;}
void  Client::setnumguichet(QString numguichet){this->numguichet=numguichet;}

bool Client::ajouter()
{
QSqlQuery query;
QString CINstring=QString::number(cin);
QString NUMTELstring=QString::number(numtel);
QString nbreticketstring=QString::number(nbreticket);
QString abonnementstring=QString::number(abonnement);
query.prepare("INSERT INTO CLIENT (CIN,ID,NOM,PRENOM,NUMTEL,ADRESSE,NBRE_TICKET,DESTINATION,ABONNEMENT,NUM_GUICHET) "
                    "VALUES ( :CIN,:ID, :NOM, :PRENOM, :NUMTEL, :ADRESSE, :NBRE_TICKET, :DESTINATION, :ABONNEMENT, :NUM_GUICHET)");
query.bindValue(":CIN", CINstring);
query.bindValue(":ID", id);
query.bindValue(":NOM", nom);
query.bindValue(":PRENOM", prenom);
query.bindValue(":NUMTEL", NUMTELstring);
query.bindValue(":ADRESSE", adresse );
query.bindValue(":NBRE_TICKET", nbreticketstring);
query.bindValue(":DESTINATION", destination );
query.bindValue(":ABONNEMENT", abonnement);
query.bindValue(":NUM_GUICHET",numguichet );
  return query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NBRE_TICKET"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("ABONNEMENT"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("NUM_GUICHET"));
//model->setHeaderData(10, Qt::Horizontal, QObject::tr("AVIS"));

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
    query.prepare("UPDATE client SET DESTINATION=:DESTINATION  WHERE ID=:ID");
    query.bindValue(":CIN", CINstring);
    query.bindValue(":ID", id);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":NUMTEL", NUMTELstring);
    query.bindValue(":ADRESSE", adresse );
    query.bindValue(":NBRE_TICKET", nbreticketstring);
    query.bindValue(":DESTINATION", destination );
    query.bindValue(":ABONNEMENT", abonnement);
    query.bindValue(":NUM_GUICHET",numguichet );
    return    query.exec();

}
QSqlQueryModel *Client::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from client where ID LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel * Client::tri()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from client order by NOM asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}










