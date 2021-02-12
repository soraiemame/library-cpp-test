#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    Point p1 = inputP(),p2 = inputP();
    int Q;
    std::cin >> Q;
    for(int i = 0;i < Q;i++){
        Point q = inputP();
        auto ans = project(line(p1,p2),q);
        std::cout << ans.x << " " << ans.y << "\n";
    }
}