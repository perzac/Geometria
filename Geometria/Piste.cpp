/* Pekko P--------------------------------
 * 
 * -------------------------, harjoitustyö */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#include "Piste.hpp"

/* Rekursiokooste-mallin mukainen operaatio. Tällä saadaan
tulostettua Pistejoukko-rakenteen olioiden sisältö. */

void Piste::nayta()
{
	cout << nimi;
}

/* Käytännön vaatimusten mukainen ominaisuus. Asiakkaiden on
joissain tilanteissa saatava jotain olion identifioivaa dataa.
Pysyäksemme uskollisina pisteiden ominaisuudettomuudelle identifioiva
data ja olion tunnus on eroteltu. Nimellä ei ole tekemistä olion
olemuksen kanssa. */

std::string Piste::annaNimi()
{
	return nimi;
}

void Piste::lisaa(Pistejoukko* p)
{
	throw runtime_error("Pisteeseen ei voi lisätä.");
}

void Piste::poista(Pistejoukko* p)
{
	throw runtime_error("Pisteestä ei voi poistaa.");
}

/* Muodostimessa annetaan nimi parametrina. */

Piste::Piste(std::string nimi_par)
{
	nimi = nimi_par;
}
