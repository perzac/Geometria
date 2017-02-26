### Geometria

Tämä repositorio sisältää opiskeluaikaisen harjoitustyöni lähdetiedostot sekä muut tarvittavat tiedostot. Makefilet olen tehnyt myöhemmin. Hakemisto `Geometria` sisältää työn sellaisena, ettei se tarvitse kuin tämän hakemiston. Hakemisto `geometria` sisältää työn jäsenneltynä, ja siellä oleva `makefile` sijoittaa tiedostot mukavasti kotihakemiston alihakemistoihin.  Alla työn kuvaus.

#####Kuvaus

Tässä työssä olen toteuttanut joukko-opin perusrelaatioineen
ja -operaatioineen. Tämän sovelluksena olen tehnyt ohjelman,
joka tutkii muodostetun äärellisen geometrian ominaisuuksia.
Joukko-opin pohjan toteuttamisessa olen käyttänyt
rekursiokooste-suunnittelumallia luomaan ominaisuudettomien
pisteiden ja niitä sekä toisiaan sisältävien koosteiden
hierarkian. Joukko-opin relaatioiden ja operaatioiden
lukumäärä on kuitenkin siksi korkea, että ei ole
tarkoituksenmukaista liittää kaikkia näitä
rekursiokooste-mallin käyttäjärajapintaan. Siksi olen
muodostanut tämän rakenteen koosteolioiden luokan perivän
aliluokan, jonka metodeina ovat joukko-opin relaatiot ja
operaatiot.

Geometrian toteuttamiseksi tarvitaan myös
insidenssirelaatio. Sen olen toteuttanut omana luokkanaan,
jonka jäsenmuuttujina on aikaisemmin toteuttamani rakenteen
joukkoja ja joka käyttää hyväkseen rekursiokooste-mallin
mukaan toteutettujen luokkien palveluita. Jotta ohjelman
käyttäminen toisi jotain lisäarvoa paperilla tehtävään
työhön nähden, olen tehnyt luokan, jonka oliot tarkastavat,
mitkä affiinin ja projektiivisen geometrian aksioomat
toteutuvat annetussa geometriassa.

Kaikkien toteutettujen luokkien ja niiden palveluiden
käyttämiseeen geometrian luomiseksi olen mukaillut "GoF":n
esittelemää julkisivu-suunnittelumallia. Olen kuitenkin
yhdistänyt tämän julkisivun käyttöliittymään, joten muiden
luokkien on vaikea käyttää sitä hyväksi. Mikäli geometrian
luomista halutaan käyttää toisista luokista, on vain
muutettava tekemäni luokan metodeitten näkyvyysmääreitä,
jolloin luokka toimisi julkisivu-mallin tarkoittamalla
tavalla.

Tiedosto Tekstit/Fanon_taso.txt sisältää merkkijonon, jolla
ajettuna ohjelma muodostaa ns. Fanon tason eli pienimmän
projektiivisen geometrian.
