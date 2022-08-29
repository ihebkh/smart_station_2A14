#include "guichet.h"
#include <QtSql/QSqlQuery>
#include<QtDebug>
#include<QObject>
Guichet::Guichet()
{
num_guich=0;tel_guich=0;revenue_ab=0;revenue_ti=0;id_caisse=0;adress_guich=" ";
}
Guichet::Guichet(int num_guich,int tel_guich,int revenue_ab,int revenue_ti,int id_caisse,QString adress_guich)
{this->num_guich=num_guich;this->tel_guich=tel_guich;this->revenue_ab=revenue_ab;this->revenue_ti=revenue_ti;this->id_caisse=id_caisse;this->adress_guich=adress_guich;}
int Guichet::getnum_guich(){return num_guich;}
int Guichet::gettel_guich(){return tel_guich;}
int Guichet::getrevenue_ab(){return revenue_ab;}
int Guichet::getrevenue_ti(){return revenue_ti;}
int Guichet::getid_caisse(){return id_caisse;}
QString Guichet::getadress_guich(){return adress_guich;}
void Guichet::setnum_guich(int num_guich){this->num_guich=num_guich;}
void Guichet::settel_guich(int tel_guich){this->tel_guich=tel_guich;}
void Guichet::setrevenue_ab(int revenue_ab){this->revenue_ab=revenue_ab;}
void Guichet::setrevenue_ti(int revenue_ti){this->revenue_ti=revenue_ti;}
void Guichet::setid_caisse(int id_caisse){this->id_caisse=id_caisse;}
void Guichet::setadress_guich(QString adress_guich){this->adress_guich=adress_guich;}

bool Guichet::ajouter()
{

    QSqlQuery query;
    QString num_guich_string=QString::number(num_guich);
     QString tel_guich_string=QString::number(tel_guich);
      QString revenue_ab_string=QString::number(revenue_ab);
       QString revenue_ti_string=QString::number(revenue_ti);
        QString id_caisse_string=QString::number(id_caisse);
       query.prepare("INSERT INTO GUICHET (NUM_GUICH,TEL_GUICH,REVENUE_AB,REVENUE_TI,ID_CAISSE,ADRESS_GUICH) "
                    "VALUES ( :NUM_GUICH,:TEL_GUICH, :REVENUE_AB, :REVENUE_TI, :ID_CAISSE, :ADRESS_GUICH)");
       query.bindValue(":NUM_GUICH",num_guich_string);
       query.bindValue(":TEL_GUICH", tel_guich_string);
       query.bindValue(":REVENUE_AB", revenue_ab_string);
       query.bindValue(":REVENUE_TI", revenue_ti_string);
       query.bindValue(":ID_CAISSE",id_caisse_string);
       query.bindValue(":ADRESS_GUICH", adress_guich);
       return  query.exec();
}
bool Guichet::supprimer(int num_guich)
{

QSqlQuery query;

    query.prepare("Delete from GUICHET where NUM_GUICH =:NUM_GUICH");
    query.bindValue(":NUM_GUICH",num_guich);

    return  query.exec();

}
QSqlQueryModel* Guichet::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM GUICHET");
     model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUM_GUICH"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("ID_CAISSE"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("TEL_GUICH"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("REVENUE_AB"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("REVENUE_TI"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESS_GUICH"));



return model;
}



bool Guichet::modifier(QString adress_guich)
{
    QSqlQuery query;
    QString num_guich_string=QString::number(num_guich);
     QString tel_guich_string=QString::number(tel_guich);
      QString revenue_ab_string=QString::number(revenue_ab);
       QString revenue_ti_string=QString::number(revenue_ti);
        QString id_caisse_string=QString::number(id_caisse);
    query.prepare("UPDATE GUICHET SET ADRESS_GUICH=:ADRESS_GUICH  WHERE NUM_GUICH=:NUM_GUICH");
    query.bindValue(":NUM_GUICH",num_guich_string);
    query.bindValue(":TEL_GUICH", tel_guich_string);
    query.bindValue(":REVENUE_AB", revenue_ab_string);
    query.bindValue(":REVENUE_TI", revenue_ti_string);
    query.bindValue(":ID_CAISSE",id_caisse_string);
    query.bindValue(":ADRESS_GUICH", adress_guich);
    return    query.exec();

}

QSqlQueryModel *Guichet::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from GUICHET where NUM_GUICH LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *Guichet::tri()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from GUICHET order by REVENUE_TI asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}

QSqlQueryModel *Guichet::afficherv2(QString loc)
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select NUM_GUICH,ADRESS_GUICH from GUICHET where NUM_GUICH LIKE '"+loc+"%'");

     return model;
 }







