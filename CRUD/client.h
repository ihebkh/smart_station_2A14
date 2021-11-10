#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{public:
    Client();
    Client(int,QString,QString,QString,int,QString,int,QString,int,QString,QString);
    int  get_cin();
    QString  get_id(); // get = lire
    QString get_nom();
    QString get_prenom();
    int get_numtel();
    QString get_adresse();
    int get_nbreticket();
    QString get_destination();
    int get_abonnement();
    QString getnumguichet();
    QString getavis();

    void  setcin(int); // set = ecrire
    void  setid(QString);
    void  setnom(QString);
    void  setprenom(QString);
    void  setnumtel( int);
    void  setadresse(QString);
    void  setnbreticket(int);
    void  setdestination(QString);
    void  setabonnement(int);
    void  setnumguichet(QString);
    void  setavis(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(QString);
  QSqlQueryModel * rechercher(QString);
   QSqlQueryModel *tri();
   //pour l avis
   bool modifierV2(QString);
   QSqlQueryModel * afficherV2();


private:
    QString id,nom,prenom,adresse,destination,numguichet,avis;
    int cin,abonnement,nbreticket,numtel;
};

#endif // CLIENT_H
