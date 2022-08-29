#ifndef AVIS_H
#define AVIS_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class avis
{
public:
    avis();
    avis(QString,QString );
    QString  get_idd();
    QString get_AVis();
   void  setidd(QString);
   void  setAVis(QString);

    bool ajouterv2();
    QSqlQueryModel * afficherv2();
    bool supprimerv2(QString);
    bool modifierv2(QString);

private:

    QString idd,AVis;
};

#endif // AVIS_H
