// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#pragma once
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QString>
#include <QtGui>

//! Die %Daten eines Sch&uuml;lers.
/*!
 * Die Klasse Daten speichert die %Daten eines Sch&uuml;lers, die mit den set-Methoden gesetzt und mit den get-Methoden abgefragt werden k&ouml;nnen.
 */

class Daten
{
private:
	int datenid; //!< DatenID.
	int schuelerid; //!< Sch&uuml;lerID.
	int organisatorid; //!< OrganisatorID.
	QDateTime datum; //!< &Auml;nderungsdatum.
	QString neuername; //!< Neuer Name.
	QString strhnr; //!< Straße und Hausnummer.
	QString plz; //!< Postleitzahl.
	QString ort; //!< Wohnort.
	QString land; //!< Land.
	QString telefon; //!< Telefonnummer.
	QString email;	//!< Email-Adresse.
	QString kommentar; //!< Kommentar.
	QString aenderungen; //!< &Auml;nderungen.

public:
	Daten(void); //!< Konstruktor.
	~Daten(void); //!< Destruktor. 
	void eintragen(int schuelerid, int organisatorid, QString neuername, QString strhnr, QString plz, QString ort, QString land, QString telefon, QString email); //!< %Daten eintragen.
	int getDatenID(); //!< DatenID abfragen.
	void setDatenID(int datenid); //!< DatenID setzen.
	int getSchuelerID(); //!< Sch&uuml;lerID abfragen.
	void setSchuelerID(int schuelerid); //!< Sch&uuml;lerID setzen.
	int getOrganisatorID(); //!< OrganisatorID abfragen.
	void setOrganisatorID(int organisatorid); //!< OrganisatorID setzen.
	QDateTime getDatum(); //!< &Auml;nderungsdatum abfragen.
	void setDatum(QDateTime datum); //!< &Auml;nderungsdatum setzen.
	QString getNeuerName(); //!< Neuen Namen abfragen.
	void setNeuerName(QString newname); //!< neuen Namen setzen.
	QString getStrHnr(); //!< Straße und Hausnummer abfragen.
	void setStrHnr(QString str); //!< Straße und Hausnummer setzen.
	QString getPLZ(); //!< Postleitzahl abfragen.
	void setPLZ(QString plz); //!< Postleitzahl setzen.
	QString getOrt(); //!< Wohnort abfragen.
	void setOrt(QString ort); //!< Wohnort setzen.
	QString getLand(); //!< Land abfragen.
	void setLand(QString land); //!< Land setzen.
	QString getTelefon(); //!< Telefonnummer abfragen.
	void setTelefon(QString tel); //!< Telefonnummer setzen.
	QString getEmail(); //!< Email-Adresse abfragen.
	void setEmail(QString email); //!< Email-Adresse setzen.
	QString getKommentar(); //!< Kommentar abfragen.
	void setKommentar(QString kommentar); //!< Kommentar setzen. 
	QString getAenderungen(); //!< &Auml;nderungen abfragen.
	void setAenderungen(QString aenderungen); //!< &Auml;nderungen setzen.
};

