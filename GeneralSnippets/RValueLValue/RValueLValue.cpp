// =====================================================================================
// LValue / RValue
// =====================================================================================

module modern_cpp:rvalue_lvalue;

import std;

namespace {

    // lvalue reference
    void sayHello(std::string& message) {
        std::println("sayHello [std::string&]:  {}", message);
    }

    // rvalue reference
    void sayHello(std::string && message) {
        std::println("sayHello [std::string&&]: {}", message);
    }

    void rvalue_lvalue_01() {

        std::string a = "Hello";

        std::string& ra = a;

        std::string b = " World";

        std::string && rab = a + b;

        sayHello(a);
        
        sayHello(a + b);  // a + b:  operator+:  std::string:  Konkatenation / Aneinanderhängen: "Hello World"
    }

    // -------------------------------------------------------------------

    void helper(std::string && message)   // RValue Referenz
    {
        sayHello( std::move(  message ) );   // a) sayHello (&&): Typgleichheit // Formal
                             // b) sayHello (&):  Das vormals anonyme Objekt hat einen Namen erhalten (message)
    }



    void rvalue_lvalue_02()
    {
        std::string a = "";

        helper( std::move( a ) );    // std::move removes the name 'a' from the object

        helper( a + "" );   // Ginge !!!  Cool  .........

        helper(std::string("Where are we going ..."));
    }

    // -------------------------------------------------------------------

    void rvalue_lvalue_03() {

        std::string s = "Hello";

        sayHello(s);
        // versus
        sayHello(std::move(s));  // casts an lvalue to an rvalue
    }

    // -------------------------------------------------------------------

    void rvalue_lvalue_04() {

        int a = 2;
        int b = 3;

        int& ri = a;          // works: (lvalue) reference to a (named) variable

        // int& i = 123;      // invalid: (lvalue) reference to a constant

        int&& i = 123;        // works: (rvalue) reference to a constant

        const int& j = 123;   // works: const references binds to everything

        // int& k = a + b;    // invalid: (lvalue) reference to a temporary object

        int&& k = a + b;      // works: (rvalue) reference to a temporary object
    }
}

void main_rvalue_lvalue()
{
    rvalue_lvalue_01();
    rvalue_lvalue_02();
    rvalue_lvalue_03();
    rvalue_lvalue_04();
}

// =====================================================================================
// End-of-File
// =====================================================================================
