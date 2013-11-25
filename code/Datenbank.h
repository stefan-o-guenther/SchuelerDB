// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#pragma once
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QString>
#include <QDateTime>
#include <QList>
#include "Schueler.h"
#include "Daten.h"

#include <QtGui>

//! %Datenbank.
/*!
 *  Die Klasse Datenbank stellt eine Verbindung mit dem Server isis.infotronik.htw-aalen.int her und unterst&uuml;tzt die Erstellung und Bearbeitung der Tabellen.
 */

class Datenbank
{
public:
	static void verbinden(); //!< Mit der %Datenbank verbinden.
	static void trennen(); //!< Verbindung trennen.
	static void initialisieren(); //!< &Datenbank initialisieren.
	static void clean(); //!< Tabellen l&ouml;schen.
	static void test(); //!< Testfunktion.
	static bool ErsterStart(); //!< Erster Start des Programms.
	static bool TabelleSchuelerLeer(); //!< &Uuml;berpr&uuml;fen ob Tabelle leer ist.
	static void TabellenErstellen(); //!< Tabellen erstellen.
	static void AdministratorAnlegen(Schueler *schueler); //!< Administrator anlegen.
	static QList<Schueler*> getAlleSchueler(); //!< Sch&uuml;lerliste zur&uuml;ckgeben.
	static QList<Daten*> getVerlauf(Schueler *schueler); //!< Verlauf zur&uuml;ckgeben.
	static Schueler *getSchueler(int schuelerid); //!< Sch&uuml;ler nach ID abfragen.
	static Schueler *getSchueler(QString vorname, QString nachname); //!< Sch&uuml;ler nach Vor- und Nachname abfragen.
	static void updateSchueler(Schueler *schueler); //!< Passwort aktualisieren.
	static Schueler *getSchuelerNeu(); //!< Zuletzt eingetragenen Sch&uuml;ler abfragen.
	static void setSchuelerNeu(Schueler *schueler); //!< Sch&uuml;ler in Tabelle eintragen.
	static Daten *getDaten(Schueler *schueler, QDateTime datum); //!< %Daten abfragen.
	static Daten *getDaten(Schueler *schueler); //!< Aktuelle %Daten zur&uuml;ckgeben.
	static void setDaten(Daten *daten); //!< Aktuelle %Daten f&uuml;r Verlauf eintragen.
	static int getErsteSchuelerID(); //!< Erste Sch&uuml;lerID abfragen.
	static int getLetzteSchuelerID(); //!< Letzte Sch&uuml;lerid abfragen.
	static bool SchuelerVorhanden(QString vorname, QString nachname); //!< &Uuml;berpr&uuml;fen ob der Sch&uuml;ler vorhanden ist.
	static bool SchuelerVorhanden(int schuelerid); //!< &Uuml;berpr&uuml;fen mit Sch&uuml;lerID ob der Sch&uuml;ler vorhanden ist.

private:
	static void TabelleSchuelerErstellen(); //!< Tabelle h_schueler erstellen.
	static void TabelleDatenErstellen(); //!< Tabelle h_daten erstellen.
	static void leereDaten(int schuelerid, int organisatorid); //!< leere %Daten speichern.
};

