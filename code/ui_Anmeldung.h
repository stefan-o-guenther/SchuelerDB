// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

/********************************************************************************
** Form generated from reading ui file 'LoginDialogJ10436.ui'
**
** Created: Tue May 31 21:28:26 2011
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef LOGINDIALOGJ10436_H
#define LOGINDIALOGJ10436_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

//! Anmeldungsfenster.
/*!
 * Automatisch generierte Klasse.
 *
 */

class Ui_Anmeldung
{
public:
    QLabel *lblVorname;
    QLabel *lblPasswort;
    QLabel *lblWiederholen;
    QLabel *lblNachname;
    QLineEdit *edtVorname;
    QLineEdit *edtNachname;
    QLineEdit *edtPasswort;
    QLineEdit *edtWiederholen;
    QPushButton *btnOK;
    QPushButton *btnAbbrechen;

    void setupUi(QDialog *Anmeldung)
    {
    if (Anmeldung->objectName().isEmpty())
        Anmeldung->setObjectName(QString::fromUtf8("Anmeldung"));
    Anmeldung->resize(259, 164);//(259,132)
    Anmeldung->setMinimumSize(QSize(259, 164));//(259,132)
    Anmeldung->setMaximumSize(QSize(259, 164));//(259,132)
    lblVorname = new QLabel(Anmeldung);
    lblVorname->setObjectName(QString::fromUtf8("lblVorname"));
    lblVorname->setGeometry(QRect(10, 10, 61, 18));
    lblPasswort = new QLabel(Anmeldung);
    lblPasswort->setObjectName(QString::fromUtf8("lblPasswort"));
    lblPasswort->setGeometry(QRect(10, 70, 61, 18));
    lblWiederholen = new QLabel(Anmeldung);
    lblWiederholen->setObjectName(QString::fromUtf8("lblWiederholen"));
    lblWiederholen->setGeometry(QRect(10, 100, 71, 31));
    lblNachname = new QLabel(Anmeldung);
    lblNachname->setObjectName(QString::fromUtf8("lblNachname"));
    lblNachname->setGeometry(QRect(10, 40, 71, 18));
    edtVorname = new QLineEdit(Anmeldung);
    edtVorname->setObjectName(QString::fromUtf8("edtVorname"));
    edtVorname->setGeometry(QRect(90, 10, 161, 24));
    edtNachname = new QLineEdit(Anmeldung);
    edtNachname->setObjectName(QString::fromUtf8("edtNachname"));
    edtNachname->setGeometry(QRect(90, 40, 161, 24));
    edtPasswort = new QLineEdit(Anmeldung);
    edtPasswort->setObjectName(QString::fromUtf8("edtPasswort"));
    edtPasswort->setGeometry(QRect(90, 70, 161, 24));
    edtWiederholen = new QLineEdit(Anmeldung);
    edtWiederholen->setObjectName(QString::fromUtf8("edtWiederholen"));
    edtWiederholen->setGeometry(QRect(90, 100, 161, 24));
    btnOK = new QPushButton(Anmeldung);
    btnOK->setObjectName(QString::fromUtf8("btnOK"));
    btnOK->setGeometry(QRect(90, 130, 75, 28));
    btnAbbrechen = new QPushButton(Anmeldung);
    btnAbbrechen->setObjectName(QString::fromUtf8("btnAbbrechen"));
    btnAbbrechen->setGeometry(QRect(170, 130, 75, 28));

    retranslateUi(Anmeldung);

    QMetaObject::connectSlotsByName(Anmeldung);
    } // setupUi

    void retranslateUi(QDialog *Anmeldung)
    {
    Anmeldung->setWindowTitle(QApplication::translate("Anmeldung", "Dialog", 0, QApplication::UnicodeUTF8));
    lblVorname->setText(QApplication::translate("Anmeldung", "Vorname:", 0, QApplication::UnicodeUTF8));
    lblPasswort->setText(QApplication::translate("Anmeldung", "Passwort:", 0, QApplication::UnicodeUTF8));
    lblWiederholen->setText(QApplication::translate("Anmeldung", "Passwort\n"
"wiederholen:", 0, QApplication::UnicodeUTF8));
    lblNachname->setText(QApplication::translate("Anmeldung", "Nachname:", 0, QApplication::UnicodeUTF8));
    btnOK->setText(QApplication::translate("Anmeldung", "OK", 0, QApplication::UnicodeUTF8));
    btnAbbrechen->setText(QApplication::translate("Anmeldung", "Abbrechen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Anmeldung);
    } // retranslateUi

};

namespace Ui {
    class Anmeldung: public Ui_Anmeldung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // AnmeldungJ10436_H
