/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Joukko-opin joukot toteuttava luokka. Perii pistejoukko-rakenteen
koosteolioiden luokan, mutta ei itse ole varsinaisesti
rekursiokooste-suunnittelumallin osallistuja. Luokan oliot ovat
joukkoja, joiden alkioina voi olla joko pistejoukko-rakenteen
olioita tai toisia joukkoja. Semanttisesti olisi järkevää olla
käyttämättä Monio-luokan olioita joukko-opissa. */


#ifndef JOUKKO_HPP_INCLUDED
#define JOUKKO_HPP_INCLUDED

#include "geometria/Monio.hpp"

class Joukko : public Monio
{
	public:	
		
		const Monio::luettelo annaLuettelo();
		const Monio::luettelo::iterator annaSelaaja();

		void lisaa(Pistejoukko*);
		void poista(Pistejoukko*);

		int mahtavuus();
		
		bool sisaltaa(Pistejoukko*);
		bool osajoukko(Joukko*);
		bool sama(Joukko*);
		Joukko* yhdiste(Joukko*);
		Joukko* leikkaus(Joukko*);
		Joukko* pois(Joukko*);
		
		Pistejoukko* osoita(std::string);
		
		virtual ~Joukko(){}
};

#endif // JOUKKO_HPP_INCLUDED
