#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    int N;
    std::cin >> N;
    VP vec(N);
    for(int i = 0;i < N;i++)vec[i] = inputP();
    auto pol = polygon(vec);
    DD ans = area(pol);
    std::cout << std::fixed << std::setprecision(1) << ans << "\n";
}