#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "caisse.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QtCharts>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int idcaisse=ui->la_caisse->text().toInt();
    int sommecaisse=ui->la_somme->text().toInt();
    int idgarage=ui->iddegarage->text().toInt();
    int idemploye=ui->idemp->text().toInt();
    int facture=ui->lafacture->text().toInt();
    int salaire=ui->salairedelemp->text().toInt();


caisse C(idcaisse,sommecaisse,idgarage,idemploye,facture,salaire);
bool test=C.ajouter();
if (test)
        { //Actualiser
     ui->tab_caisse->setModel(cai.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_supp_clicked()
{
    QItemSelectionModel *select = ui->tab_caisse->selectionModel();

           int idcaisse =select->selectedRows(0).value(0).data().toString().toInt();
           if(cai.supp(idcaisse))
           {
               ui->tab_caisse->setModel(cai.afficher());
               QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                  QObject::tr("Suppression effectué\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_recherche_clicked()
{
    QString rech =ui->idcaisse2_2->text();
        ui->tab_caisse->setModel(cai.rechercher(rech));
}

void MainWindow::on_tri_clicked()
{
    caisse *c = new caisse();
    ui->tab_caisse->setModel(c->tri());
}


void MainWindow::on_update_clicked()
{

    int idcaisse=ui->idcaisse2_2->text().toInt();
    int sommecaisse=ui->sommecaisse2->text().toInt();
    int idemploye=ui->idemp_4->text().toInt();
    int salaire=ui->salaireemp_2->text().toInt();
    int idgarage=ui->idgara_2->text().toInt();
    int facture=ui->fact_2->text().toInt();



    bool test = cai.update(idcaisse,sommecaisse,idgarage,idemploye,facture,salaire);

            if(test)

            {
                ui->tab_caisse->setModel(cai.afficher());


                QMessageBox::information(nullptr, QObject::tr("update "),
                                         QObject::tr("Caisse modifie\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
            }

        }




/*void MainWindow::on_pushButton_10_clicked()
{

}*/

void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from FINANCE where SOMMECAISSE > 100 ");
       int number1=model->rowCount();
       model->setQuery("select * from FINANCE where SOMMECAISSE < 100 ");
       int number2=model->rowCount();
       int total=number1+number2;
       QString a = QString("caisse > 100  "+QString::number((number1*100)/total,'f',2)+"%" );
       QString b = QString("caisse < 100 "+QString::number((number2*100)/total,'f',2)+"%" );

       QPieSeries *series = new QPieSeries();
       series->append(a,number1);
       series->append(b,number2);

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

               // Create the chart widget
               QChart *chart = new QChart();
               // Add data to chart with title and hide legend
               chart->addSeries(series);
               chart->setTitle("Pourcentage Par Somme des caisse "+ QString::number(total));
               chart->legend()->hide();
               // Used to display the chart
               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               chartView->show();

}

void MainWindow::on_print_clicked()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
        notifyIcon-> show ();
        notifyIcon-> showMessage ( " Caisse " , " Finance PDF " , QSystemTrayIcon :: Information, 15000 );
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_caisse->model()->rowCount();
        const int columnCount = ui->tab_caisse->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             <<  QString("<title>%1</title>\n").arg("Title")
              <<  "</head>\n"
               <<"<body bgcolor=#ffffff link=#5000A0>\n"

                 //     "<align='right'> " << datefich << "</align>"
              <<"<center> <H1>Responsable des Finances</H1></br></br>Liste des caisse </br></br><table border=1 cellspacing=0 cellpadding=2>\n";


        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tab_caisse->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_caisse->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_caisse->isColumnHidden(column)) {
                    QString data = ui->tab_caisse->model()->data(ui->tab_caisse->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
                "</body>\n"
                "</html>\n";



        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setPaperSize(QPrinter::A4);
        printer->setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(printer);

        QPrinter *p=new QPrinter();
        QPrintDialog dialog(p,this);
        if(dialog.exec()== QDialog::Rejected)
        {
            return;
        }
}

