// =====================================================================================
// Seminar_05_Range_Based_ForLoop.cpp
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

void main_seminar_05_range_based_for_loop_01()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [&](int value) -> void {
            std::println("{}", value);
        }
    );
}

void main_seminar_05_range_based_for_loop_02()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    // for_each   Neues Schlüsselwort

    for (auto& value : numbers) {   // Hat nichts mit einem Lambda zu tun
        value = value + 10;
    }

    for (auto value : numbers) {
        std::println("{}", value);
    }
}

void main_seminar_05_range_based_for_loop_03()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [&](auto value) -> void {
            std::println("{}", value);
        }
    );
}

// Modernere Schreibweise für Funktionstemplates

static void function(auto x, int y) {
    std::println("x={} y={}", x, y);
};

void main_seminar_05_range_based_for_loop_04()
{
    function(1 ,1);              // Stack Frame:  4 bytes
    function(123.456, 1);        // Stack Frame:  8 bytes
    std::string s("ABC");
    function(s, 1);              // Stack Frame:  40 bytes
}

void main_seminar_05_range_based_for_loop_06()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    auto printer = [](auto value) -> void {
        std::println("{}", value);
    };

    std::for_each(
        numbers.begin(),
        numbers.end(),
        printer
    );

    std::vector<double> doubleNumbers;
    doubleNumbers.push_back(10.7);
    doubleNumbers.push_back(11.7);
    doubleNumbers.push_back(12.7);

    std::for_each(
        doubleNumbers.begin(),
        doubleNumbers.end(),
        printer
    );
}

void main_seminar_05_range_based_for_loop()
{
    main_seminar_05_range_based_for_loop_06();
}

// =====================================================================================
// End-of-File
// =====================================================================================
