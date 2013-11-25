// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include "Datenbank.h"

QSqlDatabase sqlDatabase; //!< %Datenbank.

////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Stellt eine Verbindung zur %Datenbank her. 
 */
void Datenbank::verbinden()
{
	if (!sqlDatabase.isOpen())
	{
		
		sqlDatabase = QSqlDatabase::addDatabase("QPSQL");
		sqlDatabase.setHostName("isis.infotronik.htw-aalen.int");
		sqlDatabase.setDatabaseName("SoftwEng");
		sqlDatabase.setUserName("SoftwEng");
		sqlDatabase.setPassword("SoftwEng");

		if (!sqlDatabase.open())
		{
			QMessageBox mb;
			mb.setText(QString("Kann Datenbank nicht öffnen!"));
			mb.exec();
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Schließt die Verbindung zur %Datenbank.
 */
void Datenbank::trennen()
{
	if (sqlDatabase.isOpen())
	{
		sqlDatabase.close();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Erstellt die Tabellen falls sie noch nicht existieren.
 */
void Datenbank::initialisieren()
{
	if (Datenbank::ErsterStart())
	{
		Datenbank::TabellenErstellen();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * L&ouml;scht die Tabellen.
 */
void Datenbank::clean()
{
	QSqlQuery query1("DROP TABLE h_daten;");
	query1.exec();
	QSqlQuery query2("DROP TABLE h_schueler;");
	query2.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * F&uuml;llt die Tabellen mit Testdaten.
 */
void Datenbank::test()
{
	Datenbank::initialisieren();
	if (Datenbank::TabelleSchuelerLeer())
	{
		QString leer = "";
		QString vn, nn, pw, neu, str, plz, ort, land, tel, email;
		int first, id, org;
		Schueler *schueler = new Schueler();
		Daten *daten = new Daten();


		// Schüler eintragen

		// 1
		vn = "Christian";
		nn = "Heinlein";
		pw = "CH";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 2
		vn = "Max";
		nn = "Mustermann";
		pw = "MM";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 3
		vn = "Klara";
		nn = "Musterfrau";
		pw = "KM";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 4
		vn = "Paul";
		nn = "Maier";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 5
		vn = "Paula";
		nn = "Maier";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 6
		vn = "Stefan";
		nn = "Günther";
		pw = "SG";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 7
		vn = "Barbara";
		nn = "Hörner";
		pw = "BH";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 8
		vn = "Moritz";
		nn = "Egetemeir";
		pw = "ME";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 9
		vn = "Philipp";
		nn = "Kilic";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 10
		vn = "Michael";
		nn = "Seidel";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 11
		vn = "Daniel";
		nn = "Eichert";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 12
		vn = "Moritz";
		nn = "Kühner";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 13
		vn = "Jonathan";
		nn = "Weber";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 14
		vn = "Roy";
		nn = "Oberhauser";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 15
		vn = "Rainer";
		nn = "Werthebach";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 16
		vn = "Rainer";
		nn = "Schmidt";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 17
		vn = "Roland";
		nn = "Dietrich";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 18
		vn = "Roland";
		nn = "Hellmann";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 19
		vn = "Detlef";
		nn = "Küpper";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);

		// 20
		vn = "Hans";
		nn = "Wurst";
		pw = "";
		schueler->eintragen(vn,nn,pw);
		Datenbank::setSchuelerNeu(schueler);


		first = (Datenbank::getErsteSchuelerID());


		// Daten eintragen

		// Christian Heinlein
		id = first;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "Aalen";
		land = "";
		tel = "073615764203";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);
		
		// Max Mustermann
		id = first+1;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "";
		tel = "";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);
		
		// Klara Musterfrau
		id = first+2;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "";
		tel = "12223333";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Paul Maier
		id = first+3;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "";
		tel = "1234567890";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Paula Maier
		id = first+4;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "Deutschland";
		tel = "1234567890";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Stefan Günther
		id = first+5;
		org = first;
		neu = "";
		str = "Kelterstraße 42";
		plz = "73635";
		ort = "Rudersberg";
		land = "Deutschland";
		tel = "017625417219";
		email = "stefan_guenther@gmx.at";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Barbara Hörner
		id = first+6;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "Schwäbisch-Gmünd";
		land = "Deutschland";
		tel = "";
		email = "yazoo-san@t-online.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Moritz Egetemeir
		id = first+7;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "Deutschland";
		tel = "";
		email = "m-egetemeir@gmx.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Philipp Kilic
		id = first+8;
		org = first + 5;
		neu = "";
		str = "";
		plz = "73430";
		ort = "Aalen";
		land = "Deutschland";
		tel = "";
		email = "philipp_88@gmx.net";		
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Michael Seidel
		id = first+9;
		org = first + 5;
		neu = "";
		str = "Rombachstraße";
		plz = "73430";
		ort = "Aalen";
		land = "Deutschland";
		tel = "0176340943";
		email = "michael.ms.seidel@googlemail.com";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Daniel Eichert
		id = first+10;
		org = first + 5;
		neu = "";
		str = "Silcherstraße";
		plz = "73430";
		ort = "Aalen";
		land = "Deutschland";
		tel = "0175282591";
		email = "danieleichert@web.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Moritz Kühner
		id = first+11;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "Deutschland";
		tel = "";
		email = "Max.kue@gmx.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Jonathan Weber
		id = first+12;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";

		land = "Deutschland";
		tel = "";
		email = "contact.j.weber@googlemail.com";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Roy Oberhauser
		id = first+13;
		org = first;
		neu = "";
		str = "Beethovenstraße";
		plz = "73430";
		ort = "Aalen";
		land = "Deutschland";
		tel = "0123456789";
		email = "Roy.Oberhauser@htw-aalen.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Rainer Werthebach
		id = first+14;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "Aalen";
		land = "Deutschland";
		tel = "";
		email = "Rainer.Werthebach@htw-aalen.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Rainer Schmidt
		id = first+15;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "Aalen";
		land = "Deutschland";
		tel = "";
		email = "Rainer.Schmidt@htw-aalen.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Roland Dietrich
		id = first+16;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "Aalen";
		land = "Deutschland";
		tel = "";
		email = "Roland.Dietrich@htw-aalen.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Roland Hellmann
		id = first+17;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "Aalen";
		land = "Deutschland";
		tel = "";
		email = "Roland.Hellmann@htw-aalen.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Detlef Küpper
		id = first+18;
		org = first;
		neu = "";
		str = "Anton-Huber-Str";
		plz = "73430";
		ort = "Aalen";
		land = "Deutschland";
		tel = "0175123456";
		email = "Detlef.Kuepper@htw-aalen.de";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Hans Wurst
		id = first+19;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "";
		tel = "";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Klara Musterfrau
		id = first+2;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "";
		tel = "444445555";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Stefan Günther
		id = first+5;
		org = first;
		neu = "";
		str = "Steinertgasse 10";
		plz = "73434";
		ort = "Aalen";
		land = "Deutschland";
		tel = "017625417219";
		email = "stefan_guenther@gmx.at";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Paul Maier
		id = first+3;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "Deutschland";
		tel = "01749876543";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Paula Maier
		id = first+4;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "Deutschland";
		tel = "01749876543";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// Klara Musterfrau
		id = first+2;
		org = first;
		neu = "";
		str = "";
		plz = "";
		ort = "";
		land = "";
		tel = "4236667777";
		email = "";
		daten->eintragen(id,org,neu,str,plz,ort,land,tel,email);
		Datenbank::setDaten(daten);

		// datenid, schuelerid, organisatorid, datum, neuername, strhnr, plz, ort, land, telefon, email, kommentar, aenderungen

	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Fragt ab, ob die Sch&uuml;lertabelle vorhanden ist.
 * \return true, wenn die Tabelle schon existiert, ansonsten false.
 */
bool Datenbank::ErsterStart()
{
	QSqlQuery query;
	query.prepare("SELECT COUNT(*) FROM h_schueler");
	return !query.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Abfrage, ob Sch&uuml;ler vorhanden sind.
 * \return true, wenn keine Sch&uuml;ler in der Tabelle eingetragen sind, ansonsten false.
 */
bool Datenbank::TabelleSchuelerLeer()
{
	QSqlQuery query;
	query.prepare("SELECT COUNT(*) AS anz FROM h_schueler");
	query.exec();
	query.first();
	int anz = query.value(0).toInt();
	return (anz <= 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Erstellt die Tabellen, falls diese nicht vorhanden sind.
 */
void Datenbank::TabellenErstellen()
{
	QSqlQuery query1, query2;
	query1.prepare("SELECT * FROM h_schueler");
	query1.prepare("SELECT * FROM h_daten");
	if (!query1.exec())
	{
		Datenbank::TabelleSchuelerErstellen();
	}
	if (!query2.exec())
	{
		Datenbank::TabelleDatenErstellen();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Erstellt Tabelle mit den Sch&uuml;lern.
 */
void Datenbank::TabelleSchuelerErstellen()
{
	QSqlQuery query("CREATE TABLE h_schueler (schuelerid serial NOT NULL, vorname varchar(60), nachname varchar(60), passwort varchar(60),PRIMARY KEY (schuelerid))");
	query.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Erstellt die Tabelle mit den Sch&uuml;lerdaten f&uuml;r den Verlauf.
 */
void Datenbank::TabelleDatenErstellen()
{
	QSqlQuery query("CREATE TABLE h_daten ("
			"datenid serial NOT NULL,"
			"schuelerid serial NOT NULL,"
			"organisatorid serial NOT NULL,"
			"datum timestamp NOT NULL,"
			"neuername varchar(60),"
			"strhnr varchar(60),"
			"plz varchar(10),"
			"ort varchar(60),"
			"land varchar(60),"
			"telefon varchar(60),"
			"email varchar(60),"
			"kommentar text,"
			"aenderungen varchar(60),"
			"PRIMARY KEY (datenid),"
			"FOREIGN KEY (schuelerid) REFERENCES h_schueler(schuelerid),"
			"FOREIGN KEY (organisatorid) REFERENCES h_schueler(schuelerid)"
			")");
	query.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 *\param schueler Sch&uuml;ler.
 * Legt den Administrator an wenn die Tabelle leer ist.
 */
void Datenbank::AdministratorAnlegen(Schueler *schueler)
{
	if (Datenbank::TabelleSchuelerLeer())
	{
		Datenbank::setSchuelerNeu(schueler);
		int id = Datenbank::getErsteSchuelerID();
		Datenbank::leereDaten(id,id);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schuelerid Sch&uuml;lerID.
 * \param organisatorid OrganisatorID.
 * Speichert Sch&uuml;lerdaten ohne Inhalt.
 */
void Datenbank::leereDaten(int schuelerid, int organisatorid)
{
	Daten *daten = new Daten();
	daten->setSchuelerID(schuelerid);
	daten->setOrganisatorID(organisatorid);
	Datenbank::setDaten(daten);
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*! 
 * \return Liste mit allen Sch&uuml;lern.
 * Die Sch&uuml;ler sind alphabetisch nach Vorname geordnet.
 */
QList<Schueler*> Datenbank::getAlleSchueler()
{
	QSqlQuery query;
	query.prepare("SELECT * FROM h_schueler ORDER BY vorname, nachname");
	query.exec();
	QList<Schueler*> list;
	while (query.next()) {
		QSqlRecord record = query.record();
		Schueler *schueler = new Schueler();
		schueler->setSchuelerID(query.value(record.indexOf("schuelerid")).toInt());
		schueler->setVorname(query.value(record.indexOf("vorname")).toString());
		schueler->setNachname(query.value(record.indexOf("nachname")).toString()); 
		schueler->setPasswort(query.value(record.indexOf("passwort")).toString());
		list.append(schueler);
	}
	return list;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \return Liste mit dem Verlauf eines Sch&uuml;lers.
 * Der Verlauf ist nach der Reihenfolge des Eintrags geordnet, da das Datum zu ungenau ist.
 */
QList<Daten*> Datenbank::getVerlauf(Schueler *schueler)
{
	int id = schueler->getSchuelerID();
	QSqlQuery query;
	query.prepare("SELECT * FROM h_daten WHERE schuelerid = :id ORDER BY datenid DESC;");
	query.bindValue(":id", id);
	query.exec();
	QList<Daten*> list;
	while (query.next()) {
		QSqlRecord record = query.record();
		Daten *daten = new Daten();
		daten->setDatenID(query.value(record.indexOf("datenid")).toInt());
		daten->setSchuelerID(query.value(record.indexOf("schuelerid")).toInt());
		daten->setOrganisatorID(query.value(record.indexOf("organisatorid")).toInt());
		daten->setDatum(query.value(record.indexOf("datum")).toDateTime());
		daten->setNeuerName(query.value(record.indexOf("neuername")).toString());
		daten->setStrHnr(query.value(record.indexOf("strhnr")).toString()); 
		daten->setPLZ(query.value(record.indexOf("plz")).toString());
		daten->setOrt(query.value(record.indexOf("ort")).toString());
		daten->setLand(query.value(record.indexOf("land")).toString());
		daten->setTelefon(query.value(record.indexOf("telefon")).toString());
		daten->setEmail(query.value(record.indexOf("email")).toString());
		daten->setKommentar(query.value(record.indexOf("kommentar")).toString());
		daten->setAenderungen(query.value(record.indexOf("aenderungen")).toString());
		list.append(daten);
	}
	return list;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schuelerid Sch&uuml;lerID.
 * \return Sch&uuml;ler.
 */
Schueler* Datenbank::getSchueler(int schuelerid)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM h_schueler WHERE schuelerid = :schuelerid");
	query.bindValue(":schuelerid", schuelerid);
	query.exec();
	query.first();
	QSqlRecord record = query.record();
	Schueler *schueler = new Schueler();
	schueler->setSchuelerID(query.value(record.indexOf("schuelerid")).toInt());
	schueler->setVorname(query.value(record.indexOf("vorname")).toString());
	schueler->setNachname(query.value(record.indexOf("nachname")).toString()); 
	schueler->setPasswort(query.value(record.indexOf("passwort")).toString());

	return schueler;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param vorname Vorname des Sch&uuml;lers.
 * \param nachname Nachname des Sch&uuml;lers. 
 * \return Sch&uuml;ler.
 */
Schueler* Datenbank::getSchueler(QString vorname, QString nachname)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM h_schueler WHERE vorname = :vorname AND nachname = :nachname");
	query.bindValue(":vorname", vorname);
	query.bindValue(":nachname", nachname);
	query.exec();
	Schueler *schueler = new Schueler();
	query.first();
	QSqlRecord record = query.record();
	schueler->setSchuelerID(query.value(record.indexOf("schuelerid")).toInt());
	schueler->setVorname(query.value(record.indexOf("vorname")).toString()); 
	schueler->setNachname(query.value(record.indexOf("nachname")).toString()); 
	schueler->setPasswort(query.value(record.indexOf("passwort")).toString());
	return schueler;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schueler Sch&uuml;ler. 
 * Passwort des Sch&uuml;lers wird aktualisiert.
 */
void Datenbank::updateSchueler(Schueler *schueler)
{
	QSqlQuery query;
	query.prepare("UPDATE h_schueler SET passwort = :passwort WHERE vorname = :vorname AND nachname = :nachname");
	query.bindValue(":passwort", (schueler->getPasswort()));
	query.bindValue(":vorname", (schueler->getVorname()));
	query.bindValue(":nachname", (schueler->getNachname()));
	QMessageBox mb;
	query.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \return der zuletzt eingetragene Sch&uuml;ler.
 */
Schueler* Datenbank::getSchuelerNeu()
{
	int id = Datenbank::getLetzteSchuelerID();
	return Datenbank::getSchueler(id);
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schueler Sch&uuml;ler.
 * Tr&auml;gt Sch&uuml;ler in die Sch&uuml;lertabelle ein.
 */
void Datenbank::setSchuelerNeu(Schueler *schueler)
{
	QString vorname = schueler->getVorname();
	QString nachname = schueler->getNachname();
	QString passwort = schueler->getPasswort();
	QSqlQuery query;
	query.prepare("INSERT INTO h_schueler (vorname, nachname, passwort) VALUES (:vorname, :nachname, :passwort)");
	query.bindValue(":vorname", vorname);
	query.bindValue(":nachname", nachname);
	query.bindValue(":passwort", passwort);
	query.exec();

}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schueler Sch&uuml;ler.
 * \param datum &Auml;nderungsdatum.
 * \return bestimmte Sch&uuml;lerdaten.
 */
Daten* Datenbank::getDaten(Schueler* schueler, QDateTime datum)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM h_daten WHERE schuelerid = :schuelerid AND datum = :datum");
	query.bindValue(":schuelerid", (schueler->getSchuelerID()));
	query.bindValue(":datum", datum);
	query.exec();	
	query.first();
	Daten *daten = new Daten();
	QSqlRecord record = query.record();
	daten->setDatenID(query.value(record.indexOf("datenid")).toInt());
	daten->setSchuelerID(query.value(record.indexOf("schuelerid")).toInt());
	daten->setOrganisatorID(query.value(record.indexOf("organisatorid")).toInt());
	daten->setDatum(query.value(record.indexOf("datum")).toDateTime());
	daten->setNeuerName(query.value(record.indexOf("neuername")).toString());
	daten->setStrHnr(query.value(record.indexOf("strhnr")).toString());
	daten->setPLZ(query.value(record.indexOf("plz")).toString());
	daten->setOrt(query.value(record.indexOf("ort")).toString());
	daten->setLand(query.value(record.indexOf("land")).toString());
	daten->setTelefon(query.value(record.indexOf("telefon")).toString());
	daten->setEmail(query.value(record.indexOf("email")).toString());
	daten->setKommentar(query.value(record.indexOf("kommentar")).toString());
	daten->setAenderungen(query.value(record.indexOf("aenderungen")).toString());
	return daten;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schueler Sch&uuml;ler.
 * \return aktuelle Sch&uuml;lerdaten.
 */
Daten* Datenbank::getDaten(Schueler* schueler)
{	
	QSqlQuery query;
	//query.prepare("SELECT datenid, schuelerid, organisatorid, neuername, strhnr, plz, ort, land, telefon, email"
	//		"FROM h_daten WHERE schuelerid = :schueler"); //ORDER BY datenid DESC");
	//query.bindValue(":schuelerid", (schueler->getSchuelerID()));
	int id = schueler->getSchuelerID();
	query.prepare("SELECT * FROM h_daten WHERE schuelerid = :schuelerid ORDER BY datenid DESC;");
	query.bindValue(":schuelerid", id);
	query.exec();;
	query.first();
	Daten *daten = new Daten();
	QSqlRecord record = query.record();
	daten->setDatenID(query.value(record.indexOf("datenid")).toInt());
	daten->setSchuelerID(query.value(record.indexOf("schuelerid")).toInt());
	daten->setOrganisatorID(query.value(record.indexOf("organisatorid")).toInt());
	daten->setDatum(query.value(record.indexOf("datum")).toDateTime());
	daten->setNeuerName(query.value(record.indexOf("neuername")).toString());
	daten->setStrHnr(query.value(record.indexOf("strhnr")).toString());
	daten->setPLZ(query.value(record.indexOf("plz")).toString());
	daten->setOrt(query.value(record.indexOf("ort")).toString());
	daten->setLand(query.value(record.indexOf("land")).toString());
	daten->setTelefon(query.value(record.indexOf("telefon")).toString());
	daten->setEmail(query.value(record.indexOf("email")).toString());
	daten->setKommentar(query.value(record.indexOf("kommentar")).toString());
	daten->setAenderungen(query.value(record.indexOf("aenderungen")).toString());
	return daten;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param daten Sch&uuml;lerdaten.
 * Tr&auml;gt die aktuellen Sch&uuml;lerdaten in die Sch&uuml;lerdaten-Tabelle (Verlauf) ein.
 */
void Datenbank::setDaten(Daten* daten)
{
	QSqlQuery query;
	query.prepare("INSERT INTO h_daten (schuelerid, organisatorid, datum, neuername, strhnr, plz, ort, land, telefon, email, kommentar, aenderungen) "
			"VALUES (:schuelerid, :organisatorid, :datum, :neuername, :strhnr, :plz, :ort, :land, :telefon, :email, :kommentar, :aenderungen)");
	query.bindValue(":schuelerid", (daten->getSchuelerID()));
	query.bindValue(":organisatorid", (daten->getOrganisatorID()));
	query.bindValue(":datum", (QDateTime::currentDateTime()));
	query.bindValue(":neuername", (daten->getNeuerName()));
	query.bindValue(":strhnr", (daten->getStrHnr()));
	query.bindValue(":plz", (daten->getPLZ()));
	query.bindValue(":ort", (daten->getOrt()));
	query.bindValue(":land", (daten->getLand()));
	query.bindValue(":telefon", (daten->getTelefon()));
	query.bindValue(":email", (daten->getEmail()));
	query.bindValue(":kommentar", (daten->getKommentar()));
	query.bindValue(":aenderungen", (daten->getAenderungen()));
	query.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \return erste Sch&uuml;lerID.
 */
int Datenbank::getErsteSchuelerID()
{
	QSqlQuery query;
	query.prepare("SELECT MIN(schuelerid) FROM h_schueler");
	query.exec();
	query.first();
	return query.value(0).toInt();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \return letzte Sch&uuml;lerID.
 */
int Datenbank::getLetzteSchuelerID()
{
	QSqlQuery query;
	query.prepare("SELECT MAX(schuelerid) FROM h_schueler");
	query.exec();
	query.first();
	return query.value(0).toInt();
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param vorname Vorname.
 * \param nachname Nachname.
 * \return true, wenn ein bestimmter Sch&uuml;ler in der Tabelle vorhanden ist, ansonsten false.
 */
bool Datenbank::SchuelerVorhanden(QString vorname, QString nachname)
{
	bool res = false;
	if ((vorname != NULL) && (nachname != NULL) && (vorname != "") && (nachname != ""))
	{
		//Datenbank::StartConnection();
		QSqlQuery query;
		query.prepare("SELECT COUNT(*) AS anz FROM h_schueler WHERE vorname = :vorname AND nachname = :nachname");
		query.bindValue(":vorname", vorname);
		query.bindValue(":nachname", nachname);
		query.exec();
		query.first();
		QSqlRecord record = query.record();
		int anz = query.value(record.indexOf("anz")).toInt();
		res = (anz == 1);
	}
	return res;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*! 
 * \param schuelerid Sch&uuml;lerID.
 * \return true, wenn ein bestimmter Sch&uuml;ler schon in der Sch&uuml;lertabelle vorhanden ist.
 */
bool Datenbank::SchuelerVorhanden(int schuelerid)
{
	bool res = false;
	//Datenbank::StartConnection();
	QSqlQuery query;
	query.prepare("SELECT COUNT(*) AS anz FROM h_schueler WHERE schuelerid = :schuelerid");
	query.bindValue(":schuelerid", schuelerid);
	query.exec();
	query.first();
	QSqlRecord record = query.record();
	int anz = query.value(record.indexOf("anz")).toInt();
	if (anz == 1)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return res;
}
///////////////////////////////////////////////////////////////////////////////////////////////
