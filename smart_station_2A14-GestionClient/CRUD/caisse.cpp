#include "caisse.h"
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>



caisse::caisse()
{
idcaisse=0;sommecaisse=0;idemploye=0;idgarage=0;facture=0;salaire=0;
}

caisse::caisse(int idcaisse,int sommecaisse,int idemploye,int idgarage,int facture,int salaire)
{
    this->idcaisse=idcaisse;
    this->sommecaisse=sommecaisse;
    this->idemploye=idemploye;
    this->idgarage=idgarage;
    this->facture=facture;
    this->salaire=salaire;

}
int caisse::getidcaisse(){return idcaisse;}
int caisse::getsommecaisse(){return sommecaisse;}
int caisse::getidgarage(){return idgarage;}
int caisse::getidemploye(){return idemploye;}
int caisse::getfacture(){return facture;}
int caisse::getsalaire(){return salaire;}

void caisse::setidcaisse(int idcaisse){this ->idcaisse=idcaisse;}
void caisse::setsommecaisse(int sommecaisse){this->sommecaisse=sommecaisse;}
void caisse::setidgarage(int idcaisse){this ->idcaisse=idcaisse;}
void caisse::setidemploye(int idemploye){this->idemploye=idemploye;}
void caisse::setfacture(int facture){this ->facture=facture;}
void caisse::setsalaire(int salaire){this->salaire=salaire;}

bool caisse::ajouter()
{
QSqlQuery query;
QString IDCAISSEstring=QString::number(idcaisse);
QString SOMMECAISSEstring=QString::number(sommecaisse);
QString IDEMPLOYEstring=QString::number(idemploye);
QString SALAIREstring=QString::number(salaire);
QString IDGARAGEstring=QString::number(idgarage);
QString FACTUREstring=QString::number(facture);

query.prepare("INSERT INTO FINANCE (IDCAISSE,SOMMECAISSE,IDEMPLOYE,SALAIRE,IDGARAGE,FACTURE) "
                    "VALUES (:IDCAISSE, :SOMMECAISSE,:IDEMPLOYE,:SALAIRE,:IDGARAGE,:FACTURE)");
query.bindValue(":IDCAISSE", IDCAISSEstring);
query.bindValue(":SOMMECAISSE", SOMMECAISSEstring);
query.bindValue(":IDEMPLOYE", IDEMPLOYEstring);
query.bindValue(":SALAIRE", SALAIREstring);
query.bindValue(":IDGARAGE", IDGARAGEstring);
query.bindValue(":FACTURE", FACTUREstring);


  return query.exec();
}
QSqlQueryModel * caisse::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM FINANCE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCAISSE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SOMMECAISSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDEMPLOYE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDGARAGE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("FACTURE"));

    return model;
}
bool caisse::supp(int idcaisse)
{
QSqlQuery query;
query.prepare("Delete from FINANCE where IDCAISSE = :IDCAISSE ");
query.bindValue(0, idcaisse);
return    query.exec();
}
QSqlQueryModel * caisse::rechercher(QString rech)
{
        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from FINANCE where IDCAISSE LIKE '"+rech+"%'");
        return model;

}

QSqlQueryModel * caisse::tri()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("SELECT * FROM FINANCE order by IDCAISSE asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}
bool caisse::update(int idcaisse,int sommecaisse,int idgarage,int idemploye,int facture,int salaire)
{
    QSqlQuery query;
    QString IDCAISSEstring=QString::number(idcaisse);
    QString SOMMECAISSEstring=QString::number(sommecaisse);
    QString IDEMPLOYEstring=QString::number(idemploye);
    QString SALAIREstring=QString::number(salaire);
    QString IDGARAGEstring=QString::number(idgarage);
    QString FACTUREstring=QString::number(facture);
    query.prepare("UPDATE FINANCE SET SOMMECAISSE=:SOMMECAISSE WHERE IDCAISSE= :IDCAISSE");


    query.bindValue(":IDCAISSE",IDCAISSEstring);
    query.bindValue(":SOMMECAISSE",SOMMECAISSEstring);
    query.bindValue(":IDEMPLOYE", IDEMPLOYEstring);
    query.bindValue("SALAIRE", SALAIREstring);
    query.bindValue(":IDGARAGE", IDGARAGEstring);
    query.bindValue("::FACTURE", FACTUREstring);


    return query.exec();
}
