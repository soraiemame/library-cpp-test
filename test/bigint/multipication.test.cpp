#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C"

#include <iostream>

#include "../../math/bigint.hpp"
#include "../../atcoder/convolution.hpp"

int main(){
    bigint_convolution::set(atcoder::convolution_ll);
    bint a,b;
    std::cin >> a >> b;
    std::cout << a * b << "\n";
}