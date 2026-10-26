// =====================================================================================
// Seminar_01_STL.cpp // STL
// =====================================================================================

#include <algorithm>
#include <list>
#include <print>
#include <vector>

void test_99() {

    int n = 123;

    //   int m = ++n;   // Pre - Inkrement   // Muss KEINE Kopie bereit stellen
    //   int m = n++;   // Post - Inkrement  // Muss ne Kopie bereit stellen: Ist langsamer

       // Empfehlung: Don't do this !!!!!!!!!!!!!!!

      // ++n;
    int m = n;
    ++n;
    std::println("m= {}", m);
}

// Leerer Namesraum: Alles hier drinnen ist nur in DIESER Datei verfügbar
namespace {

    //class IntCalculator
    //{
    //public:
    //    static int add(int x, int y) { return x + y; }
    //    static int sub(int x, int y) { return x - y; }
    //    static int mul(int x, int y) { return x * y; }
    //    static int div(int x, int y) { return x / y; }
    //};

    //class DoubleCalculator
    //{
    //public:
    //    static double add(double x, double y) { return x + y; }
    //    static double sub(double x, double y) { return x - y; }
    //    static double mul(double x, double y) { return x * y; }
    //    static double div(double x, double y) { return x / y; }
    //};

    // Schablone
    template < typename T >
    class Calculator
    {
    public:
        static T add(T x, T y) { 
            return x + y;
        }
        static T sub(T x, T y) { return x - y; }
        static T mul(T x, T y) { return x * y; }
        static T div(T x, T y) { return x / y; }
    };

    void test_01() {

        int result = Calculator<int>::add(5, 4);
        double dresult = Calculator<double>::add(3.7, 5.7);
    }


    void test_02() {

        std::vector<int> numbers;   // lokale Variable

      //  numbers.reserve(80);

        numbers.resize(5);

        // unsigned long long

        std::size_t s = numbers.size();
        std::size_t cap = numbers.capacity();
        int* anfang = numbers.data();

        //int* anfang = numbers.data();
        //anfang[50] = 123;   // Offsets auf die Anfangsadresse.

        for (std::size_t i = 0; i != 100; ++i) {

            numbers[i] = static_cast<int> (2 * i);
            // numbers.push_back(static_cast<int> (2 * i));

            std::println("Index: {} - Size: {} - Capacity: {} - ", 
                i, numbers.size(), numbers.capacity());
        }
    }

    // short:  16 Bits

    auto adder(short a, short b) {
        return a + b;
    }

    void test_03() {

        std::vector<int> numbers;
       // std::list<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        for (std::size_t i = 0; i != numbers.size(); ++i) {

            std::println("Index: {} - Wert: {}", i, numbers[i]);
        }
    }

    void test_04() {

        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        // Position
        std::vector<int>::iterator pos;

        pos = numbers.begin();

        if (pos == numbers.end()) {
            std::println("Ende.");
            return;
        }

        int value = *pos;
        std::println("{}", value);

        // zur nächsten Position
        ++pos;
        if (pos == numbers.end()) {
            std::println("Ende.");
            return;
        }
        value = *pos;
        std::println("{}", value);

        // zur nächsten Position
        ++pos;
        if (pos == numbers.end()) {
            std::println("Ende.");
            return;
        }
        value = *pos;
        std::println("{}", value);

        // zur nächsten Position
        ++pos;
        if (pos == numbers.end()) {
            std::println("Ende.");
            return;
        }
        value = *pos;
        std::println("{}", value);
    }

    // C++ 98 Style
    void test_05() {

        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        std::vector<int>::iterator pos = numbers.begin();
        std::vector<int>::iterator ende = numbers.end();

        //for (; pos != numbers.end() ; ++pos ) {
        //    std::println("{}", *pos);
        //}

        while (pos != numbers.end()) {

            std::println("{}", *pos);
            ++pos;
        }
    }

    // The signature does not need to have const &.
    void print(const int& value) {

        int m = value;

        std::println("{}", value);
    }

    class Person
    {
        std::string first;
        std::string last;
        std::size_t age;
    };

    void test_semantics()
    {

    }


    // C++ 98 Style
    void test_06() {

        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        std::for_each(
            numbers.begin(),
            numbers.end(),
            print
        );
    }

}

void main_seminar_01_stl()
{
    //test_01();
    //test_02();
    // test_03();
    // test_04();
    // test_05();
    test_06();

    // test_99();
}

// =====================================================================================
// End-of-File
// =====================================================================================
