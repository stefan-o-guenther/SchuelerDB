// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include <QtGui/qdialog.h>
#include <QtGui/qmessagebox.h>
#include "ui_Anmeldung.h"
#include "Schueler.h"
#include "Daten.h"
#include "Datenbank.h"


//! Anmelden am System.
/*!
 * Die Klasse Anmeldung &ouml;ffnet das Anmeldefenster.
 */
class Anmeldung : public QDialog, private Ui::Anmeldung
{
	Q_OBJECT

public:
	Anmeldung(QDialog *parent = 0, Qt::WFlags flags = 0); //!< Konstruktor.
	~Anmeldung(void); //!< Destruktor.
private slots:
	void login(); //!< Funktion für den Login.
	void abbrechen(); //!< Programm beenden.
private:
bool first; //!< erste Nutzung abfragen.
};

