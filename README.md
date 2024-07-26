#Blackjack
--------------

##Sisällysluettelo
*Johdanto
*Ominaisuudet
*Asennus

##Johdanto
........
-Tämä projekti on konsolipohjainen blackjack-peli, toteutettu C++-kielellä. Pelissä pelaaja pelaa Blackjack jakajaa vastaan perinteisten sääntöjen mukaisesti.

##Ominaisuudet
*Pelaaja vs. jakaja.
*Blackjackin perussäännöt
*Pelihistorian tallennus JSON-tiedostoon.
*Pistetaulun ja tulosten näyttö.
*Pistetaulun ja tulosten näyttö
*Uudelleenpeluu ja lopetusvaihtoehdot

##Asennus

###Vaatimukset:
-C++ kääntäjä, joka tukee C++11 tai uudempaa(esimerkiksi g++, Visual Studio)

###Ohjeet:
1. Kloonaa repositorio:
-git clone https://github.com/Lentokone/Blackjack.git

Siirry projektikansioon.
-cd Blackjack

Rakenna projekti
-g++ -std=c++11 -o Blackjack Blackjack.cpp Deck.cpp Card.cpp Game.cpp Player.cpp Dealer.cpp

Tai suorita build.bat
-build.bat

(Jos ei onnistu rakentaminen, niin siellä on valmiiksi tehty Blackjack_final.exe)
-Blackjack_final.exe



##Käyttö
###Pelin käynnistäminen

Kun projekti on rakennettu, suorita suoritettava tiedosto:
-Blackjack.exe
###Komennot
[1] Play game: Aloittaa pelin
[2] Look at previous games: Näyttää pelihistorian
[q] Quit: Sulkee pelin

Kun aloittaa pelin, tulee seuraavat valinnat.
[1] Hit: Ota toinen kortti.
[2] Stand: Lopeta vuorosi.
[3] Show hand: Näytä nykyinen käsi ja pisteet.
[q] Quit: Poistu pelistä.

Kun valitsee "Look at previous games", tulee seuraavat valinnat
[1] Show history: Näyttää pelihistorian
[2] Clear history: Tyhjentää pelihistorian
[3] Go back: Menee takaisin päävalikkoon

Kun blackjack peli loppuu, tulee seuraavat.
[1] Play again: Aloittaa uuden pelin.
[2] Quit: Lopettaa ja siirtyy takaisin päävalikkoon.

##Peliohjeet
-Peli noudattaa standardeja Blackjack-sääntöjä.
-Tavoitteena on saada käden arvo mahdollisimman lähelle 21:tä ylittämättä sitä.
-Kuvakortit (Jätkä, Kuningatar, Kuningas) ovat arvoltaan 10 pistettä, ja ässä voi olla 1 tai 11 pistettä.
-Jakajan täytyy ottaa kortteja, kunnes hänen kätensä arvo on vähintään 17.

##Tunnetut ongelmat
-Varmista, että json.hpp-tiedosto on projektihakemistossa JSON-operaatioita varten.
-Peli saattaa kaatua, jos annetaan virheellisiä syötteitä. Käsittele syötteet huolellisesti.

##Tekijä
-Lentokone