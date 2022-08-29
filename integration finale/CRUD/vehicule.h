#ifndef  VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class vehicule
{
private:
    QString matricule,marque,model,etat;

public:
    vehicule();
    vehicule(QString,QString,QString,QString);
    QString  get_matricule();
    QString get_marque();
    QString get_model();
    QString get_etat();

    void  setmat(QString );
    void  setmarque(QString);
    void  setmodel(QString);
    void  setetat(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString,QString);
  QSqlQueryModel * rechercher(QString);
   QSqlQueryModel *tri();


};

#endif // VEHICULE_H
