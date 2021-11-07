#ifndef REPRATIONS_H
#define REPARATIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Reparations
{public:
Reparations();
Reparations(int,QString,QString,QString,QString,QString);


int getid_reparation();
QString getpiece();
QString getpanne();
QString getfacture();
QString getdate_dispo();
QString getdate_debut();
void setid_reparation(int);
void setpiece(QString);
void setpanne(QString);
void setfacture(QString);
void setdate_dispo(QString);
void setdate_debut(QString);

bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
private:
int id_reparation;
QString piece,panne,facture;
QString date_debut,date_dispo;

};

#endif // REPARATIONS_H
