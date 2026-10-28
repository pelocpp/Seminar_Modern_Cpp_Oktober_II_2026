// =====================================================================================
// Seminar_02_Referenzen.cpp // Referenzen
// =====================================================================================

#include <algorithm>
#include <list>
#include <print>
#include <vector>

// Leerer Namesraum: Alles hier drinnen ist nur in DIESER Datei verfügbar
namespace {

    void test_01() {

        int wieviel = sizeof(long long);      // 8 Bytes = 8 * 8 = 64 Bits
        int wieviel2 = sizeof(std::size_t);   // 8 Bytes = 8 * 8 = 64 Bits

        // C: Datentyp Pointer
        int n = 123;
        int m = 15;

        // Datentyp: Adresse

        int* emtpy = nullptr;    // freiwillig

        int* ptr = & n;        // &: Address of Operator   // =x10F0  // referenzieren  // hier: & vor einer VARIABLEN

        // Übungsaufgabe: Wert von 999 an n zuweisen, ohne den Variablennamen n zu verwenden
        *ptr = 999;     // indirekte Wertzuweisung // derefenzieren

        // 2. Übungsaufgabe
        ++ptr;   // Geht . Wozu ??? Whyyyyyyyyy // Was steht für ne Adresse in ptr (danach)

        char ch;
        short svar;

        char* ptr_ch = & ch;
        short* ptr_svar = & svar;

        ++ptr_ch;  // intelligentes Inkrement: Nicht um 1 , sondern um sizeof (typ)
        ++ptr_svar;

        // verwenden ptr, ich weiß: Ist - aktuell - eine falsche Adresse

        *ptr = 666;

    }

    void test_02() {

        // C: Datentyp Pointer
        int n = 123;
        int m = 456;


        int x = n & m;   // Alle Bits werden hier ver-UND et

    }

    void test_03() {

        int n = 123;

        int& rn = n;                //  hier: & nach einem DATENTYP (int)

        rn = 456;                   // Einfachere Schreibweise //  *ptr = 456;

        ++rn;                       // KEINE Adress-Arithmetik, sondern Zugriff auf die Variable, die referenziert wird.
    }

    struct Time
    {
        int hours;
        int minutes;
        int seconds;
    };

    void incrementTime(struct Time time)
    {
        // meistens richtig; wenn aktuell seconds den Wert 59 hat: Falsch // Übungsaufgabe
        ++time.seconds;
    }

    void incrementTimeEx(struct Time /*const*/ * time)  // Über die Adresse:  Zutritt zum Original
    {
        // meistens richtig; wenn aktuell seconds den Wert 59 hat: Falsch // 
        
        ++ time->seconds;
    }

    void incrementTimeExEx(struct Time& time)  // Über eine Referenz:  Zutritt zum Original
    {
        // meistens richtig; wenn aktuell seconds den Wert 59 hat: Falsch // 

        ++time.seconds;
    }

    void print (const struct Time& time)  // Über eine Referenz:  Zutritt zum Original
    {

        // Hmm, haben eine Fehler im Algorithmus // bzw. in der Realisierung:
      //  time.seconds = 999;

        int seconds = time.seconds;

        std::println("{:02}:{:02}:{:02}", time.hours, time.minutes, time.seconds);
    }


    void test_04() {
        
        struct Time now { 15, 2, 20 };

        incrementTime(now);

        incrementTimeEx(& now);

        incrementTimeExEx(now);

        print(now);
    }


    void test_05() {

        struct Time now { 15, 2, 20 };

        struct Time copy = now;
    }

}

void main_seminar_02_referenzen()
{
    test_05();
}

// =====================================================================================
// End-of-File
// =====================================================================================
