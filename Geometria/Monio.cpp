/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#include "Monio.hpp"

/* Muodostin alustaa käytettävän tietosäiliön. */

Monio::Monio()
{
	l = luettelo();
}

/* Tulostaa aaltosulkujen sisään rekursiivisesti lapsensa.
Joukko-opista tuttu notaatio. */

void Monio::nayta()
{
	luettelo::iterator selaaja;
	
	cout << "{";	
	if(l.size() > 0)
	{
		for(selaaja = l.begin(); selaaja + 1 != l.end(); selaaja++)
		{
			(*selaaja)->nayta();
			cout << ", ";
		}
		(*selaaja)->nayta();
	}
	cout << "}";
}

/*Monio-oliot ovat nimettömiä. Asiakkaat pärjäävät sisällön nimillä. */

std::string Monio::annaNimi()
{
	return "";
}

/* Ei tarkasta sisältöä duplikaattien varalta. */

void Monio::lisaa(Pistejoukko *p)
{
	l.push_back(p);
}

/* Poistaa poistettavan olion ensimmäisen esiintymän. */

void Monio::poista(Pistejoukko *p)
{
	if(l.size() > 0)
	{
		luettelo::iterator selaaja;
		for(selaaja = l.begin(); selaaja != l.end(); selaaja++)
		{
			if(*selaaja == p) l.erase(selaaja);
		}
	}
}
