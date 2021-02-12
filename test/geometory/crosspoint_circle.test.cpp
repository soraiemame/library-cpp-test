#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_E"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    circle A,B;
    A.C = inputP();std::cin >> A.r;
    B.C = inputP();std::cin >> B.r;
    auto ans = crosspointCC(A,B);
    if(ans.size() == 1)ans.push_back(ans[0]);
    if(!compare_x(ans[0],ans[1]))std::swap(ans[0],ans[1]);
    std::cout << ans[0].x << " " << ans[0].y << " " << ans[1].x << " " << ans[1].y << "\n";
}