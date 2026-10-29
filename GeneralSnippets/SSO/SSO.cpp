// =====================================================================================
// SSO.cpp // SSO (Small String Optimization)
// =====================================================================================

module modern_cpp:sso;

import std;

void main_sso()
{
    auto size{ sizeof(std::string) };
    auto capacity{ std::string{}.capacity() };
    auto small { std::string(capacity, '*') };
    auto big{ std::string{ 20, '#' } };   // Size:  2 "?#"
    auto big2{ std::string(capacity, '#') };   // Size:  capacity

    std::cout << "sizeof  : " << size << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Small   : " << small.capacity() << ": " << small << std::endl;
    std::cout << "Big     : " << big.capacity() << ": " << big << std::endl;
}

// =====================================================================================
// End-of-File
// =====================================================================================
