// =====================================================================================
// Seminar_04_Rule_Of_Three.cpp // Referenzen
// =====================================================================================

#include <cstddef>
#include <algorithm>
#include <print>
#include <vector>

// Ist flach kopierbar // hat keinen Kopier-Konstruktor
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

class Dangerous
{
public:
    int* m_ptr;

    Dangerous()    // default - c'tor
        : m_ptr{ new int[10] }
    {}

    ~Dangerous() {
        delete[] m_ptr;
    }

    // Kopier-Konstruktor
    Dangerous(const Dangerous& other) {
        m_ptr = new int[10];   // Geht, ist keine Kopie: Sorry, ist nur ein Beispiel
    }
};


//
void test_copy_stl()
{
    std::vector<Dangerous> values =
    {
        {},
        {}
    };

    // Hier wird von alles Objekten im Container der Kopier-Konstruktor
    std::vector<Dangerous> copy = values;
}



class ExclusiceBigData
{
public:
    ExclusiceBigData() {
        values = { 1, 2, 3 };
    }

    // no copy or assignment
    ExclusiceBigData(const ExclusiceBigData& other) = default;
    ExclusiceBigData& operator = (const ExclusiceBigData& other) = delete;

private:  // STL
    std::vector<int> values;
};

void test_copy()
{
    ExclusiceBigData data;
    ExclusiceBigData data2 = data;    //  Kopieren
}


class BigData
{
public:
    // Default Konstruktor
    BigData() 
        : m_data{ nullptr }, m_size{}
    {}

    // Kopier-Konstruktors  MUST (II)
    BigData(const BigData& other) {

        // von other in this eine Kopie erstellen

        m_size = other.m_size;

        m_data = new int[other.m_size];

        // nur zur leichten Lesbarkeit
        for (std::size_t i = 0; i != other.m_size; ++i) {
            m_data[i] = other.m_data[i];
        }

        // besser
        // std::copy(other.m_data, other.m_data + other.m_size, m_data);  
    }

    // Destruktor:  MUST (I)
    ~BigData() {
        std::println("d'tor");
        delete[] m_data;   // array - delete
    }  

    BigData(std::size_t size) {

        m_data = new int[size];   // array - new
        m_size = size;

        std::fill(m_data, m_data + m_size, 0);        
    }

    // Operatoren MUST (III) - Wertzuweisungs Operator
    BigData& operator = (const BigData& other) {

        // Vergleich von Adressen (!)
        if (this != &other) {

            // a) release left side // nullptr is compatible with delete
            delete[] m_data;

            // b) allocate a new buffer 
            m_data = new int[other.m_size];

            // c) copy right-side to left-side
            for (std::size_t i = 0; i != other.m_size; ++i) {
                m_data[i] = other.m_data[i];
            }

            // d) copy remaining member data
            m_size = other.m_size;
        }

        return *this;   // this: BigData*    // *this == BigData // *this == BigData& 
    }

    void print() {}

private:
    int*        m_data;
    std::size_t m_size;  //  flach / bit für bit / Byte für byte zu Kopieren
};

int tueWas(int a, int b, int c)
{
    int ergebnis = a + b + c;
    return ergebnis;
}

void main_seminar_04_rule_of_three_01()
{
    BigData data{ 1000 };   // lokales Objekt

    //int value = 11;
    //auto result = tueWas(10, value, 12);

    // Aufruf vom Destruktor AUTOMATISCH am Ende des Scopes !!!
}

void main_seminar_04_rule_of_three_02()
{
    BigData data{ 1000 };   // lokales Objekt

    BigData data2 (data);   // Anlegen einer Kopie (keine Wertzuweisung)
    // BigData data2 = data;   // Anlegen einer Kopie // exakt dasselbe wie in der Zeile zuvor !!!

    BigData notEmpty{10};          // Syntax: Keine Klammern (also weder () noch {}) bei Klassen (!!!) ==> Default-Konstruktor

    notEmpty = data;           // Wertzuweisung von Objekten

    data = data;

    int a = 1;
    int b = 1;
    int c = 1;

    int d;

    d = c = b = a = 2;   // Mehrfachzuweisung

               // void
    notEmpty = (data = data2);  // Mehrfachzuweisung
}


void main_seminar_04_rule_of_three()
{
    test_copy_stl();

   // main_seminar_04_rule_of_three_01();
    //main_seminar_04_rule_of_three_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
