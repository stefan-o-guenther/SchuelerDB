// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include <QtCore>
#include <QtSql>
#include <QtTest>

#include <string>
using std::string;

#include "Datenbank.h"
#include "Schueler.h"
#include "Daten.h"

// Testklasse.
class Test : public QObject { Q_OBJECT

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private slots:
	void start();

	void neu();
	void Testfall_ErsteAnmeldungFalsch();
	void Testfall_ErsteAnmeldungRichtig();

	void testdaten();
	void Testfall_LoginFalsch();
	void Testfall_LoginRichtig();

	void Testfall_SchuelerNeuFalsch();
	void Testfall_SchuelerNeuRichtig();

	//Datenfunktionen
	void Testfall_ErsteAnmeldungFalsch_data();
	void Testfall_LoginFalsch_data();
	void Testfall_LoginRichtig_data();
	void Testfall_SchuelerNeuFalsch_data();
	void Testfall_SchuelerNeuRichtig_data();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::start()
{
	Datenbank::verbinden();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::neu()
{
	Datenbank::clean();
	Datenbank::initialisieren();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::testdaten()
{
	Datenbank::clean();
	Datenbank::test();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool anlegenAdministrator(QString vorname, QString nachname, QString passwort, QString wiederholen)
{
	bool result = false;

	if (Datenbank::TabelleSchuelerLeer())
	{
		if ((vorname != "")&&(nachname != "")&&(passwort != "")&&(wiederholen != ""))
		{
			if (passwort == wiederholen)
			{
				Schueler *admin = new Schueler();
				admin->eintragen(vorname,nachname,passwort);
				Datenbank::AdministratorAnlegen(admin);
				result = true;
			}
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool loginOrganisator(QString vorname, QString nachname, QString passwort)
{
	bool result = false;
	if (!(Datenbank::TabelleSchuelerLeer()))
	{
		if ((vorname != "")&&(nachname != "")&&(passwort != ""))
		{
			if (Datenbank::SchuelerVorhanden(vorname,nachname))
			{
				Schueler *org = Datenbank::getSchueler(vorname,nachname);
				QString pw = org->getPasswort();
				if (pw == passwort)
				{
					result = true;
				}
			}
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool neuSchueler(Schueler *sch, Daten *dat)
{
	bool result = false;
	QString vorname = sch->getVorname();
	QString nachname = sch->getNachname();
	if ((vorname != "")&&(nachname != ""))
	{
		if (!(Datenbank::SchuelerVorhanden(vorname, nachname)))
		{
			result = true;
			Datenbank::setSchuelerNeu(sch);
			sch = Datenbank::getSchueler(vorname, nachname);
			dat->setSchuelerID(sch->getSchuelerID());
			dat->setOrganisatorID(Datenbank::getErsteSchuelerID());
			dat->setAenderungen("");
			Datenbank::setDaten(dat);
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_ErsteAnmeldungFalsch_data()
{
	QTest::addColumn<QString>("vorname"); // Spalte mit Typ QString.
	QTest::addColumn<QString>("nachname");
	QTest::addColumn<QString>("passwort");
	QTest::addColumn<QString>("wiederholen");

	QTest::newRow("MissingPW") << QString("Christian") << QString("Heinlein") << QString("")<<QString("");
	QTest::newRow("DifferentPWs") << QString("Christian") << QString("Heinlein") << QString("CH")<<QString("CG");
	QTest::newRow("NotBothNames") << QString("Christian") << QString("") << QString("CH")<<QString("CH");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_ErsteAnmeldungFalsch()
{
	QFETCH(QString, vorname);
	QFETCH(QString, nachname);
	QFETCH(QString, passwort);
	QFETCH(QString, wiederholen);
	QCOMPARE((anlegenAdministrator(vorname,nachname,passwort,wiederholen)),false);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_ErsteAnmeldungRichtig()
{
	QVERIFY(anlegenAdministrator("Christian","Heinlein","CH","CH"));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_LoginFalsch_data()
{
	QTest::addColumn<QString>("vorname");
	QTest::addColumn<QString>("nachname");
	QTest::addColumn<QString>("passwort");

	QTest::newRow("MissingGN") << QString("") << QString("Heinlein") << QString("CH");
	QTest::newRow("MissingPW") << QString("Christian") << QString("Heinlein") << QString("");
	QTest::newRow("MissingBN") << QString("Christian") << QString("") << QString("Heinlein");
	QTest::newRow("Leer") << QString("") << QString("") << QString("");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_LoginFalsch()
{
	QFETCH(QString, vorname);
	QFETCH(QString, nachname);
	QFETCH(QString, passwort);
	QCOMPARE(loginOrganisator(vorname,nachname,passwort),false);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_LoginRichtig_data()
{
	QTest::addColumn<QString>("vorname");
	QTest::addColumn<QString>("nachname");
	QTest::addColumn<QString>("passwort");

	// Vier Zeilen mit unterschiedlichen Testdaten.
	QTest::newRow("CH") << QString("Christian") << QString("Heinlein") << QString("CH");
	QTest::newRow("SG") << QString("Stefan") << QString("Günther") << QString("SG");
	QTest::newRow("BH") << QString("Barbara") << QString("Hörner") << QString("BH");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_LoginRichtig()
{
	QFETCH(QString, vorname);
	QFETCH(QString, nachname);
	QFETCH(QString, passwort);
	QVERIFY(loginOrganisator(vorname,nachname,passwort));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_SchuelerNeuFalsch_data()
{
QTest::addColumn<QString>("vorname");
QTest::addColumn<QString>("nachname");
QTest::addColumn<QString>("neuername");
QTest::addColumn<QString>("strhnr");
QTest::addColumn<QString>("plz");
QTest::addColumn<QString>("ort");
QTest::addColumn<QString>("land");
QTest::addColumn<QString>("telefon");
QTest::addColumn<QString>("email");

QTest::newRow("leer") << QString("")<< QString("")
			<< QString("")<< QString("")<< QString("")<< QString("")<< QString("")<< QString("")<< QString("");
QTest::newRow("vorhanden") << QString("Christian")<< QString("Heinlein")
			<< QString("")<< QString("")<< QString("")<< QString("")<< QString("")<< QString("")<< QString("");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_SchuelerNeuFalsch()
{
	QFETCH(QString, vorname);
	QFETCH(QString, nachname);
	QFETCH(QString, neuername);
	QFETCH(QString, strhnr);
	QFETCH(QString, plz);
	QFETCH(QString, ort);
	QFETCH(QString, land);
	QFETCH(QString, telefon);
	QFETCH(QString, email);
	Schueler *sch = new Schueler();
	sch->eintragen(vorname, nachname, "");
	Daten *dat = new Daten();
	dat->eintragen(0, 0, neuername, strhnr, plz, ort, land, telefon, email);
	QCOMPARE(neuSchueler(sch,dat),false);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_SchuelerNeuRichtig_data()
{
	QTest::addColumn<QString>("vorname");
	QTest::addColumn<QString>("nachname");
	QTest::addColumn<QString>("neuername");
	QTest::addColumn<QString>("strhnr");
	QTest::addColumn<QString>("plz");
	QTest::addColumn<QString>("ort");
	QTest::addColumn<QString>("land");
	QTest::addColumn<QString>("telefon");
	QTest::addColumn<QString>("email");

// Vier Zeilen mit unterschiedlichen Testdaten.
QTest::newRow("ok") << QString("X")<< QString("Y")
			<< QString("Z")<< QString("strasse 1")<< QString("12345")<< QString("abc")<< QString("d")<< QString("12345")<< QString("a@b.c");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Test::Testfall_SchuelerNeuRichtig()
{
	QFETCH(QString, vorname);
	QFETCH(QString, nachname);
	QFETCH(QString, neuername);
	QFETCH(QString, strhnr);
	QFETCH(QString, plz);
	QFETCH(QString, ort);
	QFETCH(QString, land);
	QFETCH(QString, telefon);
	QFETCH(QString, email);
	Schueler *sch = new Schueler();
	sch->eintragen(vorname, nachname, "");
	Daten *dat = new Daten();
	dat->eintragen(0, 0, neuername, strhnr, plz, ort, land, telefon, email);
	QCOMPARE(neuSchueler(sch,dat),true);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QTEST_MAIN(Test);

#include "Test.moc"
