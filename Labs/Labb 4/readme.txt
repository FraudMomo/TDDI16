/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt):

/**********************************************************************
 * Empirisk analys
 *
 * Fyll i tabellen nedan med riktiga k�rtider i sekunder n�r det k�nns
 * vettigt att v�nta p� hela ber�kningen.
 * Ge uppskattningar av k�rtiden (baserat p� tidskomplexiteten)
 * i �vriga fall.
 *
 **********************************************************************/
    
      N       brute           sortering
 ----------------------------------
    150       4ms             12ms
    200       16ms            23ms
    300       51ms            34ms
    400       82ms            50ms
    800       500ms           160ms
   1600       3902ms          596ms
   3200       30765ms         2192ms
   6400       1000000000ms    9721ms
  12800       160000000000ms  40539ms


/**********************************************************************
 * Teoretisk analys
 *
 * Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som en funktion
 * av N. Ge en kort motivering.
 *
 * Matchar brute-l�sningen sitt v�rstafall i praktiken, eller har den
 * ett medelfall som �r b�ttre?
 *
 **********************************************************************/

Brute: Som värst if sats sann =>  O(N^4) (fyra loops)

Sortering: O(N^2)


/**********************************************************************
 * Energianv�ndning
 *
 * Antag att du anv�nder m�nsterigenk�nningsprogrammet f�r att analysera
 * data fr�n en kamera. Kameran sitter i en byggnad och tar en bild
 * p� stommen av byggnaden var 30:e minut. Bilden f�rbehandlas sedan
 * lite, innan punkter som representerar stommen skickas till
 * m�nsterigenk�nningsprogrammet. Hittas inte tillr�ckligt m�nga raka
 * linjer s� betyder det att n�got h�ller p� att g� s�nder, och
 * att byggnaden beh�ver noggrannare inspektion.
 *
 * Hur mycket energi sparar du p� ett �r om du anv�nder din snabbare
 * sorteringsl�sning i st�llet f�r brute-l�sningen? Du kan anta f�ljande:
 * - Systemet k�rs 24/7 under hela �ret.
 * - Inget annat k�rs p� det h�r systemet.
 * - Systemet drar 8 W n�r det inte g�r n�got (idle)
 * - Systemet drar 36 W n�r det arbetar (med 1 k�rna)
 * - R�kna med att ditt program k�rs var 30:e minut (= 2 g�nger/timme)
 * - F�r- och efterbehandling �r snabba, s� vi kan bortse fr�n dem
 * - Indata till programmet inneh�ller ca 6400 punkter
 * - Det �r inte skott�r (= 365 dagar)
 *
 * Att j�mf�ra med drar en kombinerad kyl/frys ca 200 kWh per �r
 * (enligt Energimyndigheten).
 *
 * Kom ih�g: energi m�ts ofta i kWh, vilket �r:
 *  energi (kWh) = effekt (kW) * tid (h)
 *
 * Tips: ett s�tt att r�kna p� �r att f�rst r�kna f�rbrukningen av
 * ett system som inte g�r n�got p� ett helt �r, sedan l�gga till
 * den extra f�rbrukningen (36 W - 8 W = 28 W) f�r tiden som systemet
 * �r aktiv.
 *
 * (Siffrorna �r l�st baserade p� en Intel i9-9900K, vi r�knar bara p�
 * CPU:n f�r enkelhets skull, besparingarna blir sannolikt st�rre om
 * vi r�knar p� st�rre delar av systemet, �ven om andra komponenter
 * ocks� drar str�m i "idle".)
 *
 **********************************************************************/

F�rbrukning av brute p� ett �r: ? kWh

F�rbrukning av sotering p� ett �r: ? kWh

Skillnad: ? kWh



idle: 8 W
running: 36 W (1 core)
2 ggr/h
6400 punkter        1000000000ms    9721ms
365 dagar
energi (kwh) = effekt (kW) * tid (h)

sortering: 9721 