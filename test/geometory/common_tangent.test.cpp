#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    circle A,B;
    A.C = inputP();std::cin >> A.r;
    B.C = inputP();std::cin >> B.r;
    auto _ans = tangetlines(A,B,true);
    VP ans;
    for(auto a : _ans)ans.push_back(a.S);
    std::sort(ans.begin(),ans.end(),compare_x);
    for(auto a : ans)std::cout << a.x << " " << a.y << "\n";
}