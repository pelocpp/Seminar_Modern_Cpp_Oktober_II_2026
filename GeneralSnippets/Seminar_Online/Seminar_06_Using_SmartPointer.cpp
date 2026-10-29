// =====================================================================================
// Seminar_06_Using_SmartPointer.cpp
// =====================================================================================

#include <cstddef>
#include <algorithm>
#include <print>
#include <vector>
#include <memory>

// Ansatz mit std::unique_ptr<int[]>: Zu klären; Muss ich diese Objekte kopieren können ???
class MyData
{
public:
    MyData() 
        : m_data{ std::make_unique<int[]>(10) }
    {
        m_data[0] = 1;
        m_data[1] = 2;
        m_data[2] = 3;
    }

    // möchte Objekte dieses Typ kopieren
    MyData (const MyData& other) {

        // sinnvolle Impl. im Kopf
        m_data = std::make_unique<int[]>(10);

        std::copy(&other.m_data[0], &other.m_data[0] + 10, &m_data[0]);   // memcpy  ... 
    }

public:
    std::unique_ptr<int[]> m_data;
};

class MyDataAlternate
{
public:
    MyDataAlternate()
        : m_data{ std::make_shared<int[]>(10) }
    {
        m_data[0] = 1;
        m_data[1] = 2;
        m_data[2] = 3;
    }

    MyDataAlternate(const MyDataAlternate& other) {

        //// sinnvolle Impl. im Kopf
        //m_data = std::make_shared<int[]>(10);
        //std::copy(&other.m_data[0], &other.m_data[0] + 10, &m_data[0]);   // memcpy  ... 

        m_data = other.m_data;
    }

public:
    std::shared_ptr<int[]> m_data;
};



void main_seminar_06_frage_smart_pointer()
{
    MyData data;
    MyData copy = data;

    data.m_data[0] = 123;

    std::println("{}", data.m_data[0]);
    std::println("{}", copy.m_data[0]);

    // ===================

    MyDataAlternate data2;
    MyDataAlternate copy2 = data2;

    data2.m_data[0] = 123;

    std::println("{}", data2.m_data[0]);
    std::println("{}", copy2.m_data[0]);

}

// =====================================================================================
// End-of-File
// =====================================================================================
