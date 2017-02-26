CC=g++

BIN = ${HOME}/bin

INC = ${HOME}/include/geometria
SEARCH_PATH = ${HOME}/include

OBJ = ${HOME}/lib/geometria

DATA = ${HOME}/var/lib/geometria

USEDIRS = $(BIN) $(INC) $(OBJ) $(DATA)

SRCS = Paa GeometrianLuonti Joukko Monio Piste Insidenssi Analysoija
HDRS = GeometrianLuonti Joukko Monio Piste Pistejoukko Insidenssi Analysoija
FILS = Aksioomat Esittely Fanon_taso Ohje

OBJS = $(foreach SRC, $(SRCS), $(OBJ)/$(SRC).o)
INCS = $(foreach HDR, $(HDRS), $(INC)/$(HDR).hpp)
TXTS = $(foreach FIL, $(FILS), $(DATA)/$(FIL).txt)

TRG = $(BIN)/geometria

all: $(TRG)

.SECONDARY: $(OBJS) $(INCS) $(TXTS) $(USEDIRS)
.PHONY: $(USEDIRS) clean

$(TRG): $(USEDIRS) $(TXTS) $(INCS) $(OBJS)
	$(CC) -o $(TRG) $(OBJS)

$(USEDIRS):
	mkdir -p $@

$(TXTS): $(DATA)
	for FIL in $(FILS); \
	do \
		cp data/$${FIL}.txt $(DATA)/$${FIL}.txt; \
	done

$(INCS): $(INC)
	for HDR in $(HDRS); \
	do \
		cp include/$${HDR}.hpp $(INC)/$${HDR}.hpp; \
	done

Paa.o: Paa.cpp GeometrianLuonti.hpp
GeometrianLuonti.o: GeometrianLuonti.cpp GeometrianLuonti.hpp
Joukko.o: Joukko.cpp Joukko.hpp
Monio.o: Monio.cpp Monio.hpp
Piste.o: Piste.cpp Piste.hpp
Insidenssi.o: Insidenssi.cpp Insidenssi.hpp Analysoija.hpp
Analysoija.o: Analysoija.cpp Analysoija.hpp

$(OBJ)/%.o: src/%.cpp
	$(CC) -c -I$(SEARCH_PATH) -o $@ $<

clean:
	rm $(TRG) $(OBJS) $(INCS) $(TXTS); \
	rmdir $(INC) $(OBJ) $(DATA)
