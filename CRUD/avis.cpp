#include "avis.h"

avis::avis()
{
    idd="";
    AVis="";
}
avis::avis(QString id,QString AVis)
{
  this->idd=id;
  this->AVis=AVis;
}

QString avis::get_idd(){return   idd;}
QString avis::get_AVis(){return AVis;}
void avis::setidd(QString idd ){this->idd=idd;}
void  avis::setAVis(QString AVis){this->AVis=AVis;}
 bool avis::ajouterv2()
 {
     QSqlQuery query;


     query.prepare("INSERT INTO AVIS (IDD,AVIS) "
                         "VALUES (:IDD, :AVIS)");
     query.bindValue(":IDD", idd);
     query.bindValue(":AVIS",AVis);
       return query.exec();
 }
 QSqlQueryModel *avis::afficherv2()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from AVIS");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDD"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("AVIS"));
     return model;
 }
 bool avis::supprimerv2(QString idd )
 {
 QSqlQuery query;
 query.prepare("Delete from AVIS where IDD = :IDD ");
 query.bindValue(0, idd);
 return    query.exec();
 }
 bool avis::modifierv2(QString id)
 {
     QSqlQuery query;
     query.prepare("UPDATE AVIS SET AVIS=:AVIS  WHERE ID=:ID");
     query.bindValue(":ID",id );
     query.bindValue(":AVIS",AVis );
     return    query.exec();

 }

