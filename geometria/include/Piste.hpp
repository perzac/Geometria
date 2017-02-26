/* Pekko P---------------------------------
 *
 * -------------------------, harjoitustyö */

/*  Rekursiokooste-mallin primitiivien luokka. Luokan oliot ovat
joukko-opista tuttuja ominaisuudettomia alkioita. Nimi-muuttuja
on asiakkaiden tarpeita varten. */


#ifndef PISTE_HPP_INCLUDED
#define PISTE_HPP_INCLUDED

#include <string>

#include "geometria/Pistejoukko.hpp"

class Piste : public Pistejoukko
{
		std::string nimi;
		
	public:
		
		void nayta();
		std::string annaNimi();
		
		void lisaa(Pistejoukko*);
		void poista(Pistejoukko*);
		
		Piste(std::string);
		virtual ~Piste(){}
};

#endif // PISTE_HPP_INCLUDED
