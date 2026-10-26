
void test_01() {

    int wieviel = sizeof(long long);      // 8 Bytes = 8 * 8 = 64 Bits
    int wieviel2 = sizeof(size_t);   // 8 Bytes = 8 * 8 = 64 Bits

    // C: Datentyp Pointer
    int n = 123;
    int m = 15;

    // Datentyp: Adresse
    int* ptr = &n;        // &: Address of Operator   // =x10F0  // referenzieren

    // Übungsaufgabe: Wert von 999 an n zuweisen, ohne den Variablennamen n zu verwenden
    *ptr = 0xABA;     // indirekte Wertzuweisung // derefenzieren

    ptr = 999;    // <=======================

    // 2. Übungsaufgabe
    ++ptr;
}
