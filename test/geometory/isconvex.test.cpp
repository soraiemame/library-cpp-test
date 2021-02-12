#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"

#include "../../geometory/main.hpp"

int main(){
    int N;
    std::cin >> N;
    VP vec(N);
    for(int i = 0;i < N;i++)vec[i] = inputP();
    polygon pol(vec);
    std::cout << isconvex(pol) << "\n";
}