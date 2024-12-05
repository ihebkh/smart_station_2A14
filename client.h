#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{public:
    Client();
    Client(int,QString,QString,QString,int,QString,int,QString,int,QString);
    int  get_cin();
    QString  get_id();
    QString get_nom();
    QString get_prenom();
    int get_numtel();
    QString get_adresse();
    int get_nbreticket();
    QString get_destination();
    int get_abonnement();
    QString getnumguichet();

    void  setcin(int);
    void  setid(QString);
    void  setnom(QString);
    void  setprenom(QString);
    void  setnumtel( int);
    void  setadresse(QString);
    void  setnbreticket(int);
    void  setdestination(QString);
    void  setabonnement(int);
    void  setnumguichet(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(QString);
  QSqlQueryModel * rechercher(QString);
   QSqlQueryModel *tri();

private:
    QString id,nom,prenom,adresse,destination,numguichet;
    int cin,numtel,abonnement,nbreticket;
};

#endif // CLIENT_H
