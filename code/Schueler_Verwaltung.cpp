// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include "Schueler_Verwaltung.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Initialisiert #organisator, #schueler und #daten mit null.
 * Ruft deaktivieren() auf.
 */
Schueler_Verwaltung::Schueler_Verwaltung(QDialog *parent, Qt::WFlags flags) : QDialog(parent,flags)
{
	setupUi(this);

	// binde die Buttons an die entsprechenden methoden
	QObject::connect(btnOK, SIGNAL(clicked()), this, SLOT(OK()));
	QObject::connect(btnAbbrechen, SIGNAL(clicked()), this, SLOT(Abbrechen()));
	QObject::connect(btnVerlauf, SIGNAL(clicked()), this, SLOT(Verlauf()));
	QObject::connect(btnBearbeiten, SIGNAL(clicked()), this, SLOT(Bearbeiten()));
	QObject::connect(btnAktion, SIGNAL(clicked()), this, SLOT(Aktion()));
	QObject::connect(rbtnSchueler, SIGNAL(clicked()), this, SLOT(Radio()));
	QObject::connect(rbtnOrganisator, SIGNAL(clicked()), this, SLOT(Radio()));

	organisator = NULL;
	schueler = NULL;
	daten = NULL;

	deaktivieren();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param org Organisator.
 * \param sch Sch&uuml;ler.
 * Die Schueler_Verwaltung wird darauf eingestellt, ob und von wem ein Sch&uuml;ler neu erstellt oder angezeigt werden soll.
 */
void Schueler_Verwaltung::SetPerson(Schueler *org, Schueler *sch)
{
	organisator = org;
	schueler = sch;
	if (org != NULL)
	{
		if (sch != NULL)
		{
			daten = Datenbank::getDaten(schueler);
			anzeigen();
		}
		else
		{
			schueler = new Schueler();
			daten = new Daten();
			neu();
		}
	}
	else
	{

	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destruktor
Schueler_Verwaltung::~Schueler_Verwaltung(void)
{
}
/*!
 * Wenn der Radiobutton rbtnOrganisator aktiviert ist, werden die Passwortfelder angezeigt, ansonsten nicht.
 */
void Schueler_Verwaltung::Radio()
{
	edtPasswort->setText("");
	edtWiederholen->setText("");
	schueler->setPasswort("");
	if (rbtnOrganisator->isChecked())
	{
		edtPasswort->setVisible(true);
		lblPasswort->setVisible(true);
		edtWiederholen->setVisible(true);
		lblWiederholen->setVisible(true);
		edtPasswort->setEnabled(true);
		edtWiederholen->setEnabled(true);
	}
	else
	{
		edtPasswort->setVisible(false);
		lblPasswort->setVisible(false);
		edtWiederholen->setVisible(false);
		lblWiederholen->setVisible(false);
		edtPasswort->setEnabled(false);
		edtWiederholen->setEnabled(false);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*! 
 * Methode, die beim Klick auf den Verlauf-Button ausgef&uuml;hrt wird.
 */
void Schueler_Verwaltung::Verlauf()
{
	verlauf();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Methode, die beim Klick auf den Bearbeiten-Button ausgef&uuml;hrt wird.
 */
void Schueler_Verwaltung::Bearbeiten()
{
	bearbeiten();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Methode, die beim Klick auf den Aktion-Button ausgef&uuml;hrt wird.
 * Je nach Verwaltungsart wird entweder bearbeiten() oder anzeigeVerlauf() aufgerufen.
 */
void Schueler_Verwaltung::Aktion()
{
	switch(art)
	{
		case 0:
		{
			if (anlegenSchueler())
			{
				bearbeiten();
			}
			break;
		}
		case 1:
		{
			// nichts
			break;
		}
		case 2:
		{
			if (updateSchueler())
			{
				bearbeiten();
			}
			break;
		}
		case 3:
		{
			anzeigeVerlauf();
			break;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Methode, die beim Klick auf den Abbrechen-Button ausgef&uuml;hrt wird.
 * Dialog wird ohne zu speichern geschlossen.
 */
void Schueler_Verwaltung::Abbrechen()
{
	this->done(-1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Methode, die beim Klick auf den OK-Button ausgef&uuml;hrt wird.
 * Daten werden vor dem Schließen gespeichert.
 */
void Schueler_Verwaltung::OK()
{
	switch(art)
	{
		case 0:
		{
			if (anlegenSchueler())
			{
				Abbrechen();
			}
			break;
		}
		case 1:
		{
			Abbrechen();
			break;
		}
		case 2:
		{
			if (updateSchueler())
			{
				Abbrechen();
			}
			break;
		}
		case 3:
		{
			Abbrechen();
			break;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Abfrage, ob der Organisator und der zu bearbeitende Sch&uuml;ler die gleiche Person sind.
 * \return true, wenn der Organisator der zu bearbeitende Sch&uuml;ler ist, ansonsten false.
 */
bool Schueler_Verwaltung::gleicherSchueler()
{
	bool res = false;
	Schueler *sch1 = organisator;
	Schueler *sch2 = schueler;
	if ((sch1 != NULL) && (schueler != NULL))
	{
		if (sch1 == schueler)
		{
			res = true;
		}
		else
		{
			QString v1 = sch1->getVorname();
			QString v2 = sch2->getVorname();
			QString n1 = sch1->getNachname();
			QString n2 = sch2->getNachname();
			QString p1 = sch1->getPasswort();
			QString p2 = sch2->getPasswort();
			int i1 = sch1->getSchuelerID();
			int i2 = sch2->getSchuelerID();
			if ((v1==v2)&&(n1==n2)&&(p1==p2)&&(i1==i2))
			{
				res = true;
			}
			else
			{
				res = false;
			}
		}
	}
	return res;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param sch Sch&uuml;ler.
 * Abfrage, ob ein Sch&uuml;ler der Administrator ist.
 * \return true, wenn der Sch&uuml;ler der Administrator ist, ansonsten false.
 */
bool Schueler_Verwaltung::istAdministrator(Schueler *sch)
{
	int i1 = sch->getSchuelerID();
	int i2 = Datenbank::getErsteSchuelerID();
	return (i1 == i2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param sch Sch&uuml;ler.
 * Abfrage, ob ein Sch&uuml;ler ein Organisator ist.
 * \return true, wenn der Sch&uuml;ler ein Organisator ist, ansonsten false.
 */
bool Schueler_Verwaltung::istOrganisator(Schueler *sch)
{
	QString pw = sch->getPasswort();
	return (pw.trimmed().length() > 0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Alle Ein- und Ausgabefelder werden geleert.
 */
void Schueler_Verwaltung::leereFelder()
{
	edtVorname->setText("");
	edtNachname->setText("");
	edtNeuerNachname->setText("");
	edtStrHnr->setText("");
	edtPLZ->setText("");
	edtOrt->setText("");
	edtLand->setText("");
	edtTelefon->setText("");
	edtEmail->setText("");
	txtKommentar->setPlainText("");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Alle Felder und Buttons werden deaktiviert.
 * Danach k&ouml;nnen die gew&uuml;nschten Felder und Buttons wieder aktiviert werden.
 */
void Schueler_Verwaltung::deaktivieren()
{
	setWindowTitle("");
	edtVorname->setEnabled(false);
	edtNachname->setEnabled(false);
	edtNeuerNachname->setEnabled(false);
	edtStrHnr->setEnabled(false);
	edtPLZ->setEnabled(false);
	edtOrt->setEnabled(false);
	edtLand->setEnabled(false);
	edtTelefon->setEnabled(false);
	edtEmail->setEnabled(false);
	txtKommentar->setEnabled(false);

	rbtnSchueler->setEnabled(false);
	rbtnOrganisator->setEnabled(false);

	btnVerlauf->setEnabled(false);
	btnBearbeiten->setEnabled(false);
	btnAktion->setEnabled(false);
	btnAbbrechen->setEnabled(true);
	btnOK->setEnabled(true);

	edtPasswort->setVisible(false);
	lblPasswort->setVisible(false);
	edtWiederholen->setVisible(false);
	lblWiederholen->setVisible(false);
	edtPasswort->setEchoMode(QLineEdit::Password);
	edtWiederholen->setEchoMode(QLineEdit::Password);
	grbVerlauf->setVisible(false);

	btnVerlauf->setText("Verlauf");
	btnBearbeiten->setText("Bearbeiten");
	btnAktion->setText("Übernehmen");
	btnAbbrechen->setText("Abbrechen");
	btnOK->setText("OK");

	setMinimumSize(QSize(707, 393)); //(707, 668)(707, 393)
	setMaximumSize(QSize(707, 393)); //(707, 668)(707, 393)
	resize(707, 393); //(707, 668)(707, 393
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Der Dialog wird darauf eingestellt, einen Sch&uuml;ler zu erstellen.
 */
void Schueler_Verwaltung::neu()
{
	art = 0;

	deaktivieren();
	leereFelder();

	setWindowTitle("Schüler neu anlegen");
	rbtnSchueler->setChecked(true);

	edtVorname->setEnabled(true);
	edtNachname->setEnabled(true);
	edtNeuerNachname->setEnabled(true);
	edtStrHnr->setEnabled(true);
	edtPLZ->setEnabled(true);
	edtOrt->setEnabled(true);
	edtLand->setEnabled(true);
	edtTelefon->setEnabled(true);
	edtEmail->setEnabled(true);
	txtKommentar->setEnabled(true);

	if (istAdministrator(organisator))
	{
		rbtnSchueler->setEnabled(true);
		rbtnOrganisator->setEnabled(true);
	}

	btnAktion->setEnabled(true);
	btnOK->setEnabled(true);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Der Dialog wird darauf eingestellt, einen Sch&uuml;ler anzuzeigen.
 */
void Schueler_Verwaltung::anzeigen()
{
	art = 1;

	deaktivieren();
	outputSchueler();
	outputDaten();
	
	if (gleicherSchueler())
	{
		this->setWindowTitle("Eigene Daten anzeigen");
	}
	else
	{
		this->setWindowTitle("Schülerdaten anzeigen");
	}

	btnVerlauf->setEnabled(true);
	bool b1 = istAdministrator(organisator);
	bool b2 = istOrganisator(schueler);
	bool b3 = gleicherSchueler();
	btnBearbeiten->setEnabled(true);
	if ((!b1)&&(b2)&&(!b3))
	{
		btnBearbeiten->setEnabled(false);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Der Dialog wird darauf eingestellt, einen Sch&uuml;ler zu bearbeiten.
 * Es wird festgelegt, welcher Organisator welchen Sch&uuml;ler wie sehr bearbeiten kann.
 */
void Schueler_Verwaltung::bearbeiten()
{
	art = 2;
	deaktivieren();
	this->setWindowTitle("Schüler bearbeiten");
	btnAktion->setEnabled(true);
	btnAktion->setText("Übernehmen");
	outputSchueler();
	outputDaten();

	if (gleicherSchueler())
	{
		edtPasswort->setVisible(true);
		lblPasswort->setVisible(true);
		edtWiederholen->setVisible(true);
		lblWiederholen->setVisible(true);
		edtPasswort->setEnabled(true);
		edtWiederholen->setEnabled(true);
	}
	else
	{
		if (istAdministrator(organisator))
		{
			rbtnSchueler->setEnabled(true);
			rbtnOrganisator->setEnabled(true);
		}
	}

	if ((!(istOrganisator(schueler))) || (gleicherSchueler()))
	{
		edtNeuerNachname->setEnabled(true);
		edtStrHnr->setEnabled(true);
		edtPLZ->setEnabled(true);
		edtOrt->setEnabled(true);
		edtLand->setEnabled(true);
		edtTelefon->setEnabled(true);
		edtEmail->setEnabled(true);
		txtKommentar->setEnabled(true);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Der Dialog wird darauf eingestellt, den Verlauf eines Sch&uuml;lers anzuzeigen.
 * Eine zus&auml;tzliche Tabelle mit den &Auml;nderungen erscheint.
 */
void Schueler_Verwaltung::verlauf()
{
	art = 3;

	deaktivieren();
	leereFelder();
	this->setWindowTitle("Verlauf");
	outputSchueler();
	btnAktion->setEnabled(true);
	btnAktion->setText("Anzeigen");
	btnVerlauf->setEnabled(true);
	bool b1 = istAdministrator(organisator);
	bool b2 = istOrganisator(schueler);
	bool b3 = gleicherSchueler();
	btnBearbeiten->setEnabled(true);
	if ((!b1)&&(b2)&&(!b3))
	{
		btnBearbeiten->setEnabled(false);
	}

	setMinimumSize(QSize(707, 668)); //(707, 668)(707, 393)
	setMaximumSize(QSize(707, 668)); //(707, 668)(707, 393)
	resize(707, 668); //(707, 668)(707, 393)

	grbVerlauf->setVisible(true);	

	ladeVerlauf();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Abfrage, ob die Sch&uuml;lerdaten den aktuellen Sch&uuml;lerdaten aus der %Datenbank entsprechen.
 * \return true, wenn die Sch&uuml;lerdaten die aktuellen sind, ansonsten false.
 */
bool Schueler_Verwaltung::gleicheDaten()
{
	bool res = false;
	Daten *dat1 = daten;
	Daten *dat2 = Datenbank::getDaten(schueler);
	if ((dat1 != NULL) && (dat2 != NULL))
	{
		QString name1 = dat1->getNeuerName();
		QString name2 = dat2->getNeuerName();
		QString str1 = dat1->getStrHnr();
		QString str2 = dat2->getStrHnr();
		QString plz1 = dat1->getPLZ();
		QString plz2 = dat2->getPLZ();
		QString ort1 = dat1->getOrt();
		QString ort2 = dat2->getOrt();
		QString land1 = dat1->getLand();
		QString land2 = dat2->getLand();
		QString tel1 = dat1->getTelefon();
		QString tel2 = dat2->getTelefon();
		QString email1 = dat1->getEmail();
		QString email2 = dat2->getEmail();
		QString kom1 = dat1->getKommentar();
		QString kom2 = dat2->getKommentar();
	
		if ((name1==name2)&&(str1==str2)&&(plz1==plz2)&&(ort1==ort2)&&(land1==land2)&&(tel1==tel2)&&(email1==email2)&&(kom1==kom2))
		{
			res = true;
		}
		else
		{
			res = false;
		}
	}
	return res;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Tabelle mit dem Verlauf des Sch&uuml;lers wird geladen.
 */
void Schueler_Verwaltung::ladeVerlauf()
{
	treeWidget->clear();
	verlaufliste = Datenbank::getVerlauf(schueler);	

	for (int row = 0; row < verlaufliste.count(); row++) 
	{
		QTreeWidgetItem *item = new QTreeWidgetItem();
		int id = verlaufliste[row]->getOrganisatorID();

		Schueler *sch = Datenbank::getSchueler(id);
		QString vn = sch->getVorname();
		QString nn = sch->getNachname();
		QString org = vn + " "+ nn;
		QString ch = verlaufliste[row]->getAenderungen();
		QDateTime date = verlaufliste[row]->getDatum();
		item->setText(0, date.toString("dd.MM.yyyy - hh:mm")+" Uhr");
		item->setText(1, org);
		item->setText(2, ch);
		//item->setText(2, "Hallo Welt");
		treeWidget->addTopLevelItem(item);
	}

	// Tabelle beschriften
	treeWidget->headerItem()->setText(0, "Datum");
	treeWidget->headerItem()->setText(1, "Organisator");
	treeWidget->headerItem()->setText(2, "Änderungen");

	// Spaltenbreiten einteilen
	treeWidget->setColumnWidth(0,180);
	treeWidget->setColumnWidth(1,180);
	treeWidget->setColumnWidth(2,150);
	treeWidget->setRootIsDecorated(false);

	if ((verlaufliste.count()) <= 0)
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Fehler");
		msgBox.setText("kein Eintrag");
		msgBox.exec();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Felder werden mit den Werten eines bestimmten Eintrags aus dem Verlauf gef&uuml;llt.
 */
void Schueler_Verwaltung::anzeigeVerlauf()
{
	QTreeWidgetItem* item = treeWidget->currentItem(); 
	if (item != NULL)
	{
		int x = treeWidget->indexOfTopLevelItem(item);
		daten = verlaufliste[x];
		outputDaten();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Fehler");
		msgBox.setText("Es ist kein Eintrag ausgewählt.");
		msgBox.exec();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Der &Auml;nderungstext für den Verlauf wird erstellt.
 * \return &Auml;nderungen, die gemacht wurden.
 */
QString Schueler_Verwaltung::Aenderungen()
{
	QString result = "";
	Daten *aktuell = Datenbank::getDaten(schueler);
	int anz = 0;
	if ((daten->getNeuerName())!=(aktuell->getNeuerName()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "neuer Name";
	}
	if ((daten->getStrHnr())!=(aktuell->getStrHnr()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "Str und HNr";
	}
	if ((daten->getPLZ())!=(aktuell->getPLZ()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "PLZ";
	}
	if ((daten->getOrt())!=(aktuell->getOrt()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "Ort";
	}
	if ((daten->getLand())!=(aktuell->getLand()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "Land";
	}
	if ((daten->getTelefon())!=(aktuell->getTelefon()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "Telefon";
	}
	if ((daten->getEmail())!=(aktuell->getEmail()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "Email";
	}
	if ((daten->getKommentar())!=(aktuell->getKommentar()))
	{
		anz += 1;
		if (anz > 1)
		{
			result += ", ";
		}
		result += "Kommentar";
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Eintr&auml;ge in den Feldern fuer die %Daten werden in die Variable #daten gespeichert.
 */
void Schueler_Verwaltung::inputDaten()
{
	QString neuername = edtNeuerNachname->text();
	QString strhnr = edtStrHnr->text();
	QString plz = edtPLZ->text();
	QString ort = edtOrt->text();
	QString land = edtLand->text();
	QString telefon = edtTelefon->text();
	QString email = edtEmail->text();	
	QString kommentar = txtKommentar->toPlainText();
	int schuelerid = schueler->getSchuelerID();
	int organisatorid = organisator->getSchuelerID();
	if (daten == NULL)
	{
		daten = new Daten();
	}
	daten->eintragen(schuelerid,organisatorid,neuername,strhnr,plz,ort,land,telefon,email);
	daten->setKommentar(kommentar);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Eintr&auml;ge in den Feldern f&uuml;r den Sch&uuml;ler werden in die Variable #schueler gespeichert.
 * Es wird auf die Korrektheit und Vollst&auml;ndigkeit geachtet.
 * \return true, wenn die %Daten korrekt eingegeben wurden, ansonsten false.
 */
bool Schueler_Verwaltung::inputSchueler()
{
	bool result = false;
	QString vorname = edtVorname->text();
	QString nachname = edtNachname->text();
	QString passwort = edtPasswort->text();
	QString wiederholen = edtWiederholen->text();
	if ((vorname != "") && (nachname != ""))
	{
		if (((rbtnOrganisator->isChecked()) && (passwort != "") && (wiederholen != "") && (passwort == wiederholen)) || (rbtnSchueler->isChecked()))
		{
			result = true;
			if (schueler == NULL)
			{
				schueler = new Schueler();
			}
			schueler->eintragen(vorname,nachname,passwort);
		}
		else
		{
			result = false;
			QMessageBox msgBox;
			msgBox.setWindowTitle("Fehler");
			msgBox.setText("Es sind nicht alle Daten angegeben!");
			msgBox.exec();	
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Werte in der Varible #daten werden in den jeweiligen Feldern ausgegeben.
 */
void Schueler_Verwaltung::outputDaten()
{
	edtNeuerNachname->setText(daten->getNeuerName());
	edtStrHnr->setText(daten->getStrHnr());
	edtPLZ->setText(daten->getPLZ());
	edtOrt->setText(daten->getOrt());
	edtLand->setText(daten->getLand());
	edtTelefon->setText(daten->getTelefon());
	edtEmail->setText(daten->getEmail());
	txtKommentar->setText(daten->getKommentar());
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Werte in der Variable #schueler werden in den jeweiligen Feldern ausgegeben.
 * Es wird mithilfe der Radiobuttons angezeigt, ob es sich bei dem Sch&uuml;ler um einen Organisator oder einen Sch&uuml;ler handelt.
 */
void Schueler_Verwaltung::outputSchueler()
{
	edtVorname->setText(schueler->getVorname());
	edtNachname->setText(schueler->getNachname());
	edtPasswort->setText(schueler->getPasswort());
	edtWiederholen->setText(schueler->getPasswort());
	if (istOrganisator(schueler))
	{
		rbtnOrganisator->setChecked(true);
	}
	else
	{
		rbtnSchueler->setChecked(true);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Ein Sch&uuml;ler wird mit seinen %Daten in die %Datenbank eingetragen.
 * \return true, wenn der Sch&uuml;ler noch nicht vorhanden ist, ansonsten false.
 */
bool Schueler_Verwaltung::anlegenSchueler()
{
	bool result = false;
	schueler = new Schueler();
	if (inputSchueler())
	{
		QString vorname = schueler->getVorname();
		QString nachname = schueler->getNachname();
		if (Datenbank::SchuelerVorhanden(vorname, nachname))
		{
			result = false;
			QMessageBox msgBox;
			msgBox.setWindowTitle("Fehler");
			msgBox.setText("Schüler ist schon vorhanden");
			msgBox.exec();
		}
		else
		{
			result = true;
			Datenbank::setSchuelerNeu(schueler);
			schueler = Datenbank::getSchueler(vorname, nachname);
			inputDaten();
			Datenbank::setDaten(daten);
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Ein Sch&uuml;ler wird in der %Datenbank aktualisiert.
 * Das Passwort wird ge&auml;ndert und f&uuml;r die &uuml;brigen %Daten wird ein neuer Eintrag erstellt, falls sie sich von den aktuellen %Daten unterscheiden.
 * \return true, wenn die Sch&uuml;lerdaten erfolgreich aktualisiert wurde, ansonsten false.
 */
bool Schueler_Verwaltung::updateSchueler()
{
	bool result = false;
	if (inputSchueler())
	{
		QString vorname = schueler->getVorname();
		QString nachname = schueler->getNachname();
		if (Datenbank::SchuelerVorhanden(vorname, nachname))
		{
			result = true;
			Datenbank::updateSchueler(schueler);
			schueler = Datenbank::getSchueler(vorname, nachname);
			inputDaten();
			daten->setAenderungen(Aenderungen());
			if (!(gleicheDaten()))
			{
				Datenbank::setDaten(daten);
			}
		}
		else
		{
			result = false;
			QMessageBox msgBox;
			msgBox.setWindowTitle("Fehler");
			msgBox.setText("Schüler ist nicht vorhanden");
			msgBox.exec();
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

