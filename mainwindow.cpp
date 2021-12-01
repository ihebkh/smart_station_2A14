#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "QrCode.hpp"

#include <QIntValidator>
#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_vehicule->setModel(Etmp.afficher());
    ui->le_matricule->setMaxLength(12);
    ui->le_model->setMaxLength(10);
    ui->le_etat->setMaxLength(10);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonAjouter_clicked()
{
    QString  matricule=ui->le_matricule->text();
    QString  marque=ui->le_marque->currentText();
    QString model=ui->le_model->text();
    QString etat=ui->le_etat->text();

    vehicule Etmp(matricule,marque,model,etat);




    bool test=Etmp.ajouter();
    if (test)
            { //Actualiser
         ui->tab_vehicule->setModel(Etmp.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("Ajout effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);





}

void MainWindow::on_id_supp_clicked()
{
    QItemSelectionModel *select = ui->tab_vehicule->selectionModel();

           QString mat =select->selectedRows(0).value(0).data().toString();
           if(Etmp.supprimer(mat))
           {
               ui->tab_vehicule->setModel(Etmp.afficher());
               QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                  QObject::tr("Suppression effectué\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
           }

void MainWindow::on_nbrjours_modifier_clicked()
{
    QString mat=ui->le_matricule->text();
    QString  marq=ui->le_marque->currentText();
    QString modl=ui->le_model->text();
    QString etatv=ui->le_etat->text();


         vehicule c;
         if (mat.isEmpty())
             {
                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir la matricule svp."),QMessageBox::Cancel);
             }
         else
         {
     bool test=c.modifier(mat);
     if (test)
             { //Actualiser
          ui->tab_vehicule->setModel(Etmp.afficher());
             QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                QObject::tr("Modification de vehicule effectué©\n"
                                                            "click cancel to exit."),QMessageBox::Cancel);
             }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("Ajout non effectué.\n"

                                       "click Cancel to exit."),QMessageBox::Cancel);

}
}

void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->le_matricule2->text();
        ui->tab_vehicule->setModel(Etmp.rechercher(rech));
}

void MainWindow::on_trier_button_clicked()
{

        vehicule *c = new vehicule();
        ui->tab_vehicule->setModel(c->tri());

}


void MainWindow::on_qrcodegen_clicked()
{
    int tabeq=ui->tab_vehicule->currentIndex().row();
           QVariant x=ui->tab_vehicule->model()->data(ui->tab_vehicule->model()->index(tabeq,0));
           QString matt= x.toString();
           QSqlQuery qry;
           qry.prepare("select * from vehicule where mat=:matt");
           qry.bindValue(":mat",matt);
           qry.exec();
              QString  iden,marque,model,etat ,ide;

           while(qry.next()){

               matt=qry.value(1).toString();
               marque=qry.value(2).toString();
               model=qry.value(3).toString();
               etat=qry.value(4).toString();





           }
           ide=QString(matt);
                  ide="matricule:"+matt+"marque:"+marque+"model:"+model,"etat:"+etat;
           QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from vehicule where marque ='BMW' ");
     int number1=model->rowCount();
     model->setQuery("select * from vehicule where marque='PEUGEOT' ");
     int number2=model->rowCount();
     model->setQuery("select * from vehicule where marque='RENAULT' ");
     int number3=model->rowCount(); // calculer le nombre de voiture de marque RENAULT
    model->setQuery("select * from vehicule where marque='OPEL' ");
          int number4=model->rowCount();
          model->setQuery("select * from vehicule where marque='CHEVROLET' ");
          int number5=model->rowCount();
     model->setQuery("select * from vehicule where marque='Autre' ");
     int number6=model->rowCount();
     int total=number1+number2+number3+number4+number5+number6;
     QString a = QString("BMW"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("PEUGEOT"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("RENAULT"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("OPEL" +QString::number((number4*100)/total,'f',2)+"%" );

      QString e = QString("CHEVROLET" +QString::number((number5*100)/total,'f',2)+"%" );

     QString f = QString("Autre "+QString::number((number6*100)/total,'f',2)+"%" );
     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par marque de voitures :Nombre Des MARQUE "+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}


void MainWindow::on_btn_imp_clicked()
{
    QString strStream;
                             QTextStream out(&strStream);

                             const int rowCount = ui->tab_vehicule->model()->rowCount();
                             const int columnCount = ui->tab_vehicule->model()->columnCount();
                             QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                             out <<"<html>\n"
                                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 << "<title>ERP - COMmANDE LIST<title>\n "
                                 << "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"
                                 "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                                 "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                   "</br> </br>";
                             // headers
                             out << "<thead><tr bgcolor=#d6e5ff>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!ui->tab_vehicule->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(ui->tab_vehicule->model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tab_vehicule->isColumnHidden(column)) {
                                         QString data =ui->tab_vehicule->model()->data(ui->tab_vehicule->model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table>\n"
                                 "</body>\n"
                                 "</html>\n";

                             QTextDocument *document = new QTextDocument();
                             document->setHtml(strStream);

                             QPrinter printer;

                             QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                             if (dialog->exec() == QDialog::Accepted) {
                                 document->print(&printer);
                             }

                             delete document;


}
