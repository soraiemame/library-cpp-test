#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A"

#include "../../geometory/main.hpp"

int main(){
    circle A,B;
    A.C = inputP();std::cin >> A.r;
    B.C = inputP();std::cin >> B.r;
    std::cout << tangetlines(A,B).size() << "\n";
}