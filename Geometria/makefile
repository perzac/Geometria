CC=g++

all: geometria

geometria: Paa.o GeometrianLuonti.o Joukko.o Monio.o Piste.o Insidenssi.o Analysoija.o
	$(CC) -o geometria Paa.o GeometrianLuonti.o Joukko.o Monio.o Piste.o Insidenssi.o Analysoija.o

Paa.o: Paa.cpp GeometrianLuonti.hpp
	$(CC) -c Paa.cpp

GeometrianLuonti.o: GeometrianLuonti.cpp GeometrianLuonti.hpp
	$(CC) -c GeometrianLuonti.cpp

Joukko.o: Joukko.cpp Joukko.hpp
	$(CC) -c Joukko.cpp

Monio.o: Monio.cpp Monio.hpp
	$(CC) -c Monio.cpp

Piste.o: Piste.cpp Piste.hpp
	$(CC) -c Piste.cpp

Insidenssi.o: Insidenssi.cpp Insidenssi.hpp Analysoija.hpp
	$(CC) -c Insidenssi.cpp

Analysoija.o: Analysoija.cpp Analysoija.hpp
	$(CC) -c Analysoija.cpp

clean:
	rm *.o geometria

