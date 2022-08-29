#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{public:
    Client();
    Client(int,QString,QString,int,int,QString,int,int);
    int  get_cin();
    QString  get_id(); // get = lire
    QString get_nom();
    int get_numtel();
    int get_nbreticket();
    QString get_destination();
    int get_abonnement();
    int get_nombre();


    void  setcin(int); // set = ecrire
    void  setid(QString);
    void  setnom(QString);
    void  setnumtel( int);
    void  setnbreticket(int);
    void  setdestination(QString);
    void  setabonnement(int);
    void  setnombre(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(QString);
  QSqlQueryModel * rechercher(QString);
   QSqlQueryModel *tri();
   QSqlQueryModel * trid();


private:
    QString id,nom,destination;
    int cin,abonnement,nbreticket,numtel,nombre;
};

#endif // CLIENT_H
