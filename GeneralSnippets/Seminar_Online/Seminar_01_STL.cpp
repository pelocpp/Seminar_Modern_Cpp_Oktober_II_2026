// =====================================================================================
// Seminar_01_STL.cpp // STL
// =====================================================================================

#include <vector>
#include <print>

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

        std::vector<int> numbers;

        for (std::size_t i = 0; i != 100; ++i) {

        }
    }

    // short:  16 Bits

    auto adder(short a, short b) {
        return a + b;
    }
}

void main_seminar_01_stl()
{
    test_01();
    test_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
