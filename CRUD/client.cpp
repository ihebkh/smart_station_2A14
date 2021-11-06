#include "client.h"
Client::Client()
{
id="";
cin=0;
nom="";
prenom="";
numtel=0;
adresse="";
dateres="";
nbrjours=0;
avis="";
}
Client::Client(QString id ,int cin ,QString nom ,QString prenom ,int numtel ,QString adresse ,QString dateres ,int nbrjours,QString avis )
{
  this->id=id;
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->numtel=numtel;
  this->adresse=adresse;
  this->dateres=dateres;
  this->nbrjours=nbrjours;
  this->avis=avis;
}
QString Client::get_id(){return  id;}
int Client::get_cin(){return  cin;}
QString Client::get_nom(){return nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_numtel(){return  numtel;}
QString Client::get_adresse(){return adresse;}
QString Client::get_dateres(){return dateres;}
int Client::get_nbrjours(){return  nbrjours;}
QString Client::get_avis(){return avis;}

void  Client::setid(QString id ){this->id=id;}
void  Client::setcin( int cin){this->cin=cin;}
void  Client::setnom(QString nom){this->nom=nom;}
void  Client::setprenom(QString prenom){this->prenom=prenom;}
void  Client::setnumtel(int numtel) {this->numtel=numtel;}
void  Client::setadresse(QString adresse) {this->adresse=adresse;}
void  Client::setdateres(QString dateres) {this->dateres=dateres;}
void  Client::setnbrjours(int nbrjours) {this->nbrjours=nbrjours;}
void  Client::setavis(QString avis) {this->avis=avis;}

bool Client::ajouter()
{
QSqlQuery query;
QString CINstring=QString::number(cin);
QString NUMTELstring=QString::number(numtel);
QString NBRJOURSstring=QString::number(nbrjours);
query.prepare("INSERT INTO CLIENT (ID,CIN,NOM,PRENOM,NUMTEL,ADRESSE,DATERES,NBRJOURS) "
                    "VALUES (:ID, :CIN, :NOM,:PRENOM,:NUMTEL,:ADRESSE,:DATERES,:NBRJOURS)");
query.bindValue(":ID", id);
query.bindValue(":CIN", CINstring);
query.bindValue(":NOM", nom);
query.bindValue(":PRENOM", prenom);
query.bindValue(":NUMTEL", NUMTELstring);
query.bindValue(":ADRESSE", adresse );
query.bindValue(":DATERES", dateres);
query.bindValue(":NBRJOURS",NBRJOURSstring);
  return query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATERES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("NBRJOURS"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("AVIS"));

    return model;
}
bool Client::supprimer(QString id )
{
QSqlQuery query;
query.prepare("Delete from client where ID = :ID ");
query.bindValue(0, id);
return    query.exec();
}

bool Client::modifier(QString id)
{
    QSqlQuery query;
    QString CINstring=QString::number(cin);
    QString NUMTELstring=QString::number(numtel);
    QString NBRJOURSstring=QString::number(nbrjours);
    query.prepare("UPDATE client SET NBRJOURS=:NBRJOURS  WHERE ID=:ID");
    query.bindValue(":ID", id);
    query.bindValue(":CIN", CINstring);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":NUMTEL", NUMTELstring);
    query.bindValue(":ADRESSE", adresse );
    query.bindValue(":DATERES", dateres);
    query.bindValue(":NBRJOURS",NBRJOURSstring);
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
    q->prepare("select * from client order by DATERES desc");
    q->exec();
    model->setQuery(*q);
    return  model;
}
bool Client::modifierv2(QString id)
{
    QSqlQuery query;
    QString CINstring=QString::number(cin);
    QString NUMTELstring=QString::number(numtel);
    QString NBRJOURSstring=QString::number(nbrjours);
    query.prepare("UPDATE client SET AVIS=:AVIS  WHERE ID=:ID");
    query.bindValue(":ID", id);
    query.bindValue(":CIN", CINstring);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":NUMTEL", NUMTELstring);
    query.bindValue(":ADRESSE", adresse );
    query.bindValue(":DATERES", dateres);
    query.bindValue(":NBRJOURS",NBRJOURSstring);
    query.bindValue(":AVIS",avis);
    return    query.exec();

}









