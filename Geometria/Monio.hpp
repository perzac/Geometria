/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Rekursiokooste-mallin mukainen yhdistelmäolioiden luokka.
Pystyy säilömään muita rakenteen olioita. Ei ole kuitenkaan
vielä joukko-opin mukainen joukko, koska duplikaatit ovat
mahdollisia. Poista-metodi poistaa moniosta luettelossa
ensimmäisenä olevan ilmentymän. Monio-olioilla ei ole nimeä,
ja nayta-metodi tulostaa sisällön, joka voi koostua piste- ja
monio-olioista. */


#ifndef MONIO_HPP_INCLUDED
#define MONIO_HPP_INCLUDED

#include <string>
#include <vector>

#include "Pistejoukko.hpp"

class Monio : public Pistejoukko
{
	public:
		
		typedef std::vector<Pistejoukko*> luettelo;
	
	protected:
		
		luettelo l;
		
	public:	
		
		void nayta();
		std::string annaNimi();
		
		void lisaa(Pistejoukko*);
		void poista(Pistejoukko*);
		
		Monio();
		virtual ~Monio(){}
};

#endif // MONIO_HPP_INCLUDED
