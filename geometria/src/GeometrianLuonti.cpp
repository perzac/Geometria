/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

/* Muodostimessa luodaan kekodynaamisesti joukko pisteille ja
suorille sekä insidenssi. */

#include "geometria/GeometrianLuonti.hpp"

GeometrianLuonti::GeometrianLuonti()
{
	Pisteet = new Joukko();
	Suorat = new Joukko();
	I = new Insidenssi(*Pisteet, *Suorat);
}

/* Luokan ainoa julkinen metodi ohjaa käyttöliittymää. Aluksi
tulostaa ohjelman esittelyn tiedostosta ja sen jälkeen ohjaa
komennot riveittäin tulkittavaksi. */

void GeometrianLuonti::aloita()
{
	char a;
	
	string ymparisto = getenv("HOME");
	string sijainti = "/var/lib/geometria/Esittely.txt";
	string tdst;
	tdst = ymparisto + sijainti;
	ifstream vuoksi(tdst.c_str());
	while(vuoksi.peek() != EOF)
	{
		vuoksi.get(a);
		cout << a;	
	}
	vuoksi.close();

	string komento;
	cout << "Geo>> ";
	getline(cin, komento);
	
	while(komento != "lopeta" && komento != "Lopeta" && komento != "LOPETA")
	{
		tulkitse(komento);
		cout << "Geo>> ";
		getline(cin, komento);
	}
	
	cout << "\n\tGeometrian luonti loppuu. Hei hei!\n\n";
}

/* Tulostaa ohjelman käyttöohjeet tiedostosta. */

void GeometrianLuonti::neuvo()
{
	char a;
	
	string ymparisto = getenv("HOME");
	string sijainti = "/var/lib/geometria/Ohje.txt";
	string tdst = ymparisto + sijainti;
	ifstream vuoksi(tdst.c_str());
	while(vuoksi.peek() != EOF)
	{
		vuoksi.get(a);
		cout << a;
	}
	vuoksi.close();
}

/* Tulostaa ohjelman alussakin näkyvän esittelyn tiedostosta. */

void GeometrianLuonti::esittely()
{
	char a;
	
	string ymparisto = getenv("HOME");
	string sijainti = "/var/lib/geometria/Esittely.txt";
	string tdst = ymparisto + sijainti;
	ifstream vuoksi(tdst.c_str());
	while(vuoksi.peek() != EOF)
	{
		vuoksi.get(a);
		cout << a;
		
	}
	vuoksi.close();
}

/* Tulostaa affiinin ja projektiivisen geometrian aksioomat
tiedostosta. */

void GeometrianLuonti::aksioomat()
{
	char a;
	
	string ymparisto = getenv("HOME");
	string sijainti = "/var/lib/geometria/Aksioomat.txt";
	string tdst = ymparisto + sijainti;
	ifstream vuoksi(tdst.c_str());
	while(vuoksi.peek() != EOF)
	{
		vuoksi.get(a);
		cout << a;
		
	}
	vuoksi.close();
}

/* Luo paramentrina annetun nimen nimisen pisteen kekodynaamisesti,
lisää sen geometriaan ja pyytää insidenssiä päivittämään itsensä. */

void GeometrianLuonti::piste(std::string nimi)
{
	Pisteet->lisaa(new Piste(nimi));
	I->paivita(-1, 'p');
}

/* Luo paramentrina annetun nimen nimisen suoran kekodynaamisesti,
lisää sen geometriaan ja pyytää insidenssiä päivittämään itsensä. */

void GeometrianLuonti::suora(std::string nimi)
{
	Suorat->lisaa(new Piste(nimi));
	I->paivita(-1, 's');
}

/* Poistaa parametrina annetun nimisen pisteen geometriasta,
pyytää insidenssiä päivittämään itsensä ja vapauttaa pisteen
varaaman muistialueen. Jos pistettä ei ole geometriassa, nappaa
poikkeuksen. */

void GeometrianLuonti::poista_piste(std::string nimi)
{
	try
	{
		Pistejoukko *P = Pisteet->osoita(nimi);
		Monio::luettelo l = Pisteet->annaLuettelo();
		Monio::luettelo::iterator sel = Pisteet->annaSelaaja();
		int a = 0;
		for(sel = l.begin(); sel != l.end(); sel++)
		{
			if(*sel != P) a++;
			else break;
		}
		Pisteet->poista(P);
		I->paivita(a, 'p');
		delete P;
	}
	catch(runtime_error &virhe)
	{
		cerr << "\n" << virhe.what() << "\n\n";
	}
}

/* Poistaa parametrina annetun nimisen suoran geometriasta,
pyytää insidenssiä päivittämään itsensä ja vapauttaa suoran
varaaman muistialueen. Jos suoraa ei ole geometriassa, nappaa
poikkeuksen. */

void GeometrianLuonti::poista_suora(std::string nimi)
{
	try
	{
		Pistejoukko *s = Suorat->osoita(nimi);
		Monio::luettelo l = Suorat->annaLuettelo();
		Monio::luettelo::iterator sel = Suorat->annaSelaaja();
		int a = 0;
		for(sel = l.begin(); sel != l.end(); sel++)
		{
			if(*sel != s) a++;
			else break;
		}
		Suorat->poista(s);
		I->paivita(a, 's');
		delete s;
	}
	catch(runtime_error &virhe)
	{
		cerr << "\n" << virhe.what() << "\n\n";
	}
}

/* Tulostaa pisteiden joukon. */

void GeometrianLuonti::pisteet()
{
	cout << "\n\tPisteet = ";
	Pisteet->nayta();
	cout << "\n\n";
}

/* Tulostaa suorien joukon. */

void GeometrianLuonti::suorat()
{
	cout << "\n\tSuorat = ";
	Suorat->nayta();
	cout << "\n\n";
}

/* Tulkitsee parametrina saamansa geometrian ohjauskomennon
sanoittain ja välittää pyynnöt eteenpäin. Jättää ylimääräiset
sanat ja väärät komennot huomiotta. */

void GeometrianLuonti::tulkitse(std::string komento)
{
	istringstream vuoksi(komento);

	vector<string> ohjeet;
	string ohje;
	while(vuoksi >> ohje) ohjeet.push_back(ohje);
	
	vector<string>::iterator selaaja;
	
	if(ohjeet.size() == 0);
	else if(ohjeet[0] == "PISTE")
	{
		for(selaaja = ++ohjeet.begin(); selaaja != ohjeet.end(); selaaja++)
		{
			piste(*selaaja);
		}
	}else if(ohjeet[0] == "SUORA")
	{
		for(selaaja = ++ohjeet.begin(); selaaja != ohjeet.end(); selaaja++)
		{
			suora(*selaaja);
		}
	}else if(ohjeet[0] == "PISTEET")
	{
		pisteet();
	}else if(ohjeet[0] == "SUORAT")
	{
		suorat();
	}else if(ohjeet[0] == "POISTA")
	{
		if(ohjeet[1] == "PISTE")
		{
			for(selaaja = (ohjeet.begin() + 2); selaaja != ohjeet.end(); selaaja++)
			{
				poista_piste(*selaaja);
			}
		}else if(ohjeet[1] == "SUORA")
		{
			for(selaaja = (ohjeet.begin() + 2); selaaja != ohjeet.end(); selaaja++)
			{
				poista_suora(*selaaja);
			}
		}
	}else if(ohjeet[0] == "I")
	{
		if(ohjeet[1] == "MATRIISI")
		{
			I->matriisi();
		}else if(ohjeet[1] == "TAULUKKO")
		{
			I->taulukko();
		}else if(ohjeet[1] == "TAULUKKO_T")
		{
			I->kaannettyTaulukko();
		}else if(ohjeet[1] == "SUORAT")
		{
			try // Jos merkkijonon ohjeet[2] nimistä pistettä ei ole geometriassa, nappaa poikkeuksen.
			{
				cout << "\n\t";
				I->suorat(Pisteet->osoita(ohjeet[2]));
				cout << "\n\n";
			}
			catch(runtime_error &virhe)
			{
				cerr << "\b\b\b\b\b\b\b\b"  << virhe.what() << "\n\n";
			}
		}else if(ohjeet[1] == "PISTEET")
		{
			try // Jos merkkijonon ohjeet[2] nimistä suoraa ei ole geometriassa, nappaa poikkeuksen.
			{
				cout << "\n\t";
				I->pisteet(Suorat->osoita(ohjeet[2]));
				cout << "\n\n";
			}
			catch(runtime_error &virhe)
			{
				cerr << "\b\b\b\b\b\b\b\b" << virhe.what() << "\n\n";
			}
		}else if(ohjeet[1] == "ASETA")
		{
			if(ohjeet.size() == 2)
			{
				I->aseta();
			}else if(ohjeet[2] == "PISTE")
			{
				try // Jos merkkijonon ohjeet[3] nimistä pistettä ei ole geometriassa, nappaa poikkeuksen.
				{
					I->asetaPiste(Pisteet->osoita(ohjeet[3]));
				}
				catch(runtime_error &virhe)
				{
					cerr << "\n" << virhe.what() << "\n\n";
					
				}
			}else if(ohjeet[2] == "SUORA")
			{
				try // Jos merkkijonon ohjeet[3] nimistä suoraa ei ole geometriassa, nappaa poikkeuksen.
				{
					I->asetaSuora(Suorat->osoita(ohjeet[3]));
				}
				catch(runtime_error &virhe)
				{
					cerr << "\n" << virhe.what() << "\n\n";
					
				}
			}else
			{
				I->aseta();
			}
		}
	}else if(ohjeet[0] == "ANALYSOI")
	{
		I->analysoi();
	}else if(ohjeet[0] == "OHJE")
	{
		neuvo();
	}else if(ohjeet[0] == "ESITTELY")
	{
		esittely();
	}else if(ohjeet[0] == "AKSIOOMAT")
	{
		aksioomat();
	}
}

/* Hajotin vapauttaa geometrian kekodynaamisten olioiden
muistialueet. */

GeometrianLuonti::~GeometrianLuonti()
{
	delete I;
	delete Pisteet;
	delete Suorat;
}
