#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include <iostream>

#include "../data-structure/lazysegtree.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    SegTree<int> S(N,2147483647);
    S.range_update(0,N,0);
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int s,t,x;
            std::cin >> s >> t >> x;
            S.range_add(s - 1,t,x);
        }
        if(t == 1){
            int a;
            std::cin >> a;
            std::cout << S.get(a - 1) << "\n";
        }
    }
}