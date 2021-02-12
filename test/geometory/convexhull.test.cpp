#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"

#include "../../geometory/main.hpp"

int main(){
    int N;
    std::cin >> N;
    VP vec(N);
    for(int i = 0;i < N;i++)vec[i] = inputP();
    auto ans = convexhull(vec);
    int n = ans.size();
    int from = 0;Point now = ans[0];
    for(int i = 0;i < n;i++){
        if(compare_y(ans[i],now)){
            now = ans[i];
            from = i;
        }
    }
    std::cout << n << "\n";
    for(int i = n;i > 0;i--){
        std::cout << ans[(i + from) % n].x << " " << ans[(i + from) % n].y << "\n";
    }
}