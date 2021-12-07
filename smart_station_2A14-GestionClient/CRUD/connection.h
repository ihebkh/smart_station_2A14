#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError> //degager les erreurs specifiques a la base de donnees
#include <QSqlQuery>
#include <QtDebug>
class Connection
{
private :
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeConnection();

};

#endif // CONNECTION_H
