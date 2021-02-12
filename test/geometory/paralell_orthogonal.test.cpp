#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"

#include "../../geometory/main.hpp"

int main(){
    int Q;
    std::cin >> Q;
    while(Q--){
        line A(inputP(),inputP()),B(inputP(),inputP());
        int ans = line_place(A,B);
        if(ans == 1)ans = 2;
        else if(ans == 3)ans = 1;
        std::cout << ans << "\n";
    }
}