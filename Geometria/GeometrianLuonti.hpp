/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Tämä luokka toteuttaa käyttöliittymän ja toiminnallisuuden,
jolla muiden luokkien apuna saadaan geometrian toteuttava
ohjelma. Muuttamalla yksityiset metodit julkisiksi tämä luokka
toimisi julkisivu-suunnittelumallin julkisivuluokkana. */

#ifndef GEOMETRIANLUONTI_HPP_INCLUDED
#define GEOMETRIANLUONTI_HPP_INCLUDED

#include <string>

#include "Piste.hpp"
#include "Joukko.hpp"
#include "Insidenssi.hpp"

class GeometrianLuonti
{
	private:
		
		Joukko *Pisteet;
		Joukko *Suorat;
		Insidenssi *I;
		
		void neuvo();
		void esittely();
		void aksioomat();
		void esimerkki();
		
		void piste(std::string);
		void suora(std::string);
		void poista_piste(std::string);
		void poista_suora(std::string);
		void pisteet();
		void suorat();
		
		void tulkitse(std::string);
		
	public:
		
		void aloita();
		
		GeometrianLuonti();
		virtual ~GeometrianLuonti();
};

#endif // GEOMETRIANLUONTI_HPP_INCLUDED
