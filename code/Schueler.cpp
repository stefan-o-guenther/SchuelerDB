// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include "Schueler.h"

//////////////////////////////////////////////////////////
/*!
 * Initialisiert die Sch&uuml;lerID, den Vor- und Nachname und das Passwort.
 */
Schueler::Schueler(void)
{
	this->schuelerid = 0;
	this->vorname = "";
	this->nachname = "";
	this->passwort = "";
}
//////////////////////////////////////////////////////////
Schueler::~Schueler(void)
{
}
//////////////////////////////////////////////////////////
/*!
 * \param vorname Vorname.
 * \param nachname Nachname.
 * \param passwort Passwort.
 */
void Schueler::eintragen(QString vorname, QString nachname, QString passwort)
{
	this->vorname = vorname;
	this->nachname = nachname;
	this->passwort = passwort;
}
//////////////////////////////////////////////////////////
/*!
 * \return Sch&uuml;lerID.
 */
int Schueler::getSchuelerID()
{
	return schuelerid;
}

/*!
 * \param schuelerid Sch&uuml;lerID.
 */
void Schueler::setSchuelerID(int schuelerid)
{
	this->schuelerid = schuelerid;
}
//////////////////////////////////////////////////////////
/*!
 * \return Vorname.
 */
QString Schueler::getVorname()
{
	return vorname;
}

/*!
 * \param vorname Vorname.
 */
void Schueler::setVorname(QString vorname)
{
	this->vorname = vorname;
}
//////////////////////////////////////////////////////////
/*!
 * \return Nachname.
 */
QString Schueler::getNachname()
{
	return nachname;
}

/*!
 * \param nachname Nachname.
 */
void Schueler::setNachname(QString nachname)
{
	this->nachname = nachname;
}
//////////////////////////////////////////////////////////
/*!
 * \return Passwort.
 */
QString Schueler::getPasswort()
{
	return passwort;
}

/*!
 * \param passwort Passwort.
 */
void Schueler::setPasswort(QString passwort)
{
	this->passwort = passwort;
}
//////////////////////////////////////////////////////////
