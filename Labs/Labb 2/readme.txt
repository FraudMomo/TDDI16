/**********************************************************************
 *  Knäcka lösenord readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt):

/**********************************************************************
 *  Ge en högnivåbeskrivning av ditt program decrypt.c.
 **********************************************************************/
Först loopar vi igenom alla möjliga kombinationer av första halvan av
tabellen. Sedan, för andra halvan, använder vi uppslagning i hashtabellen
för att få fram andra delen. Till sist slår vi ihop dem och skriver ut
resultatet.

/**********************************************************************
 *  Beskriv symboltabellen du använt för decrypt.c.
 **********************************************************************/
Symboltabellen vi använde var en unordered_map.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver         10 bokstäver
-----------         ------------
congrats            completely
youfound            unbreakabl
theright            cryptogram
solution            ormaybenot

/****************************************************************************
 *  Hur lång tid använder brute.c för att knäcka lösenord av en viss storlek?
 *  Ge en uppskattning (baserad på tidskomplexiteten)  markerad med en asterisk
 *  om det tar längre tid än vad du orkar vänta. Ge en kort motivering för
 *  dina uppskattningar.
 ***************************************************************************/


Char     Brute     
--------------
 4       0
 5       3
 6       144
 8       *256


/******************************************************************************
 *  Hur lång tid använder decrypt.c för att knäcka lösenord av en viss storlek?
 *  Hur mycket minne använder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6       0                 32kb
8       1                 1mb
10      43                2.8gb
12      *2048             *25gb

/*************************************************************************
 * Hur många operationer använder brute.c för ett N-bitars lösenord?
 * Hur många operationer använder din decrypt.c för ett N-bitars lösenord?
 * Använd ordo-notation.
 *************************************************************************/
O(2^N) för brute och O(2^N/2) för decrypt.


/*************************************************************************
 * Vilka egenskaper skulle ni leta efter i en hashfunktion för att
 * försäkra er om att den är "säker"?
 *************************************************************************/
En hashfunktion som är kryptografisk och svår att knäcka, istället för en
som är snabb, ex. SHA-3 eller Blowfish.