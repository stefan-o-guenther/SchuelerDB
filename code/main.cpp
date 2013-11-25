// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

/*!
 *  \mainpage Programm zum Organisieren von Klassentreffen
 *
 * Das Programm dient zur Unterst&uuml;tzung der Organisation eines Klassentreffens und zur Verwaltung der Adressdaten aller ehemaligen Sch&uuml;ler.
 */

/*! \file */

#include "Hauptmenu.h"
#include "Datenbank.h"
#include <QtGui/QApplication>
#include <QMessageBox>

//! Hauptprogramm.
/*!
 *  \param argv[1] test oder clean, kann jedoch auch leer gelassen werden.
 *   <br>
 *  <tt>test</tt> f&uuml;llt die %Datenbank mit Beispieldaten,<br>
 *  <tt>clean</tt> l&ouml;scht alle %Daten aus der %Datenbank.
 *
 * Ruft die Klasse Hauptmenu auf, außer bei der Eingabe von clean.
 */
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Datenbank::verbinden();
	QString befehl = QString(argv[1]);
	if ((befehl == NULL) || (befehl != "clean"))
	{

		if (befehl == "test")
		{
			Datenbank::test();
		}
		else
		{
			Datenbank::initialisieren();
		}
		Hauptmenu w;
		w.show();
		return a.exec();
	}
	else
	{
		Datenbank::clean();
		exit(3);
	}
}
