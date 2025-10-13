#ifndef FUNCTION_H
#define FUNCTION_H

#include "Set.h"
#include <iostream>

using namespace std;

void test() {
    set<int> s1;
    s1.add(1);
    s1.add(2);
    s1.add(3);
    cout << "s1 = " << s1 << "\n";

    set<int> s2;
    s2.add(3);
    s2.add(4);
    cout << "s2 = " << s2 << "\n";

    cout << "s1 + s2 = " << s1 + s2 << "\n";
    cout << "s1 - s2 = " << s1 - s2 << "\n";
    cout << "Intersection: " << s1.intersection(s2) << "\n";
    cout << "s1.has(2) = " << s1.has(2) << "\n";
    cout << "s1.is_empty() = " << s1.is_empty() << "\n\n";
    


    set<float> f1;
    f1.add(1.1);
    f1.add(2.2);
    f1.add(3.3);
    cout << "f1 = " << f1 << "\n";

    set<float> f2;
    f2.add(2.2);
    f2.add(4.4);
    cout << "f2 = " << f2 << "\n";

    cout << "f1 + f2 = " << f1 + f2 << "\n";
    cout << "f1 - f2 = " << f1 - f2 << "\n";
    cout << "f1.has(2.2) = " << f1.has(2.2) << "\n";

    set<float> f3;
    f3.add(1.100000000001);
    cout << "f1.has(1.100000000001): " << f1.has(1.100000000001) << "\n\n";



    set<string> str1;
    str1.add("apple");
    str1.add("banane");
    str1.add("orange");
    cout << "str1 = " << str1 << "\n";

    set<string> str2;
    str2.add("banana");
    str2.add("grape");
    cout << "str2 = " << str2 << "\n";

    cout << "str1 + str2 = " << str1 + str2 << "\n";
    cout << "Intersection: " << str1.intersection(str2) << "\n";
    cout << "str1.has('apple') = " << str1.has("apple") << "\n\n";

    

    set<pair<int, double>> p1;
    p1.add({1, 1.1});
    p1.add({2, 2.2});
    p1.add({3, 3.3});
    cout << "p1 = " << p1 << "\n";

    set<pair<int, double>> p2;
    p2.add({2, 2.2});
    p2.add({4, 4.4});
    cout << "p2 = " << p2 << "\n";

    cout << "p1 + p2 = " << (p1 + p2) << "\n";
    cout << "p1.has({2, 2.2}) = " << p1.has({2, 2.2}) << "\n\n";

    

    set<int> A;
    A.add(1); A.add(2); A.add(3); A.add(4); A.add(5);

    set<int> B;
    B.add(2); B.add(3); B.add(4);

    set<int> C;
    C.add(4); C.add(5); C.add(6);

    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << "\n\n";

    cout << "B is subset of A: " << (B.is_subset_of(A) ? "Yes" : "No") << "\n";
    cout << "A is superset of B: " << (A.is_superset_of(B) ? "Yes" : "No") << "\n";
    cout << "C is subset of A: " << (C.is_subset_of(A) ? "Yes" : "No") << "\n";
    cout << "A is superset of C: " << (A.is_superset_of(C) ? "Yes" : "No") << "\n\n";

    

    try {
        cout << "Index Error: ";
        int value = s1[10];
        cout << value << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    

    set<int> test;
    cout << test << "\n";
    test += 10;
    test += 20;
    cout << test << "\n";
    test -= 10;
    cout << test << "\n";
}

#endif
