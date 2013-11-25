// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#pragma once
#include <QVariant>
#include <QString>
#include <QtGui>

//! Sch&uuml;ler.
/*!
 * Die Klasse Sch&uuml;ler definiert einen Sch&uuml;ler mit einer Sch&uuml;lerID, einem Vor- und Nachname und evtl einem Passwort.
 */
class Schueler
{
private:
	int schuelerid; //!< Sch&uuml;lerID.
	QString vorname; //!< Vorname.
	QString nachname; //!< Nachname.
	QString passwort; //!< Passwort.

public:
	Schueler(void); //!< Konstruktor.
	void eintragen(QString vorname, QString nachname, QString passwort); //!< Sch&uuml;ler eintragen.
	~Schueler(void); //!< Destruktor.
	int getSchuelerID(); //!< Sch&uuml;lerID abfragen.
	void setSchuelerID(int schuelerid); //!< Sch&uuml;lerID setzen.
	QString getVorname(); //!< Vorname abfragen.
	void setVorname(QString vorname); //!< Vorname setzen.
	QString getNachname(); //!< Nachname abfragen.
	void setNachname(QString nachname); //!< Nachnamen setzen.
	QString getPasswort(); //!< Passwort abfragen.
	void setPasswort(QString passwort); //!< Passwort setzen.
};

