// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include <QtGui/QMainWindow>
#include <QtGui/QTableWidgetItem>
#include <QtGui/QStandardItemModel>
#include <QModelIndex>
#include <QModelIndexList>

#include "ui_Hauptmenu.h"
#include "Anmeldung.h"
#include "Schueler_Verwaltung.h"
#include "Datenbank.h"
#include "Schueler.h"
#include "Daten.h"

//! Hauptfenster.
/*!
 * Die Klasse Hauptmenu zeigt das Hauptfenster an.
 */
class Hauptmenu : public QMainWindow, private Ui::Hauptmenu
{
	Q_OBJECT

public:
	Hauptmenu(QWidget *parent = 0, Qt::WFlags flags = 0); //!< Konstruktor.
	~Hauptmenu(); //!< Destruktor.
private:
	//Ui::Hauptmenu ui;
	void FillList(); //!< Sch&uuml;lerliste anzeigen.
	void Update(); //!< Sch&uuml;lerliste aktualisieren.
	QColor *AmpelFarbe(Schueler *schueler); //!< Farbe der Ampel anpassen.
	Schueler *organisator; //!< Organisator.
	QList<Schueler*> schuelerliste; //!< Sch&uuml;lerliste
private slots:

	void NeuAnlegen(); //!< Neuen Sch&uuml;ler anlegen.
	void Anzeigen(); //!< Sch&uuml;ler anzeigen. 
	void EigeneDaten(); //!< Eigene %Daten anzeigen.
	void Beenden(); //!< Programm beenden.
};

