// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#pragma once
#include <QtGui/qdialog.h>
#include <QtGui/qmessagebox.h>
#include "ui_Schueler_Verwaltung.h"
#include "Datenbank.h"
#include "Schueler.h"
#include "Daten.h"

//! Verwaltung der Sch&uuml;lerdaten.
/*!
 * In der Klasse Schueler_Verwaltung werden die %Daten bearbeitet. 
*/
class Schueler_Verwaltung : public QDialog, private Ui::Schueler_Verwaltung
{

	Q_OBJECT

public:
	Schueler_Verwaltung(QDialog *parent = 0, Qt::WFlags flags = 0); //!< Konstruktor.
	~Schueler_Verwaltung(void); //!< Destruktor.
	void SetPerson(Schueler *org, Schueler *sch); //!< Person setzen.
private slots:   
	void Verlauf(); //!< Verlauf anzeigen.
	void Bearbeiten(); //!< Bearbeitungsfenster anzeigen.
	void Aktion();
	void Abbrechen(); //!< Verwaltungsfenster schließen.
	void OK(); //!< OK.
	void Radio(); //!< Radiobuttons anzeigen/verbergen.
private:
	Schueler *organisator; //!< Organisator.
	Schueler *schueler; //!< Sch&uuml;ler.
	Daten *daten; //!< %Daten.
	QList<Daten*> verlaufliste; //!< Verlaufsliste
	
	int art; //!< Verwaltungsart (0=neu, 1=anzeigen, 2=bearbeiten, 3=verlauf).
	bool isOrg; 
	bool gleicherSchueler(); //!< Organisator = Sch&uuml;ler?
	bool istAdministrator(Schueler *sch); //!< Administrator &uuml;berpr&uuml;fen.
	bool istOrganisator(Schueler *sch); //!< Organisator &uuml;berpr&uuml;fen.
	void leereFelder(); //!< Bearbeitungsfelder leeren.
	void deaktivieren(); //!< Buttons und Felder deaktivieren.
	bool gleicheDaten(); //!< Sch&uuml;lerdaten &uuml;berpr&uuml;fen.
	void neu(); //!< Fenster f&uuml;r neue Sch&uuml;lerdaten anpassen.
	void anzeigen(); //!< Fenster f&uuml;r das Anzeigen der %Daten anpassen.
	void bearbeiten(); //!< Fenster f&uuml;r das Bearbeiten anpassen.
	void verlauf(); //!< Fenster f&uuml;r den Verlauf anpassen.
	void ladeVerlauf(); //!< Verlauf laden.
	void anzeigeVerlauf(); //!< Verlauf anzeigen.
	bool inputSchueler(); //!< Sch&uuml;ler in #schueler speichern.
	void inputDaten(); //!< Sch&uuml;lerdaten in #daten speichern.
	void outputSchueler(); //!< Inhalt von #schueler ausgeben.
	void outputDaten(); //!< Inhalt von #daten ausgeben.
	bool anlegenSchueler(); //!< Sch&uuml;ler anlegen.
	bool updateSchueler(); //!< Sch&uuml;ler aktualisieren.
	QString Aenderungen(); //!< Anzeige der &Auml;nderungen erstellen.
};

