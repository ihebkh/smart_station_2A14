#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(QString,QString,QString,QString,int,QString);
    QString getid(){return id;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getemail(){return email;}
    int getsalaire(){return salaire;}
    QString getmessage(){return message;}

    void setid(QString id){this->id=id;}
    void setnom(QString nom){this->nom=nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    void setemail(QString email){this->email=email;}
    void setsalaire(int salaire){this->salaire=salaire;}
    void setmessage(QString message){this->message=message;}
     bool ajouter();
     bool ajouterMessage(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherMessage();
    QSqlQueryModel * trierprenom();
    QSqlQueryModel * triernom();
    QSqlQueryModel * trieremail();
    QSqlQueryModel * statistiques();
    QSqlQueryModel * rechercher(QString);
    bool supprimer(QString);
private:
    QString id,nom,prenom,email,message;
    int salaire;
};

#endif // EMPLOYE_H
