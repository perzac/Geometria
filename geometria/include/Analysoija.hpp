/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Luokan olio tutkii, mitkä affiinin ja projektiivisen geometrian
aksioomat jäsenmuuttujana olevaa insidenssimatriisia vastaava
geometria toteuttaa. Muodostimen parametreina ovat geometrian
pisteiden ja joukkojen lukumäärät sekä insidenssimatriisi esitettynä
yksiulotteisena totuusarvovektorina (matriisi luettu riveittäin
vasemmalta oikealle ja ylhäältä alas). Toinen kokonaisluvuista
riittäisi selvittämään toisen jakolaskuna matriisin koon avulla,
mutta tämä ratkaisu on mielestäni selkeämpi.

Tarkastettavat aksioomat löytyvät tiedostosta Tekstit/Aksioomat.txt */


#ifndef ANALYSOIJA_HPP_INCLUDED
#define ANALYSOIJA_HPP_INCLUDED

#include <vector>

class Analysoija
{
	private:
		
		const int& m;
		const int& n;
		const std::vector<bool>& M;
		
		bool GEO0();
		bool AP1();
		bool P2();
		bool P3();
		bool A2();
		bool A3();
		
	public:
		
		void analysoi();
		
		Analysoija(const int& m_p, const int& n_p, const std::vector<bool>& M_p);
		virtual ~Analysoija(){}
};

#endif // ANALYSOIJA_HPP_INCLUDED
