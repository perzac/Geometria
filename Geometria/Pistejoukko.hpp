/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Rekursiokooste-mallin kantaluokka */


#ifndef PISTEJOUKKO_HPP_INCLUDED
#define PISTEJOUKKO_HPP_INCLUDED

class Pistejoukko
{
	public:
		
		virtual void nayta() = 0;
		virtual std::string annaNimi() = 0;
		
		virtual void lisaa(Pistejoukko*) = 0;
		virtual void poista(Pistejoukko*) = 0;
		virtual ~Pistejoukko(){}
};

#endif // PISTEJOUKKO_HPP_INCLUDED
