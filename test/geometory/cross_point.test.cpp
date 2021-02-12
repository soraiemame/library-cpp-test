#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    int Q;
    std::cin >> Q;
    while(Q--){
        line A(inputP(),inputP()),B(inputP(),inputP());
        auto ans = crosspointLL(A,B);
        std::cout << ans.x << " " << ans.y << "\n";
    }
}