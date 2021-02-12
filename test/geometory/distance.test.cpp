#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    int Q;
    std::cin >> Q;
    while(Q--){
        lineseg A(inputP(),inputP()),B(inputP(),inputP());
        DD ans = distSS(A,B);
        std::cout << ans << "\n";
    }
}