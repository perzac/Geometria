/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

using namespace std;

#include "Insidenssi.hpp"
#include "Analysoija.hpp"

/* Parametrimuodostin alustaa insidenssin tyhjäksi. */

Insidenssi::Insidenssi(Joukko& Pisteet_par, Joukko& Suorat_par) : Pisteet(Pisteet_par), Suorat(Suorat_par), M((Pisteet.mahtavuus())*(Suorat.mahtavuus())), Imatriisi(M) {}

/* Kutsuu Analysoija-luokan oliota analysoimaan insidenssin määräämän
geometrian ominaisuuksia. */

void Insidenssi::analysoi()
{
	Analysoija tarkastaja = Analysoija(Pisteet.mahtavuus(), Suorat.mahtavuus(), Imatriisi);
	tarkastaja.analysoi();
	tarkastaja.Analysoija::~Analysoija();
}

/* Palauttaa totuusarvon, onko parametreina annettu piste-suora -pari
insidentti. Parin ollessa kuulumaton geometriaan heittää poikkeuksen. */

bool Insidenssi::I(Pistejoukko *P, Pistejoukko *s)
{
	int m = Pisteet.mahtavuus();
	int n = Suorat.mahtavuus();
	
	int i = 0;
	int j = 0;
	
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Luettelo luetteloS = Suorat.annaLuettelo();
	
	if(Pisteet.sisaltaa(P) && Suorat.sisaltaa(s))
	{
		while(luetteloP[i] != P) i++;
		while(luetteloS[j] != s) j++;
	} else throw runtime_error("Piste-suora -pari virheellinen");
	
	return Imatriisi[i*n+j];
}

/* Asettaa parametreina annetun piste-suora -parin insidentiksi.
Parin ollessa kuulumaton geometriaan heittää poikkeuksen. */

void Insidenssi::lisaa(Pistejoukko *P, Pistejoukko *s)
{
	int m = Pisteet.mahtavuus();
	int n = Suorat.mahtavuus();
	
	int i = 0;
	int j = 0;
	
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Luettelo luetteloS = Suorat.annaLuettelo();

	
	if(Pisteet.sisaltaa(P) && Suorat.sisaltaa(s))
	{
		while(luetteloP[i] != P) i++;
		while(luetteloS[j] != s) j++;
	} else throw runtime_error("Piste-suora -pari virheellinen");
	
	Imatriisi[i*n+j] = true;
}

/* Asettaa parametreina annetun piste-suora -parin epäinsidentiksi.
Parin ollessa kuulumaton geometriaan heittää poikkeuksen. */

void Insidenssi::poista(Pistejoukko *P, Pistejoukko *s)
{
	int m = Pisteet.mahtavuus();
	int n = Suorat.mahtavuus();
	
	int i = 0;
	int j = 0;
	
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Luettelo luetteloS = Suorat.annaLuettelo();
	
	if(Pisteet.sisaltaa(P) && Suorat.sisaltaa(s))
	{
		while(luetteloP[i] != P) i++;
		while(luetteloS[j] != s) j++;
	} else throw runtime_error("Piste-suora -pari virheellinen");
	
	Imatriisi[i*n+j] = false;
}

/* Metodissa käyttäjä voi määrätä insidenssin kokonaan. */

void Insidenssi::aseta()
{
	char a;

	int m = Pisteet.mahtavuus();
	int n = Suorat.mahtavuus();
	
	Luettelo luetteloS = Suorat.annaLuettelo();
	Luettelo luetteloP = Pisteet. annaLuettelo();
	
	int i = 0;
	int j = 0;
	
	cout << "\t";
	for(i = 0; i < n; i++)
	{
		luetteloS[i]->nayta();
		cout << "\t";
	}
	cout << endl;

	for(i = 0; i < m; i++)
	{
		luetteloP[i]->nayta();
		cout << "\t";
		for(j = 0; j < n; j++)
		{
			system("stty -echo raw");
			cin >> a;
			system("stty echo cooked");
			if(a == '0') Imatriisi[i*n + j] = false;
			else
			{
				Imatriisi[i*n + j] = true;
				cout << 'X';
			}
			cout << "\t";
		}
		cout << endl;
	}
}

/* Metodissa käyttäjä voi määrätä parametrina annetun pisteen
insidenttiyden kaikkien suorien kanssa. Jos piste ei kuulu
geometriaan, nappaa poikkeuksen. */

void Insidenssi::asetaPiste(Pistejoukko* P)
{
	char a;

	Luettelo luetteloS = Suorat.annaLuettelo();
	Selaaja selaajaS = Suorat.annaSelaaja();


	cout << "\t";
	for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
	{
		(*selaajaS)->nayta();
		cout << "\t";
	}
	cout << endl;

	P->nayta();
	cout << "\t";
	for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
	{
		system("stty -echo raw");
		cin >> a;
		system("stty echo cooked");
		try
		{
			if(a == '0') poista(P, *selaajaS);
			else
			{
				lisaa(P, *selaajaS);
				cout << 'X';
			}
		}
		catch(runtime_error &virhe)
		{
			cerr << virhe.what();
		}
		cout << "\t";
	}
	cout << endl;
}

/* Metodissa käyttäjä voi määrätä parametrina annetun suoran
insidenttiyden kaikkien pisteiden kanssa. Jos suora ei kuulu
geometriaan, nappaa poikkeuksen. */

void Insidenssi::asetaSuora(Pistejoukko *s)
{
	char a;

	Luettelo luetteloP = Pisteet.annaLuettelo();
	Selaaja selaajaP = Pisteet.annaSelaaja();
	
	cout << "\t";
	s->nayta();
	cout << endl;
	
	for(selaajaP = luetteloP.begin(); selaajaP != luetteloP.end(); selaajaP++)
	{
		(*selaajaP)->nayta();
		cout << '\t';
		system("stty -echo raw");
		cin >> a;
		system("stty echo cooked");
		try
		{
			if(a == '0') poista(*selaajaP, s);
			else
			{
				lisaa(*selaajaP, s);
				cout << 'X';
			}
		}
		catch(runtime_error &virhe)
		{
			cerr << virhe.what();
		}
		cout << endl;
	}
}

/* Metodi näyttää, minkä suorien kanssa parametrina annettu piste
on insidentti. Jos piste ei kuulu geometriaan, nappaa poikkeuksen. */

void Insidenssi::suorat(Pistejoukko *P)
{
	Luettelo luetteloS = Suorat.annaLuettelo();
	Selaaja selaajaS = Suorat.annaSelaaja();
	
	for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
	{
		try
		{
			if(I(P, *selaajaS))
			{
				P->nayta();
				cout << 'I';
				(*selaajaS)->nayta();
				cout << ' ';
			}
		}
		catch(runtime_error &virhe)
		{
			cerr << virhe.what();
		}
	}
}

/* Metodi näyttää, minkä pisteiden kanssa parametrina annettu piste
on insidentti. Jos suora ei kuulu geometriaan, nappaa poikkeuksen. */

void Insidenssi::pisteet(Pistejoukko *s)
{
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Selaaja selaajaP = Pisteet.annaSelaaja();
	
	for(selaajaP = luetteloP.begin(); selaajaP != luetteloP.end(); selaajaP++)
	{
		try
		{
			if(I(*selaajaP, s))
			{
				(*selaajaP)->nayta();
				cout << 'I';
				s->nayta();
				cout << ' ';
			}
		}
		catch(runtime_error &virhe)
		{
			cerr << virhe.what();
		}
	}
}

/* Metodi tulostaa insidenssimatriisin. */

void Insidenssi::matriisi()
{
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Luettelo luetteloS = Suorat.annaLuettelo();
	Selaaja selaajaP = Pisteet.annaSelaaja();
	Selaaja selaajaS = Suorat.annaSelaaja();
	
	for(selaajaP = luetteloP.begin(); selaajaP != luetteloP.end(); selaajaP++)
	{
		for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
		{
			cout << I(*selaajaP, *selaajaS) << ' ';
		}
		cout << endl;
	}
}

/* Metodi tulostaa insidenssin näytettynä taulukkona, jossa pisteet
ovat riveinä ja suorat sarakkeina. */

void Insidenssi::taulukko()
{
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Luettelo luetteloS = Suorat.annaLuettelo();
	Selaaja selaajaP = Pisteet.annaSelaaja();
	Selaaja selaajaS = Suorat.annaSelaaja();
	
	cout << "\t";
	for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
	{
		(*selaajaS)->nayta();
		cout << "\t";
	}
	cout << endl;
	
	for(selaajaP = luetteloP.begin(); selaajaP != luetteloP.end(); selaajaP++)
	{
		(*selaajaP)->nayta();
		cout << "\t";
		for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
		{
			if(I(*selaajaP, *selaajaS)) cout << 'X';
			cout << "\t";
		}
		cout << endl;
	}
}

/* Metodi tulostaa insidenssin näytettynä edelliseen nähden
transponoituna taulukkona. */

void Insidenssi::kaannettyTaulukko()
{
	Luettelo luetteloP = Pisteet.annaLuettelo();
	Luettelo luetteloS = Suorat.annaLuettelo();
	Selaaja selaajaP = Pisteet.annaSelaaja();
	Selaaja selaajaS = Suorat.annaSelaaja();
	
	cout << "\t";
	for(selaajaP = luetteloP.begin(); selaajaP != luetteloP.end(); selaajaP++)
	{
		(*selaajaP)->nayta();
		cout << "\t";
	}
	cout << endl;
	
	for(selaajaS = luetteloS.begin(); selaajaS != luetteloS.end(); selaajaS++)
	{
		(*selaajaS)->nayta();
		cout << "\t";
		for(selaajaP = luetteloP.begin(); selaajaP != luetteloP.end(); selaajaP++)
		{
			if(I(*selaajaP, *selaajaS)) cout << 'X';
			cout << "\t";
		}
		cout << endl;
	}
}

/* Metodi päivittää insidenssin, kun geometriaan lisätään tai siitä
poistetaan piste tai suora. Parametri int a on poistettavan alkion
indeksi joukon säiliössä ja -1, kun geometriaan lisätään alkio.
Parametri char k ilmoittaa onko alkio piste ('p') vai suora ('s').
Asiakkaan on kutsuttava metodia poiston tai lisäyksen jälkeen, jotta
indeksit täsmäävät. */

void Insidenssi::paivita(int a, char k)
{
	int m = Pisteet.mahtavuus();
	int n = Suorat.mahtavuus();
	
	if(a == -1)
	{
		if(k == 'p')
		{
			for(int i = 0; i < n; i++)
			{
				Imatriisi.push_back(false);
			}
		}else if (k == 's')
		{
			for(int i = 0; i < m; i++)
			{
				Imatriisi.insert(Imatriisi.begin() + i*n + n - 1, false);
			}
		}
        }else
	{
		if(k == 'p')
		{
			Imatriisi.erase(Imatriisi.begin() + a*n, Imatriisi.begin() + a*n + n);
		}else if(k == 's')
		{
			for(int i = m - 1; i >= 0; i--)
			{
				Imatriisi.erase(Imatriisi.begin() + a + i*(n + 1));	
			}
		}
	}
}
