/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

/* Pääohjelma aloittaa geometrian luomisen ja loppuu,
kun geometrian luominen loppuu. */

#include "geometria/GeometrianLuonti.hpp"

int main()
{
	GeometrianLuonti geo = GeometrianLuonti();
	geo.aloita();

	return 0;
}
