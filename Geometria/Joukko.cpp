/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#include "Joukko.hpp"

/* Palauttaa asiakkaalle joukon alkioiden säiliön selaamista varten.
Säiliö ei ole asiakkaiden muutettavissa. */

const Monio::luettelo Joukko::annaLuettelo()
{
	return l;
}

/* Halutessaan asiakas saa joukon säiliön selaajan suoraan luokalta
tällä metodilla. */

const Monio::luettelo::iterator Joukko::annaSelaaja()
{
	luettelo::iterator selaaja;
	return selaaja;
}

/* Palauttaa joukon mahtavuuden */

int Joukko::mahtavuus()
{
	return l.size();
}

/* Lisää joukkoon parametrina annetun alkion tarkastettuaan sen
duplikaattien varalta. */

void Joukko::lisaa(Pistejoukko *p)
{
	bool kuuluu = false;
	
	if(l.size() > 0)
	{
		luettelo::iterator selaaja;
		for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
		{
			if(p != *selaaja) continue;
			kuuluu = true;
			break;
		}
	}
	
	if(!kuuluu) l.push_back(p);
}

/* Poistaa parametrina annetun alkion joukosta. */

void Joukko::poista(Pistejoukko *p)
{
	if(l.size() > 0)
	{
		luettelo::iterator selaaja;
		for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
		{
			if(p == *selaaja)
			{
				l.erase(selaaja);
				break;
			}
		}
	}
}

/* Palauttaa totuusarvon, sisältyykö parametrina annettu alkio
joukkoon. */

bool Joukko::sisaltaa(Pistejoukko *p)
{
	bool sisaltaa = false;
	
	if(l.size() > 0)
	{
		luettelo::iterator selaaja;
		for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
		{
			if((*selaaja) == p)
			{
			sisaltaa = true;
			break;
			}
		}
	}
	return sisaltaa;
}

/* Palauttaa totuusarvon, onko joukko parametrina annetun joukon
osajoukko. */

bool Joukko::osajoukko(Joukko *j)
{
	if(mahtavuus() == 0) return true;
	
	luettelo::iterator selaaja;
	for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
	{
		if(!(j->sisaltaa(*selaaja))) return false;
	}
	
	return true;
}

/* Palauttaa totuusarvon, onko joukko parametrina annetun joukon kanssa
joukko-opillisesti sama. */

bool Joukko::sama(Joukko *j)
{
	if((this->mahtavuus() == j->mahtavuus()) && (this->osajoukko(j))) return true;
	else return false;
}

/* Palauttaa joukon ja parametrina annetun joukon yhdisteen
kekodynaamisena Joukko-oliona */

Joukko* Joukko::yhdiste(Joukko *j)
{
	Joukko *yhdiste = new Joukko();
	
	luettelo::iterator selaaja;
	for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
	{
		yhdiste->lisaa(*selaaja);
	}
	for(selaaja = (j->l).begin(); selaaja != (j->l).end(); selaaja++)
	{
		yhdiste->lisaa(*selaaja);
	}
	
	return yhdiste;
}

/* Palauttaa joukon ja parametrina annetun joukon leikkauksen
kekodynaamisena Joukko-oliona */

Joukko* Joukko::leikkaus(Joukko *j)
{
	Joukko *leikkaus = new Joukko();
	
	luettelo::iterator selaaja;
	for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
	{
		if(j->sisaltaa(*selaaja)) leikkaus->lisaa(*selaaja);
	}
	
	return leikkaus;
}

/* Palauttaa joukon ja parametrina annetun joukon erotuksen
kekodynaamisena Joukko-oliona */

Joukko* Joukko::pois(Joukko *j)
{
	Joukko *erotus = new Joukko();
	
	luettelo::iterator selaaja;
	for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
	{
		if(!(j->sisaltaa(*selaaja))) erotus->lisaa(*selaaja);
	}
	
	return erotus;
}

/* Palauttaa osoittimen parametrina annetun nimiseen joukon alkioon.
Mikäli nimeä ei löydy, heittää poikkeuksen. */

Pistejoukko* Joukko::osoita(std::string nimi)
{
	luettelo::iterator selaaja;
	for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
	{
		{
			if((*selaaja)->annaNimi() == nimi) return *selaaja;
		}
	}
	
	string virhe = "Nimen " + nimi + " vastinosoitetta ei löytynyt.";
	throw runtime_error(virhe);
}
