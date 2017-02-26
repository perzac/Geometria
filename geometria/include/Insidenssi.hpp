/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Luokan oliot ovat insidenssirelaatioita eli geometrian pisteiden
joukon ja suorien joukon karteesisen tulon osajoukkoja. Relaatio
on esitetty jäsenmuuttujana olevan matriisin karakterisoimana.
Matriisi on toteutettu totuusarvovektorina, johon matriisi on
luettu riveittäin vasemmalta oikealle ja ylhäältä alas.

Luokan metodit mahdollistavat relaation muokkaamisen ja esittämisen
sekä yksittäisen piste-suora -parin insidenssin selvittämisen.

Parametrimuodostimen parametreina annetaan pisteden ja suorien
joukot. */


#ifndef INSIDENSSI_HPP_INCLUDED
#define INSIDENSSI_HPP_INCLUDED

#include "geometria/Piste.hpp"
#include "geometria/Joukko.hpp"
#include <vector>

class Insidenssi
{
	public:
		
		typedef class Piste Suora;
		typedef std::vector<Pistejoukko*> Luettelo;
		typedef std::vector<Pistejoukko*>::iterator Selaaja;
		
	private:
		
		Joukko &Pisteet;
		Joukko &Suorat;
		
		int M;
		std::vector<bool> Imatriisi;
		
	public:
		
		Insidenssi(Joukko&, Joukko&);
		virtual ~Insidenssi(){}

		void analysoi();
		
		bool I(Pistejoukko*, Pistejoukko*);
		void lisaa(Pistejoukko*, Pistejoukko*);
		void poista(Pistejoukko*, Pistejoukko*);
		void aseta();
		void asetaPiste(Pistejoukko*);
		void asetaSuora(Pistejoukko*);
		
		void suorat(Pistejoukko*);
		void pisteet(Pistejoukko*);
		void matriisi();
		void taulukko();
		void kaannettyTaulukko();

		void paivita(int, char);
};

#endif // INSIDENSSI_HPP_INCLUDED
