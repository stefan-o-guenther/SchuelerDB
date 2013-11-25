// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

/********************************************************************************
** Form generated from reading ui file 'Schueler_VerwaltungJ10471.ui'
**
** Created: Tue May 31 21:28:57 2011
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef Schueler_VerwaltungJ10471_H
#define Schueler_VerwaltungJ10471_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

//! Fenster zur Sch&uuml;lerverwaltung.
/*!
 * Automatisch generierte Klasse.
 *
 */

class Ui_Schueler_Verwaltung
{
public:
    QGroupBox *grbPflicht;
    QLineEdit *edtVorname;
    QLabel *lblNachname;
    QLabel *lblVorname;
    QLineEdit *edtNachname;
    QPushButton *btnOK;
    QGroupBox *grbKommentar;
    QTextEdit *txtKommentar;
    QGroupBox *grbRechte;
    QRadioButton *rbtnSchueler;
    QRadioButton *rbtnOrganisator;
    QLineEdit *edtPasswort;
    QLineEdit *edtWiederholen;
    QLabel *lblPasswort;
    QLabel *lblWiederholen;
    QPushButton *btnVerlauf;
    QPushButton *btnAktion;
    QGroupBox *grbOptional;
    QLabel *lblNeuerNachname;
    QLabel *lblStrHnr;
    QLabel *lblOrt;
    QLabel *lblPLZ;
    QLabel *lblLand;
    QLabel *lblEmail;
    QLineEdit *edtNeuerNachname;
    QLineEdit *edtStrHnr;
    QLineEdit *edtPLZ;
    QLineEdit *edtOrt;
    QLineEdit *edtLand;
    QLineEdit *edtTelefon;
    QLineEdit *edtEmail;
    QLabel *lblTelefon;
    QPushButton *btnBearbeiten;
    QGroupBox *grbVerlauf;
    QTreeWidget *treeWidget;
    QPushButton *btnAbbrechen;

    void setupUi(QDialog *Schueler_Verwaltung)
    {
    if (Schueler_Verwaltung->objectName().isEmpty())
        Schueler_Verwaltung->setObjectName(QString::fromUtf8("Schueler_Verwaltung"));
    Schueler_Verwaltung->resize(707, 393); //(707, 668)
    Schueler_Verwaltung->setMinimumSize(QSize(707, 393)); //(707, 668)
    Schueler_Verwaltung->setMaximumSize(QSize(707, 393)); //(707, 668)
    grbPflicht = new QGroupBox(Schueler_Verwaltung);
    grbPflicht->setObjectName(QString::fromUtf8("grbPflicht"));
    grbPflicht->setEnabled(true);
    grbPflicht->setGeometry(QRect(10, 10, 321, 91));
    edtVorname = new QLineEdit(grbPflicht);
    edtVorname->setObjectName(QString::fromUtf8("edtVorname"));
    edtVorname->setEnabled(true);
    edtVorname->setGeometry(QRect(80, 30, 231, 24));
    lblNachname = new QLabel(grbPflicht);
    lblNachname->setObjectName(QString::fromUtf8("lblNachname"));
    lblNachname->setEnabled(true);
    lblNachname->setGeometry(QRect(10, 60, 71, 18));
    lblNachname->setLineWidth(1);
    lblVorname = new QLabel(grbPflicht);
    lblVorname->setObjectName(QString::fromUtf8("lblVorname"));
    lblVorname->setEnabled(true);
    lblVorname->setGeometry(QRect(10, 30, 61, 18));
    edtNachname = new QLineEdit(grbPflicht);
    edtNachname->setObjectName(QString::fromUtf8("edtNachname"));
    edtNachname->setEnabled(true);
    edtNachname->setGeometry(QRect(80, 60, 231, 24));
    btnOK = new QPushButton(Schueler_Verwaltung);
    btnOK->setObjectName(QString::fromUtf8("btnOK"));
    btnOK->setEnabled(true);
    btnOK->setGeometry(QRect(590, 360, 111, 28));
    grbKommentar = new QGroupBox(Schueler_Verwaltung);
    grbKommentar->setObjectName(QString::fromUtf8("grbKommentar"));
    grbKommentar->setEnabled(true);
    grbKommentar->setGeometry(QRect(10, 110, 321, 141));
    txtKommentar = new QTextEdit(grbKommentar);
    txtKommentar->setObjectName(QString::fromUtf8("txtKommentar"));
    txtKommentar->setEnabled(true);
    txtKommentar->setGeometry(QRect(10, 20, 301, 111));
    grbRechte = new QGroupBox(Schueler_Verwaltung);
    grbRechte->setObjectName(QString::fromUtf8("grbRechte"));
    grbRechte->setEnabled(true);
    grbRechte->setGeometry(QRect(10, 260, 691, 91));
    rbtnSchueler = new QRadioButton(grbRechte);
    rbtnSchueler->setObjectName(QString::fromUtf8("rbtnSchueler"));
    rbtnSchueler->setEnabled(true);
    rbtnSchueler->setGeometry(QRect(20, 20, 92, 24));
    rbtnSchueler->setChecked(false);
    rbtnOrganisator = new QRadioButton(grbRechte);
    rbtnOrganisator->setObjectName(QString::fromUtf8("rbtnOrganisator"));
    rbtnOrganisator->setEnabled(true);
    rbtnOrganisator->setGeometry(QRect(20, 50, 92, 24));
    rbtnOrganisator->setChecked(true);
    edtPasswort = new QLineEdit(grbRechte);
    edtPasswort->setObjectName(QString::fromUtf8("edtPasswort"));
    edtPasswort->setEnabled(true);
    edtPasswort->setGeometry(QRect(450, 20, 231, 24));
    edtWiederholen = new QLineEdit(grbRechte);
    edtWiederholen->setObjectName(QString::fromUtf8("edtWiederholen"));
    edtWiederholen->setEnabled(true);
    edtWiederholen->setGeometry(QRect(450, 50, 231, 24));
    lblPasswort = new QLabel(grbRechte);
    lblPasswort->setObjectName(QString::fromUtf8("lblPasswort"));
    lblPasswort->setEnabled(true);
    lblPasswort->setGeometry(QRect(370, 20, 54, 18));
    lblWiederholen = new QLabel(grbRechte);
    lblWiederholen->setObjectName(QString::fromUtf8("lblWiederholen"));
    lblWiederholen->setEnabled(true);
    lblWiederholen->setGeometry(QRect(370, 50, 71, 31));
    btnVerlauf = new QPushButton(Schueler_Verwaltung);
    btnVerlauf->setObjectName(QString::fromUtf8("btnVerlauf"));
    btnVerlauf->setEnabled(true);
    btnVerlauf->setGeometry(QRect(10, 360, 111, 28));
    btnAktion = new QPushButton(Schueler_Verwaltung);
    btnAktion->setObjectName(QString::fromUtf8("btnAktion"));
    btnAktion->setEnabled(true);
    btnAktion->setGeometry(QRect(300, 360, 111, 28));
    grbOptional = new QGroupBox(Schueler_Verwaltung);
    grbOptional->setObjectName(QString::fromUtf8("grbOptional"));
    grbOptional->setEnabled(true);
    grbOptional->setGeometry(QRect(350, 10, 351, 241));
    lblNeuerNachname = new QLabel(grbOptional);
    lblNeuerNachname->setObjectName(QString::fromUtf8("lblNeuerNachname"));
    lblNeuerNachname->setEnabled(true);
    lblNeuerNachname->setGeometry(QRect(10, 30, 101, 18));
    lblStrHnr = new QLabel(grbOptional);
    lblStrHnr->setObjectName(QString::fromUtf8("lblStrHnr"));
    lblStrHnr->setEnabled(true);
    lblStrHnr->setGeometry(QRect(10, 60, 91, 18));
    lblOrt = new QLabel(grbOptional);
    lblOrt->setObjectName(QString::fromUtf8("lblOrt"));
    lblOrt->setEnabled(true);
    lblOrt->setGeometry(QRect(10, 120, 54, 18));
    lblPLZ = new QLabel(grbOptional);
    lblPLZ->setObjectName(QString::fromUtf8("lblPLZ"));
    lblPLZ->setEnabled(true);
    lblPLZ->setGeometry(QRect(10, 90, 71, 18));
    lblLand = new QLabel(grbOptional);
    lblLand->setObjectName(QString::fromUtf8("lblLand"));
    lblLand->setEnabled(true);
    lblLand->setGeometry(QRect(10, 150, 41, 18));
    lblEmail = new QLabel(grbOptional);
    lblEmail->setObjectName(QString::fromUtf8("lblEmail"));
    lblEmail->setEnabled(true);
    lblEmail->setGeometry(QRect(10, 210, 91, 18));
    edtNeuerNachname = new QLineEdit(grbOptional);
    edtNeuerNachname->setObjectName(QString::fromUtf8("edtNeuerNachname"));
    edtNeuerNachname->setEnabled(true);
    edtNeuerNachname->setGeometry(QRect(110, 30, 231, 24));
    edtStrHnr = new QLineEdit(grbOptional);
    edtStrHnr->setObjectName(QString::fromUtf8("edtStrHnr"));
    edtStrHnr->setEnabled(true);
    edtStrHnr->setGeometry(QRect(110, 60, 231, 24));
    edtPLZ = new QLineEdit(grbOptional);
    edtPLZ->setObjectName(QString::fromUtf8("edtPLZ"));
    edtPLZ->setEnabled(true);
    edtPLZ->setGeometry(QRect(110, 90, 231, 24));
    edtPLZ->setLayoutDirection(Qt::LeftToRight);
    edtOrt = new QLineEdit(grbOptional);
    edtOrt->setObjectName(QString::fromUtf8("edtOrt"));
    edtOrt->setEnabled(true);
    edtOrt->setGeometry(QRect(110, 120, 231, 24));
    edtLand = new QLineEdit(grbOptional);
    edtLand->setObjectName(QString::fromUtf8("edtLand"));
    edtLand->setEnabled(true);
    edtLand->setGeometry(QRect(110, 150, 231, 24));
    edtTelefon = new QLineEdit(grbOptional);
    edtTelefon->setObjectName(QString::fromUtf8("edtTelefon"));
    edtTelefon->setEnabled(true);
    edtTelefon->setGeometry(QRect(110, 180, 231, 24));
    edtEmail = new QLineEdit(grbOptional);
    edtEmail->setObjectName(QString::fromUtf8("edtEmail"));
    edtEmail->setEnabled(true);
    edtEmail->setGeometry(QRect(110, 210, 231, 24));
    lblTelefon = new QLabel(grbOptional);
    lblTelefon->setObjectName(QString::fromUtf8("lblTelefon"));
    lblTelefon->setEnabled(true);
    lblTelefon->setGeometry(QRect(10, 180, 91, 18));
    btnBearbeiten = new QPushButton(Schueler_Verwaltung);
    btnBearbeiten->setObjectName(QString::fromUtf8("btnBearbeiten"));
    btnBearbeiten->setEnabled(true);
    btnBearbeiten->setGeometry(QRect(160, 360, 111, 28));
    grbVerlauf = new QGroupBox(Schueler_Verwaltung);
    grbVerlauf->setObjectName(QString::fromUtf8("grbVerlauf"));
    grbVerlauf->setEnabled(true);
    grbVerlauf->setGeometry(QRect(10, 390, 691, 271));
    treeWidget = new QTreeWidget(grbVerlauf);
    treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
    treeWidget->setGeometry(QRect(10, 20, 671, 241));
    btnAbbrechen = new QPushButton(Schueler_Verwaltung);
    btnAbbrechen->setObjectName(QString::fromUtf8("btnAbbrechen"));
    btnAbbrechen->setEnabled(true);
    btnAbbrechen->setGeometry(QRect(440, 360, 111, 28));

    retranslateUi(Schueler_Verwaltung);

    QMetaObject::connectSlotsByName(Schueler_Verwaltung);
    } // setupUi

    void retranslateUi(QDialog *Schueler_Verwaltung)
    {
    Schueler_Verwaltung->setWindowTitle(QApplication::translate("Schueler_Verwaltung", "Verwaltung", 0, QApplication::UnicodeUTF8));
    grbPflicht->setTitle(QApplication::translate("Schueler_Verwaltung", "Pflichtfelder", 0, QApplication::UnicodeUTF8));
    edtVorname->setText(QString());
    lblNachname->setText(QApplication::translate("Schueler_Verwaltung", "Nachname:", 0, QApplication::UnicodeUTF8));
    lblVorname->setText(QApplication::translate("Schueler_Verwaltung", "Vorname:", 0, QApplication::UnicodeUTF8));
    edtNachname->setText(QString());
    btnOK->setText(QApplication::translate("Schueler_Verwaltung", "OK", 0, QApplication::UnicodeUTF8));
    grbKommentar->setTitle(QApplication::translate("Schueler_Verwaltung", "Kommentar", 0, QApplication::UnicodeUTF8));
    grbRechte->setTitle(QApplication::translate("Schueler_Verwaltung", "Rechte", 0, QApplication::UnicodeUTF8));
    rbtnSchueler->setText(QApplication::translate("Schueler_Verwaltung", "Sch\303\274ler", 0, QApplication::UnicodeUTF8));
    rbtnOrganisator->setText(QApplication::translate("Schueler_Verwaltung", "Organisator", 0, QApplication::UnicodeUTF8));
    edtPasswort->setText(QString());
    edtWiederholen->setText(QString());
    lblPasswort->setText(QApplication::translate("Schueler_Verwaltung", "Passwort:", 0, QApplication::UnicodeUTF8));
    lblWiederholen->setText(QApplication::translate("Schueler_Verwaltung", "Passwort\nwiederholen:", 0, QApplication::UnicodeUTF8));
    btnVerlauf->setText(QApplication::translate("Schueler_Verwaltung", "Verlauf", 0, QApplication::UnicodeUTF8));
    btnAktion->setText(QApplication::translate("Schueler_Verwaltung", "\303\234bernehmen", 0, QApplication::UnicodeUTF8));
    grbOptional->setTitle(QApplication::translate("Schueler_Verwaltung", "optionale Felder", 0, QApplication::UnicodeUTF8));
    lblNeuerNachname->setText(QApplication::translate("Schueler_Verwaltung", "neuer Nachname:", 0, QApplication::UnicodeUTF8));
    lblStrHnr->setText(QApplication::translate("Schueler_Verwaltung", "Stra\303\237e und HNr.:", 0, QApplication::UnicodeUTF8));
    lblOrt->setText(QApplication::translate("Schueler_Verwaltung", "Wohnort:", 0, QApplication::UnicodeUTF8));
    lblPLZ->setText(QApplication::translate("Schueler_Verwaltung", "Postleitzahl:", 0, QApplication::UnicodeUTF8));
    lblLand->setText(QApplication::translate("Schueler_Verwaltung", "Land:", 0, QApplication::UnicodeUTF8));
    lblEmail->setText(QApplication::translate("Schueler_Verwaltung", "E-Mail-Adresse:", 0, QApplication::UnicodeUTF8));
    edtOrt->setText(QString());
    edtLand->setText(QString());
    edtEmail->setText(QString());
    lblTelefon->setText(QApplication::translate("Schueler_Verwaltung", "Telefonnummer:", 0, QApplication::UnicodeUTF8));
    btnBearbeiten->setText(QApplication::translate("Schueler_Verwaltung", "Bearbeiten", 0, QApplication::UnicodeUTF8));
    grbVerlauf->setTitle(QApplication::translate("Schueler_Verwaltung", "Verlauf", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(0, QApplication::translate("Schueler_Verwaltung", "Datum", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(1, QApplication::translate("Schueler_Verwaltung", "Organisator", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(2, QApplication::translate("Schueler_Verwaltung", "\303\204nderungen", 0, QApplication::UnicodeUTF8));
    btnAbbrechen->setText(QApplication::translate("Schueler_Verwaltung", "Abbrechen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Schueler_Verwaltung);
    } // retranslateUi

};

namespace Ui {
    class Schueler_Verwaltung: public Ui_Schueler_Verwaltung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PERSONDIALOGJ10471_H
