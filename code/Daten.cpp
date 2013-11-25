// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include "Daten.h"

//////////////////////////////////////////////////////////
/*!
 * Initialisiert die %Daten mit Nullen und leeren QStrings.
 */
Daten::Daten(void)
{
	this->datenid = 0;
	this->schuelerid = 0;
	this->organisatorid = 0;
	this->datum = QDateTime();
	this->neuername = "";
	this->strhnr = "";
	this->plz = "";
	this->ort = "";
	this->land = "";
	this->telefon = "";
	this->email = "";
	this->kommentar = "";
	this->aenderungen = "";
}
//////////////////////////////////////////////////////////
Daten::~Daten(void)
{
}
//////////////////////////////////////////////////////////
/*!
 * \param schuelerid SchuelerID.
 * \param organisatorid OrganisatorID.
 * \param neuername Neuer Name.
 * \param strhnr Straße und Hausnummer.
 * \param plz Postleitzahl.
 * \param ort Wohnort.
 * \param land Land.
 * \param telefon Telefonnummer.
 * \param email Email-Adresse.
 * &Uuml;bergibt die %Daten an die Variablen.
 */ 
void Daten::eintragen(int schuelerid, int organisatorid, QString neuername, QString strhnr, QString plz, QString ort, QString land, QString telefon, QString email)
{
	this->schuelerid = schuelerid;
	this->organisatorid = organisatorid;
	this->datum = datum;
	this->neuername = neuername;
	this->strhnr = strhnr;
	this->plz = plz;
	this->ort = ort;
	this->land = land;
	this->telefon = telefon;
	this->email = email;
}
//////////////////////////////////////////////////////////
/*!
 * \return DatenID.
 */ 
int Daten::getDatenID()
{
	return datenid;
}

/*!
 * \param datenid DatenID.
 */ 
void Daten::setDatenID(int datenid)
{
	this->datenid = datenid;
}
//////////////////////////////////////////////////////////
/*!
 * \return SchuelerID.
 */ 
int Daten::getSchuelerID()
{
	return schuelerid;
}

/*!
 * \param schuelerid SchuelerID.
 */ 
void Daten::setSchuelerID(int schuelerid)
{
 	this->schuelerid = schuelerid;
}
//////////////////////////////////////////////////////////
/*!
 * \return OrganisatorID.
 */ 
int Daten::getOrganisatorID()
{
	return organisatorid;
}

/*!
 * \param organisatorid OrganisatorID.
 */ 
void Daten::setOrganisatorID(int organisatorid)
{
	this->organisatorid = organisatorid;
}
//////////////////////////////////////////////////////////
/*!
 * \return Aenderungsdatum.
 */ 
QDateTime Daten::getDatum()
{
	return datum;
}

/*!
 * \param datum Aenderungsdatum.
 */ 
void Daten::setDatum(QDateTime datum)
{
	this->datum = datum;
}
//////////////////////////////////////////////////////////
/*!
 * \return Neuer Name des Schuelers.
 */ 
QString Daten::getNeuerName()
{
	return neuername;
}

/*!
 * \param neuername Neuer Name.
 */ 
void Daten::setNeuerName(QString neuername)
{
	this->neuername = neuername;
}
//////////////////////////////////////////////////////////
/*!
 * \return Straße und Hausnummer.
 */ 
QString Daten::getStrHnr()
{
	return strhnr;
}

/*!
 * \param strhnr Straße und Hausnummer.
 */ 
void Daten::setStrHnr(QString strhnr)
{
	this->strhnr = strhnr;
}
//////////////////////////////////////////////////////////
/*!
 * \return Postleitzahl.
 */ 
QString Daten::getPLZ()
{
	return plz;
}

/*!
 * \param plz Postleitzahl.
 */ 
void Daten::setPLZ(QString plz)
{
	this->plz = plz;
}
//////////////////////////////////////////////////////////
/*!
 * \return Wohnort.
 */ 
QString Daten::getOrt()
{
	return ort;
}

/*!
 * \param ort Wohnort.
 */ 
void Daten::setOrt(QString ort)
{
	this->ort = ort;
}
//////////////////////////////////////////////////////////
/*!
 * \return Land.
 */ 
QString Daten::getLand()
{
	return land;
}

/*!
 * \param land Land.
 */ 
void Daten::setLand(QString land)
{
	this->land = land;
}
//////////////////////////////////////////////////////////
/*!
 * \return Telefonnummer.
 */ 
QString Daten::getTelefon()
{
	return telefon;
}

/*!
 * \param telefon Telefonnummer.
 */ 
void Daten::setTelefon(QString telefon)
{
	this->telefon = telefon;
}
//////////////////////////////////////////////////////////
/*!
 * \return Email-Adresse.
 */ 
QString Daten::getEmail()
{
	return email;
}

/*!
 * \param email Email-Adresse.
 */ 
void Daten::setEmail(QString email)
{
	this->email = email;
}
//////////////////////////////////////////////////////////
/*!
 * \return Kommentar zu einem %Schueler.
 */ 
QString Daten::getKommentar()
{
	return kommentar;
}

/*!
 * \param kommentar Kommentar.
 */ 
void Daten::setKommentar(QString kommentar)
{
	this->kommentar = kommentar;
}
//////////////////////////////////////////////////////////
/*!
 * \return Aenderungen.
 */ 
QString Daten::getAenderungen()
{
	return aenderungen;
}

/*!
 * \param aenderungen Aenderungen.
 */ 
void Daten::setAenderungen(QString aenderungen)
{
	this->aenderungen = aenderungen;
}
//////////////////////////////////////////////////////////
