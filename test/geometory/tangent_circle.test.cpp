#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_F"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    Point A = inputP();circle B;
    B.C = inputP();std::cin >> B.r;
    auto ans = tangentpoints(B,A);
    if(!compare_x(ans[0],ans[1]))std::swap(ans[0],ans[1]);
    std::cout << ans[0].x << " " << ans[0].y << "\n" << ans[1].x << " " << ans[1].y << "\n";
}