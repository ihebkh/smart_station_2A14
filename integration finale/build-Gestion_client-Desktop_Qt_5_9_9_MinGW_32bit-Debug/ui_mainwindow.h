/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *label_17;
    QLabel *label_25;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_69;
    QWidget *page_8;
    QLabel *label_19;
    QLabel *label_24;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_70;
    QWidget *page_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *CIN_2;
    QLineEdit *ID;
    QLineEdit *NOM;
    QLineEdit *NUMTEL;
    QPushButton *pushButtonAjouter;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *NBRETICKET;
    QLabel *label_14;
    QLineEdit *ABONNEMENT;
    QComboBox *DESTINATION;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QWidget *tab_2;
    QTableView *tab_client;
    QLabel *label_10;
    QLineEdit *identifiant;
    QPushButton *id_supp;
    QPushButton *nbrjours_modifier;
    QPushButton *rechercher_button;
    QLabel *label_12;
    QLineEdit *destination;
    QPushButton *qrcodegen;
    QLabel *qrcodecommande;
    QGroupBox *groupBox;
    QRadioButton *radioButton_croissant;
    QRadioButton *radioButton_dcroissant;
    QLineEdit *nbtspoints;
    QPushButton *statsmed_3;
    QLabel *label_4;
    QWidget *tab_3;
    QLabel *label_7;
    QLineEdit *id3;
    QLabel *label_11;
    QPushButton *ajouteravis;
    QLineEdit *avis2;
    QTableView *tab_avis;
    QLabel *label_13;
    QPushButton *supprimeravis_2;
    QPushButton *modifieravis_3;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_31;
    QWidget *page_6;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_71;
    QWidget *page_4;
    QLabel *label_16;
    QLabel *label_22;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_72;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QLabel *label_15;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QPushButton *ajoutertey;
    QLineEdit *caisseajou;
    QLineEdit *sommeajou;
    QLineEdit *idemployeajou;
    QLineEdit *salaireajou;
    QLineEdit *idgaraajou;
    QLineEdit *numfactajou;
    QWidget *tab_6;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLineEdit *caissemod;
    QLineEdit *sommemod;
    QLineEdit *idemployemod;
    QLineEdit *salairemod;
    QLineEdit *idgaragemod;
    QLineEdit *facturemod;
    QPushButton *modifiertey;
    QWidget *tab_5;
    QTableView *tab_caisse;
    QPushButton *tritey;
    QPushButton *recherhcetey;
    QLineEdit *caisserech;
    QLabel *label_37;
    QPushButton *imprimertey;
    QPushButton *supprimertey;
    QPushButton *stattey;
    QWidget *page_7;
    QLabel *label_18;
    QLabel *label_23;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_73;
    QWidget *page_9;
    QPushButton *pushButton_67;
    QPushButton *pushButton_63;
    QPushButton *pushButton_64;
    QPushButton *pushButton_66;
    QPushButton *pushButton_65;
    QPushButton *pushButton_68;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1403, 739);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 1391, 661));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(255,255, 255) ;\n"
""));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_17 = new QLabel(page_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 0, 211, 671));
        label_17->setStyleSheet(QLatin1String("background-color: rgb(112, 114, 110) ;\n"
""));
        label_25 = new QLabel(page_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(800, 330, 56, 16));
        pushButton_21 = new QPushButton(page_3);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(60, 220, 93, 28));
        pushButton_21->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_22 = new QPushButton(page_3);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(60, 270, 93, 28));
        pushButton_22->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_23 = new QPushButton(page_3);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(60, 370, 93, 28));
        pushButton_23->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_24 = new QPushButton(page_3);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(60, 420, 93, 28));
        pushButton_24->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_25 = new QPushButton(page_3);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(60, 320, 93, 28));
        pushButton_25->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_69 = new QPushButton(page_3);
        pushButton_69->setObjectName(QStringLiteral("pushButton_69"));
        pushButton_69->setGeometry(QRect(70, 60, 93, 28));
        pushButton_69->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        stackedWidget->addWidget(page_3);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        label_19 = new QLabel(page_8);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 0, 211, 671));
        label_19->setStyleSheet(QLatin1String("background-color: rgb(112, 114, 110) ;\n"
""));
        label_24 = new QLabel(page_8);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(580, 340, 56, 16));
        pushButton_26 = new QPushButton(page_8);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setGeometry(QRect(60, 240, 93, 28));
        pushButton_26->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_27 = new QPushButton(page_8);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(60, 290, 93, 28));
        pushButton_27->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_28 = new QPushButton(page_8);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(60, 190, 93, 28));
        pushButton_28->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_29 = new QPushButton(page_8);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setGeometry(QRect(60, 390, 93, 28));
        pushButton_29->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_30 = new QPushButton(page_8);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        pushButton_30->setGeometry(QRect(60, 340, 93, 28));
        pushButton_30->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_70 = new QPushButton(page_8);
        pushButton_70->setObjectName(QStringLiteral("pushButton_70"));
        pushButton_70->setGeometry(QRect(60, 50, 93, 28));
        pushButton_70->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        stackedWidget->addWidget(page_8);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(210, 20, 1151, 631));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 81, 41));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 71, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 150, 101, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 210, 141, 16));
        CIN_2 = new QLineEdit(tab);
        CIN_2->setObjectName(QStringLiteral("CIN_2"));
        CIN_2->setGeometry(QRect(220, 50, 113, 20));
        ID = new QLineEdit(tab);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(220, 100, 113, 20));
        NOM = new QLineEdit(tab);
        NOM->setObjectName(QStringLiteral("NOM"));
        NOM->setGeometry(QRect(220, 160, 113, 20));
        NUMTEL = new QLineEdit(tab);
        NUMTEL->setObjectName(QStringLiteral("NUMTEL"));
        NUMTEL->setGeometry(QRect(220, 210, 113, 20));
        pushButtonAjouter = new QPushButton(tab);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setGeometry(QRect(910, 352, 111, 61));
        pushButtonAjouter->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 50, 131, 21));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(450, 100, 181, 21));
        NBRETICKET = new QLineEdit(tab);
        NBRETICKET->setObjectName(QStringLiteral("NBRETICKET"));
        NBRETICKET->setGeometry(QRect(680, 50, 113, 20));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(450, 150, 181, 21));
        ABONNEMENT = new QLineEdit(tab);
        ABONNEMENT->setObjectName(QStringLiteral("ABONNEMENT"));
        ABONNEMENT->setGeometry(QRect(680, 150, 113, 20));
        DESTINATION = new QComboBox(tab);
        DESTINATION->setObjectName(QStringLiteral("DESTINATION"));
        DESTINATION->setGeometry(QRect(680, 100, 111, 22));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 20, 351, 241));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(430, 30, 401, 221));
        tabWidget->addTab(tab, QString());
        groupBox_3->raise();
        groupBox_2->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_5->raise();
        CIN_2->raise();
        ID->raise();
        NOM->raise();
        NUMTEL->raise();
        pushButtonAjouter->raise();
        label_8->raise();
        label_9->raise();
        NBRETICKET->raise();
        label_14->raise();
        ABONNEMENT->raise();
        DESTINATION->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_client = new QTableView(tab_2);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(20, 40, 611, 331));
        tab_client->setStyleSheet(QLatin1String("QTableView {\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                stop: 0 #FF92BB, stop: 1 black);\n"
"}"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(720, 20, 81, 16));
        identifiant = new QLineEdit(tab_2);
        identifiant->setObjectName(QStringLiteral("identifiant"));
        identifiant->setGeometry(QRect(820, 20, 113, 22));
        id_supp = new QPushButton(tab_2);
        id_supp->setObjectName(QStringLiteral("id_supp"));
        id_supp->setGeometry(QRect(670, 110, 93, 28));
        id_supp->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        nbrjours_modifier = new QPushButton(tab_2);
        nbrjours_modifier->setObjectName(QStringLiteral("nbrjours_modifier"));
        nbrjours_modifier->setGeometry(QRect(840, 110, 93, 28));
        nbrjours_modifier->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        rechercher_button = new QPushButton(tab_2);
        rechercher_button->setObjectName(QStringLiteral("rechercher_button"));
        rechercher_button->setGeometry(QRect(980, 110, 93, 28));
        rechercher_button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(720, 60, 81, 16));
        destination = new QLineEdit(tab_2);
        destination->setObjectName(QStringLiteral("destination"));
        destination->setGeometry(QRect(820, 60, 113, 22));
        qrcodegen = new QPushButton(tab_2);
        qrcodegen->setObjectName(QStringLiteral("qrcodegen"));
        qrcodegen->setGeometry(QRect(860, 440, 200, 28));
        qrcodegen->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        qrcodecommande = new QLabel(tab_2);
        qrcodecommande->setObjectName(QStringLiteral("qrcodecommande"));
        qrcodecommande->setEnabled(true);
        qrcodecommande->setGeometry(QRect(860, 230, 200, 200));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qrcodecommande->sizePolicy().hasHeightForWidth());
        qrcodecommande->setSizePolicy(sizePolicy);
        qrcodecommande->setMinimumSize(QSize(200, 200));
        qrcodecommande->setMaximumSize(QSize(200, 200));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(100, 430, 191, 131));
        radioButton_croissant = new QRadioButton(groupBox);
        radioButton_croissant->setObjectName(QStringLiteral("radioButton_croissant"));
        radioButton_croissant->setGeometry(QRect(10, 40, 161, 20));
        radioButton_dcroissant = new QRadioButton(groupBox);
        radioButton_dcroissant->setObjectName(QStringLiteral("radioButton_dcroissant"));
        radioButton_dcroissant->setGeometry(QRect(10, 80, 171, 20));
        nbtspoints = new QLineEdit(tab_2);
        nbtspoints->setObjectName(QStringLiteral("nbtspoints"));
        nbtspoints->setGeometry(QRect(460, 500, 113, 22));
        statsmed_3 = new QPushButton(tab_2);
        statsmed_3->setObjectName(QStringLiteral("statsmed_3"));
        statsmed_3->setGeometry(QRect(860, 480, 201, 28));
        statsmed_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(380, 410, 281, 171));
        tabWidget->addTab(tab_2, QString());
        label_4->raise();
        tab_client->raise();
        label_10->raise();
        identifiant->raise();
        id_supp->raise();
        nbrjours_modifier->raise();
        rechercher_button->raise();
        label_12->raise();
        destination->raise();
        qrcodegen->raise();
        qrcodecommande->raise();
        groupBox->raise();
        nbtspoints->raise();
        statsmed_3->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 50, 71, 16));
        id3 = new QLineEdit(tab_3);
        id3->setObjectName(QStringLiteral("id3"));
        id3->setGeometry(QRect(210, 50, 113, 20));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 160, 47, 14));
        ajouteravis = new QPushButton(tab_3);
        ajouteravis->setObjectName(QStringLiteral("ajouteravis"));
        ajouteravis->setGeometry(QRect(30, 230, 111, 28));
        ajouteravis->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        avis2 = new QLineEdit(tab_3);
        avis2->setObjectName(QStringLiteral("avis2"));
        avis2->setGeometry(QRect(210, 160, 121, 21));
        tab_avis = new QTableView(tab_3);
        tab_avis->setObjectName(QStringLiteral("tab_avis"));
        tab_avis->setGeometry(QRect(550, 30, 471, 331));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 120, 491, 31));
        supprimeravis_2 = new QPushButton(tab_3);
        supprimeravis_2->setObjectName(QStringLiteral("supprimeravis_2"));
        supprimeravis_2->setGeometry(QRect(30, 270, 111, 28));
        supprimeravis_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        modifieravis_3 = new QPushButton(tab_3);
        modifieravis_3->setObjectName(QStringLiteral("modifieravis_3"));
        modifieravis_3->setGeometry(QRect(30, 310, 111, 28));
        modifieravis_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        tabWidget->addTab(tab_3, QString());
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 0, 211, 671));
        label_6->setStyleSheet(QLatin1String("background-color: rgb(112, 114, 110) ;\n"
""));
        pushButton = new QPushButton(page_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 200, 93, 28));
        pushButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_2 = new QPushButton(page_5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 250, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_3 = new QPushButton(page_5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 300, 93, 28));
        pushButton_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_4 = new QPushButton(page_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 350, 93, 28));
        pushButton_4->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_5 = new QPushButton(page_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(50, 400, 93, 28));
        pushButton_5->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_31 = new QPushButton(page_5);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setGeometry(QRect(40, 50, 93, 28));
        pushButton_31->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_20 = new QLabel(page_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(-10, 0, 221, 671));
        label_20->setStyleSheet(QLatin1String("background-color: rgb(112, 114, 110) ;\n"
""));
        label_21 = new QLabel(page_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(660, 320, 56, 16));
        pushButton_6 = new QPushButton(page_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(60, 290, 93, 28));
        pushButton_6->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_7 = new QPushButton(page_6);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(60, 390, 93, 28));
        pushButton_7->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_8 = new QPushButton(page_6);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(60, 240, 93, 28));
        pushButton_8->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_9 = new QPushButton(page_6);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(60, 440, 93, 28));
        pushButton_9->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_10 = new QPushButton(page_6);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(60, 340, 93, 28));
        pushButton_10->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_71 = new QPushButton(page_6);
        pushButton_71->setObjectName(QStringLiteral("pushButton_71"));
        pushButton_71->setGeometry(QRect(70, 70, 93, 28));
        pushButton_71->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        stackedWidget->addWidget(page_6);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_16 = new QLabel(page_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 0, 211, 671));
        label_16->setStyleSheet(QLatin1String("background-color: rgb(112, 114, 110) ;\n"
""));
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(600, 370, 56, 16));
        pushButton_11 = new QPushButton(page_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(70, 320, 93, 28));
        pushButton_11->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_12 = new QPushButton(page_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(70, 220, 93, 28));
        pushButton_12->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_13 = new QPushButton(page_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(70, 270, 93, 28));
        pushButton_13->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_14 = new QPushButton(page_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(70, 370, 93, 28));
        pushButton_14->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_15 = new QPushButton(page_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(70, 420, 93, 28));
        pushButton_15->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_72 = new QPushButton(page_4);
        pushButton_72->setObjectName(QStringLiteral("pushButton_72"));
        pushButton_72->setGeometry(QRect(120, 110, 93, 28));
        pushButton_72->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        tabWidget_2 = new QTabWidget(page_4);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(220, 10, 961, 571));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(70, 140, 56, 16));
        label_26 = new QLabel(tab_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(70, 190, 91, 16));
        label_27 = new QLabel(tab_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(70, 240, 91, 16));
        label_28 = new QLabel(tab_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(70, 290, 91, 16));
        label_29 = new QLabel(tab_4);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(70, 340, 91, 16));
        label_30 = new QLabel(tab_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(70, 390, 91, 16));
        ajoutertey = new QPushButton(tab_4);
        ajoutertey->setObjectName(QStringLiteral("ajoutertey"));
        ajoutertey->setGeometry(QRect(530, 470, 93, 28));
        caisseajou = new QLineEdit(tab_4);
        caisseajou->setObjectName(QStringLiteral("caisseajou"));
        caisseajou->setGeometry(QRect(200, 140, 113, 22));
        sommeajou = new QLineEdit(tab_4);
        sommeajou->setObjectName(QStringLiteral("sommeajou"));
        sommeajou->setGeometry(QRect(200, 190, 113, 22));
        idemployeajou = new QLineEdit(tab_4);
        idemployeajou->setObjectName(QStringLiteral("idemployeajou"));
        idemployeajou->setGeometry(QRect(200, 240, 113, 22));
        salaireajou = new QLineEdit(tab_4);
        salaireajou->setObjectName(QStringLiteral("salaireajou"));
        salaireajou->setGeometry(QRect(200, 290, 113, 22));
        idgaraajou = new QLineEdit(tab_4);
        idgaraajou->setObjectName(QStringLiteral("idgaraajou"));
        idgaraajou->setGeometry(QRect(200, 340, 113, 22));
        numfactajou = new QLineEdit(tab_4);
        numfactajou->setObjectName(QStringLiteral("numfactajou"));
        numfactajou->setGeometry(QRect(200, 390, 113, 22));
        tabWidget_2->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_31 = new QLabel(tab_6);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(90, 270, 91, 16));
        label_32 = new QLabel(tab_6);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(90, 170, 91, 16));
        label_33 = new QLabel(tab_6);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(90, 220, 91, 16));
        label_34 = new QLabel(tab_6);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(90, 320, 91, 16));
        label_35 = new QLabel(tab_6);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(90, 370, 91, 16));
        label_36 = new QLabel(tab_6);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(90, 120, 56, 16));
        caissemod = new QLineEdit(tab_6);
        caissemod->setObjectName(QStringLiteral("caissemod"));
        caissemod->setGeometry(QRect(220, 120, 113, 22));
        sommemod = new QLineEdit(tab_6);
        sommemod->setObjectName(QStringLiteral("sommemod"));
        sommemod->setGeometry(QRect(220, 170, 113, 22));
        idemployemod = new QLineEdit(tab_6);
        idemployemod->setObjectName(QStringLiteral("idemployemod"));
        idemployemod->setGeometry(QRect(220, 220, 113, 22));
        salairemod = new QLineEdit(tab_6);
        salairemod->setObjectName(QStringLiteral("salairemod"));
        salairemod->setGeometry(QRect(220, 270, 113, 22));
        idgaragemod = new QLineEdit(tab_6);
        idgaragemod->setObjectName(QStringLiteral("idgaragemod"));
        idgaragemod->setGeometry(QRect(220, 320, 113, 22));
        facturemod = new QLineEdit(tab_6);
        facturemod->setObjectName(QStringLiteral("facturemod"));
        facturemod->setGeometry(QRect(220, 370, 113, 22));
        modifiertey = new QPushButton(tab_6);
        modifiertey->setObjectName(QStringLiteral("modifiertey"));
        modifiertey->setGeometry(QRect(520, 410, 93, 28));
        tabWidget_2->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tab_caisse = new QTableView(tab_5);
        tab_caisse->setObjectName(QStringLiteral("tab_caisse"));
        tab_caisse->setGeometry(QRect(30, 30, 871, 421));
        tritey = new QPushButton(tab_5);
        tritey->setObjectName(QStringLiteral("tritey"));
        tritey->setGeometry(QRect(30, 470, 93, 28));
        recherhcetey = new QPushButton(tab_5);
        recherhcetey->setObjectName(QStringLiteral("recherhcetey"));
        recherhcetey->setGeometry(QRect(150, 470, 93, 28));
        caisserech = new QLineEdit(tab_5);
        caisserech->setObjectName(QStringLiteral("caisserech"));
        caisserech->setGeometry(QRect(150, 520, 91, 22));
        label_37 = new QLabel(tab_5);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(150, 500, 56, 16));
        imprimertey = new QPushButton(tab_5);
        imprimertey->setObjectName(QStringLiteral("imprimertey"));
        imprimertey->setGeometry(QRect(280, 470, 93, 28));
        supprimertey = new QPushButton(tab_5);
        supprimertey->setObjectName(QStringLiteral("supprimertey"));
        supprimertey->setGeometry(QRect(510, 470, 93, 28));
        stattey = new QPushButton(tab_5);
        stattey->setObjectName(QStringLiteral("stattey"));
        stattey->setGeometry(QRect(400, 470, 93, 28));
        tabWidget_2->addTab(tab_5, QString());
        stackedWidget->addWidget(page_4);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        label_18 = new QLabel(page_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 0, 211, 671));
        label_18->setStyleSheet(QLatin1String("background-color: rgb(112, 114, 110) ;\n"
""));
        label_23 = new QLabel(page_7);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(580, 380, 56, 16));
        pushButton_16 = new QPushButton(page_7);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(70, 340, 93, 28));
        pushButton_16->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_17 = new QPushButton(page_7);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(70, 240, 93, 28));
        pushButton_17->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_18 = new QPushButton(page_7);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(70, 440, 93, 28));
        pushButton_18->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_19 = new QPushButton(page_7);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(70, 290, 93, 28));
        pushButton_19->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_20 = new QPushButton(page_7);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(70, 390, 93, 28));
        pushButton_20->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_73 = new QPushButton(page_7);
        pushButton_73->setObjectName(QStringLiteral("pushButton_73"));
        pushButton_73->setGeometry(QRect(130, 90, 93, 28));
        pushButton_73->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        stackedWidget->addWidget(page_7);
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        pushButton_67 = new QPushButton(page_9);
        pushButton_67->setObjectName(QStringLiteral("pushButton_67"));
        pushButton_67->setGeometry(QRect(290, 230, 141, 71));
        pushButton_67->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_63 = new QPushButton(page_9);
        pushButton_63->setObjectName(QStringLiteral("pushButton_63"));
        pushButton_63->setGeometry(QRect(540, 370, 141, 71));
        pushButton_63->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_64 = new QPushButton(page_9);
        pushButton_64->setObjectName(QStringLiteral("pushButton_64"));
        pushButton_64->setGeometry(QRect(290, 370, 141, 71));
        pushButton_64->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_66 = new QPushButton(page_9);
        pushButton_66->setObjectName(QStringLiteral("pushButton_66"));
        pushButton_66->setGeometry(QRect(590, 217, 171, 81));
        pushButton_66->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_65 = new QPushButton(page_9);
        pushButton_65->setObjectName(QStringLiteral("pushButton_65"));
        pushButton_65->setGeometry(QRect(760, 370, 141, 71));
        pushButton_65->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        pushButton_68 = new QPushButton(page_9);
        pushButton_68->setObjectName(QStringLiteral("pushButton_68"));
        pushButton_68->setGeometry(QRect(850, 240, 151, 51));
        pushButton_68->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color:  QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#000075, stop: 1 #000075);\n"
" border-radius: 10;"));
        stackedWidget->addWidget(page_9);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1403, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_17->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "client", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("MainWindow", "reparation", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("MainWindow", "guichets", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_69->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        label_19->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "guichet", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("MainWindow", "client", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("MainWindow", "reparation", Q_NULLPTR));
        pushButton_70->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Cin :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Identifiant :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Nom et prenom :", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Numero de telephone :", Q_NULLPTR));
        pushButtonAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "nombre du ticket :", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Destination : ", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Num\303\251ro de l'abonnement :", Q_NULLPTR));
        DESTINATION->clear();
        DESTINATION->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Rades", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Ezzahra", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Hammem lif", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Autre", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Donn\303\251s personelles :", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Pour la reservation ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter Client", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Identifiant :", Q_NULLPTR));
        id_supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        nbrjours_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        rechercher_button->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Destination :", Q_NULLPTR));
        qrcodegen->setText(QApplication::translate("MainWindow", "QR Code", Q_NULLPTR));
        qrcodecommande->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Trier  :", Q_NULLPTR));
        radioButton_croissant->setText(QApplication::translate("MainWindow", "nom croissant", Q_NULLPTR));
        radioButton_dcroissant->setText(QApplication::translate("MainWindow", "nom decroissant", Q_NULLPTR));
        statsmed_3->setText(QApplication::translate("MainWindow", "Appliquer la statistique", Q_NULLPTR));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher Client", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Identifiant :", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Avis :", Q_NULLPTR));
        ajouteravis->setText(QApplication::translate("MainWindow", "Ajouter Avis", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Tapez votre avis : (mauvais-moyen-bien-execellent ) pour am\303\251liorer notre application :", Q_NULLPTR));
        supprimeravis_2->setText(QApplication::translate("MainWindow", "supprimer Avis", Q_NULLPTR));
        modifieravis_3->setText(QApplication::translate("MainWindow", "modifier Avis", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Avis", Q_NULLPTR));
        label_6->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "guichet", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "reparation", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "guichet", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "client", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "reparation", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_71->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        label_16->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "reparation", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "client", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "guichets", Q_NULLPTR));
        pushButton_72->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "ID caisse", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Somme Caisse", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Id employe", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "Slaire employe", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "Id garage", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "N\302\260 Facture", Q_NULLPTR));
        ajoutertey->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "Slaire employe", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "Somme Caisse", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "Id employe", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "Id garage", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "N\302\260 Facture", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "ID caisse", Q_NULLPTR));
        modifiertey->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        tritey->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        recherhcetey->setText(QApplication::translate("MainWindow", "recherche", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "Id Caisse", Q_NULLPTR));
        imprimertey->setText(QApplication::translate("MainWindow", "Imprimer/pdf", Q_NULLPTR));
        supprimertey->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        stattey->setText(QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        label_18->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "rep", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("MainWindow", "client", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("MainWindow", "guichets", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_73->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        pushButton_67->setText(QApplication::translate("MainWindow", "finance", Q_NULLPTR));
        pushButton_63->setText(QApplication::translate("MainWindow", "client", Q_NULLPTR));
        pushButton_64->setText(QApplication::translate("MainWindow", "employe", Q_NULLPTR));
        pushButton_66->setText(QApplication::translate("MainWindow", "guichets", Q_NULLPTR));
        pushButton_65->setText(QApplication::translate("MainWindow", "logistique", Q_NULLPTR));
        pushButton_68->setText(QApplication::translate("MainWindow", "reparations", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
