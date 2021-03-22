#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A"

#include <iostream>

#include "../../math/bigint.hpp"

int main(){
    string S,T;
    cin >> S >> T;
    bint a(S),b(T);
    cout << (a + b).to_string() << "\n";
}