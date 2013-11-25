// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include "Hauptmenu.h"
#include <QMessageBox>

//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * &Ouml;ffnet zuerst das Anmeldefenster und bei erfolgreicher Anmeldung dann das Hauptfenster.
 */
Hauptmenu::Hauptmenu(QWidget *parent, Qt::WFlags flags) : QMainWindow(parent, flags)
{
	setupUi(this);
	// binde die befehle an die jeweiligen methoden
	QObject::connect(btnNeu,SIGNAL(clicked()), this, SLOT(NeuAnlegen()));
	QObject::connect(btnAnz,SIGNAL(clicked()), this, SLOT(Anzeigen()));
	QObject::connect(btnOwn,SIGNAL(clicked()), this, SLOT(EigeneDaten()));
	QObject::connect(btnEnd,SIGNAL(clicked()), this, SLOT(Beenden()));
	//QObject::connect(actionQuit,SIGNAL(triggered()), this, SLOT(Beenden()));

	// mit Datenbank verbinden
	Datenbank::verbinden();
	// zeige Anmeldung an
	Anmeldung *loginForm = new Anmeldung();
	int result = loginForm->exec();
	if (result > 0)
	{
		organisator = Datenbank::getSchueler(result);
		QString vorname = organisator->getVorname();
		QString nachname = organisator->getNachname();
		this->setWindowTitle("Hauptfenster - "+vorname+" "+nachname);
		FillList();
	}
	else
	{
		Hauptmenu::Beenden();
	}

}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Beendet das Programm.
 */ 
Hauptmenu::~Hauptmenu()
{
	exit(0);
}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Klasse Schueler_Verwaltung wird geladen, um einen neuen Sch&uuml;ler anzulegen.
 */
void Hauptmenu::NeuAnlegen()
{
	Schueler_Verwaltung* pF = new Schueler_Verwaltung();	// zeige Schueler_Verwaltung an, um eine neue Person anzulegen
	pF->SetPerson(organisator, NULL); // &uuml;bergebe an den dialog die bearbeitende person und die angemeldete person
	int result = pF->exec();
	Update();
}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Klasse Schueler_Verwaltung wird geladen um eine ausgew&auml;hlte Person anzuzeigen.
 */
void Hauptmenu::Anzeigen()
{	
	// finde aktuell ausgewaehlte person raus, uebergebe diese an den Schueler_Verwaltung und zeige diesen an
	QTreeWidgetItem* item = treeWidget->currentItem(); 
	if (item != NULL)
	{
		int x = treeWidget->indexOfTopLevelItem(item);
		Schueler *schueler = schuelerliste[x];
		Schueler_Verwaltung* pF = new Schueler_Verwaltung();
		pF->SetPerson(organisator, schueler);
		int result = pF->exec();
		Update();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Fehler");
		msgBox.setText("Es ist kein Schüler ausgewählt.\nBitte wählen Sie aus der Liste einen Schüler aus, der angezeigt werden soll.");
		msgBox.exec();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Klasse Schueler_Verwaltung wird geladen um die eigenen %Daten &auml;ndern zu k&ouml;nnen.
 */
void Hauptmenu::EigeneDaten()
{
	Schueler_Verwaltung* pF = new Schueler_Verwaltung();
	pF->SetPerson(organisator, organisator); 
	int result = pF->exec();
	Update();
}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Das Programm wird beendet.
 */
void Hauptmenu::Beenden()
{
	exit(0);
}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Die Tabelle mit den Sch&uml;lern wird aktualisiert.
 * Der Organisator wird auch aktualisiert, falls er sich selbst bearbeitet hat.
 */
void Hauptmenu::Update()
{
	QString vorname = organisator->getVorname();
	QString nachname = organisator->getNachname();
	organisator = Datenbank::getSchueler(vorname,nachname);
	FillList();

}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Liste aller Sch&uuml;ler wird angezeigt.
 */
void Hauptmenu::FillList()
{
	// Tabelle loeschen
	treeWidget->clear();
	schuelerliste = Datenbank::getAlleSchueler();

	// Tabelle fuellen
	for (int row = 0; row < schuelerliste.count(); row++) 
	{
		QTreeWidgetItem *item = new QTreeWidgetItem();
		item->setText(0, schuelerliste[row]->getVorname());
		item->setText(1, schuelerliste[row]->getNachname());
		if ((schuelerliste[row]->getSchuelerID()) == 1)
		{
			item->setText(2, "Administrator");
		}
		else
		{
			if ((schuelerliste[row]->getPasswort()) != "")
			{
				item->setText(2, "Organisator");
			}
			else
			{
				item->setText(2, "Schüler");
			}
		}
		QColor *farbe = AmpelFarbe(schuelerliste[row]);
		item->setBackgroundColor(3, *farbe);
		treeWidget->addTopLevelItem(item);
	}

	// Tabelle beschriften
	treeWidget->headerItem()->setText(0, "Vorname");
	treeWidget->headerItem()->setText(1, "Nachname");
	treeWidget->headerItem()->setText(2, "Rolle");
	treeWidget->headerItem()->setText(3, "Ampel");

	// Spaltenbreiten einteilen
	treeWidget->setColumnWidth(0,180);
	treeWidget->setColumnWidth(1,180);
	treeWidget->setColumnWidth(2,150);
	treeWidget->setRootIsDecorated(false);
}
//////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \param schueler Sch&uuml;ler, dessen Vollst&auml;ndigkeit &uuml;berpr&uuml;ft werden soll.
 * Die jeweilige Farbe der Ampel wird abh&auml;ngig nach dem Grad der Vollst&auml;ndigkeit der %Daten bestimmt. Dabei steht Rot f&uuml;r unvollst&auml;ndig, gelb f&uuml;r teilweise unvollst&auml;ndig und gr&uuml;n f&uum;r vollst&auml;ndig.
 * \return Farbe rot, gelb oder gr&uuml;n.
 */
QColor *Hauptmenu::AmpelFarbe(Schueler *schueler)
{
	QColor *farbe;
	Daten *daten = Datenbank::getDaten(schueler);
	int leer = 0;
	if ((daten->getStrHnr()) == "")
		leer += 1;
	if ((daten->getPLZ()) == "")
		leer += 1;
	if ((daten->getOrt()) == "")
		leer += 1;
	if ((daten->getLand()) == "")
		leer += 1;
	if ((daten->getTelefon()) == "")
		leer += 1;
	if ((daten->getEmail()) == "")
		leer += 1;
	
	switch (leer) {
		case 0:  farbe = new QColor("green"); break;
		case 6:  farbe = new QColor("red"); break;
		default: farbe = new QColor("orange"); break;
	}
	return farbe;
}
//////////////////////////////////////////////////////////////////////////////////////////
