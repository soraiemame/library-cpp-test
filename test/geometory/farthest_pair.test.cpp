#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    int N;
    std::cin >> N;
    VP vec(N);
    for(int i = 0;i < N;i++)vec[i] = inputP();
    auto ans = farthestdist(vec);
    std::cout << ans << "\n";
}