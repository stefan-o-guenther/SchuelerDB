// Gruppe H: Stefan Günther, Barbara Hörner, Moritz Egetemeir

#include "Anmeldung.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*! 
 * &Ouml;ffnet das Fenster zur %Anmeldung. 
 */
Anmeldung::Anmeldung(QDialog *parent, Qt::WFlags flags) : QDialog(parent,flags)
{
	setupUi(this);
	edtPasswort->setEchoMode(QLineEdit::Password);
	edtWiederholen->setEchoMode(QLineEdit::Password);
	bool b = Datenbank::TabelleSchuelerLeer();
	this->first = b;
	lblWiederholen->setVisible(b);
	edtWiederholen->setVisible(b);

	if(!first)
	{
		setWindowTitle("Anmeldung");
		resize(259, 132);
    		setMinimumSize(QSize(259, 132));
   		setMaximumSize(QSize(259, 132));
   		btnOK->setGeometry(QRect(90, 100, 75, 28)); 
   		btnAbbrechen->setGeometry(QRect(170, 100, 75, 28)); 
	}
	else
	{
		setWindowTitle("Erste Anmeldung");
	}

	// binde die Buttons auf die jeweiligen Methoden
	QObject::connect(btnOK, SIGNAL(clicked()), this, SLOT(login()));
	QObject::connect(btnAbbrechen, SIGNAL(clicked()), this, SLOT(abbrechen()));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
Anmeldung::~Anmeldung(void)
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*! 
 * &Uuml;berpr&uuml;ft ob alle Felder ausgef&uuml;llt sind und ob die Person existiert.    
 * &Ouml;ffnet dann das Hauptfenster.
 * Bei der ersten %Anmeldung wird der Administrator angelegt.
 */
void Anmeldung::login()
{
	QMessageBox mb;
	mb.setWindowTitle("Fehler");
	Schueler *organisator = new Schueler();
	
	//ueberprueft ob was eingegeben wurde
	if(edtVorname->text().trimmed().length() != 0){
		if(edtNachname->text().trimmed().length() != 0){
			if(edtPasswort->text().trimmed().length() != 0){
				QString vorname = edtVorname->text();
				QString nachname = edtNachname->text();
				QString passwort = edtPasswort->text();
				if (this->first){		
					QString wiederholen = edtWiederholen->text();
					if (wiederholen != ""){
						if (passwort == wiederholen){
							organisator->eintragen(vorname,nachname,passwort);
							// Administrator anlegen
							Datenbank::AdministratorAnlegen(organisator);
							this->done(1);
						}
						else{

							mb.setText("Passwort stimmt mit der Wiederholung nicht über ein");
							mb.exec();
						}
					}
					else
					{
						mb.setText("PW wiederholen ausfuellen!");
						mb.exec();
					}
				}
				else{
					//ueberprueft ob der schueler in der db vorhanden ist
					if(Datenbank::SchuelerVorhanden(vorname,nachname)){
						Schueler *schueler = Datenbank::getSchueler(vorname,nachname);
						QString pw = schueler->getPasswort();
						if (passwort == pw){
							//oeffnet hauptfenster
							this->done(schueler->getSchuelerID());
						}
						else{
							mb.setText("falsches Passwort");
							mb.exec();
						}
					}
					else{
						//fehlermeldung
						mb.setText("Schueler nicht vorhanden");
						mb.exec();
					}
				}
			}
			else{
				//fehlermeldung
				mb.setText("Bitte Passwort eingeben");
				mb.exec();
			}
		}
		else{
			//fehlermeldung
			mb.setText("Bitte Nachnamen eingeben");
			mb.exec();
		}
	}
	else{	
		//fehlermeldung
		mb.setText("Bitte Daten eingeben");
		mb.exec();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * Bricht das Programm ab.
*/
void Anmeldung::abbrechen()
{
	this->done(-1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
