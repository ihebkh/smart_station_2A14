#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QStringList languages;
    languages << "French" << "English";
    QString lang = QInputDialog::getItem(NULL,"choisir langue",
                                         "Langue",languages);
    if( lang == "English")
    {
        t.load(":/english.qm");
    }
    if (lang != "French")
    {
        a.installTranslator(&t);
    }



    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}