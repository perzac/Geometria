/* Pekko P---------------------------------
 * 
 * -------------------------, harjoitustyö */

#include <iostream>
#include <vector>

using namespace std;

#include "geometria/Analysoija.hpp"

/* Parametrimuodostin */

Analysoija::Analysoija(const int& m_p, const int& n_p, const std::vector<bool>& M_p) : m(m_p), n(n_p), M(M_p) {}

/* Luokan julkinen metodi, joka tulostaa jäsenmuuttujageometrian
ominaisuudet. */

void Analysoija::analysoi()
{
	int i = -1;
	
	if(!GEO0());
	else if(!AP1()) i = 0;
	else if(!P2())
	{
		if(!A2()) i = 1;
		else if(!A3()) i = 4;
		else i = 5;
	} else if(!P3())
	{
		if(!A3()) i = 2;
		else i = 6;
	}
		else i = 3;
		
	cout << "\n\t";
	
	switch(i)
	{
		case -1: cout << "Geometriasi ei ole vielä geometria.";
		break;

		case 0: cout << "Geometriasi on geometria.";
		break;

		case 1: cout << "Geometriasi toteuttaa aksiooman\n\n\t\tAP1.";
		break;

		case 2: cout << "Geometriasi toteuttaa aksioomat\n\n\t\tAP1 ja P2.";
		break;

		case 3: cout << "Geometriasi on projektiivinen geometria.";
		break;

		case 4: cout << "Geometriasi toteuttaa aksioomat\n\n\t\tAP1 ja A2.";
		break;

		case 5: cout << "Geometriasi on affiini geometria.";
		break;
		
		case 6: cout << "Geometriasi toteuttaa aksioomat\n\n\t\tAP1, P2 ja A3.";
		break;
	}
	
	cout << "\n" << endl;
}

/* Yksityinen metodi, joka palauttaa totuusarvon, toteutuuko
"geometria-aksiooma" GEO0. */

bool Analysoija::GEO0()
{
	for(int i = 0; i < m - 1; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(M[i*n + k] && M[j*n + k]) break;
				if(k == n - 1) return false;
			}
		}
	}
	return true;
}

/* Yksityinen metodi, joka palauttaa totuusarvon, toteutuuko
aksiooma AP1. */

bool Analysoija::AP1()
{
	for(int i = 0; i < m - 1; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			int lkm = 0;
			for(int k = 0; k < n; k++)
			{
				if(M[i*n + k] && M[j*n + k]) lkm++;
			}
			if(lkm != 1) return false;
		}
	}
	return true;
}

/* Yksityinen metodi, joka palauttaa totuusarvon, toteutuuko
aksiooma P2. */

bool Analysoija::P2()
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int lkm = 0;
			for(int k = 0; k < n; k++)
			{
				if(M[k*n + i] && M[k*n + j]) lkm++;
			}
			if(lkm != 1) return false;
		}
	}
	return true;
}

/* Yksityinen metodi, joka palauttaa totuusarvon, toteutuuko
aksiooma P3. */

bool Analysoija::P3()
{
	if(m < 4) return false;

	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			for(int k = j + 1; k < m; k++)
			{
				bool ekakolme = false;
				for(int l = 0; l < n; l++)
				{
					if(M[i*n + l] && M[j*n + l] && M[k*n + l]) break;
					if(l == n - 1) ekakolme = true;
				}
				if(ekakolme)
				{
					bool tokakolme = false;
					bool kolmaskolme = false;
					bool nelikolme = false;
					for(int o = k + 1; o < m; o++)
					{
						for(int l = 0; l < n; l++)
						{
							if(M[i*n + l] && M[j*n + l] && M[o*n + l]) break;
							if(l == n - 1) tokakolme = true;
						}
						if(tokakolme)
						{
							for(int l = 0; l < n; l++)
							{
								if(M[i*n + l] && M[k*n + l] && M[o*n + l]) break;
								if(l == n - 1) kolmaskolme = true;
							}
							if(kolmaskolme)
							{
								for(int l = 0; l < n; l++)
								{
									if(M[j*n + l] && M[k*n + l] && M[o*n + l]) break;
									if(l == n - 1) nelikolme = true;
								}
								if(nelikolme) return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

/* Yksityinen metodi, joka palauttaa totuusarvon, toteutuuko
aksiooma A2. */

bool Analysoija::A2()
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(M[i*n + j]) continue;
			int lkm1 = 0;
			for(int k = 0; k < n; k++)
			{
				if(k == j) continue;
				int lkm2 = 0;
				if(!M[i*n + k]) continue;
				for(int l = 0; l < m; l++)
				{
					if(M[l*n + j] && M[l*n + k]) lkm2++;
				}
				if(lkm2 == 0) lkm1++;
			}
			if(lkm1 != 1) return false;
		}
	}
	return true;
}

/* Yksityinen metodi, joka palauttaa totuusarvon, toteutuuko
aksiooma A3. */

bool Analysoija::A3()
{
	if(m < 3) return false;

	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			for(int k = 0; k < m; k++)
			{
				for(int l = 0; l < n; l++)
				{
					if(M[i*n + l] && M[j*n + l] && M[k*n + l]) break;
					if(l == n-1) return true;
				}
			}
		}
	}
	return false;
}
