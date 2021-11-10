#ifndef CAISSE_H
#define CAISSE_H
#include<QSqlQuery>
#include<QSqlQueryModel>

class caisse
{
public:
    caisse();
    caisse(int,int/*,int,int,int,int*/);

    int getidcaisse();
    int getsommecaisse();
   /* int getidemploye();
    int getidgarage();
    int getfacture();
    int getsalaire();*/

    void setidcaisse(int);
    void setsommecaisse(int);
   /* void setidgarage(int);
    void setidemploye(int);
    void setfacture(int);
    void setsalaire(int);*/


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supp(int);
   QSqlQueryModel * rechercher(QString);
     QSqlQueryModel *tri();
     bool update(int,int);

private:
    int idcaisse,sommecaisse/*,idemploye,idgarage,facture,salaire*/;


};

#endif // CAISSE_H
