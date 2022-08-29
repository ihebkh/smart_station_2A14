#ifndef REPARATIONS_H
#define REPARATIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Reparations
{
    public:
Reparations();
Reparations(QString,QString,QString,QString,QString,QString,QString);


QString getid_reparation();
QString getpiece();
QString getpanne();
QString getfacture();
QString getdate_dispo();
QString getdate_debut();
QString getemail();

void setid_reparation(QString);
void setpiece(QString);
void setpanne(QString);
void setfacture(QString);
void setdate_dispo(QString);
void setdate_debut(QString);
void setemail(QString);
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(QString);
bool modifier(QString);
QSqlQueryModel * rechercher(QString);
 QSqlQueryModel *tri();
 QSqlQueryModel * trid();
 int calculer();
private:
QString id_reparation;
QString piece,panne,facture;
QString date_debut,date_dispo,email;


};

#endif // REPARATIONS_H
