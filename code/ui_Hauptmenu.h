// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

/********************************************************************************
** Form generated from reading ui file 'HauptmenuKP3284.ui'
**
** Created: Tue May 31 18:09:21 2011
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef HauptmenuKP3284_H
#define HauptmenuKP3284_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

//! Hauptmenu.
/*!
 * Automatisch generierte Klasse.
 *
 */

class Ui_Hauptmenu
{
public:
    QLabel *label;
    QPushButton *btnNeu;
    QPushButton *btnOwn;
    QPushButton *btnAnz;
    QPushButton *btnEnd;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Hauptmenu)
    {
    if (Hauptmenu->objectName().isEmpty())
        Hauptmenu->setObjectName(QString::fromUtf8("Hauptmenu"));
    Hauptmenu->resize(651, 375);
    Hauptmenu->setMinimumSize(QSize(651, 375));
    Hauptmenu->setMaximumSize(QSize(651, 375));
    label = new QLabel(Hauptmenu);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 10, 71, 18));
    btnNeu = new QPushButton(Hauptmenu);
    btnNeu->setObjectName(QString::fromUtf8("btnNeu"));
    btnNeu->setGeometry(QRect(10, 340, 151, 28));
    btnOwn = new QPushButton(Hauptmenu);
    btnOwn->setObjectName(QString::fromUtf8("btnOwn"));
    btnOwn->setGeometry(QRect(330, 340, 151, 28));
    btnAnz = new QPushButton(Hauptmenu);
    btnAnz->setObjectName(QString::fromUtf8("btnAnz"));
    btnAnz->setGeometry(QRect(170, 340, 151, 28));
    btnEnd = new QPushButton(Hauptmenu);
    btnEnd->setObjectName(QString::fromUtf8("btnEnd"));
    btnEnd->setGeometry(QRect(490, 340, 151, 28));
    treeWidget = new QTreeWidget(Hauptmenu);
    treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
    treeWidget->setGeometry(QRect(10, 30, 631, 301));
    treeWidget->setMinimumSize(QSize(631, 0));
    treeWidget->setMaximumSize(QSize(631, 16777215));
    treeWidget->setLineWidth(1);

    retranslateUi(Hauptmenu);

    QMetaObject::connectSlotsByName(Hauptmenu);
    } // setupUi

    void retranslateUi(QWidget *Hauptmenu)
    {
    Hauptmenu->setWindowTitle(QApplication::translate("Hauptmenu", "Hauptmen\303\274", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Hauptmenu", "Sch\303\274lerliste:", 0, QApplication::UnicodeUTF8));
    btnNeu->setText(QApplication::translate("Hauptmenu", "Sch\303\274ler neu anlegen", 0, QApplication::UnicodeUTF8));
    btnOwn->setText(QApplication::translate("Hauptmenu", "Eigene Daten anzeigen", 0, QApplication::UnicodeUTF8));
    btnAnz->setText(QApplication::translate("Hauptmenu", "Sch\303\274ler anzeigen", 0, QApplication::UnicodeUTF8));
    btnEnd->setText(QApplication::translate("Hauptmenu", "Beenden", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(0, QApplication::translate("Hauptmenu", "Vorname", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(1, QApplication::translate("Hauptmenu", "Nachname", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(2, QApplication::translate("Hauptmenu", "Rolle", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(3, QApplication::translate("Hauptmenu", "Ampel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Hauptmenu);
    } // retranslateUi

};

namespace Ui {
    class Hauptmenu: public Ui_Hauptmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINFORMKP3284_H
