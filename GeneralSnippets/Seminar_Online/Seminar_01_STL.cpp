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

        //std::vector<int>::iterator pos = numbers.begin();
        //std::vector<int>::iterator ende = numbers.end();
        
        auto pos = numbers.begin();
        auto ende = numbers.end();

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

    // ======================================

    // Was ist ein aufrufbares Objekt:
    // Ein Objekt / Klasse, das den Operator operator() implementiert
    class Base {

        virtual void print() {};
    };

    class Addierer : public Base
    {
    public:
        // Überladen von Operatoren
        int operator () (int a, int b) { 
            return a + b;
        }

        void print() override {}
    };


    // 0000000000000000000000000000000000000000000000

    class MyClass
    {
    public:
        MyClass () : m_hiddenValue (0) {}
        MyClass(int value) : m_hiddenValue(value) {}

        // Überladen von Operatoren
        // Was ist ein Operator IN C++: Quasi eine Methode !!! Mit (hier) dem Namen operator + 
        MyClass operator + (const MyClass& other) {

            // Wieviele MyClass Objekte stehen in dieser Zeile zur Verfügung:  
            // this.m_hiddenValue, (  self ), other.m_hiddenValue,
            MyClass result (this->m_hiddenValue + other.m_hiddenValue);  // lokale Var.
            return result;   // Kopie !!!

          //  return MyClass (this->m_hiddenValue + other.m_hiddenValue);
        }

        MyClass* operator * (const MyClass& other) {

            int prod = m_hiddenValue * other.m_hiddenValue;
            MyClass* ptr = new MyClass(prod);    //  C++ 98  // C++  Classic
            return ptr;
        }


    private:
        int m_hiddenValue;
    };

    void test_07() {
    
        MyClass a(10);
        MyClass b(20);
        MyClass c;

        c = a + b;
        c = a.operator+ (b);

        MyClass* resultPtr = a * b;

        delete resultPtr;

        // int n = 1 + 2; 
    
    }

    void test_08() {
    
        Addierer myAdder;

        int result = myAdder(3, 4);
    }

    // ===========================================

    //void print(const int& value) {
    //    std::println("{}", value);
    //}



    void test_09() {

        // C++ 98
        // Jepp, das geht tatsächlich: Eine lokale Klasse
        class Printer
        {
        private:
            std::string m_header;

        public:
            Printer() : m_header(">>> ") {}

            Printer(const std::string& header) : m_header(header) {}

            void operator () (int value) {
                std::println("{} {}", m_header, value);
            }
        };
    
        std::vector<int> numbers;

   //     Printer myPrinter ("??? --> ");

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        std::for_each(
            numbers.begin(),
            numbers.end(),
            Printer ("??? --> ")
        );
    }

    //void print(int value) {
    //    std::println("{}", value);
    //}

    void test_10() {

        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        std::for_each(
            numbers.begin(),
            numbers.end(),
            [] (int value) {               // Inline  // Lambda
                std::println("{}", value);
            } 
        );
    }

    void test_11() {

        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        auto myLambda = [](int value) { std::println("{}", value); };

        std::for_each(
            numbers.begin(),
            numbers.end(),
            myLambda
        );
    }

    void test_12() {

        std::vector<int> numbers;

        std::string header(">>> ");

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        std::for_each(
            numbers.begin(),
            numbers.end(),
            [&](int value) -> void {
                std::println("{} {}", header, value);
            }
        );
    }

    void test_13() {

        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(11);
        numbers.push_back(12);

        // einen Wert im Container suchen .... std::vector

        auto result = std::find(   // result ist eine Position
            numbers.begin(),
            numbers.end(),
            111
        );

        if (result == numbers.end()) {
            std::println("Not found");
        }
        else {
            std::println("Found: {}", *result);
        }

        // 2. Alternative
        for (int i = 0; i != numbers.size(); ++i) {
            if (numbers[i] == 11) {
                std::println("Found!");
                break;
            }
        }
    }
}

void main_seminar_01_stl()
{
    //test_99();
 
    //test_01();
    //test_02();
    //test_03();
    //test_04();
    //test_05();
    //test_06();
    test_07();
    //test_08();
    //test_09();
    //test_10();
    //test_11();
    //test_12();
    // test_13();




}


// =====================================================================================
// End-of-File
// =====================================================================================
