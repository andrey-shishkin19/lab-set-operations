#ifndef FUNCTION_H
#define FUNCTION_H

#include "set.h"
#include <iostream>
#include <string>

using namespace std;

void test() {
    int arr_int[] = {1, 3, 5, 7, 9};
    set<int> A1(arr_int, 5);
    cout << "A1 = " << A1 << "\n";
    
    set<int> A5(A1);
    cout << "A5 = " << A5 << "\n";

    set<int> A;
    A.add(1); A.add(2); A.add(3);
    set<int> B;
    B.add(2); B.add(3); B.add(4);

    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "A + B = " << A + B << "\n";
    cout << "A - B = " << A - B << "\n";
    cout << "A + 5 = " << A + 5 << "\n";
    cout << "A - 2 = " << A - 2 << "\n";
    cout << "A.has(2) = " << A.has(2) << "\n";
    cout << "Intersection = " << set_intersection(A, B) << "\n";
    cout << "A == B = " << (A == B) << "\n";
    cout << "A != B = " << (A != B) << "\n";

    set<int> C;
    C.add(2); C.add(3);
    cout << "C = " << C << "\n";
    
    C += 10;
    cout << "C += 10 = " << C << "\n";
    C -= 2;
    cout << "C -= 2 = " << C << "\n";

    cout << "C is subset of A = " << is_subset(C, A) << "\n";
    cout << "A is superset of C = " << is_superset(A, C) << "\n";
    cout << "A[0] = " << A[0] << "\n";

    
    float arr_float[] = {1.1, 3.3, 5.5, 7.7, 9.9};
    set<float> A2(arr_float, 5);
    cout << "A2 = " << A2 << "\n";

    set<float> D;
    D.add(1.1); D.add(2.2); D.add(3.3);
    set<float> E;
    E.add(2.2); E.add(4.4);

    cout << "D = " << D << "\n";
    cout << "E = " << E << "\n";
    cout << "D + E = " << D + E << "\n";
    cout << "D.has(2.2001) = " << D.has(2.2001) << "\n";

    
    string arr_str[] = {"Lamine", "Bellingham", "Vitinha"};
    set<string> F1(arr_str, 3);
    cout << "F1 from array = " << F1 << "\n";

    set<string> F;
    F.add("apple"); F.add("Yamal"); F.add("orange");
    set<string> G;
    G.add("Yamal"); G.add("grape");

    cout << "F = " << F << "\n";
    cout << "G = " << G << "\n";
    cout << "F + G = " << F + G << "\n";
    cout << "F.has(\"apple\") = " << F.has("apple") << "\n";

    
    set<pair<int, double>> H;
    H.add({1, 1.1}); H.add({2, 2.2}); H.add({3, 3.3});
    set<pair<int, double>> I;
    I.add({2, 2.2}); I.add({4, 4.4});

    cout << "H = " << H << "\n";
    cout << "I = " << I << "\n";
    cout << "H + I = " << H + I << "\n";
    cout << "H.has({2, 2.2001}) = " << H.has({2, 2.2001}) << "\n";

    
    set<int> random_ints(5, 1, 10);
    set<float> random_floats(4, 0.0, 5.0);
    set<string> random_strings(4, "a", "z");

    cout << "Random ints = " << random_ints << "\n";
    cout << "Random floats = " << random_floats << "\n";
    cout << "Random strings = " << random_strings << "\n";


    
    set<int> J = A;
    J += 10;
    cout << "A += 10 = " << J << "\n";
    J -= 2;
    cout << "J -= 2 = " << J << "\n";

    
    try {
        cout << "A[10] = " << A[10] << "\n";
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << "\n";
    }
}

#endif
