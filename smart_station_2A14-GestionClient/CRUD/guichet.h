#ifndef GUICHET_H
#define GUICHET_H
#include <QString>
#include<QtSql/QSqlQueryModel>
class Guichet
{
public:
    Guichet();
    Guichet(int,int,int,int,int,QString);
    int getnum_guich();
    int gettel_guich();
    int getrevenue_ab();
    int getrevenue_ti();
    int getid_caisse();
    QString getadress_guich();
void setnum_guich(int);
void settel_guich(int);
void setrevenue_ab(int);
void setrevenue_ti(int);
void setid_caisse(int);
void setadress_guich(QString);
bool ajouter();
QSqlQueryModel*afficher();
bool supprimer(int);
bool modifier(QString);
  QSqlQueryModel * rechercher(QString);
   QSqlQueryModel *tri();
   QSqlQueryModel * afficherv2(QString);
private:
    int num_guich,tel_guich,revenue_ab,revenue_ti,id_caisse;
    QString adress_guich ;
};

#endif // GUICHET_H
