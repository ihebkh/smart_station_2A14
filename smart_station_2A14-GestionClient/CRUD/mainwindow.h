#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "caisse.h"
#include <QMainWindow>
#include "client.h"
#include "avis.h"
#include <QSound>
#include"guichet.h"
#include"reparations.h"
#include <QMainWindow>
#include"reparations.h"
#include <QDialog>

#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QUrl>
#include <QSystemTrayIcon>
#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
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
#include "smtp.h"
#include "vehicule.h"
#include <QMediaPlayer>
#include "employe.h"
#include "QMovie"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

     void showtime();

    void on_pushButtonAjouter_clicked();

    void on_id_supp_clicked();


    void on_nbrjours_modifier_clicked();

    void on_rechercher_button_clicked();

    void on_trier_button_clicked();

    void on_qrcodegen_clicked();

    void on_ajouteravis_clicked();

    void on_radioButton_croissant_clicked();

    void on_radioButton_dcroissant_clicked();


    void on_supprimeravis_2_clicked();

    void on_modifieravis_3_clicked();

    void on_statsmed_clicked();

    void on_destination_2_clicked();

    void on_tab_client_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_66_clicked();

    void on_pushButton_68_clicked();


    void on_supprimertey_clicked();

    void on_recherhcetey_clicked();

    void on_imprimertey_clicked();

    void on_tritey_clicked();

    void on_stattey_clicked();

    void on_ajoutertey_clicked();

    void on_modifiertey_clicked();

    void on_ajouterdaadaa_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_trierdaadaa_clicked();

    void on_rechercherdaadaa_clicked();

    void on_imprimerdaadaa_clicked();

    void on_statistiquedaadaa_clicked();

    void on_localiserdaadaaa_clicked();

    void on_excel_clicked();

    void on_excel_2_clicked();

    void on_excel_3_clicked();

    void on_cancel_clicked();

    void on_Applytheme_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_32_clicked();

    void on_ajouterismael_clicked();

    void on_imprimerismael_clicked();

    void on_rechercherismael_clicked();

    void on_modifierismael_clicked();

    void on_supprimerismael_clicked();

    void on_radioButton_croissant_2_clicked();

    void on_radioButton_dcroissant_2_clicked();

    void on_calculerismael_clicked();

    void on_exitismael_clicked();

    void on_appliquerstatismael_clicked();

    void on_envoyermailismael_clicked();

    void on_Login_clicked();

    void on_resetlogin_clicked();

    void on_dec_clicked();

    void on_quitttter_clicked();

    void on_ajouterrayen_clicked();

    void on_supprimerrayen_clicked();

    void on_modifierrayen_clicked();

    void on_rechercherayen_clicked();

    void on_trierrayen_clicked();

    void on_qrcodegen_2_clicked();

    void on_afficherstat_clicked();

   void on_imprimerrayen_clicked();

   void on_MuteMedia_clicked();

   void on_StopMedia_clicked();

   void on_PauseMedia_clicked();

   void on_PlayMedia_clicked();

   void on_OpenMedia_clicked();

   void on_VolumeMediaControl_actionTriggered(int action);

   void on_VolumeMediaControl_valueChanged(int value);

   void on_ajouteremploye_clicked();

   void on_supprimeempoye_clicked();

   void on_prenomtri_clicked();

   void on_emailtri_clicked();

   void on_nomtri_clicked();

   void on_envoyeremploye_clicked();

   void on_rechercheremploye_clicked();

   void on_statsmed_3_clicked();


   void on_stataziz_clicked();

   void on_pdfaziz_clicked();
   void animation();

private:
    Ui::MainWindow *ui;
    QSound *son;
    Client Etmp;
    caisse cai;
    avis AA;
    Guichet G;
    Reparations R;
    QStringList files;
    vehicule v;
    Employe E;
    QMediaPlayer *mMediaPlayer ;

};

#endif // MAINWINDOW_H
