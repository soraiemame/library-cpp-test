#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    Point A = inputP(),B = inputP(),C = inputP();
    auto ans = gaisin(A,B,C);
    std::cout << ans.x << " " << ans.y << " " << distPP(ans,A) << "\n";
}