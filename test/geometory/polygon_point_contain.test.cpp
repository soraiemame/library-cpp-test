#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C"

#include "../../geometory/main.hpp"

int main(){
    int N;
    std::cin >> N;
    VP vec(N);
    for(int i = 0;i < N;i++)vec[i] = inputP();
    polygon pol(vec);
    int Q;
    std::cin >> Q;
    while(Q--){
        Point p = inputP();
        int ans = inpolygon(p,pol);
        if(ans == 1)ans = 2;
        else if(ans == 2)ans = 1;
        std::cout << ans << "\n";
    }
}