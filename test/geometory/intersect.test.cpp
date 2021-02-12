#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"

#include "../../geometory/main.hpp"

int main(){
    int Q;
    std::cin >> Q;
    while(Q--){
        lineseg A(inputP(),inputP()),B(inputP(),inputP());
        std::cout << isecSS(A,B) << "\n";
    }
}