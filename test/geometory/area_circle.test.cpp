#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_I"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    circle A,B;
    A.C = inputP();std::cin >> A.r;
    B.C = inputP();std::cin >> B.r;
    auto ans = twocirclearea(A,B);
    std::cout << ans << "\n";
}