// =====================================================================================
// Seminar_04_Rule_Of_Three.cpp // Referenzen
// =====================================================================================

#include <cstddef>
#include <algorithm>
#include <print>

class BigData
{
public:
    BigData() 
        : m_data{ nullptr }, m_size{}
    {}

    // Destruktor
    ~BigData() {
        std::println("d'tor");
        delete[] m_data;   // array - delete
    }  

    BigData(std::size_t size) {

        m_data = new int[size];   // array - new
        m_size = size;

        std::fill(m_data, m_data + m_size, 0);        
    }

private:
    int*        m_data;
    std::size_t m_size;
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

    BigData data2 = data;    // Anlegen einer Kopie
}


void main_seminar_04_rule_of_three()
{
   // main_seminar_04_rule_of_three_01();
    main_seminar_04_rule_of_three_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
